#include "writerfuncs.h"

std::string write_to_csv(const std::string& name, prof_info& prof) {
	//if professor was on registry but didn't have any students, don't print
	if (prof.getNumStu() == 0) {
		return "";
	}

	//format: "name,average gpa,total students taught,first year,recent year,pnp,grade,subject,subject...,subject,\n"
	std::string str = name;
	str += ',' + std::to_string(prof.getAvgGPA());
	str += ',' + std::to_string(prof.getNumStu());
	str += ',' + std::to_string(prof.getFirstYear());
	str += ',' + std::to_string(prof.getLastYear());
	str += ',' + std::to_string(prof.getNumPNP());
	str += ',' + std::to_string(prof.getNumLetter());
	for (const std::string& dept : prof.getDepartments())
		str += ',' + dept;
	str += ',\n';
	
	return str;
}
