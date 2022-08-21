#include "Signal.cpp"
#include "Lhdeccic.cpp"
#include "Folhdeccic.cpp"
int main() {
	//Modify your main function so that, after opening the output file, an object from the firstorder derived class is defined that corresponds to the initial value problem
	std::ofstream ofs;
	ofs.open("ECE 0301 - Differential Equation Reports.txt");
	Folhdeccic test_step8(2,-1.25,120);
	test_step8.lh_f_mutate_solutionLabel("x");
	test_step8.folh_f_write_textRep(ofs);
	test_step8.folh_f_write_solution_textRep(ofs);
	return 1;
}