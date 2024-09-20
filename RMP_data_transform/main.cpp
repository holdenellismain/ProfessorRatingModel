#include "writerfuncs.h"
#include "professor.h"
#include "test.h"

#include <fstream>
#include <string>
#include <iostream> //debugging
#include <unordered_map>

using namespace std;

int main() {
	//open file stream
	fstream infs;

	string in_path = "C:/Users/fires/Python Projects/Rate My Professor LM/courseGrades.csv";
	infs.open(in_path, ios::in);
	
	if (!infs.is_open()) {
		return 1;
	}
	
	//initialize variables
	unordered_map<string, prof_info> professors; //map of all professors
	string line; //temporary varaible to read lines into
	getline(infs, line); //pass header
	getline(infs, line); //read 1st line
	
	while (!infs.eof()) {
		int end_name = line.find(',');
		string name = line.substr(0, end_name);

		if (professors.find(name) == professors.end()) {
			//construct new professor info object
			professors[name] = prof_info();
		}
		professors[name].addData(line);

		//read next line
		getline(infs, line);
	}

	//close input file stream
	infs.close();

	//open output file stream
	ofstream ofs;

	string o_path = "C:/Users/fires/Python Projects/Rate My Professor LM/transformedData.csv";
	ofs.open(o_path);

	if (!ofs.is_open()) {
		return 1;
	}

	// write to output file
	//write header
	ofs << "Name,GPA,Students,First,Recent,PNP Students,Letter Students,Subject,Subject,Subject,Subject,Subject,Subject,Subject\n";
	for (auto prof: professors) {
		string line = write_to_csv(prof.first, prof.second);
		ofs << line;
	}

	ofs.close();

	return 0;
};