#include "Node.cpp"
#include "Network.cpp"
#include "Component.cpp"
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	DCVoltageSource.h	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//
///#ifndef check_c_7
///#define check_c_7
///#endif
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	DCVoltageSource.cpp	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//
///#ifndef check_c_8
///#define check_c_8
///#endif
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	DCCurrentSource.h	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//
///#ifndef check_c_9
///#define check_c_9
///#endif
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	DCCurrentSource.cpp	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//
///#ifndef check_c_10
///#define check_c_10
///#endif
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	Resistor.h			%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//
///#ifndef check_c_11
///#define check_c_11
///#endif
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	Resistor.cpp		%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//
///#ifndef check_c_12
///#define check_c_12
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
	Component c0, c1, c2;//Define 3 components
	network.Network_f_connect(&c0, 0, 1);//C0 is connected between node 0 and node 1
	network.Network_f_connect(&c1, 1, 2);//Repeat for the other two components.
	network.Network_f_connect(&c2, 2, 0);//Repeat for the other two components.
	network.Network_f_set("Node_v_voltage", 0, 0);
	network.Network_f_set("Node_v_voltage", 1, -5);
	network.Network_f_set("Node_v_voltage", 2, 1.25);
	network.Network_f_report(ofs);//Call the member function that writes information about the network to the output file.
	c0.Component_f_report(ofs);//Use component C0 to call the member function that writes information about a
	c1.Component_f_report(ofs);//Repeat for the other two components.
	c2.Component_f_report(ofs);//Repeat for the other two components.
	ofs.close();//Close the output file.
	//getchar();//pause console
}