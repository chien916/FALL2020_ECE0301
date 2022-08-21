//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	DCVoltageSource.h	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//
#ifndef check_c_7
#define check_c_7
#include <string>
#include <fstream>
#include <iostream>
#include <complex>
#include <cstdint>
#include <vector>
#include "Component.h"
class DCVoltageSource :public Component {//This class must be a derived class of Component
private:
	double DCVoltageSource_v_sourceVoltage;//The only private member variable of the class is of type double
	double DCVoltageSource_v_current;//Add a member variable of type double to store the current drawn from the source.
public:
	DCVoltageSource();//The constructor must initialize the source voltage to zero.
	DCVoltageSource(double v);
	DCVoltageSource(double v,double i);
	void DCVoltageSource_f_set(std::string identifier, double inputDouble);//There must be a mutator function to set the source voltage,
	double DCVoltageSource_f_get_double(std::string identifier) const;//and a const accessor function to return the source voltage.
	void DCVoltageSource_f_report(std::ofstream& ofs);//There must be a member function to write information about a DC voltage source
};

#endif