#include "test.h"
using namespace std;

void professor_test_1() {
	string class1 = "BRADLEY N D,Fall,2009,19,0,0,0,2,26,0,3.619230769230769,0,WRIT,0,0,0,1,0,0,4,0,0,0,0,";
	string class2 = "BRADLEY N D,Winter,2010,9,9,1,0,1,46,0,3.217391304347826,0,WRIT,0,0,0,6,2,0,10,8,0,0,0,";

	prof_info bradley = prof_info();
	bradley.addData(class1);
	bradley.addData(class2);

	cout << "--OUTPUT: " << endl;
	bradley.print();

	cout << "--EXPECTED: " << endl;
	cout << "Students Taught: 72" << endl;
	cout << "Average GPA: 3.362" << endl;
	cout << "Taught 2009-2010" << endl;
	cout << "Taught subjects: WRIT" << endl;
}

void professor_test_2() {
	string class1 = "JAMIESON A E,Winter,2019,0,0,0,0,0,0,431,0.0,406,ES,0,0,0,0,0,0,0,0,0,0,0,";

	prof_info jamie = prof_info();
	jamie.addData(class1);

	cout << "--OUTPUT: " << endl;
	jamie.print();

	cout << "--EXPECTED: " << endl;
	cout << "Students Taught: 431" << endl;
	cout << "Average GPA: 3.767" << endl;
	cout << "Taught 2019-2019" << endl;
	cout << "Taught subjects: ES" << endl;
}

void professor_test_3() {
	string class1 = "PROF A,Winter,2010,9,9,1,0,1,46,0,3.217391304347826,0,WRIT,0,0,0,6,2,0,10,8,0,0,0,";
	string class2 = "PROF A,Winter,2019,0,0,0,0,0,0,431,0.0,406,ES,0,0,0,0,0,0,0,0,0,0,0,";

	prof_info prof = prof_info();
	prof.addData(class1);
	prof.addData(class2);

	cout << "--OUTPUT: " << endl;
	prof.print();

	cout << "--EXPECTED: " << endl;
	cout << "Students Taught: 477" << endl;
	cout << "Average GPA: 3.714" << endl;
	cout << "Taught 2010-2019" << endl;
	cout << "Taught subjects: ES, WRIT" << endl;
}