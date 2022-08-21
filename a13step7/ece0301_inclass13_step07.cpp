#include "Signal.cpp"
#include "Lhdeccic.cpp"
#include "Folhdeccic.cpp"
int main() {
	std::ofstream ofs;
	ofs.open("ECE 0301 - Differential Equation Reports.txt");
	Folhdeccic test;
	test.folh_f_write_textRep(ofs);
	test.folh_f_write_solution_textRep(ofs);
	Folhdeccic test2(10,-2.5,1);
	test2.lh_f_mutate_solutionLabel("x");
	test2.folh_f_write_textRep(ofs);
	test2.folh_f_write_solution_textRep(ofs);
	return 1;
}