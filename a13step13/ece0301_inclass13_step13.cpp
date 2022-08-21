#include "Signal.cpp"
#include "Lhdeccic.cpp"
#include "Folhdeccic.cpp"
#include "Solhdeccic.cpp"
int main() {
	//Modify your main function so that, after opening the output file, an object from the firstorder derived class is defined that corresponds to the initial value problem
	std::ofstream ofs;//define ofstream object
	ofs.open("ECE 0301 - Differential Equation Reports.txt");
	Solhdeccic test(3,2,0,0,250);//only one second-order differential equation is defined
	(*test.lh_f_access_p_solution()).f_mutate("lbl", "y");//set the label to y
	(*test.lh_f_access_p_solution()).f_round();//ounds the signal values to the nearest integers.
	test.folh_f_write_textRep(ofs);//write the differential equation and initial conditions to the text file, and
	test.folh_f_write_solution_textRep(ofs); //write information about the solution to the differential equation to a text file.
	(*test.lh_f_access_p_solution()).f_write_txt();//write to text
	return 1;//return sucessful code
}
