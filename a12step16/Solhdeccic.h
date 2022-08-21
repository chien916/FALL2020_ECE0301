#pragma once
#ifndef check_solhdeccich
#define check_solhdeccich
#include "Lhdeccic.h"
class Solhdeccic :public Lhdeccic {
private:
	double solh_v_a;//must also have two private member variables of type double to store the coefficient a
	double solh_v_K1;//must also have two private member variables of type double to store and the initial value K1
	void solh_f_construct(double a,double k1, std::string label);//second part of the constructor
public:
	void solh_f_mutate_a(double inp);//Write mutator functions and const accessor functions for the member variables a
	void solh_f_mutate_K1(double inp);//Write mutator functions and const accessor func1tions for the member variables k1
	Solhdeccic();// The default constructor
	Solhdeccic(double a, double b, double t0, double K0, double K1);//The alternative contructor
	virtual std::string folh_lh_v_solutionLabel_textRep() const override;//// must have the same name as the function in the first - order class that performs the same task.
	virtual std::string folh_initialCondition_textRep()const override;//This function returns a text representation for the initial condition.
	virtual void folh_f_write_textRep(std::ofstream& ofs) override;//is function will fill the solution signal with values, but for this step the body of this
	virtual void folh_f_fillSignals();//add a virtual member function that fills the solution signal 
};
#endif