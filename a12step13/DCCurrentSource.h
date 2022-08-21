//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	DCCurrentSource.h	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//
#ifndef check_c_9
#define check_c_9
#include <string>
#include <fstream>
#include <iostream>
#include <complex>
#include <cstdint>
#include <vector>
#include "Component.h"
class DCCurrentSource :public Component {//This class must be a derived class of Component
private:
	double DCCurrentSource_v_sourceCurrent;//The only private member variable of the class is of type double
	double DCCurrentSource_v_voltage;//Add a member variable of type double to store the current drawn from the source.
public:
	DCCurrentSource();//The constructor must initialize the source voltage to zero.
	DCCurrentSource(double i);
	DCCurrentSource(double i, double v);
	void DCCurrentSource_f_set(std::string identifier, double inputDouble);//There must be a mutator function to set the source voltage,
	double DCCurrentSource_f_get_double(std::string identifier) const;//and a const accessor function to return the source voltage.
	void DCCurrentSource_f_report(std::ofstream& ofs);//There must be a member function to write information about a DC voltage source
};

#endif