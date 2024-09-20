#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <vector>
#include <string>
#include <set>
#include <iostream>

class prof_info {
 public:
	 // default constructor
	 prof_info();
	 
	 // returns total number of students that a professor has taught
	 // num_pnp_stu + num_letter_stu
	 const int getNumStu();

	 // divides total_gpa_points by number of students taught
	 const double getAvgGPA();

	 // basic getters
	 const int getNumPNP();
	 const int getNumLetter();
	 const int getFirstYear();
	 const int getLastYear();
	 const std::set<std::string> getDepartments();

	 // adds data when the professor has taught multiple classes
	 // utilizes csv_line struct
	 void addData(std::string& line);
	 
	 void print();


 private:
	 int num_pnp_stu = 0;
	 int num_letter_stu = 0;
	 double total_gpa_points = 0.0; //storing total instead of average so that average is properly weighted by class size
	 int first_year = 0;
	 int recent_year = 0;
	 std::set<std::string> departments;
};

#endif