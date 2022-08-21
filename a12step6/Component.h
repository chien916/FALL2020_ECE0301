//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	Component.h			%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//
#ifndef check_c_3
#define check_c_3
#include <string>
#include <fstream>
#include <iostream>
#include <complex>
#include <cstdint>
#include "Node.cpp"

//#include "Component.h"
class Component {
private:
	static int Component_v_count;//A static member variable of type int to store the number of components in existence
	int Component_v_index;//A member variable of type int to store the component index
	Node* Component_p_NodeA;//A pointer to an object from the node class, which will point to the node
	Node* Component_p_NodeB;//A pointer to an object from the node class, which will point to the node
public:
	Component();//The constructor
	int Component_f_get_int(std::string identifier) const;//There must be a const member function that
	void Component_f_set(std::string identifier,Node& inputNode);//There must be mutator functions for the node pointers.
	double Component_f_get_double(std::string identifier) const;//There must be a const member function that
	void Component_f_report(std::ofstream& ofs);//Write a member function for the component class that takes no parameters, and returns the
	
};
#endif