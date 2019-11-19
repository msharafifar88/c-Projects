/*
 ============================================================================
 Name        : String.cpp
 Author      : Mohammad Sharafifar
 Email       : mSharafifar@myseneca.ca
 Student #   : 147
 Course Code : OOP345
 Section     : SBB
 Date        : may 17, 2019 -
 Workshop    : Workshop 1 - Lab
 ============================================================================
 */

 /*
  ============================================================================
  Description : Describe what the file does
  ============================================================================
 */


#include<iostream>
#include"process.h"
using namespace std;
using namespace sict;

int INITIAL = 3;

int main(int argc, char *argv[]) {

	if (argc <= 2) {

		cout << "***Insufficient number of arguments***" << std::endl;

		return 1;
	}
	else {
		cout << "Command Line : ";
		for (int index = 0; index < argc; index++) {
			cout << argv[index] << " ";

		}
		cout << endl;
	}
	for (int index = 1; index < argc; index++) {
		process(argv[index]);
	}

	return 0;
}
