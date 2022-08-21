#include "Signal.cpp"
#include "Lhdeccic.cpp"
#include "Folhdeccic.cpp"
#include "Solhdeccic.cpp"

int main() {
	//Modify your main function so that, after opening the output file, an object from the firstorder derived class is defined that corresponds to the initial value problem
	std::ofstream ofs;//define ofstream object
	ofs.open("ECE 0301 - Differential Equation Reports.txt");//Define an ofstream object, and use it to open a text file named
	////TEST/////
	Solhdeccic testg(2, 101, -5, 100, -100);//Define an object from the second-order differential equations class
	(*testg.lh_f_access_p_solution()).f_round();
	testg.lh_f_mutate_solutionLabel("g");//Use the differential equation object to set the label to ¡°g¡±
	testg.folh_f_write_textRep(ofs);//Call the member function that writes the differential equation and initial conditions to
	testg.folh_f_write_solution_textRep(ofs);//Call the member function that writes information about the solution to the differential								
	/////////////
	return 1;//return sucessful code
}
