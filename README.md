# PROFESSOR RATINGS MODEL

## Goals
- Summarize [UCSB Grades Dataset](courseGrades.csv) by professor.
- Scrape data from [ratemyprofessor.com](ratemyprofessor.com) for each relevant professor.
- Create a model to predict professor ratings based on the data.

## Skills/Tools Used

- Object Oriented Programming in C++
- CSV file manipulation using C++
- HTML Scraping with BeautifulSoup in Python
- Analysis and linear modeling with R

## Steps
1. Starting with the [original dataset](data/courseGrades.csv) for each line in the csv
   - instantiate or update the appropriate `prof_info` object as described in [professor.cpp](RMP_data_transform/professor.cpp)
   - add professor name to the professors `unordered_map` with `prof_info` object as the associated value.
   - for professors who taught pass/no pass classes, GPA is esimated with pass as a 4.0 and no pass as a 0.
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
7. Do data analysis and create a model in R. Results are described below and the code can be found [here](RMP_data_analysis.Rmd)
   - *Note: It would have been easier to write the code in a normal .R file, but I needed to practice .Rmd for my research poisition*

## Conclusions
1. Average GPA has been increasing at UCSB and this trend was accelerated by COVID-19
    
   ![YearGPA](https://github.com/user-attachments/assets/4195aaae-74ad-4939-92f7-6e20308f9048)
   
2. The best model for rating out of the data that I collected is a one-factor model based soley on GPA (reasoning explained in [RMP_data_analysis.Rmd](RMP_data_analysis.Rmd)). GPA is not a particularly good predictor, with an R² = 0.12

   ![One-Factor Model](https://github.com/user-attachments/assets/f9b3c3d4-d08b-4d31-b022-c243851d5b40)
   
3. GPA and Difficulty are inversely correlated, but not as closely as expected. Personally, I would rate the difficulty of a class by how much time I have to commit to get an A, with some bonus points for challenging exam questions. This provides a few possible explanations for the errors between self-reported difficulty and grading difficulty.
   - People posting reviews before grades are finalized (ex: exam scores are low but the professor always makes large curves to the final class grade)
   - A professor's classes aren't difficult, but it is more/less difficult than students expected when they signed up. (ex: A GE with in-person exams or a Comp-Sci professor who only does projects)
   - A professor teaches mostly lower division courses to freshman who expect to not have to study.
   
   ![GPA vs difficulty](https://github.com/user-attachments/assets/86a4d09e-0551-47c3-82b4-15b845ae8188)

## Sources
- UCSB Grades Data - [DailyNexus](https://github.com/dailynexusdata/grades-data)
- Professor Ratings - [RateMyProfessor](https://www.ratemyprofessors.com/search/professors/1077?q=)
- Linear Modeling Textbook - [Linear Models in R by Julian Faraway](https://julianfaraway.github.io/faraway/LMR/)
   
