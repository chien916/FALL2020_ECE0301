//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	Node.h				%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//
#ifndef check_c_1
#define check_c_1
#include <string>
#include <fstream>
#include <iostream>
#include <complex>
#include <cstdint>
#include <vector>
// The static member variable that stores the number of nodes must be initialized to zeroutside the class.
class Node {
private:
	static int Node_v_count;//A static member variable of type int to store the number of nodes in existence, and
	int Node_v_index;//A member variable of type int to store the node index.
	double Node_v_voltage;//Add a member variable to the node class of type double to store the node voltage
public:
	Node();
	int Node_f_get_int(std::string identifier) const;//Accessor Functions all in one
	double Node_f_get_double(std::string identifier) const;//Write an accessor function to return the node voltage.
	void Node_f_set(std::string identifier, double input);// Write a mutator function to set the node voltage to a desired value.
	void Node_f_report(std::ofstream& writeObject);//Write a member function to report information about a node. 
};
#endif