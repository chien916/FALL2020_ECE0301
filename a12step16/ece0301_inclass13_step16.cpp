#include "Signal.cpp"
#include "Lhdeccic.cpp"
#include "Folhdeccic.cpp"
#include "Solhdeccic.cpp"

int main() {
	//Modify your main function so that, after opening the output file, an object from the firstorder derived class is defined that corresponds to the initial value problem
	std::ofstream ofs;//define ofstream object
	ofs.open("ECE 0301 - Differential Equation Reports.txt");
	////TEST/////
	Solhdeccic test1(4, 4, 0, -50, 500);//Define an object from the second-order differential equations 
	(*test1.lh_f_access_p_solution()).f_round();
	test1.lh_f_mutate_solutionLabel("s");//Use the differential equation object to set the label to 
	test1.folh_f_write_textRep(ofs);//write the differential equation and initial conditions to the text file, and
	test1.folh_f_write_solution_textRep(ofs); //write information about the solution to the differential equation to a text file.
	(*test1.lh_f_access_p_solution()).f_write_txt();//write to text
	/////////////
	return 1;//return sucessful code
}
