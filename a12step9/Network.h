//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	Network.h			%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//
#ifndef check_c_5
#define check_c_5
#include <string>
#include <fstream>
#include <iostream>
#include <complex>
#include <cstdint>
#include "Node.h"
#include "Component.h"
class Network {
private:
	static int Network_v_count;//A static member variable of type int to store the number of networks in existence
	int Network_v_index;//A member variable of type int to store the network index
	int Network_v_numOfNodes;//A member variable of type int to store the number of nodes in this network, and
	Node* Network_p_begOfNodes;//A pointer to the beginning of an array of nodes.
	void Network_f_constructor(int input);
public:
	Network();
	Network(int input);
	void Network_f_releaseMemory();//There must be a destructor to release the memory allocated for the array of nodes
	int Network_f_get_int(std::string identifier) const;// There must be a const member function that returns 
	void Network_f_set(std::string identifier,int intInput,double doubleInput);// There must be a member function to set the voltage at any of the nodes in the
	void Network_f_report(std::ofstream& writeObject);
	void Network_f_connect(Component* inputComponent, int inputInt1, int inputInt2);//Add a member function to the network class that takes three parameters 

};
#endif