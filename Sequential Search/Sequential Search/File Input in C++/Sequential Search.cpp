// File Input in C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include "Employee.h"

using namespace std;
// Employee array for its objects 
Employee** list;

// to do: create the lookup method and include the arraylist as the parameter to measure n.
int lookUp(int x, int arrayLength)
{
	for (int i = 0; i < arrayLength;i++) {
		if (x == list[i]->id) {
			return i;
		}
	}
	return -1;
}




int main(int argc, char** argv)
{
	// Global Vars 
	//Employee** idList;

	// int n is the arrayLength
	int n;



	if (argc != 3) {
		cout << "Are you forgetting the command-line parameter?" << endl;
		exit(0);
	}
	ifstream ifs;
	ifs.open(argv[1], ios::in);

	if (!ifs) {
		cout << "Error! Please check filename." << endl;
	}
	else {
		string topNumber;
		getline(ifs, topNumber);
		n = stoi(topNumber);
		list = new Employee * [n];
		//idList = new Employee * [n];

		for (int i = 0; i < n; i++) {

			// these variables are just named the same as the global variables under the Employee class
			// these variable will is a temporary var to convert to int using stoi
			string temporaryVariable;
			string name;
			int idNumber;
			int age;
			string job;
			int hireYear;
			getline(ifs, name, '|');
			getline(ifs, temporaryVariable, '|');
			idNumber = stoi(temporaryVariable);
			getline(ifs, temporaryVariable, '|');
			age = stoi(temporaryVariable);
			getline(ifs, job, '|');
			getline(ifs, temporaryVariable);
			hireYear=stoi(temporaryVariable);
			
			list[i] = new Employee(name, idNumber, age,job,hireYear);
			//idList[i] = new Employee(idNumber);

		}
		ifs.close();


		/*for (int i = 0; i < n; i++) {
			//list[i]->printEmployee();
			idList[i]->printEmployeeID();
		}*/
	}

	// This is the code block for query file

	ifs.open(argv[2], ios::in);
	if (!ifs) {
		cout << "Error! Please check filename for the query file." << endl;
		exit(0);
	}
	else {
		double total=0;
		string tempVar;
		getline(ifs, tempVar);
		int numberOfQueries = stoi(tempVar);
	

		for (int j = 0; j < numberOfQueries;j++) {
			
			getline(ifs,tempVar);
			
			// the currentID is the current line the program is reading
			int currentID = stoi(tempVar);
			int index = lookUp(currentID, n);
			int numberOfComaparisons = index+ 1;
			total += numberOfComaparisons;

			cout << "Looking for " << currentID <<"..." << "Found "<< list[index]->getName()<<"at position "<< index <<" after "<<numberOfComaparisons<< " of comparisons." <<endl;
			
		}
		double averageQueries = total / numberOfQueries;
		cout<<"Average number of comparisons overall : " << averageQueries<<endl;

	}
	}
	

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
