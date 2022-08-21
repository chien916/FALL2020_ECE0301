#pragma once
#ifndef check_lhdecciccpp
#define check_lhdecciccpp
#include "Lhdeccic.h"
void Lhdeccic::lh_f_mutate_b(double b) {
	lh_v_b = b;
}
void Lhdeccic::lh_f_mutate_t0(double t0) {
	lh_v_t0 = t0;
}
void Lhdeccic::lh_f_mutate_K0(double K0) {
	lh_v_K0 = K0;
}
double Lhdeccic::lh_f_access_b() const {
	return lh_v_b;
}
double Lhdeccic::lh_f_access_t0() const {
	return lh_v_t0;
}
double Lhdeccic::lh_f_access_K0() const {
	return lh_v_K0;
}
Lhdeccic::Lhdeccic() {//Write a default constructor that accepts no parameters, 
	lh_f_mutate_b(1);//and sets t0 = 0 and b K = = 0 1
	lh_f_mutate_t0(0);//and sets t0 = 0 and b K = = 0 1
	lh_f_mutate_K0(1);//and sets t0 = 0 and b K = = 0 1
	lh_f_construct(lh_f_access_b(), lh_f_access_t0(), lh_f_access_K0());
}
Lhdeccic::Lhdeccic(double b, double t0, double K0) {
	lh_f_mutate_b(b);// and sets the member variables to the values
	lh_f_mutate_t0(t0);// and sets the member variables to the values
	lh_f_mutate_K0(K0);// and sets the member variables to the values
	lh_f_construct(lh_f_access_b(), lh_f_access_t0(), lh_f_access_K0());
}
void Lhdeccic::lh_f_construct(double b, double t0, double K0) {
	double taoTemp = 1/lh_v_b;//you will find that tau = 1/b
	double freqTemp = 100 / taoTemp;//Define a pointer to an object from the signal class, 
	lh_p_solution = new Signal(501, freqTemp,  lh_f_access_t0());//Use the solution pointer to set the number of samples, sampling rate, and initial time
	lh_f_mutate_solutionLabel("y");//Modify both constructors for the base class, so that the signal label is set to ¡°y¡±
	std::string eqn_t;
	(*lh_p_solution).f_eqn_update();
}
std::string Lhdeccic::lh_f_access_solutionLabel() const {
	return lh_v_solutionLabel;
}
void Lhdeccic::lh_f_mutate_solutionLabel(std::string slb) {//Write a mutator function and a const accessor function for the new member variable 
	lh_v_solutionLabel = slb;
	(*lh_p_solution).f_mutate("lbl", lh_v_solutionLabel);//uses the solution signal to set its label member variable to the label 
}
std::string Lhdeccic::textNum(double x) const {
	if (x >= 100)
		// large numbers truncated as int -> string
		return std::to_string(int(x));
	else
	{
		// small numbers will get 3 digits
		std::string x_exp = std::to_string(x);
		// return 4 characters, or 5 if x<0
		return x_exp.substr(0, 4 + (x<0));
	}
}
Signal* Lhdeccic::lh_f_access_p_solution() {// This function returns the member variable that is a pointer to the solution signal.
	return lh_p_solution;
}
std::string Lhdeccic::lh_f_solution_textRep() const {//add a member function that takes no arguments, and returns an object from
	std::string solnLabel_t = lh_f_access_solutionLabel();//the member variable from the base class that stores the solution signal label
	std::string eqn_t;
	(*lh_p_solution).f_access("eqn", eqn_t);//he member variable from the signal class that stores the mathematical expression f
	return (solnLabel_t + "(t) = " + eqn_t);//the string constant 
}
void Lhdeccic::folh_f_write_solution_textRep(std::ofstream& ofs) const {//add a virtual member function that writes information about th
	ofs << "Solution\n"
		<< "--------\n"
		<< lh_f_solution_textRep() << std::endl << std::endl;
	(*lh_p_solution).f_write_txt();//uses the solution signal to call the member function
	//(*lh_p_solution).f_plot();// call the member function from the signal class that draws a plot of
}
#endif