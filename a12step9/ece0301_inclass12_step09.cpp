#include "Node.cpp"
#include "Network.cpp"
#include "Component.cpp"
#include "DCVoltageSource.cpp"
#include "Resistor.cpp"
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	DCCurrentSource.h	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//
///#ifndef check_c_9
///#define check_c_9
///#endif
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	DCCurrentSource.cpp	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//
///#ifndef check_c_10
///#define check_c_10
///#endif
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	VoltageDivider.h	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//
///#ifndef check_c_13
///#define check_c_13
///#endif
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	VoltageDivider.cpp	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//
///#ifndef check_c_14
///#define check_c_14
///#endif
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	CurrentDivider.h	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//
///#ifndef check_c_15
///#define check_c_15
///#endif
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	CurrentDivider.cpp	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//
///#ifndef check_c_16
///#define check_c_16
///#endif
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	Source.cpp			%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//
int main() {
	std::ofstream ofs;//Define an ofstream object,
	ofs.open("ECE 0301 - Electrical Network Reports.txt");//use it to open the text file
	ofs << "ECE 0301 - Electrical Network Simulation\n";
	Network network(3);//Define a network with 3 nodes.
	int vs = 12;
	DCVoltageSource vdc(vs,0.04);
	network.Network_f_connect(&vdc, 0, 1);//C0 is connected between node 0 and node 1

	Resistor r1(200);
	network.Network_f_connect(&r1, 1, 2);//Repeat for the other two components.


	Resistor r2(100);
	network.Network_f_connect(&r2, 2, 0);//Repeat for the other two components.
	

	network.Network_f_set("Node_v_voltage", 0, 0);
	network.Network_f_set("Node_v_voltage", 1, vs);
	network.Network_f_set("Node_v_voltage", 2, vs/3);
	network.Network_f_report(ofs);//Call the member function that writes information about the network to the output file.
	vdc.DCVoltageSource_f_report(ofs);
	r1.Resistor_f_report(ofs);
	r2.Resistor_f_report(ofs);
	ofs.close();//Close the output file.
	//getchar();//pause console
}