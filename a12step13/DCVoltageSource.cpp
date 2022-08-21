//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	DCVoltageSource.cpp	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//
#ifndef check_c_8
#define check_c_8
#include "DCVoltageSource.h"
DCVoltageSource::DCVoltageSource() {//The constructor must initialize the source voltage to zero.
	DCVoltageSource_v_sourceVoltage = 0;//initialize the source voltage to zero
	DCVoltageSource_v_current = 0;
	Component_f_config(1);
}
DCVoltageSource::DCVoltageSource(double v) {
	DCVoltageSource_v_sourceVoltage = v;
	DCVoltageSource_v_current = 0;
	Component_f_config(1);
}
DCVoltageSource::DCVoltageSource(double v,double i) {
	DCVoltageSource_v_sourceVoltage = v;
	DCVoltageSource_v_current = i;
	Component_f_config(1);
}
void DCVoltageSource::DCVoltageSource_f_set(std::string identifier, double inputDouble) {//There must be a mutator function to set the source voltage,
	if (identifier == "DCVoltageSource_v_sourceVoltage") {
		DCVoltageSource_v_sourceVoltage = inputDouble;
	}
	else if (identifier == "DCVoltageSource_v_current") {
		DCVoltageSource_v_current = inputDouble;
	}
	else {
		std::cout << "DCVoltageSource::DCVoltageSource_f_set ERROR\nIdentifier: " << identifier;
		std::getchar();
		exit(44);
	}
	Component_f_config();
}
double DCVoltageSource::DCVoltageSource_f_get_double(std::string identifier) const {//and a const accessor function to return the source voltage.
	if (identifier == "DCVoltageSource_v_sourceVoltage") {
		return DCVoltageSource_v_sourceVoltage;
	}
	else if (identifier == "DCVoltageSource_v_current") {
		return DCVoltageSource_v_current;
	}
	else if (identifier == "DCVoltageSource_v_power") {
		return std::abs(DCVoltageSource_v_current*DCVoltageSource_v_sourceVoltage);
	}
	else {
		std::cout << "DCVoltageSource::DCVoltageSource_f_get_double ERROR\nIdentifier: " << identifier;
		std::getchar();
		exit(44);
	}
}
void DCVoltageSource::DCVoltageSource_f_report(std::ofstream& ofs) {//There must be a member function to write information about a DC voltage source to a
	Component_f_config();
	ofs << "\nComponent # ";
	ofs << Component_f_get_int("Component_v_index");
	ofs << " is a DC Voltage Source, Vs = ";
	ofs << (DCVoltageSource_v_sourceVoltage);
	ofs << " Volts.\n";
	Component_f_report(ofs);//call the member function for the component class that writes component information to a
	ofs << "The current in this DC Voltage Source = ";
	ofs << std::abs(DCVoltageSource_v_current);
	ofs << " Amps,\n";
	ofs << "flowing from Node ";
	ofs << Component_f_get_config(2);
	ofs << " to Node ";
	ofs << Component_f_get_config(3);
	ofs << ".\nThe power supplied by this DC Voltage Source = ";
	ofs << DCVoltageSource_f_get_double("DCVoltageSource_v_power");
	ofs << " Watts.\n";


}
#endif 