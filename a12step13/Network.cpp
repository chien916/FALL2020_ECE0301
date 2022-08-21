//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	Network.cpp			%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//
#ifndef check_c_6
#define check_c_6
#include "Network.h"
int Network::Network_v_count = 0;//The static member variable that stores the number of nodes must be initialized to zero outside the class.
Network::Network() {
	Network_f_constructor(2);//The default value for this parameter must be 2.
}
Network::Network(int input) {//The constructor must accept a parameter of type int representing the number of
	Network_f_constructor(input);
}
void Network::Network_f_constructor(int input) {
	Network_v_index = Network_v_count;//Assign the network index,
	Network_v_count++;//Increment the number of networks in existence
	Network_v_numOfNodes = input;//Set the number of nodes in the network to value of the parameter, and
	Node* h_arrayOfNodes=new Node[Network_v_numOfNodes];//Allocate memory for an array of nodes, with the number of elements equal to the
	Network_p_begOfNodes = h_arrayOfNodes;
	//std::cout << "now p beg of nodes havs been set to " << Network_p_begOfNodes << " with nodes of " << Network_v_numOfNodes;
	//std::getchar();
}
void Network::Network_f_releaseMemory() {
	delete[] Network_p_begOfNodes;//There must be a destructor to release the memory allocated for the array of nodes
}
int Network::Network_f_get_int(std::string identifier)const {
	if (identifier == "Network_v_index") {
		return Network_v_index;
	}
	else if (identifier == "Network_v_count") {
		return Network_v_count;
	}
	else if (identifier == "Network_v_numOfNodes") {
		return Network_v_numOfNodes;
	}
	else if (identifier == "Node_v_count") {//There must be a const member function that returns the number of nodes in
		return (*Network_p_begOfNodes).Node_f_get_int("Node_v_count");
	}
	else {
		std::cout << "Network::Network_f_get_int(std::string identifier) ERROR";
		std::getchar();
		exit(44);
	}
}
void Network::Network_f_set(std::string identifier, int intInput, double doubleInput) {// There must be a member function to set the voltage at any of the nodes in the
	if (identifier == "Node_v_voltage") {
		(*(Network_p_begOfNodes + intInput)).Node_f_set("Node_v_voltage", doubleInput);
	}
	else {
		std::cout << "Network::Network_f_set(std::string identifier, int intInput, double doubleInput) ERROR";
		std::getchar();
		exit(44);
	}
}
void Network::Network_f_report(std::ofstream& writeObject,int controller) {
	if (controller == 0) {
		writeObject << "\n";//An empty line
		for (int i = 0; i < 48; i++) {
			writeObject << "-";//A line of 48 dashes
		}
		writeObject << "\n\nData for Electric Network # " << Network_v_index<<":";
	}
	writeObject
		<< "\nAt present, there are " << Network_v_count << " Networks in existence."
		<< "\nAt present, there are " << Network_f_get_int("Node_v_count") << " nodes in existence."
		<< "\nNetwork # " << Network_v_index << " contains " << Network_v_numOfNodes << " nodes.\n";
	for (int i = 0; i < Network_v_numOfNodes; i++) {
		(*(Network_p_begOfNodes + i)).Node_f_report(writeObject);
	}
}
void Network::Network_f_connect(Component *inputComponent, int inputInt1, int inputInt2) {//Add a member function to the network class that takes three parameters
	(*inputComponent).Component_f_set("Component_p_NodeA", *(Network_p_begOfNodes + inputInt1));// sets the node pointers for the component referenced
	(*inputComponent).Component_f_set("Component_p_NodeB", *(Network_p_begOfNodes + inputInt2));// sets the node pointers for the component referenced
}
Node* Network::Network_f_get_NodePtr(int inputInt) {
	return (Network_p_begOfNodes + inputInt);// and returns a pointer to an object from the node class.
}
#endif