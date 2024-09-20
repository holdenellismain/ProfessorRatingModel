#include "professor.h"

prof_info::prof_info() {
}

const int prof_info::getNumStu() {
	return num_pnp_stu + num_letter_stu;
}

const double prof_info::getAvgGPA() {
	return total_gpa_points / (num_pnp_stu + num_letter_stu);
}

const int prof_info::getNumPNP() {
	return num_pnp_stu;
}

const int prof_info::getNumLetter() {
	return num_letter_stu;
}

const int prof_info::getFirstYear() {
	return first_year;
}

const int prof_info::getLastYear() {
	return recent_year;
}

const std::set<std::string> prof_info::getDepartments() {
	return departments;
}

void prof_info::addData(std::string& line) {
	//get a vector of comma locations
	std::vector<int> locations;
	for (int i = 0; i < line.length(); ++i) {
		if (line[i] == ',') {
			locations.push_back(i);
		}
	}
	//locations:
	//year is at locations[1]
	//num letter grades is at locations[7]
	//num pass no pass is at locations[8]
	//avg gpa is at locations[9]
	//pass is at locations[10]
	//department is at locations[11]
	int class_year = stoi(line.substr(locations[1] + 1, locations[2] - locations[1] - 1));
	double avg_gpa = stod(line.substr(locations[9] + 1, locations[10] - locations[9] - 1));
	int passed = stoi(line.substr(locations[10] + 1, locations[11] - locations[10] - 1));
	int letter_grades = stoi(line.substr(locations[7] + 1, locations[8] - locations[7] - 1));
	int pnp_count = stoi(line.substr(locations[8] + 1, locations[9] - locations[8] - 1));
	
	// if class doesn't have students, don't update
	if (letter_grades == 0 && pnp_count == 0) {
		return;
	}

	//update professor's teaching years
	//works because sheet is sorted by year
	if (first_year == 0) { // 0 is default value
		first_year = class_year;
		recent_year = class_year;
	}
	else {
		recent_year = class_year;
	}

	//update professor's gpa
	total_gpa_points += avg_gpa * letter_grades;
	total_gpa_points += passed * 4.0; //assume anyone who passed got a 4.0 and anyone who didn't pass got 0.0

	//update attributes that don't require calculations
	departments.insert(line.substr(locations[11] + 1, locations[12] - locations[11] - 1));
	num_pnp_stu += pnp_count;
	num_letter_stu += letter_grades;
}

void prof_info::print() {
	std::cout << "Students Taught: " << getNumStu() << std::endl;
	std::cout << "Average GPA: " << getAvgGPA() << std::endl;
	std::cout << "Taught " << first_year << "-" << recent_year << std::endl;
	std::cout << "Taught subjects: ";
	for (const std::string& str : departments) {
		std::cout << str << ",";
	}
	std::cout << std::endl;
}
