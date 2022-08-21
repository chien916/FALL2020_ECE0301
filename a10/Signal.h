#ifndef p_prot_h//protection for including header for multiple times unnecessarily
#define p_prot_h//protection for including header for multiple times unnecessarily
///////Signal.h///////
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <memory>
#include <mgl2/mgl.h>
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
	Signal(unsigned int, double, double);//Overload the constructor by writing a second constructor that accepts parameters for the
	void fillSignal(double, double, double);//Write a member function that fills the signal array with samples of a sinusoidal signal
	void roundSignal();//Write a new member function for the class that rounds the values in the signal array by
	void plotSignal();//Write a member function for the signal class that generates a plot of the signal, and stores it
};
#endif