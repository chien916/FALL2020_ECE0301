//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	Resistor.cpp		%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//
#ifndef check_c_12
#define check_c_12
#include <string>
#include <fstream>
#include <iostream>
#include <complex>
#include <cstdint>
#include "Component.h"
class Resistor :public Component {//This class must be a derived class, with the component class as the base class.
private:
	double Resistor_v_resistance;//The only private member variable of the class is of type double, to store the resistance.
public:
	Resistor();//constructor
	Resistor(double r);//constructor with pre-assigned R value
	void Resistor_f_set(std::string identifier,double d);//There must be a mutator function to set the resistance
	double Resistor_f_get_double(std::string identifier) const;// and a const accessor
	void Resistor_f_report(std::ofstream& ofs);//There must be a member function to write information about a resistor to a text file.
};

#endif