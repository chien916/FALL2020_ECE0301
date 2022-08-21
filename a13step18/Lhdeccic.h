#pragma once
#ifndef check_lhdeccich
#define check_lhdeccich
#include <iostream>
#include <fstream>
#include <complex>
#include <memory>
#include <string>
#include <vector>
#include "signal.h"
class Lhdeccic {
private:
	double lh_v_b;
	double lh_v_t0;
	double lh_v_K0;
	std::string lh_v_solutionLabel;
	Signal* lh_p_solution;
	void lh_f_construct(double b, double t0, double K0);
public:
	virtual void lh_f_mutate_b(double b);//make the mutator functions for b , t0 and K0 virtual. 
	virtual void lh_f_mutate_t0(double t0);//make the mutator functions for b , t0 and K0 virtual. 
	virtual void lh_f_mutate_K0(double K0);//make the mutator functions for b , t0 and K0 virtual. 
	void lh_f_mutate_solutionLabel(std::string slb);//Write a mutator function and a const accessor function for the new member variable 
	double lh_f_access_b()const ;
	double lh_f_access_t0()const ;
	double lh_f_access_K0()const ;
	std::string lh_f_access_solutionLabel() const;
	Lhdeccic();//Write a default constructor that accepts no parameters, 
	Lhdeccic(double b, double t0, double K0);//Write a second constructor that accepts three parameters
	std::string textNum(double x) const;//Copy the member function textNum from the signal class,
	virtual std::string folh_lh_v_solutionLabel_textRep() const=0;//Make both of these pure virtual functions by using ¡° = 0¡±
	virtual void folh_f_write_textRep(std::ofstream& ofs)=0;//Make both of these pure virtual functions by using ¡° = 0¡±
	virtual std::string folh_initialCondition_textRep()const=0;// declare a virtual member function that has the same name and function
	Signal* lh_f_access_p_solution();// This function returns the member variable that is a pointer to thesolution signal.
	virtual void folh_f_fillSignals() = 0;// and declare a virtual member function that has the same name
	std::string lh_f_solution_textRep() const;//add a member function that takes no arguments, and returns an object from
	void folh_f_write_solution_textRep(std::ofstream& ofs) const;//add a virtual member function that writes information about th
	
};

#endif