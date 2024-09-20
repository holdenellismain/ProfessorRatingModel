# PROFESSOR RATINGS MODEL

## Goals
- Summarize [UCSB Grades Dataset](courseGrades.csv) by professor.
- Scrape data from [ratemyprofessor.com](ratemyprofessor.com) for each relevant professor.
- Create a model to predict professor ratings based on the data.

## Skills/Tools Used

- Object Oriented Programming in C++
- CSV file manipulation using C++
- HTML Scraping with BeautifulSoup in Python
- Linear modelling with [statsmodels](https://www.statsmodels.org/stable/index.html) package.

## Steps
1. Starting with the [original dataset](data/courseGrades.csv) for each line in the csv
   - instantiate or update the appropriate `prof_info` object as described in [professor.cpp](RMP_data_transform/professor.cpp)
   - add professor name to the professors `unordered_map` with `prof_info` object as the associated value.
2. Export professors map to [csv](data/transformedData.csv), using `write_to_csv()` function
   - Remove professors who don't have any students taught.
4. In [Python](Python/rmpquery.py), import the [transformed data](data/transformedData.csv) as a pandas data frame and remove professors who have taught less than 600 students.
   This is done to limit html queries since most professors with less than 600 students will not have a large enough sample of professor reviews.
5. For each professor, use `scrape()` as defined in [web_scraped.py](Python/webscraper.py) to retrieve rating, difficulty, number of reviews, and the corresponding name from ratemyprofessor.
   - If ratemyprofessor's search feature does not return any professors, this function returns `None`
6. Update the dataframe with these values and write to the [output](data/output.csv)
   - Only writes if the professor has more than 20 reviews to avoid outliers due to small samples.
8. Do some manual cleaning on the output. Certain professors do not exist in ratemyprofessor which leads to the search returning a false positive. Deleting duplicates and manually
   verifying some of the professors who haven't taught at UCSB in a while resolved most of these cases. This is how [output_cleaned](data/output_cleaned.csv) was created.
7. Linear Model in JupyterNotebook -- WIP

## Conclusions
1. There is not as strong of a correlation between GPA and rating as I thought.
2. GPA and Difficulty are inversely correlated as expected, but not as strongly as I thought.

## Sources
- UCSB Grades Data - [DailyNexus](https://github.com/dailynexusdata/grades-data)
- Professor Ratings - [RateMyProfessor](https://www.ratemyprofessors.com/search/professors/1077?q=)
   
