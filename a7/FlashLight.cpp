#include "FlashLight.h"
#ifndef ck
#define ck




FlashLight::FlashLight() {//A Constructor that
	v = 3;//initializes the battery voltage to 3.0 V,
	r = 100;//the bulb resistance to 100 Ohms,
	state = 0;//and the switch state to false.
}
void FlashLight::setV(double vv) {//Two mutator functions that take a double parameter and set the battery voltage and bulb resistance,
	v = vv;
}
void FlashLight::setR(double rr) {//Two mutator functions that take a double parameter and set the battery voltage and bulb resistance,
	r = rr;
}
void FlashLight::toggle() {//A mutator function that toggles the switch state,
	state = (!state);
}
double FlashLight::getV() {//Three accessor functions that return each of the member variables.
	return v;
}
double FlashLight::getR() {//Three accessor functions that return each of the member variables.
	return r;
}
double FlashLight::getState() {//Three accessor functions that return each of the member variables.
	return state;
}
double FlashLight::getI() {//Two accessor functions that return the current flowing in the bulb and the power dissipated in the bulb.
	double I = v / r;
	return I;
}
double FlashLight::getP() {//Two accessor functions that return the current flowing in the bulb and the power dissipated in the bulb.
	double P = pow(v, 2) / r;
	return P;
}
void FlashLight::displayAll() {//A function that prints to standard output all available information about the current state of the flashlight
	cout << "Here are the data on the FlashLight :" << endl
		<< "The battery voltage is " << (getV()) << " Volts." << endl
		<< "The bulb resistance is " << (getR()) << " Ohms." << endl
		<< "The switch is " << (getState() == 0 ? "open" : "closed") << "." << endl
		<< "The FlashLight is " << (getState() == 0 ? "off" : "on") << "." << endl
		<< "The bulb current is " << (getI()) << " Amperes." << endl
		<< "The bulb power is " << (getP()) << " Watts." << endl;
}
#endif