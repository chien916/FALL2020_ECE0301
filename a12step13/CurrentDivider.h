//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	CurrentDivider.h	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//
#ifndef check_c_15
#define check_c_15
//These classes will be constructed in ways that are directly analogous to
//the DC voltage course and voltage divider classes.
#include <string>
#include <fstream>
#include <iostream>
#include <complex>
#include <cstdint>
#include <vector>
#include "Network.h"
#include "DCCurrentSource.h"
#include "Resistor.h"
class CurrentDivider :public Network {//This class must be a derived class, with the network class as the base class.
private:
	DCCurrentSource* CurrentDivider_o_DCCurrentSource;// an object from the DC Current source class
	Resistor* CurrentDivider_o_ResistorA;//and two objects from the resistor class
	Resistor* CurrentDivider_o_ResistorB;//and two objects from the resistor class
	void CurrentDivider_f_connect();
	void CurrentDivider_f_preConstruct(double idc, double r1, double r2);
public:
	CurrentDivider();//The default constructor for this class must:
	CurrentDivider(double idc, double r1, double r2);//There must also be a constructor that accepts three arguments 
	void CurrentDivider_f_set(std::string identifier, double inputDouble);
	void CurrentDivider_f_report(std::ofstream& ofs);
	void CurrentDivider_f_calculate();//Write a new member function that takes no arguments and returns nothing
};
#endif