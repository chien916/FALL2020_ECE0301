//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	VoltageDivider.cpp	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//
#ifndef check_c_16
#define check_c_16
#include "CurrentDivider.h"
//These classes will be constructed in ways that are directly analogous to
//the DC voltage course and voltage divider classes.
void CurrentDivider::CurrentDivider_f_preConstruct(double idc, double r1, double r2) {
	CurrentDivider_o_DCCurrentSource = new DCCurrentSource(idc);
	CurrentDivider_o_ResistorA = new Resistor(r1);
	CurrentDivider_o_ResistorB = new Resistor(r2);
}
CurrentDivider::CurrentDivider() :Network(2) {//Call the constructor for the network class, with 2 nodes
	CurrentDivider_f_preConstruct(1, 1000, 1000);
	CurrentDivider_f_connect();
	CurrentDivider_f_calculate();//must be called as the last step of every member function that changes the circuit conditions :
}
CurrentDivider::CurrentDivider(double idc, double r1, double r2) : Network(2) {//The default constructor for this class must:
	CurrentDivider_f_preConstruct(idc, r1, r2);
	CurrentDivider_f_connect();
	CurrentDivider_f_calculate();//must be called as the last step of every member function that changes the circuit conditions :
}
void CurrentDivider::CurrentDivider_f_connect() {
	Network_f_connect(CurrentDivider_o_DCCurrentSource, 0, 1);//Connect the DC Current course between nodes 0 and 1,
	Network_f_connect(CurrentDivider_o_ResistorA, 0, 1);//Connect R1 between nodes 1 and 0, and
	Network_f_connect(CurrentDivider_o_ResistorB, 0, 1);//Connect R2 between nodes 1 and 0.
}
void CurrentDivider::CurrentDivider_f_set(std::string identifier, double inputDouble) {
	if (identifier == "CurrentDivider_o_ResistorA_v_resistance") {
		(*CurrentDivider_o_ResistorA).Resistor_f_set("Resistor_v_resistance", inputDouble);// There must be a mutator function that sets the resistances of R1
	}
	else if (identifier == "CurrentDivider_o_ResistorB_v_resistance") {
		(*CurrentDivider_o_ResistorB).Resistor_f_set("Resistor_v_resistance", inputDouble);//There must be a mutator function that sets the resistances of R2
	}
	else if (identifier == "CurrentDivider_o_DCCurrentSource_v_sourceCurrent") {
		(*CurrentDivider_o_DCCurrentSource).DCCurrentSource_f_set("DCCurrentSource_v_sourceCurrent", inputDouble);//There must be a mutator function for the source Current.
	}
	else {
		std::cout << "CurrentDivider::CurrentDivider_f_set() ERROR, identifier:" << identifier;
		std::getchar();
		exit(44);
	}
}
void CurrentDivider::CurrentDivider_f_report(std::ofstream& ofs) {
	ofs << "\n";//An empty line
	for (int i = 0; i < 48; i++) {
		ofs << "-";
	}//A line of 48 dashes
	ofs << "\n\nData for Electric Network # " << Network_f_get_int("Network_v_index") << ":\n"
		<< "Network # "
		<< Network_f_get_int("Network_v_index")
		<< " is a Current Divider.";
	Network_f_report(ofs, -1);//Cut these statements from the function for the network class
	ofs << "At present, there are "
		<< (*CurrentDivider_o_DCCurrentSource).Component_f_get_int("Component_v_count")//Write a line to the file to report the number of components in existence,
		<< " components in existence.\n";
	(*CurrentDivider_o_DCCurrentSource).DCCurrentSource_f_report(ofs);//Call the member function from the DC Current source class that writes
	(*CurrentDivider_o_ResistorA).Resistor_f_report(ofs);//Use R1 to call the member function from the resistor class that writes resistor
	(*CurrentDivider_o_ResistorB).Resistor_f_report(ofs);//Use R2 to call the member function from the resistor class that writes resistor
}
void CurrentDivider::CurrentDivider_f_calculate() { //Write a new member function that takes no arguments and returns nothing
	Node* NodePtr0 = Network_f_get_NodePtr(0);
	Node* NodePtr1 = Network_f_get_NodePtr(1);
	double R1 = (*CurrentDivider_o_ResistorA).Resistor_f_get_double("Resistor_v_resistance");
	double R2 = (*CurrentDivider_o_ResistorB).Resistor_f_get_double("Resistor_v_resistance");
	double Idc = (*CurrentDivider_o_DCCurrentSource).DCCurrentSource_f_get_double("DCCurrentSource_v_sourceCurrent");
	double VoltageNode0 = 0;//Set the Current at node 0 to 0 V
	double Reqv = 1 / (1 / R1 + 1 / R2);//Compute the equivalent resistance of the two parallel resistors
	double VoltageNode1 = Idc*Reqv;//Set the voltage at node 1 equal to the source current of the DC current source, multiplied by the equivalent resistance.
	double Voltage = VoltageNode1;//Set the Voltage member variable for the DC Current source equal to the value of the loop Voltage.
	(*CurrentDivider_o_DCCurrentSource).DCCurrentSource_f_set("DCCurrentSource_v_voltage", Voltage);//Set the Voltage member variable for the DC Current source equal to the value of
	(*NodePtr0).Node_f_set("Node_v_voltage", VoltageNode0);//Actually Setting
	(*NodePtr1).Node_f_set("Node_v_voltage", VoltageNode1);//Actually Setting
}
#endif