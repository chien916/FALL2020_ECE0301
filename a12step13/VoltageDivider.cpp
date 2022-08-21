//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	VoltageDivider.cpp	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//
#ifndef check_c_14
#define check_c_14
#include "VoltageDivider.h"
void VoltageDivider::VoltageDivider_f_preConstruct(double vdc, double r1, double r2) {
	VoltageDivider_o_DCVoltageSource = new DCVoltageSource(vdc);
	VoltageDivider_o_ResistorA = new Resistor(r1);
	VoltageDivider_o_ResistorB = new Resistor(r2);
}
VoltageDivider::VoltageDivider():Network(3) {//The default constructor for this class must:
	VoltageDivider_f_preConstruct(1, 1000, 1000);
	VoltageDivider_f_connect();
	VoltageDivider_f_calculate();//must be called as the last step of every member function that changes the circuit conditions :
}
VoltageDivider::VoltageDivider(double vdc,double r1,double r2) :Network(3) {//The default constructor for this class must:
	VoltageDivider_f_preConstruct(vdc, r1, r2);
	VoltageDivider_f_connect();
	VoltageDivider_f_calculate();//must be called as the last step of every member function that changes the circuit conditions :
}
void VoltageDivider::VoltageDivider_f_connect() {
	Network_f_connect(VoltageDivider_o_DCVoltageSource, 0, 1);//Connect the DC voltage course between nodes 0 and 1,
	Network_f_connect(VoltageDivider_o_ResistorA, 1, 2);//Connect R1 between nodes 1 and 2, and
	Network_f_connect(VoltageDivider_o_ResistorB, 2, 0);//Connect R2 between nodes 2 and 0.
}
void VoltageDivider::VoltageDivider_f_set(std::string identifier, double inputDouble) {
	if (identifier == "VoltageDivider_o_ResistorA_v_resistance") {
		(*VoltageDivider_o_ResistorA).Resistor_f_set("Resistor_v_resistance", inputDouble);// There must be a mutator function that sets the resistances of R1
	}
	else if (identifier == "VoltageDivider_o_ResistorB_v_resistance") {
		(*VoltageDivider_o_ResistorB).Resistor_f_set("Resistor_v_resistance", inputDouble);//There must be a mutator function that sets the resistances of R2
	}
	else if (identifier == "VoltageDivider_o_DCVoltageSource_v_sourceVoltage") {
		(*VoltageDivider_o_DCVoltageSource).DCVoltageSource_f_set("DCVoltageSource_v_sourceVoltage", inputDouble);//There must be a mutator function for the source voltage.
	}
	else {
		std::cout << "VoltageDivider::VoltageDivider_f_set() ERROR, identifier:" << identifier;
		std::getchar();
		exit(44);
	}
}
void VoltageDivider::VoltageDivider_f_report(std::ofstream& ofs) {
	ofs << "\n";//An empty line
	for (int i = 0; i < 48; i++) {
		ofs << "-";
	}//A line of 48 dashes
	ofs << "\n\nData for Electric Network # " << Network_f_get_int("Network_v_index") << ":\n"
		<< "Network # " 
		<< Network_f_get_int("Network_v_index") 
		<< " is a Voltage Divider.";	
	Network_f_report(ofs,-1);//Cut these statements from the function for the network class
	ofs << "At present, there are "
		<< (*VoltageDivider_o_DCVoltageSource).Component_f_get_int("Component_v_count")//Write a line to the file to report the number of components in existence,
		<<" components in existence.\n";
	(*VoltageDivider_o_DCVoltageSource).DCVoltageSource_f_report(ofs);//Call the member function from the DC voltage source class that writes
	(*VoltageDivider_o_ResistorA).Resistor_f_report(ofs);//Use R1 to call the member function from the resistor class that writes resistor
	(*VoltageDivider_o_ResistorB).Resistor_f_report(ofs);//Use R2 to call the member function from the resistor class that writes resistor
}
void VoltageDivider::VoltageDivider_f_calculate() { //Write a new member function that takes no arguments and returns nothing
	Node* NodePtr0 = Network_f_get_NodePtr(0);
	Node* NodePtr1 = Network_f_get_NodePtr(1);
	Node* NodePtr2 = Network_f_get_NodePtr(2);
	double R1 = (*VoltageDivider_o_ResistorA).Resistor_f_get_double("Resistor_v_resistance");
	double R2 = (*VoltageDivider_o_ResistorB).Resistor_f_get_double("Resistor_v_resistance");
	double Vdc = (*VoltageDivider_o_DCVoltageSource).DCVoltageSource_f_get_double("DCVoltageSource_v_sourceVoltage");
	double VoltageNode0 = 0;//Set the voltage at node 0 to 0 V
	double VoltageNode1 = Vdc;//Set the voltage at node 1 equal to the source voltage of the DC voltage source
	double Current = Vdc / (R1 + R2);//Set the current member variable for the DC voltage source equal to the value of the loop current.
	(*VoltageDivider_o_DCVoltageSource).DCVoltageSource_f_set("DCVoltageSource_v_current", Current);//Set the current member variable for the DC voltage source equal to the value of
	double VoltageNode2 = Current*R2;//Set the voltage at node 2 equal to the loop current times the resistance of R2
	(*NodePtr0).Node_f_set("Node_v_voltage", VoltageNode0);//Actually Setting
	(*NodePtr1).Node_f_set("Node_v_voltage", VoltageNode1);//Actually Setting
	(*NodePtr2).Node_f_set("Node_v_voltage", VoltageNode2);//Actually Setting
}
#endif