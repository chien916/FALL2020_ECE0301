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
	else if (identifier == "Component_p_NodeA_v_index") {
		return (*Component_p_NodeA).Node_f_get_int("Node_v_index");//returns the index of the node to which terminal A is connected
	}
	else if (identifier == "Component_p_NodeB_v_index") {
		return (*Component_p_NodeB).Node_f_get_int("Node_v_index");//returns the index of the node to which terminal A is connected
	}
	else {
		std::cout << "Component::Component_f_get(std::string identifier) ERROR";
		std::getchar();
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
		std::getchar();
		exit(44);
	}
}
double Component::Component_f_get_double(std::string identifier) const {//Write a member function for the component class that takes no parameters, and returns the
	if (identifier == "Component_p_NodeA_v_voltage") {
		return (*Component_p_NodeA).Node_f_get_double("Node_v_voltage");//returns the index of the node to which terminal A is connected
	}
	else if (identifier == "Component_p_NodeB_v_voltage") {
		return (*Component_p_NodeB).Node_f_get_double("Node_v_voltage");//returns the index of the node to which terminal A is connected
	}
	else {
		std::cout << "Component::Component_f_get_double ERROR, Identifier: "<<identifier;
		std::getchar();
		exit(44);
	}
}
void Component::Component_f_report(std::ofstream& ofs) {//print lines
	Component_f_config();
	ofs << "Component # ";
	ofs << Component_v_index;
	ofs << " is connected between node ";
	ofs << (*Component_p_NodeA).Node_f_get_int("Node_v_index");
	ofs << " and node ";
	ofs << (*Component_p_NodeB).Node_f_get_int("Node_v_index");
	ofs << "." << std::endl;
	ofs << "The Voltage across Component # ";
	ofs << Component_v_index;
	ofs << " = ";
	ofs << std::abs((*Component_p_NodeA).Node_f_get_double("Node_v_voltage") - (*Component_p_NodeB).Node_f_get_double("Node_v_voltage"));
	ofs << " Volts," << std::endl;
	ofs << "with the negative terminal at node ";
	ofs << Component_s_config[1]
		<<"." << std::endl;

}
void Component::Component_f_config(int type) {
	if (type == 0) {//not a source
		Component_s_config[0] = -1;
	}
	else if (type == 1) {//is a source
		Component_s_config[0] = 1;
	}
	else {
		std::cout << "Component_f_config ERROR, type: " << type;
		std::getchar();
		exit(44);
	}
}
void Component::Component_f_config() {
	double VTempV1,VTempV2;
	int nodeTempV1, nodeTempV2, nodeNeg, nodeFrom, nodeTo;
	VTempV1 = (*Component_p_NodeA).Node_f_get_double("Node_v_voltage");
	VTempV2 = (*Component_p_NodeB).Node_f_get_double("Node_v_voltage");
	nodeTempV1= (*Component_p_NodeA).Node_f_get_int("Node_v_index");
	nodeTempV2 = (*Component_p_NodeB).Node_f_get_int("Node_v_index");
	int srs;
	if (Component_s_config[0] == 1)
		srs = 1;
	else if (Component_s_config[0] == -1)
		srs = -1;
	else {
		std::cout << "if (Component_s_config[0] == 1) ERROR, Component_s_config[0]: " << Component_s_config[0];
		std::getchar();
		exit(44);
	}
	if (srs==1) {//IS A SOURCE
		if (VTempV1 <= VTempV2) {
			nodeNeg = nodeTempV1;
			nodeFrom = nodeTempV1;
			nodeTo = nodeTempV2;
		}
		else {
			nodeNeg = nodeTempV2;
			nodeFrom = nodeTempV2;
			nodeTo = nodeTempV1;
		}
	}
	else  {
		if (VTempV1 <= VTempV2) {
			nodeNeg = nodeTempV1;
			nodeFrom = nodeTempV2;
			nodeTo = nodeTempV1;
		}
		else {
			nodeNeg = nodeTempV2;
			nodeFrom = nodeTempV1;
			nodeTo = nodeTempV2;
		}
	}
	Component_s_config[1] = nodeNeg;
	Component_s_config[2] = nodeFrom;
	Component_s_config[3] = nodeTo;
}
int Component::Component_f_get_config(int ind) {
	return Component_s_config[ind];
}
#endif