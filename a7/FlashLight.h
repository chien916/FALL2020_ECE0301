#pragma once
#include <iostream>//port in precessor
#include <cmath>//port in precessor 
#include <string>//port in precessor 
#ifndef ck2
#define ck2
using namespace std;
class FlashLight {//The name of the class must be FlashLight.
private://The private member variables are
	double v;//two double variables that store the battery voltage and bulb resistance,
	double r;//two double variables that store the battery voltage and bulb resistance,
	bool state;//and a bool variable that stores the switch state.
public://The public member functions are:
	FlashLight();
	void setV(double vv);
	void setR(double rr);
	void toggle();
	double getV();
	double getR();
	double getState();
	double getI();
	double getP();
	void displayAll();
};
#endif