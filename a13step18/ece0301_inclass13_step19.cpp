#include "Signal.cpp"
#include "Lhdeccic.cpp"
#include "Folhdeccic.cpp"
#include "Solhdeccic.cpp"

void ode(double a,double b,double c,double d,double e,std::string l){
	std::ofstream ofs;//define ofstream object
	ofs.open("ECE 0301 - Differential Equation Reports.txt");//Define an ofstream object, and use it to open a text file named
	Solhdeccic testg(a, b, c, d, e);//Define an object from the second-order differential equations class
	(*testg.lh_f_access_p_solution()).f_round();
	testg.lh_f_mutate_solutionLabel(l);//Use the differential equation object to set the label to ¡°g¡±
	testg.folh_f_write_textRep(ofs);//Call the member function that writes the differential equation and initial conditions to
	testg.folh_f_write_solution_textRep(ofs);//Call the member function that writes information about the solution to the differential	
}
void ode(double a,double b,double c,std::string l){
	std::ofstream ofs;//define ofstream object
	ofs.open("ECE 0301 - Differential Equation Reports.txt");//Define an ofstream object, and use it to open a text file named
	Folhdeccic testg(a, b, c);//Define an object from the second-order differential equations class
	(*testg.lh_f_access_p_solution()).f_round();
	testg.lh_f_mutate_solutionLabel(l);//Use the differential equation object to set the label to ¡°g¡±
	testg.folh_f_write_textRep(ofs);//Call the member function that writes the differential equation and initial conditions to
	testg.folh_f_write_solution_textRep(ofs);//Call the member function that writes information about the solution to the differential	
}
int main() {
	////TEST/////
	ode(2,-1.25,120,"x");
	ode(3,2,0,0,250,"y");
	ode(4,4,0,-50,500,"s");
	ode(2,101,-5,100,-100,"g");
	/////////////
	return 1;//return sucessful code
}
