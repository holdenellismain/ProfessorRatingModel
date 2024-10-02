import pandas as pd
from web_scraper import scrape
from time import sleep

path = 'transformedData.csv'
csv = pd.read_csv(path)

#filter DF to reduce GPA outliers and professors without RMP ratings
csv = csv[csv['Students'] > 600] #600 chosen somewhat arbitrarily as the threshold where professors will usually have >20 RMP ratings

#add rows for new variables
csv.insert(1, 'RMP Name', '')
csv.insert(3, 'Difficulty', '')
csv.insert(5, 'n', '')
csv.insert(10, 'Rating', '')

amount_written = 0

for index, row in csv.iterrows():
    professor_name = row['Name']
    info = scrape(professor_name)
    
    #add columns for new data
    if info != None:
        csv.loc[index,'RMP Name'] = info[0]
        csv.loc[index,'Difficulty'] = info[2]
        csv.loc[index,'n'] = info[3]
        csv.loc[index,'Rating'] = info[1]
        #write to csv row-by-row
        #makes program to take longer but means data isn't lost due to crashes
        #important because crashes can be caused by factors mostly out of my control such as wifi or rate limiting
        if csv.loc[index,'n'] > 20: #if there is a sufficent sample of reviews
            output_row = csv.loc[index].to_frame().T
            output_row.to_csv('output.csv', mode='a', index=False, header=False)

    #sleep to avoid rate limiting, not sure if this is actually necessary
    sleep(0.3)

print('Execution complete')
