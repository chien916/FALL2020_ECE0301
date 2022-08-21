//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	DCCurrentSource.cpp	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//
#ifndef check_c_10
#define check_c_10
#include "DCCurrentSource.h"
DCCurrentSource::DCCurrentSource() {//The constructor must initialize the source voltage to zero.
	DCCurrentSource_v_sourceCurrent = 0;//initialize the source voltage to zero
	DCCurrentSource_v_voltage = 0;
	Component_f_config(1);
}
DCCurrentSource::DCCurrentSource(double i) {
	DCCurrentSource_v_sourceCurrent = i;
	DCCurrentSource_v_voltage = 0;
	Component_f_config(1);
}
DCCurrentSource::DCCurrentSource(double i, double v) {
	DCCurrentSource_v_sourceCurrent = i;
	DCCurrentSource_v_voltage = v;
	Component_f_config(1);
}
void DCCurrentSource::DCCurrentSource_f_set(std::string identifier, double inputDouble) {//There must be a mutator function to set the source voltage,
	if (identifier == "DCCurrentSource_v_sourceCurrent") {
		DCCurrentSource_v_sourceCurrent = inputDouble;
	}
	else if (identifier == "DCCurrentSource_v_voltage") {
		DCCurrentSource_v_voltage = inputDouble;
	}
	else {
		std::cout << "DCCurrentSource::DCCurrentSource_f_set ERROR\nIdentifier: " << identifier;
		std::getchar();
		exit(44);
	}
	Component_f_config();
}
double DCCurrentSource::DCCurrentSource_f_get_double(std::string identifier) const {//and a const accessor function to return the source voltage.
	if (identifier == "DCCurrentSource_v_sourceCurrent") {
		return DCCurrentSource_v_sourceCurrent;
	}
	else if (identifier == "DCCurrentSource_v_voltage") {
		return DCCurrentSource_v_voltage;
	}
	else if (identifier == "DCCurrentSource_v_power") {
		return std::abs(DCCurrentSource_v_voltage*DCCurrentSource_v_sourceCurrent);
	}
	else {
		std::cout << "DCCurrentSource::DCCurrentSource_f_get_double ERROR\nIdentifier: " << identifier;
		std::getchar();
		exit(44);
	}
}
void DCCurrentSource::DCCurrentSource_f_report(std::ofstream& ofs) {//There must be a member function to write information about a DC voltage source to a
	Component_f_config();
	ofs << "\nComponent # ";
	ofs << Component_f_get_int("Component_v_index");
	ofs << " is a DC Current Source, Is = ";
	ofs << (DCCurrentSource_v_sourceCurrent);
	ofs << " Amps.\n";
	Component_f_report(ofs);//call the member function for the component class that writes component information to a
	ofs << "The current in this DC Current Source = ";
	ofs << std::abs(DCCurrentSource_v_sourceCurrent);
	ofs << " Amps,\n";
	ofs << "flowing from Node ";
	ofs << Component_f_get_config(2);
	ofs << " to Node ";
	ofs << Component_f_get_config(3);
	ofs << ".\nThe power supplied by this DC Current Source = ";
	ofs << DCCurrentSource_f_get_double("DCCurrentSource_v_power");
	ofs << " Watts.\n";


}

#endif