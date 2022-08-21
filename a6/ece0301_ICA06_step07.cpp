#include<iostream>//port in header file from standard library
#include<fstream>//port in header file from standard library
#include<iomanip>//port in header file from standard library
#include <string>//port in header file from standard library
#include "array_dim.h"//port in custom pre-processor
using namespace std;//give permission for using "<<"" and "">>"cin,cout 

//CUSTOM FUNCTIONS:
///this function is solely for testing. I'll delete getchar() upon finishing
void cexit() {//define new function
	getchar();
	exit(1);
}
int readPara(ifstream& ifs,double aryA[][DIM],double aryb[]) {//define function
	string check;//define new string
	string output;//define new string
	getline(ifs, check);//get 1st line
	if (check != "ECE 0301: Ax = b Problem") {//check matching
		cout << "ERROR! Input file format error.";//display
		cexit();//exit
	}
	getline(ifs, check);
	output = check;//copy
	check.erase(4, 1);//erase unnecessary chars
	if (check != "N = ") {//check matching
		cout << "ERROR! Input file format error.";
		cexit();
	}
	output.erase(0, 4);
	if (stoi(output) != DIM) {//check match
		cout << "ERROR! Dimension mismatch, N != DIM.";
		cexit();
	}
	getline(ifs, check);
	if (check != "A = ") {//check match
		cout << "ERROR! Input file format error.";
		cexit();
	}
	for (int i = 0; i < DIM; i++) {//iteration for displaying array A-row
		for (int j = 0; j < DIM; j++) {//iteration for displaying array-col
			getline(ifs, check);
			aryA[i][j] = stod(check);
		}
	}
	getline(ifs, check);
	if (check != "b = ") {//check match
		cout << "ERROR! Input file format error.";
		cexit();
	}
	for (int i = 0; i < DIM; i++) {//iteration for retriving array b
		getline(ifs, check);
		aryb[i] = stod(check);
	}
	return stoi(output);//convert str to int
}
void outputPara(ofstream& ofs,double aryA[][DIM],double aryb[]) {
	ofs << "ECE 0301 - Matrix-Vector Computations,\nDeterminants and Cramer's Rule.\n\n";//put out ofstream text
	ofs << "Global array dimension: DIM = " << DIM << endl;
	ofs << "Input file: N = " << DIM << endl;
	ofs << "\nA =\n";
	for (int i = 0; i < DIM; i++) {//iteration for displaying array
		ofs << "[ ";
		for(int j = 0; j < DIM; j++) {
		ofs << setw(10) << aryA[i][j];
		}
		ofs << " ]\n";
	}
	ofs << "\nb =\n";
	for (int i = 0; i < DIM; i++) {//iteration for displaying array
		ofs << "[ ";
		ofs << setw(10) << aryb[i];
		ofs << " ]\n";
	}
}
//MAIN FUNCTION:
int main() {//declare main method
	ofstream ofs;//new ofstream object
	ofs.open("ECE0301_ICA06_Axeqb_solution.txt");//open ofstream object
	ifstream ifs;//new ofstream object
	ifs.open("ECE0301_ICA06_Axeqb_problem.txt");//open ifstream object
	double aryA[DIM][DIM];//define array of A
	double aryb[DIM];//define array of b
	int valN = readPara(ifs, aryA, aryb);//initiate function
	outputPara(ofs, aryA, aryb);//initiate function


	return 0;//return 0 if main runs correctly
}