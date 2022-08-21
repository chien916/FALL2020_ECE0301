#pragma once
#ifndef check_signalcpp
#define check_signalcpp
#include "Signal.h"
void errorExit(int errCode) {//Custom Error Exit Enterance
	std::cout << "\nEXIT CODE:" << errCode;
	std::getchar();
	std::exit(errCode);
}
Signal::Signal(double nos, double frq, double itt) {//Write a single constructor that sets these variables to values provided by input parameters
	v_nos = nos;
	v_frq = frq;
	v_itt = itt;
	f_construct();
}
Signal::Signal() {//while also specifying default values of 101 samples, 100 samples/second, nd an initial time of 0.
	v_nos = 101;
	v_frq = 100; 
	v_itt = 0;
	f_construct();
}
void Signal::f_construct() {//Second half of Constructor
	f_mutate("lbl", "x");//Add a line of code to the constructor that calls the mutator function for the label with the input string ?¡ãx?¡À.
	f_mutate("eqn", "0");//Calls the member function from the Signal class to set the mathematical expression
	std::vector<double> tempVectorWithAllZero(v_nos, 0.0);
	v_v_tme = tempVectorWithAllZero;
	v_v_sgn = tempVectorWithAllZero;
	f_fill_tme();//Calls the member function from the Signal class to fill the time vector with
	f_eqn_update();//modify equation string to get rid of double expressions
}
void Signal::f_access(std::string selector, double& place) {////Write mutator functions for the member variables
	if (selector == "nos")
		place = v_nos;
	else if (selector == "frq")
		place = v_frq;
	else if (selector == "itt")
		place = v_itt;
	else {
		errorExit(10);
	}
}
void Signal::f_access(std::string selector, std::string& place) {
	if (selector == "lbl")
		place = v_lbl;
	else if (selector == "fnm")
		place = v_fnm;
	else if (selector == "eqn")
		place = v_eqn;//Write mutator and accessor functions for the mathematical expression string.
	else {
		errorExit(11);
	}
}
void Signal::f_access(std::string selector, std::vector<double>& place) {//Write accessor functions for the signal vector and time vector
	if (selector == "tme")
		place = v_v_tme;
	else if (selector == "sgn")
		place = v_v_sgn;
	else {
		errorExit(14);
	}
}
void Signal::f_access(std::string selector, double& place, unsigned int index) {//Overload the accessor functions for the signal and time vectors
	if (selector == "tme")
		place = v_v_tme.at(index);
	else if (selector == "sgn")
		place = v_v_sgn.at(index);
	else {
		errorExit(15);
	}
}
void Signal::f_mutate(std::string selector, double valueToMutate) {//double f_mutate(std::string selector, double valueToMutate);//Write mutator functions for the member variables
	if (selector == "nos")
		v_nos = valueToMutate;
	else if (selector == "frq")
		v_frq = valueToMutate;
	else if (selector == "itt")
		v_itt = valueToMutate;
	else
		errorExit(12);
	f_eqn_update();//modify equation string to get rid of double expressions
}
void Signal::f_mutate(std::string selector, std::string label) {//Write a mutator function for the label that:
	if (selector == "lbl") {
		v_lbl = label;//Accepts a string parameter, and sets the label to this string
		v_fnm = "diff_eqn_soln_" + v_lbl;//Sets the filename template to ?¡ãsignal_?¡À with the label appended. 
	}
	else if (selector == "eqn") {
		v_eqn = label;//Write mutator and accessor functions for the mathematical expression string.
	}
	else {
		errorExit(13);
	}
	f_eqn_update();//modify equation string to get rid of double expressions
}
void Signal::f_write_txt() {//Write a new member function for the class that writes information about a signal to a text
	std::ofstream ofs;
	ofs.open(v_fnm + ".txt");
	ofs << "Time-Domain Signal Samples" << std::endl
		<< "N = " << v_nos << std::endl
		<< "fs = " << v_frq << std::endl
		<< "t0 = " << v_itt << std::endl
		<< "Signal label: " << v_lbl << std::endl
		<< "Mathematical expression" << std::endl
		<< v_lbl << "(t) = " << v_eqn << std::endl
		<< "Time and signal samples in .csv format" << std::endl
		<< "t, " << v_lbl << "(t)" << std::endl
		<< "-------" << std::endl;
	for (unsigned int i = 0; i < v_nos; i++) {
		ofs << v_v_tme.at(i) << ", " << v_v_sgn.at(i) << std::endl;
	}
}
void Signal::f_fill_tme() {//Write a member function that fills the time array with linearly-spaced time samples
	for (unsigned int i = 0; i < v_nos; i++) {//The number of time samples written must be equal to the value stored in the member variable
		v_v_tme.at(i) = v_itt + i / v_frq;
	}
	f_eqn_update();//modify equation string to get rid of double expressions
}
void Signal::f_fill_sgn(double K) {//Write a new member function for the class that creates a constant signal such as
	for (unsigned int i = 0; i < v_nos; i++) {//The number of time samples written must be equal to the value stored in the member variable
		v_v_sgn.at(i) = K;//writes the value of the parameter to all elements of the signal vector
	}
	v_eqn = textNum(K);//sets the mathematical expression to the value of the parameter, converted to a string
	f_eqn_update();//modify equation string to get rid of double expressions
}
void Signal::f_fill_sgn(double A, double f0, double ph) {//Write a member function that fills the signal vector with samples of a sinusoidal signal
	for (unsigned int i = 0; i < v_nos; i++) {//The number of time samples written must be equal to the value stored in the member variable
		v_v_sgn.at(i) = A*cos(2 * 3.14159*f0*v_v_tme.at(i) + ph);//writes the value of the parameter to all elements of the signal vector
	}
	if (ph >= 0)
		v_eqn = textNum(A) + "cos(" + textNum(f0) + "t" + "+" + textNum(ph) + ")";
	else
		v_eqn = textNum(A) + "cos(" + textNum(f0) + "t" + textNum(ph) + ")";
	f_eqn_update();//modify equation string to get rid of double expressions
}
std::string Signal::textNum(double x) const//Copy the function shown below. Make it a member function of the signal class
{

	if (x >= 100)
		// large numbers truncated as int -> string
		return std::to_string(int(x));
	else
	{
		// small numbers will get 3 digits
		std::string x_exp = std::to_string(x);
		// return 4 characters, or 5 if x<0
		return x_exp.substr(0, 4 + (x<0));
	}
}
/*
void Signal::f_plot() {//Write a member function for the signal class that generates a plot of the signal, and stores it
mglData axis_time_vals(v_nos), axis_signal_vals(v_nos);//Define two objects from the mglData class, for storing the time and signal samples.
for (unsigned int i = 0; i<v_nos; i++) {
axis_signal_vals.a[i] = v_v_sgn.at(i);//Copy the time and signal arrays into the mglData objects using the mglData
axis_time_vals.a[i] = v_v_tme.at(i);//Copy the time and signal arrays into the mglData objects using the mglData
}
mglGraph mglg;// Create a mglGraph object.
mglg.Title((v_lbl + "(t)").c_str());//Give the object a title, by using the Title member function.
double tmin, tmax,smin,smax;
tmin = 999;
tmax = -999;
smin = 999;
smax = -999;
for (unsigned int i = 0; i < v_nos; i++) {//obtain tmin tmax smin smax for setting ranges uses
double ttemp,stemp;
ttemp = v_v_tme.at(i);//Search the mglData object that holds the signal samples for the maximum absolute
stemp = v_v_sgn.at(i);
if (ttemp > tmax)
tmax = ttemp;
if (ttemp < tmin)
tmin = ttemp;
if (stemp > smax)
smax = stemp;
if (stemp < smin)
smin = stemp;
}
if (smin < smax) {
mglg.SetRanges(tmin, tmax, -smax,smax);//Use the time axis limits and the maximum absolute signal value to set the axis ranges
mglg.SetOrigin(0, 0);//Set the origin for the plot to (0,0), by using the SetOrigin member function.
}
else {
mglg.SetRanges(tmin, tmax, smin - 5, smax + 5);//Use the time axis limits and the maximum absolute signal value to set the axis ranges
mglg.SetOrigin(0, 0);//Set the origin for the plot to (0,0), by using the SetOrigin member function.
smax = smax + 5.2;
}


mglg.Axis();//Create an axis, by using the Axis member function
//if((smax + smax*0.2)>=1)
mglg.Puts(mglPoint(-(tmax*0.07),0), "y(t)");//Label both axes, by using the Puts member function
//else
//mglg.Puts(mglPoint(0, 1.2), "y(t)");//Label both axes, by using the Puts member function
mglg.Puts(mglPoint(tmax + tmax*0.1, 0), "t");//Label both axes, by using the Puts member function
mglg.Plot(axis_time_vals, axis_signal_vals);//Draw the plot in memory, by using the Plot member function.
const char* fnam_c_eps = new char[v_fnm.size() + 5];
const char* fnam_c_png = new char[v_fnm.size() + 5];
std::string fnam_cpp_eps = v_fnm + ".eps";
std::string fnam_cpp_png = v_fnm + ".png";
fnam_c_eps = fnam_cpp_eps.c_str();//converting the strings to C-strings by using the c_str() member function from the
fnam_c_png = fnam_cpp_png.c_str();//converting the strings to C-strings by using the c_str() member function from the
mglg.WriteEPS(fnam_c_eps);//Save the plot to .eps and .eps image files,
mglg.WritePNG(fnam_c_png);//Save the plot to .eps and .png image files,
}
*/


Signal Signal::operator= (Signal toCopy) {//Overload the = operator by writing an operator function for the class
	if (this == &toCopy) {//Test for self reference
		errorExit(20);
	}
	v_nos = toCopy.v_nos;//copy all of the member variables from the input object to thecalling object
	v_frq = toCopy.v_frq;//copy all of the member variables from the input object to thecalling object
	v_itt = toCopy.v_itt;//copy all of the member variables from the input object to thecalling object
	v_eqn = toCopy.v_eqn;//copy all of the member variables from the input object to thecalling object
	v_v_tme = toCopy.v_v_tme;//copy all of the member variables from the input object to thecalling object
	v_v_sgn = toCopy.v_v_sgn;//copy all of the member variables from the input object to thecalling object
	f_eqn_update();//modify equation string to get rid of double expressions
	return *this;

}
void Signal::f_round() {//Write a new member function for the class that rounds the values in the signal array by
	for (unsigned int i = 0; i < v_nos; i++) {// It simply loops through the elements in the signal array
		v_v_sgn.at(i) = round(v_v_sgn.at(i));//calls the round function, and stores the rounded value back in the same element of the signal array.
	}
	f_eqn_update();//modify equation string to get rid of double expressions
}
Signal Signal::operator+ (Signal toAdd) {//Overload the + operator by writing an operator function for the class.
	double conditionCheck = 0;
	conditionCheck += std::abs(int(v_v_tme.size() - toAdd.v_v_tme.size()));
	conditionCheck += std::abs(int(v_v_sgn.size() - toAdd.v_v_sgn.size()));
	conditionCheck += std::abs(double(v_itt - toAdd.v_itt));
	conditionCheck += std::abs(double(v_frq - toAdd.v_frq));
	if (conditionCheck != 0) {//If the input signal and calling signal dont have the same number of samples, sampling frequency and initial time
		std::cout << "ERROR! Attempt to add incompatible signals.";//Otherwise, this function must print the following message to standard output:
		errorExit(30);//and exit with a failure code.
	}
	else {//If the input signal and calling signal have the same number ofsamples, sampling frequency and initial time
		for (int i = 0; i < v_nos; i++) {
			v_v_sgn.at(i) = v_v_sgn.at(i) + toAdd.v_v_sgn.at(i);//and the time vector that is returned must be equal to the time vector for the calling signal.
		}
		std::string new_v_eqn;
		bool ifneg = f_ifNegative(toAdd, new_v_eqn);
		
		if (ifneg == 1) {
			v_eqn = v_eqn + " - " + new_v_eqn;
		}
		else {
			v_eqn = v_eqn + " + " + toAdd.v_eqn;//This function must also form the mathematical expression string for the returned signal
		}
		//v_eqn = v_eqn + " + " + toAdd.v_eqn;//This function must also form the mathematical expression string for the returned signal
	
	}
	f_eqn_update();//modify equation string to get rid of double expressions
	return *this;
}
Signal Signal::operator* (Signal toMul) {//Overload the * operator by writing an operator function for the class
	double conditionCheck = 0;
	conditionCheck += std::abs(int(v_v_tme.size() - toMul.v_v_tme.size()));
	conditionCheck += std::abs(int(v_v_sgn.size() - toMul.v_v_sgn.size()));
	conditionCheck += std::abs(double(v_itt - toMul.v_itt)); 
	conditionCheck += std::abs(double(v_frq - toMul.v_frq)); 
	if (conditionCheck != 0) {//If the input signal and calling signal dont have the same number of samples, sampling frequency and initial time
		std::cout << "ERROR! Attempt to add incompatible signals.";//Otherwise, this function must print the following message to standard output:
		errorExit(40);//and exit with a failure code.
	}
	else {//If the input signal and calling signal have the same number ofsamples, sampling frequency and initial time
		for (int i = 0; i < v_nos; i++) {
			v_v_sgn.at(i) = v_v_sgn.at(i) * toMul.v_v_sgn.at(i);//and the time vector that is returned must be equal to the time vector for the calling signal.
		}
		v_eqn = "(" + v_eqn + ")(" + toMul.v_eqn + ")";
	}
	f_eqn_update();//modify equation string to get rid of double expressions
	return *this;
}
void Signal::f_fill_sgn_exponential(double A, double tao) {//Write a new member function for the signal class that fills the signal vector with values for
	for (unsigned int i = 0; i < v_nos; i++) {//The number of time samples written must be equal to the value stored in the member variable
		v_v_sgn.at(i) = (A*exp(-(v_v_tme.at(i)-v_itt)/tao));//writes the value of the parameter to all elements of the signal vector
		//v_v_sgn.at(i) = std::round(A*exp(-(v_v_tme.at(i)-v_itt)/tao));//writes the value of the parameter to all elements of the signal vector
	}//Add a statement to the end of this function that rounds the solution signal values to the nearest integer.
	std::string sign1 = "-";
	std::string sign2 = "";
	if (v_itt < 0) {
		sign1 = "+";
	}
	if (tao < 0) {
		sign2 = "- ";
	}
	if (tao == 1) {
		v_eqn = textNum(A) + " exp( -(t " + sign1 + " " + textNum(std::abs(v_itt)) + ") )";
	}
	else {
		v_eqn = textNum(A) + " exp( -(t " + sign1 + " " + textNum(std::abs(v_itt)) + ") / " + sign2 + textNum(std::abs(tao)) + " )";
	}
	
	f_eqn_update();//modify equation string to get rid of double expressions
}
void Signal::f_fill_sgn_timeVaring(double m,double b) {//where m is the slope and b is the value of the signal a
	for (unsigned int i = 0; i < v_nos; i++) {
		v_v_sgn.at(i) = m*(v_v_tme.at(i) - v_itt) + b;//signal that varies linearly with time according to
	}
	std::string sign1, sign2;
	sign1 = "-";
	sign2 = "+";
	if (v_itt < 0) {
		sign1 = "+";
	}
	if (b < 0) {
		sign2 = "-";
	}
	if (v_itt == 0&&b==0) {
		v_eqn = textNum(m) + " t "+ " " ;
	}
	else if (v_itt == 0) {
		v_eqn = textNum(m) + " t "+ " " + sign2 + " " + textNum(std::abs(b));
	}
	else if (b == 0) {
		v_eqn = textNum(m) + " (t " + sign1 + " " + textNum(std::abs(v_itt)) + ") " ;
	}
	else {
		v_eqn = textNum(m) + " (t " + sign1 + " " + textNum(std::abs(v_itt)) + ") " + sign2 + " " + textNum(std::abs(b));
	}
	
	f_eqn_update();//modify equation string to get rid of double expressions
}
void Signal::f_fill_sgn_sinusoid(double A, double f0, double ph) {
	for (unsigned int i = 0; i < v_nos; i++) {//The number of time samples written must be equal to the value stored in the member variable
		v_v_sgn.at(i) = A*cos(f0*(v_v_tme.at(i)- v_itt) + ph);//writes the value of the parameter to all elements of the signal vector
	}
	std::string sign1, sign2;
	sign1 = "-";
	sign2 = "+";
	if(v_itt < 0)
		sign1 = "+";
	if (ph < 0)
		sign2 = "-";
	if (ph==0) {
		v_eqn = textNum((A)) + " cos( " + textNum(std::abs(f0)) + " (t " + sign1 + " " + textNum(std::abs(v_itt)) + ")  " + ")";
	}
	else if (v_itt == 0) {
		v_eqn = textNum((A)) + " cos( " + textNum(std::abs(f0)) + " t "+ "  " + sign2 + " " + textNum(std::abs(ph)) + ")";
	}
	else {
		v_eqn = textNum((A)) + " cos( " + textNum(std::abs(f0)) + " (t " + sign1 + " " + textNum(std::abs(v_itt)) + ") " + sign2 + " " + textNum(std::abs(ph)) + " )";
	}
	
	f_eqn_update();//modify equation string to get rid of double expressions
}
void Signal::f_eqn_update() {
	/*
	std::string equation = v_eqn;
	int index_temp = 0; 
	while (index_temp != -1) {
		index_temp = equation.find("- -");
		if (index_temp != -1) {
			equation.replace(index_temp, 3, "+ ");
		}
	}
	bool NoRedun = 0;
	while (NoRedun != 1) {
		int index_temp1 = equation.find("- 0.00");
		int index_temp2 =  equation.find("+ 0.00");
		int index_temp3 =  equation.find("* 1.00");
		int index_temp4 = equation.find("/ 1.00");
		NoRedun = ((index_temp1 + index_temp2 + index_temp3 + index_temp4) == -4);
		if (index_temp1 != -1) {
			equation.replace(index_temp1, 6, "");
			if (equation.substr(index_temp1, 1) == ")") {
				equation.replace(index_temp1, 2, "");
				std::size_t temppar = equation.rfind("(");
				if (temppar != std::string::npos)
					equation.replace(temppar, 1, "");
			}
			else if (equation.substr(index_temp1, 1) == " ") {
				equation.replace(index_temp1, 1, "");
			}
		}
		else if (index_temp2 != -1) {
			equation.replace(index_temp2, 6, "");
			if (equation.substr(index_temp2, 1) == ")") {
				equation.replace(index_temp2, 2, "");
				std::size_t temppar = equation.rfind("(");
				if (temppar != std::string::npos)
					equation.replace(temppar, 1, "");
			}
			else if (equation.substr(index_temp2, 1) == " ") {
				equation.replace(index_temp1, 1, "");
			}
		}
		else if (index_temp3 != -1) {
			equation.replace(index_temp3, 6, "");
			if (equation.substr(index_temp3, 1) == ")") {
				equation.replace(index_temp3, 2, "");
				std::size_t temppar = equation.rfind("(");
				if (temppar != std::string::npos)
					equation.replace(temppar, 1, "");
			}
			else if (equation.substr(index_temp3, 1) == " ") {
				equation.replace(index_temp3, 1, "");
			}
		}
		else if (index_temp4 != -1) {
			equation.replace(index_temp4, 6, "");
			if (equation.substr(index_temp4, 1) == ")") {
				equation.replace(index_temp4, 2, "");
				std::size_t temppar = equation.rfind("(");
				if (temppar != std::string::npos)
					equation.replace(temppar, 1, "");
			}
			else if (equation.substr(index_temp4, 1) == " ") {
				equation.replace(index_temp4, 1, "");
			}
		}
	}
	/*
	index_temp = 0;
	while (index_temp !=- 1) {
		index_temp = equation.find("+-");
		if (index_temp != -1) {
			equation.replace(index_temp, 2, "- ");
		}
		index_temp = equation.find("+-");
	}
	index_temp = 0;
	while (index_temp != -1) {
		index_temp = equation.find("-+");
		if (index_temp != -1) {
			equation.replace(index_temp, 3, "- ");
		}
		index_temp = equation.find("-+");
	}
	index_temp = 0;
	while (index_temp != -1) {
		index_temp = equation.find("( t )");
		if (index_temp != -1) {
			equation.replace(index_temp, 5, " t ");
		}
		index_temp = equation.find("( t )");
	}
	//v_v_sgn.at(i) = std::round(A*exp(-(v_v_tme.at(i)-v_itt)/tao));//writes the value of the parameter to all elements of the signal vector
	
	
	v_eqn = equation; */
}
bool Signal::f_ifNegative(Signal ain,std::string& out) {
	ain.f_access("eqn", out);
	if (out.at(0) == '-') {
		out=out.substr(1);
		return true;
	}
	else {
		return false;
	}
}

#endif