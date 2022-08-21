// This program demonstrates a simple class.
#include <iostream>//port in precessor
#include <cmath>//port in precessor 
#include <string>//port in precessor 
using namespace std;
class Not {
private:
	string inputNode;//The private member variables are a string variable to store a text label used to identify the input node
	bool logicValue;//and a bool variable used to store the logic value at the input node.
public://The public member functions are:
	void setInputNode(string takeIn) {//A mutator function that takes a string parameter
		inputNode = takeIn;// and sets the input label.
	}
	void setLogicValue(bool takeIn) {//A mutator function that takes a bool parameter
		logicValue = takeIn;//sets the input logic value
	}
	string getLabel() {//Accessor functions that return the input label and input logic value.
		return inputNode;
	}
	int getLogic() {//Accessor functions that return the input label and input logic value.
		return logicValue;
	}
	string getLabelAppended() {//An accessor function that returns a string variable containing the label for the output node,
		return(inputNode + "_not");// which is equal to the input label with the string literal ¡°_not¡± appended.
	}
	bool getLogicCompliment() {//An accessor function that returns a bool variable containing the logic value at the output node
		return(!logicValue);//which is equal to the complement of the logic value at the input node.
	}
};
int main()
{
	string labelIn;
	int logicIn;
	Not not1;
	cout << "This program will simulate a not gate." << endl//Prompt the user with this message:
		<< "What is the label for the gate input?" ;//Prompt the user with this message:
	cin >> labelIn;//Read user input from the keyboard.
	cout << "What is the logic value at the input (0/1)?" ;//Prompt the user with this message:
	
	cin >> logicIn;//Read user input from the keyboard.
	
	not1.setInputNode(labelIn);
	not1.setLogicValue(logicIn);
	//Print messages to standard output to report information about the NOT gate, following the format shown below. Each cout statement should use the accessor functions to obtain the information needed:
	cout << "Here are the data on the not gate:\nInput label: " << not1.getLabel() << "\nOutput label: " << not1.getLabelAppended() << "\nLogic value at input: ";
	cout << not1.getLogic() << "\nLogic value at output: " << not1.getLogicCompliment() << endl;

	
}