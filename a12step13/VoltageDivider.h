//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	VoltageDivider.h	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//
#ifndef check_c_13
#define check_c_13
#include <string>
#include <fstream>
#include <iostream>
#include <complex>
#include <cstdint>
#include <vector>
#include "Network.h"
#include "DCVoltageSource.h"
#include "Resistor.h"
class VoltageDivider :public Network {//This class must be a derived class, with the network class as the base class.
private:
	DCVoltageSource* VoltageDivider_o_DCVoltageSource;// an object from the DC voltage source class
	Resistor* VoltageDivider_o_ResistorA;//and two objects from the resistor class
	Resistor* VoltageDivider_o_ResistorB;//and two objects from the resistor class
	void VoltageDivider_f_connect();
	void VoltageDivider_f_preConstruct(double vdc, double r1, double r2);
public:
	VoltageDivider();//The default constructor for this class must:
	VoltageDivider(double vdc, double r1, double r2);//There must also be a constructor that accepts three arguments 
	void VoltageDivider_f_set(std::string identifier, double inputDouble);
	void VoltageDivider_f_report(std::ofstream& ofs);
	void VoltageDivider_f_calculate();//Write a new member function that takes no arguments and returns nothing
};
#endif