//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	Node.cpp			%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//
#ifndef check_c_2
#define check_c_2
#include "Node.h"
int Node::Node_v_count = 0;//The static member variable that stores the number of nodes must be initialized to zero outside the class.
Node::Node() {
	Node_v_index = Node_v_count;//The constructor must set the node index and increment the number of nodes in existence.
	Node_v_count++;
	Node_v_voltage = 0;//Add a statement to the constructor to initialize the node voltage to 0.
}
int Node::Node_f_get_int(std::string identifier) const {
	if (identifier == "Node_v_index") {
		return Node_v_index;//There must be an accessor functions that return the number of nodes and the node index.
	}
	else if (identifier == "Node_v_count") {
		return Node_v_count;//There must be an accessor functions that return the number of nodes and the node index.
	}
	else {
		std::cout << "Node::Node_f_get(std::string identifier) ERROR\n:"<<identifier;
		getchar();
		exit(44);
	}
}
double Node::Node_f_get_double(std::string identifier) const {//Write an accessor function to return the node voltage.
	if (identifier == "Node_v_voltage") {
		return Node_v_voltage;
	}
}
void Node::Node_f_set(std::string identifier, double input) {//Write a mutator function to set the node voltage to a desired value.
	if (identifier == "Node_v_voltage") {
		Node_v_voltage = input;
	}
}
void Node::Node_f_report(std::ofstream& writeObject) {//Write a member function to report information about a node. 
	std::string tempOther = "Voltage at node " + std::to_string(Node_v_index) + " = ";
	writeObject << tempOther << Node_v_voltage<<"."<< std::endl;//The function writes one line of text to the file
}
#endif