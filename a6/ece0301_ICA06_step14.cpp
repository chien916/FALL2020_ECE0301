#include<iostream>//port in header file from standard library
#include<fstream>//port in header file from standard library
#include<iomanip>//port in header file from standard library
#include <string>//port in header file from standard library
#include <math.h>//port in header file from standard library
#include "array_dim.h"//port in custom pre-processor
using namespace std;//give permission for using "<<"" and "">>"cin,cout 

//CUSTOM FUNCTIONS:
///↓this function is solely for testing. I'll delete getchar() upon finishing
void cexit() {//define new function
	//dummy function for testing only
	//empty after testing
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
		cout << "ERROR! Input file format error4.";
		cexit();
	}
	for (int i = 0; i < DIM; i++) {//iteration for retriving array b
		getline(ifs, check);
		aryb[i] = stod(check);
	}
	return stoi(output);//convert str to int
}
void multip(double aryA[][DIM], double aryx[], double aryb[]) {//define new func
	for (int i = 0; i < DIM; i++) {//iteration for one col
		double tempSumOfProduct = 0;//temp var for dummy uses
		for (int j = 0; j < DIM; j++) {//iteration for one row
			tempSumOfProduct += aryA[i][j] * aryx[j];//initiate the calculation
		}
		aryb[i] = tempSumOfProduct;//give sumOfProduct to b(the result)
	}
}
bool ifSign(int i) {//function: determine if this is the place to put a operation sign when on the middle
	int middleIndex = (DIM - 1) / 2;
	return (middleIndex == i);
}
void outputPara(ofstream& ofs,double aryA[][DIM],double aryb[],double aryx[]) {
	ofs << "ECE 0301 - Matrix-Vector Computations,\nDeterminants and Cramer's Rule.\n\n"; //Write the introductory message to the output file.
	ofs << "Global array dimension: DIM = " << DIM << endl;//Write the global array dimension to the output file.
	ofs << "Input file: N = " << DIM << endl;//Write the value of N to the output file.
	//Write the matrix A to the output file:
	ofs << "\nA =\n";
	for (int i = 0; i < DIM; i++) {//iteration for displaying array
		ofs << "[ ";
		for(int j = 0; j < DIM; j++) {
		ofs << setw(10) << aryA[i][j];
		}
		ofs << " ]\n";
	}
	//Write the column vector b to the output file.
	ofs << "\nb =\n";
	for (int i = 0; i < DIM; i++) {//iteration for displaying array
		ofs << "[ ";
		ofs << setw(10) << aryb[i];
		ofs << " ]\n";
	}
	//Write the Ax = b problem (with solution vector unspecified) to the output file:
	ofs << "\nProblem: A * x = b\n";
	for (int i = 0; i < DIM; i++) {//iteration for displaying array
		ofs << "[ ";
		for (int j = 0; j < DIM; j++) {
			ofs << setw(10) << aryA[i][j];
		}
		if (ifSign(i))//set conditions with middle point of array
			ofs << " ] * [ ";
		else
			ofs << " ]   [ ";
		ofs << "x"<<i;
		if (ifSign(i))//set conditions with middle point of array
			ofs << " ] = [ ";
		else
			ofs << " ]   [ ";
		ofs << setw(10) << aryb[i];
		ofs << " ]\n";
	}
	//Write the solution vector x to the output file:
	ofs << endl<<"Solution: x =";
	for (int i = 0; i < DIM; i++) {//iteration for displaying array
		ofs << "\n[ ";
		ofs << setw(10) << aryx[i];
		ofs << " ]";
	}
	ofs << endl;
	double aryb2[DIM] = { 0 };//Define an array to store the A*x
	multip(aryA, aryx, aryb2);//Compute Ax.				  
	//Write the Ax = b problem solution to the output file, with the solution vector in place of x, and the product Ax in place of b.
	ofs << "\nChecking Solution: A * x = b\n";
	for (int i = 0; i < DIM; i++) {//iteration for displaying array
		ofs << "[ ";
		for (int j = 0; j < DIM; j++) {
			ofs << setw(10) << aryA[i][j];
		}
		if (ifSign(i))//set conditions with middle point of array
			ofs << " ] * [ ";
		else
			ofs << " ]   [ ";
		ofs << setw(10) << aryx[i];
		if (ifSign(i))//set conditions with middle point of array
			ofs << " ] = [ ";
		else
			ofs << " ]   [ ";
		ofs << setw(10) << aryb[i];
		ofs << " ]\n";
	}

	//Compute and report the error vector Ax – b:
	double aryERR[DIM] = { 0 };//Define an array to store the RHS
	for (int j = 0; j < DIM; j++) {//Compute Error
		aryERR[j] = aryb[j] - aryb2[j];
	}
	ofs << "\nError in RHS values:\n";
	for (int i = 0; i < DIM; i++) {//iteration for displaying array
		ofs << "[";
		ofs << setw(9) << aryERR[i];
		ofs << " ]\n";
	}
}
void outputTill(ofstream& ofs,double aryA[][DIM],int r) {
	for (int i = 0; i < r; i++) {//iteration for one col
		ofs << "[ ";
		for (int j = 0; j < r; j++) {//iteration for one row
			ofs<<setw(10)<< aryA[i][j];
		}
		ofs << " ]\n";
	}
	
}
void customCopy(double aryin[DIM][DIM], double aryout[DIM][DIM],int vali,int valj,int valn) {//Write a function that copies the upper-left portion of one matrix to another, except for a specified row and column.
	int ifSkipped[2] = { 0,0 };//control index
	for (int i = 0; i < (valn); i++) {//row iteration
		for (int j = 0; j < (valn); j++) {//col iteration
			int newi = i;
			int newj = j;
			if (i != vali&&j != valj) {//copy process
				if (i >= vali)//reduce index by 1 if it goes over skipped index
					newi = i - ifSkipped[0];
				if (j >= valj)//reduce index by 1 if it goes over skipped index
					newj = j - ifSkipped[1];
				aryout[newi][newj] = aryin[i][j];//copy value
			}
			else {//except for column i and j
				if (i == vali)//except for column i,
					ifSkipped[0] = 1;//decrease index by 1 to ensure no space is there
				if (j == valj)//except for column j,
					ifSkipped[1] = 1;//decrease index by 1 to ensure no space is there
			}
		}
	}
}
double getDet(double ary[][DIM], int n) {//Write a recursive function that returns the determinant of a square matrix
	switch (n) {
	case 1://n = 1, then the array of interest contains only one element, 
		return ary[0][0];// and the determinant is equal to this element.Return this value and go back to the calling routine.
		break;
	default://Otherwise,
		double det = 0;//initialize the determinant to 0
		double arysub[DIM][DIM];//and define a new 2D array with at least n-1 rows and columns. 
		for (int j = 0; j <= (n - 1); j++) {//Loop over the elements in row 0 of A. For each element,
			customCopy(ary, arysub, 0, j, n);//Call your function from step 11 to copy the first n rows and columns of A, except for row 0 and the column of the current element, to the first n-1 rows and columns of the sub-matrix.
			double detloop = getDet(arysub,n-1); //call the determinant function with the array parameter set to the sub - matrix and the integer parameter set to n-1.
			detloop *= pow(-1, j);//Multiply the value returned by the determinant function by ()1j−, where j is the column index
			det +=(ary[0][j]*detloop);//and add the result to the determinant..
		}
		return det;//Return the value of the determinant.
		break;
	}
}
void customCopy(double aryin[DIM][DIM], double aryin2[DIM], double aryoutbig[DIM][DIM],  int valj) {//Write a function that will copy all but one of the columns of a matrix A to another matrix,
	int valn = DIM;
	for (int i = 0; i < (valn); i++) {//row iteration
		for (int j = 0; j < (valn); j++) {//col iteration
			if (j != valj) {//copy process
				aryoutbig[i][j] = aryin[i][j]; //copy all but one of the columns of a matrix A to another matrix,
			}
			else {//except for column i and j
				aryoutbig[i][j] = aryin2[i];//and copy a specified vector b to the remaining column.
			}
		}
	}
}
//MAIN FUNCTION:
int main() {//declare main method
	ofstream ofs;//Declare an ofstream object, 
	ofs.open("ECE0301_ICA06_Axeqb_solution.txt");//and uses it to open the output file.
	ifstream ifs;//Declare an ifstream object,
	ifs.open("ECE0301_ICA06_Axeqb_problem.txt");//o and uses it to open the input file.
	double aryA[DIM][DIM];//define array of A
	double aryb[DIM];//define array of b
	readPara(ifs, aryA, aryb);//Call your function to read the input file.
	//outputTill(ofs, aryA, DIM);//Call the function from step 10, with n = N, so that all rows and columns of A are written to the output file.
	double det = getDet(aryA, DIM);//Call the function from step 12 to compute the determinant of the A matrix
	//ofs <<"det(A) = "<< det<<endl;//Write the determinant to the output file.
	double aryCRP[DIM][DIM] = { 0 };//Define a new array the same size as A. We will refer to this as the column-replaced matrix.
	double aryx[DIM] = { 0 };//Define an array to store the matrix-vector soln x.
	for (int j=0; j < DIM; j++) {//Loop over the columns of A, beginning with column 0. For each column,
		customCopy(aryA, aryb, aryCRP, j);//Call your new function to copy A to the column-replaced matrix, but copy b to the current column.
		//outputTill(ofs, aryCRP, DIM);//Call the function from step 10, with n = N, so that all rows and columns of the column-replaced matrix are written to the output file.
		//double det = getDet(aryCRP, DIM);//Call the function from step 12 to compute the determinant of the column-replaced matrix.
		aryx[j] = getDet(aryCRP, DIM) / getDet(aryA, DIM);//Compute the corresponding element of the solution vector.
	}
	outputPara(ofs,aryA, aryb, aryx);//Call the file output function to report all information about this Ax = b problem and the solution to the output file.

	cexit();
	return 0;//return 0 if main runs correctly
}