#pragma once
#ifndef check_folhdeccich
#define check_folhdeccich
#include "Lhdeccic.h"
class Folhdeccic: public Lhdeccic {
private:
	void folh_f_contruct();
public:
	Folhdeccic();
	Folhdeccic(double b, double t0, double K0);
	virtual std::string folh_lh_v_solutionLabel_textRep() const override;//dd a virtual member function to the first-order derived class 
	virtual void folh_f_write_textRep(std::ofstream& ofs) override;
	virtual std::string folh_initialCondition_textRep()const override;//This function returns a text representation for the initial condition.
	virtual void folh_f_fillSignals();//add a virtual member function that fills the solution signal 
	virtual void lh_f_mutate_b(double b);//add virtual mutator functions for b , t0 and K0 . 
	virtual void lh_f_mutate_t0(double t0);//add virtual mutator functions for b , t0 and K0 . 
	virtual void lh_f_mutate_K0(double K0);//add virtual mutator functions for b , t0 and K0 . 
};
#endif
