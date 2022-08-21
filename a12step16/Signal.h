#pragma once
#ifndef check_signalh
#define check_signalh
#include <iostream>
#include <fstream>
#include <complex>
#include <memory>
#include <string>
#include <vector>//Insert a pre-processor directive near the top of your file to include the vector libraries
//#include <mgl2/mgl.h>

class Signal {//build a new class named Signal for a time-domain
private://beginning with the member variables for
	double v_nos;// the number of samples
	double v_frq;//sampling frequency
	double v_itt;// initial time
	std::string v_lbl;//A label or name for the signal, e.g. if you want to call the signal s t ( ) then the label will be ?¡ãs?¡À
	std::string v_fnm;//A filename template that will be used when saving signal info to a text file or saving signal plots to image files.
	std::string v_eqn;//Add another member variable from the string class that will be used to store the mathematical expression for the signal.
	std::vector<double> v_v_tme;//Add two member variables from the vector class that will store the signal samples and the time value for each sample.
	std::vector<double> v_v_sgn;//Add two member variables from the vector class that will store the signal samples and the time value for each sample.
	void f_construct();//Second-Half of Constructor
public:
	Signal(double nos, double frq, double itt);//Write a single constructor that sets these variables to values provided by input parameters
	Signal();//while also specifying default values of 101 samples, 100 samples / second, 0d an initial time of 0.
	void f_access(std::string selector, double& place);//Write accessor functions for the member variables
	void f_access(std::string selector, std::string& place);//Write accessor functions for the member variables
	void f_access(std::string selector, std::vector<double>& place);//Write accessor functions for the signal vector and time vector. 
	void f_access(std::string selector, double& place, unsigned int index);//Overload the accessor functions for the signal and time vectors
	void f_mutate(std::string selector, double valueToMutate);//Write mutator functions for the member variables
	void f_mutate(std::string selector, std::string label);//Write a mutator function for the label that:
	void f_write_txt();//Write a new member function for the class that writes information about a signal to a text
	void f_fill_tme();//Write a member function that fills the time array with linearly-spaced time samples
	void f_fill_sgn(double K);//Write a new member function for the class that creates a constant signal such as
	void f_fill_sgn(double A, double f0, double ph);//Write a member function that fills the signal vector with samples of a sinusoidal signal,
	std::string textNum(double x) const;//Copy the function shown below. Make it a member function of the signal class
	//void f_plot();//Write a member function for the signal class that generates a plot of the signal
	Signal operator= (Signal toCopy);//Overload the = operator by writing an operator function for the class
	void f_round();//Write a new member function for the class that rounds the values in the signal array by
	Signal operator+ (Signal toAdd);//Overload the + operator by writing an operator function for the class.
	Signal operator* (Signal toMul);//Overload the * operator by writing an operator function for the class. 
	void f_fill_sgn_exponential(double A, double tao);//Write a new member function for the signal class that fills the signal vector with values for
	void f_eqn_update();//Function to eliminate double signs expressions 
	void f_fill_sgn_timeVaring(double m, double b);// Write a new member function that fills the signal vector with
};

#endif
