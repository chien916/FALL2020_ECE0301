//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	Resistor.h			%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//
#ifndef check_c_11
#define check_c_11
#include "Resistor.h"
Resistor::Resistor() {//constructor
	Resistor_v_resistance = 1000;
	Component_f_config(0);
}
Resistor::Resistor(double r) {//constructor with pre assigned resistance
	Resistor_v_resistance = r;
	Component_f_config(0);
}
void Resistor::Resistor_f_set(std::string identifier,double d) {//There must be a mutator function to set the resistance
	if (identifier == "Resistor_v_resistance") {
		Resistor_v_resistance = d;
	}
	else {
		std::cout << "Resistor::Resistor_f_set ERROR\nIdentifier: " << identifier;
		std::getchar();
		exit(44);
	}
	Component_f_config();
}
double Resistor::Resistor_f_get_double(std::string identifier) const{// and a const accessor
	if (identifier == "Resistor_v_resistance") {
		return Resistor_v_resistance ;
	}
	else if (identifier == "Resistor_v_voltage") {
		double temp_vA = Component_f_get_double("Component_p_NodeA_v_voltage");
		double temp_vB = Component_f_get_double("Component_p_NodeB_v_voltage");
		return (temp_vA - temp_vB);
	}
	else if (identifier == "Resistor_v_current") {//Add a const accessor function that returns the current.
		double temp_dV = Resistor_f_get_double("Resistor_v_voltage");
		double temp_i = temp_dV / Resistor_v_resistance;
		return temp_i;
	}
	else if (identifier == "Resistor_v_power") {//Add a const accessor function that returns the voltage.
		return std::abs(Resistor_f_get_double("Resistor_v_current")*Resistor_f_get_double("Resistor_v_voltage"));
	}
	else {
		std::cout << "Resistor::Resistor_f_get_double ERROR\nIdentifier: " << identifier;
		std::getchar();
		exit(44);
	}
}
void Resistor::Resistor_f_report(std::ofstream& ofs) {//There must be a member function to write information about a resistor to a text file.
	Component_f_config();
	ofs << "\nComponent # ";
	ofs << Component_f_get_int("Component_v_index");
	ofs << " is a Resistor, R = ";
	ofs << Resistor_v_resistance;
	ofs << " Ohms.\n";
	Component_f_report(ofs);//call the member function for the component class that writes component information to a
	ofs << "The current in this Resistor = ";
	ofs << std::abs(Resistor_f_get_double("Resistor_v_current"));
	ofs << " Amps,\n";
	ofs << "flowing from Node ";
	ofs << Component_f_get_config(2);
	ofs << " to Node ";
	ofs << Component_f_get_config(3);
	ofs << ".\nThe power dissipated in this Resistor = ";
	ofs << Resistor_f_get_double("Resistor_v_power");
	ofs << " Watts.\n";


}
#endif