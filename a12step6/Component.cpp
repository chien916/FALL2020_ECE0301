//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	Component.cpp		%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//
#ifndef check_c_4
#define check_c_4
#include "Component.h"
int Component::Component_v_count = 0;
Component::Component() {//The constructor
	Component_v_index = Component_v_count;//assign the component index
	Component_v_count++;//increment the number of components in existence
	(Component_p_NodeA) = nullptr;//and initialize both node pointers to nullptr.
	(Component_p_NodeB) = nullptr;//and initialize both node pointers to nullptr.
}
int Component::Component_f_get_int(std::string identifier) const {//There must be a const member function that
	if (identifier == "Component_v_index") {
		return Component_v_index;//for the component index 
	}
	else if (identifier == "Component_v_count") {
		return Component_v_count;//and the number of components in existence.
	}
	else if (identifier == "test0") {//FOR DEBUG ONLY
		std::uintptr_t i = reinterpret_cast<uintptr_t>(Component_p_NodeB);
		return i;
	}
	else if (identifier == "Component_p_NodeA_v_index") {
		return (*Component_p_NodeA).Node_f_get_int("Node_v_index");//returns the index of the node to which terminal A is connected
	}
	else if (identifier == "Component_p_NodeB_v_index") {
		return (*Component_p_NodeB).Node_f_get_int("Node_v_index");//returns the index of the node to which terminal A is connected
	}
	else {
		std::cout << "Component::Component_f_get(std::string identifier) ERROR";
		getchar();
		exit(44);
	}
}
void Component::Component_f_set(std::string identifier, Node& inputNode) {//There must be mutator functions for the node pointers.
	if (identifier == "Component_p_NodeA") {
		Component_p_NodeA = &inputNode;//and sets the node pointer member variable to the value of the parameter.
	}
	else if (identifier == "Component_p_NodeB") {
		Component_p_NodeB = &inputNode;//and sets the node pointer member variable to the value of the parameter.
	}
	else {
		std::cout << "Component::Component_f_set(std::string identifier, Node& inputNode) ERROR";
		getchar();
		exit(44);
	}
}
double Component::Component_f_get_double(std::string identifier) const {//Write a member function for the component class that takes no parameters, and returns the
	if (identifier == "Component_p_Nodes") {
		double tempVA = (*Component_p_NodeA).Node_f_get_double("Node_v_voltage");//This gives the voltage at terminal A.
		double tempVB = (*Component_p_NodeB).Node_f_get_double("Node_v_voltage");//Repeat to obtain the voltage at terminal B.
		return (std::abs(tempVA - tempVB));//Return the voltage at terminal B minus the voltage at terminal A
											//this function must always report a positive value
	}
	else {
		std::cout << "Component::Component_f_get_double(std::string identifier) ERROR";
		getchar();
		exit(44);
	}
}
void Component::Component_f_report(std::ofstream& ofs) {//print lines
	ofs << "Component # ";
	ofs << Component_v_index;
	ofs << " is connected between node ";
	ofs << (*Component_p_NodeA).Node_f_get_int("Node_v_index");
	ofs << " and node ";
	ofs << (*Component_p_NodeB).Node_f_get_int("Node_v_index");
	ofs << "." << std::endl;
	ofs << "The Voltage across Component # ";
	ofs << Component_v_index;;
	ofs << " = ";
	ofs << Component_f_get_double("Component_p_Nodes");
	ofs << " Volts," << std::endl;
	ofs << "with the negative terminal at node ";
	int tempWhichNegativeNode;
	double tempVA = (*Component_p_NodeA).Node_f_get_double("Node_v_voltage");
	double tempVB = (*Component_p_NodeB).Node_f_get_double("Node_v_voltage");
	if (tempVA > tempVB) {
		tempWhichNegativeNode = (*Component_p_NodeB).Node_f_get_int("Node_v_index");
	}
	else {
		tempWhichNegativeNode = (*Component_p_NodeA).Node_f_get_int("Node_v_index");
	}
	ofs	<< tempWhichNegativeNode
		<<"." << std::endl;

}
#endif