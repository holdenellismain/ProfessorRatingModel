import requests
from bs4 import BeautifulSoup

def scrape(full_name):
    '''
    -- Parameters --
    (str) : a professors name in the format "LAST F M"
    -- Returns --
    (array) : [rate my professor name, rating, difficulty rating, number of ratings]
    '''
    #STEP 1: CLEAN PROFESSOR NAME TO SEARCH
    
    #remove split into first and last and remove extra initials
    full_name = full_name.split()
    last_name = full_name.pop(0)
    try:
        first_name = full_name.pop(0)
    except:
        first_name = ""
    #extra = ' '.join(full_name) #not sure if this helps the search or not

    #some last names have a dash in them, just take the first part in this case
    idx = last_name.find('-')
    if idx > 0:
        last_name = last_name[:idx]
    
    #searches professors at UCSB by name
    url = f'https://www.ratemyprofessors.com/search/professors/1077?q={last_name}%20{first_name}'
    request = requests.get(url)
    soup = BeautifulSoup(request.text, 'html.parser')
    
    #scrape data off the first professor card on the search result page
    try: 
        rating = soup.select('[class*="CardNumRating__CardNumRatingNumber"]')[0].text
    except: #if RateMyProfessor search doesn't return anything
        print(full_name, "not found by ratemyprofessor.com")
        return None
    
    difficulty = soup.select('[class*="CardFeedback"]')[0].text
    start_idx = difficulty.index('again')
    end_idx = difficulty.index('level')
    difficulty_rating = difficulty[start_idx+5:end_idx]
    
    rmp_name = soup.select('[class*="CardName"]')[0].text
    
    num_ratings = soup.select('[class*="CardNumRating__CardNumRatingCount"]')[0].text.split()[0]
    
    return rmp_name, float(rating), float(difficulty_rating), int(num_ratings)