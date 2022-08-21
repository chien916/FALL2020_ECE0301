///////Signal.h///////
#include <iostream>
#include <fstream>
#include <string>
class Signal {//Create a new class named Signal to represent a time-domain signal.
private://The private member variables for the class are :
	unsigned int nosp;//A variable of type unsigned int to store the number of samples
	double freq, intt;//Two variables of type double to store the sampling frequency and the initial time
	double* sgnp; //Add a private member variable that is a pointer to double.
	double* timp;//Add another member variable that is a pointer to double. This variable will point to an
	std::string fnam;//Add a private member variable from the string class; this variable will hold a filename
public://Write the following public member function for the class:
	void nosp_set(unsigned int);//Mutator functions that allow you to set each of the member variables.
	void freq_set(double);//Mutator functions that allow you to set each of the member variables.
	void intt_set(double);//Mutator functions that allow you to set each of the member variables.
	unsigned int nosp_get();//Accessor functions that will return the value of each member variable
	double freq_get();//Accessor functions that will return the value of each member variable
	double intt_get();//Accessor functions that will return the value of each member variable
	Signal();//A default constructor
	double* sgnp_get(); //Add a public accessor function that returns the signal pointer.
	void sgnp_setZero(); //Write a member function that fills the signal array with zeros. 
	void destructAll();//Write a destructor that uses the delete operator to de-allocate the memory that was
	double* timp_get();//Add a public accessor function that returns the time pointer
	void timp_set();//Write a member function that fills the time array with linearly-spaced time samples, using
	void fnam_set(std::string);//Write a public member function that sets the filename member variable
	void write();//Write a public member function that writes information about a signal to a text file:
};
///////Signal.cpp///////
void Signal::nosp_set(unsigned int a) {//Mutator functions that allow you to set each of the member variables.
	nosp = a;
}
void Signal::freq_set(double a) {//Mutator functions that allow you to set each of the member variables.
	freq = a;
}
void Signal::intt_set(double a) {//Mutator functions that allow you to set each of the member variables.
	intt = a;
}
unsigned int Signal::nosp_get() {//Accessor functions that will return the value of each member variable
	return nosp;
}
double Signal::freq_get() {//Accessor functions that will return the value of each member variable
	return freq;
}
double Signal::intt_get() {//Accessor functions that will return the value of each member variable
	return intt;
}
Signal::Signal() {//A default constructor
	nosp = 101;// sets the number of samples to 101
	freq = 100.0;//the sampling frequency to 100.0 Hz
	intt = 0.0;//and the initial time to 0.0 sec.
	double* signalArrayPointerTemp = new double[nosp];//Add a line of code to the default constructor so that it uses the new operator to allocate
	sgnp = signalArrayPointerTemp;// and assigns it to the signal pointer
	sgnp_setZero();//Add a line of code to the default constructor so that it calls the member function to fill the
	double* timePointerTemp = new double[nosp];//Add a line of code to the default constructor so that it uses the new operator to allocate
	timp = timePointerTemp;//and assigns it to the time pointer.
	timp_set();//Add a line of code to the default constructor so that it calls the member function to fill the time array with linearly - spaced values
	
}
double* Signal::sgnp_get() {//Add a public accessor function that returns the signal pointer.
	return sgnp;
}
void Signal::sgnp_setZero() {//Write a member function that fills the signal array with zeros. 
	for (unsigned int i = 0; i < nosp; i++) {//write zeros to consecutive locations, starting at the address stored in the
		*(sgnp + i) = 0;//you must use the signal pointer
	}
}
void Signal::destructAll() {//Write a destructor that uses the delete operator to de-allocate the memory that was
	delete sgnp;
	delete timp;//Add a line of code to your destructor that uses the delete operator to de-allocate the
}
double* Signal::timp_get() {//Add a public accessor function that returns the time pointer
	return timp;
}
void Signal::timp_set() {//Write a member function that fills the time array with linearly-spaced time samples, using
	for(unsigned int i=0; i < nosp; i++) {//The number of time samples written must be equal to the value stored in the member variable
		*(timp + i) = intt + i / freq;
	}
}
void Signal::fnam_set(std::string a) {//Write a public member function that sets the filename member variable
	fnam = a;
}
void Signal::write() {//Write a public member function that writes information about a signal to a text file:
	std::ofstream ofs;//Declare a variable from the ofstream class, and use it to open a file whose name is
	std::string toOutputFileNameTemp = fnam + ".txt";//whose name is equal to the file name template with “.txt” appended to it.
	ofs.open(toOutputFileNameTemp);//use it to open a file whose name is
	ofs//Write lines of text to the file, following the same format used in step 3
		<< "ECE 0301: Time-Domain Signal Samples" << std::endl
		<< "The number of samples is " << nosp << std::endl
		<< "The sample rate is " << freq << std::endl
		<< "The initial time is " << intt << std::endl
		<< "Here is your signal:" << std::endl
		<< "t, s(t)" << std::endl;
	for (unsigned int i = 0; i < nosp; i++) {
		ofs
			<< *(timp + i)
			<< ", "
			<< *(sgnp + i)
			<< std::endl;
	}
	ofs.close(); //Close the file.
}
///////Source.cpp///////
int main() {//Write a main function
	Signal* inst=new Signal();//defines an instance of your time-domain signal class
	(*inst).fnam_set("time_domain_signal_samples");//Sets the filename template to “time_domain_signal_samples”.
	(*inst).write();//Calls the member function to write the signal to the text file.

	delete inst;

	


	std::getchar();
}