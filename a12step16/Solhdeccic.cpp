#pragma once
#ifndef check_solhdecciccpp
#define check_solhdecciccpp
#include "Solhdeccic.h"
void Solhdeccic::solh_f_mutate_a(double inp) {//Write mutator functions and const accessor functions for the member variables a
	solh_v_a = inp;
}
void Solhdeccic::solh_f_mutate_K1(double inp) {////Write mutator functions and const accessor functions for the member variables k1
	solh_v_K1 = inp;
}
void Solhdeccic::solh_f_construct(double a, double k1,std::string label){
	(*lh_f_access_p_solution()).f_mutate("lbl", label);//set the signal label to “y”, by calling the mutator functions for these member variables.
	solh_v_a = a;	// then set the values for a and K1,
	solh_v_K1 = k1;// then set the values for a and K1,
	folh_f_fillSignals();// call to the member function that fills the solution signal with values.
}
Solhdeccic::Solhdeccic():Lhdeccic() {//The default constructor must call the default constructor for the base class,
	lh_f_mutate_b(2);//and then set the parameters to
	lh_f_mutate_t0(0);//and then set the parameters to
	lh_f_mutate_K0(0);//and then set the parameters to
	solh_f_construct(3, 1,"y");//set the signal label to “y”
}
Solhdeccic::Solhdeccic (double a, double b, double t0, double K0, double K1):Lhdeccic() {
	lh_f_mutate_b(b);//and then set the parameters to
	lh_f_mutate_t0(t0);//and then set the parameters to
	lh_f_mutate_K0(K0);//and then set the parameters to
	solh_f_construct(a, K1, "y");//set the signal label to “y”
}
std::string Solhdeccic::folh_lh_v_solutionLabel_textRep() const {// must have the same name as the function in the first - order class that performs the same task.
	std::string solLabel_t = lh_f_access_solutionLabel();
	std::string b_t = textNum(abs(lh_f_access_b()));
	std::string a_t = textNum(abs(solh_v_a));
	std::string sign1_t = "+";
	std::string sign2_t = "+";
	if (lh_f_access_b() < 0) {
		sign2_t = "-";
	}
	if (solh_v_a<0) {
		sign1_t = "-";
	}
	std::string toReturn_t = solLabel_t + "''(t) "+ sign1_t +" " + a_t + " " + solLabel_t + "'(t) "+ sign2_t +" " + b_t + " " + solLabel_t + "(t) = 0";
	return (toReturn_t);
}
std::string Solhdeccic::folh_initialCondition_textRep()const {// This function returns a text representation for the initial conditions,
	double t0_t = lh_f_access_t0();
	double K0_t = lh_f_access_K0();
	std::string solutionLabel_t = lh_f_access_solutionLabel();
	std::string eqn1_t = (solutionLabel_t + "(" + textNum(t0_t) + ") = " + textNum(K0_t));
	double K1_t = solh_v_K1;
	std::string eqn2_t = (solutionLabel_t + "'(" + textNum(t0_t) + ") = " + textNum(K1_t));
	return (eqn1_t+", "+eqn2_t);
 }
void Solhdeccic::folh_f_write_textRep(std::ofstream& ofs) {
	ofs << "----------------------------------\n"
		<< "Second-Order Differential Equation\n"
		<< "----------------------------------\n"
		<< folh_lh_v_solutionLabel_textRep() << std::endl << std::endl;
	ofs << "Initial Condition\n"
		<< "-----------------\n"
		<< folh_initialCondition_textRep() << std::endl << std::endl;
}
void  Solhdeccic::folh_f_fillSignals() {
	double a_qs_t = 1;
	double b_qs_t = solh_v_a;
	double c_qs_t = lh_f_access_b();
	double k_cef_K0 = lh_f_access_K0();
	double k_cef_K1 = solh_v_K1;
	double b24ac_t = pow(b_qs_t, 2) - 4 * a_qs_t*c_qs_t;//b^2-4*a*c-Charistic euqation
	if (b24ac_t > 0) {//If a b 2 > 4 , your function must implement the tasks from step 12
		double root1 = (-b_qs_t + sqrt(b24ac_t)) / (2 * a_qs_t);//Use the quadratic formula to compute the rates for the two exponential terms
		double root2 = (-b_qs_t - sqrt(b24ac_t)) / (2 * a_qs_t);//Use the quadratic formula to compute the rates for the two exponential terms
		double cef1 = (k_cef_K0*root2 - k_cef_K1) / (root2 - root1);//Compute the coefficients
		double cef2 = -(k_cef_K0*root2 - k_cef_K1) / (root2 - root1);//Compute the coefficients
		Signal* pointerTemp = lh_f_access_p_solution();
		delete pointerTemp;//delete old Signal
		pointerTemp = new Signal(501, 100, lh_f_access_t0());//actual signal with reference value
		Signal* pointerTemp2 = new Signal(501, 100, lh_f_access_t0());//Define a new object from the signal class
		(*pointerTemp).f_fill_sgn_exponential(cef1, -1/(root1));//Use the solution pointer to call the member function from the signal
		(*pointerTemp2).f_fill_sgn_exponential(cef2, -1/(root2));
		(*pointerTemp).operator+(*pointerTemp2);//Use the overloaded + and = operators to add the two signals
		delete pointerTemp2;//release memory
	}
	else if (b24ac_t == 0) {//If a b 2 = 4 , your function must fill the solution signal as described by equation (10)
		double lamda = -a_qs_t*0.5;//Compute  
		double taoTemp = std::pow(std::abs(lamda), -1);//where t =1/
		double sampleRateTemp = 100 * taoTemp;//Set the sample rate for the solution signal so that that there are 100 samples p!!!!!WARNING!!!!!
		//std::cout << "\namda:" << lamda << " tao:" << taoTemp;
		double cef1 = k_cef_K0;//Compute
		double cef2 = k_cef_K1 + (k_cef_K0*b_qs_t)/2;// and 2 1	o2K ac K = +.
		//std::cout << "\n" << k_cef_K1 << " " << k_cef_K0 << " " << a_qs_t;
		Signal* pointerTemp = lh_f_access_p_solution();
		delete pointerTemp;//delete old Signal
		std::cout << "\nTEST for: [" << std::abs(lamda) << "] \n";
		pointerTemp = new Signal(501, sampleRateTemp, lh_f_access_t0());//actual signal with reference value
		(*pointerTemp).f_fill_sgn_timeVaring(cef2, cef1);//Create a signal c t t c 2 0 1 ( − + ) 
		Signal* pointerTemp2 = new Signal(501, sampleRateTemp, lh_f_access_t0());//Create a second signal
		(*pointerTemp2).f_fill_sgn_exponential(1, -lamda);//Create a second 
		(*pointerTemp).operator*(*pointerTemp2);//Set the solution signal equal to the product of the two signals just created
		delete pointerTemp2;//release memory
	}
}
#endif