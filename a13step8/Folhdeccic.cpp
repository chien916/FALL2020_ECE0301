#pragma once
#ifndef check_folhdecciccpp
#define check_folhdecciccpp
#include "Folhdeccic.h"
Folhdeccic::Folhdeccic() :Lhdeccic() {
	folh_f_contruct();//add one statement to both constructors that calls the member function
}
Folhdeccic::Folhdeccic(double b, double t0, double K0) : Lhdeccic(b,t0,K0) {
	folh_f_contruct();//add one statement to both constructors that calls the member function
}
void Folhdeccic::folh_f_contruct() {
	folh_f_fillSignals();
}
std::string Folhdeccic::folh_lh_v_solutionLabel_textRep()const{//dd a virtual member function to the first-order derived class 
	std::string solLabel_t = lh_f_access_solutionLabel();
	std::string b_t= textNum(lh_f_access_b());
	std::string toReturn_t = solLabel_t +"'(t) + "+b_t+" "+ solLabel_t +"(t) = 0";
	return (toReturn_t);
}
void Folhdeccic::folh_f_write_textRep(std::ofstream& ofs) {
	ofs << "---------------------------------\n"
		<< "First-Order Differential Equation\n"
		<< "---------------------------------\n"
		<< folh_lh_v_solutionLabel_textRep() << std::endl << std::endl;
	ofs <<"Initial Condition\n"
		<<"-----------------\n"
		<< folh_initialCondition_textRep() << std::endl << std::endl;
}
std::string Folhdeccic::folh_initialCondition_textRep()const {//This function returns a text representation for the initial condition.
	double t0_t = lh_f_access_t0();
	double K0_t = lh_f_access_K0();
	std::string solutionLabel_t = lh_f_access_solutionLabel();
	std::string eqn_t=(solutionLabel_t + "(" + textNum (t0_t)+ ") = " + textNum(K0_t));
	return eqn_t;
	
}
void Folhdeccic::folh_f_fillSignals() {
	Signal* pointerTemp= lh_f_access_p_solution();
	double taoTemp = pow(lh_f_access_b(), -1);//you will find that tau = 1/b

	(*pointerTemp).f_fill_sgn_exponential(lh_f_access_K0(), taoTemp);//Use the solution pointer to call the member function from the signal class that fills a
}
void Folhdeccic::lh_f_mutate_b(double b) {
	Lhdeccic::lh_f_mutate_b(b);
	folh_f_fillSignals();//hen call the member function from the first - order class to fill the solution signal with values
}
void Folhdeccic::lh_f_mutate_t0(double t0) {
	Lhdeccic::lh_f_mutate_t0(t0);
	folh_f_fillSignals();//hen call the member function from the first - order class to fill the solution signal with values
}
void Folhdeccic::lh_f_mutate_K0(double K0) {
	Lhdeccic::lh_f_mutate_K0(K0);
	folh_f_fillSignals();//hen call the member function from the first - order class to fill the solution signal with values
}
#endif