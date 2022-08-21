///////Signal.h///////
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <memory>
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
	void fillSignal(double,double,double);//Write a member function that fills the signal array with samples of a sinusoidal signal
	void roundSignal();//Write a new member function for the class that rounds the values in the signal array by
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
Signal::Signal(unsigned int a,double b,double c) {//Overload the constructor by writing a second constructor that accepts parameters for the
	nosp = a;//set the member variables equal to the values of the parameters
	freq = b;//set the member variables equal to the values of the parameters
	intt = c;//set the member variables equal to the values of the parameters
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
void Signal::fillSignal(double A,double f0,double phi) {
	for(int i = 0; i < nosp; i++) {
		double t = *(timp + i);
		*(sgnp + i) = A*cos(2 * 3.1415926*f0*t + phi);
	}
}
bool readSpft_extract(const std::string& in,double& numout,const std::string& toCheckWith) {//Custom Function to extract number, check validity at the same time
	std::string temp=in;
	int indexOfColon = temp.find(":");
	if (indexOfColon == -1) {
		return 0;
	}
	std::string number, title;
	title = temp.substr(0,indexOfColon + 2);
	number = temp.substr(indexOfColon + 2,temp.size());
	if (title == toCheckWith) {
		numout = stod(number);
		return 1;
	}
	else {
		return 0;
	}
}
unsigned int readSpft(double& so_f0,double& so_t0,double& wf_A,double& wf_f,double& wf_phi) {//Write a function that is outside the definition of your signal class that reads the
	std::ifstream ifs;
	ifs.open("sine_wave_specification.txt");
	std::string* title = new std::string[6];//malloc(string)
	unsigned int titleIndexTemp = 0;//reset index iterator
	*(title + (titleIndexTemp++)) = "Number of samples: ";
	*(title + (titleIndexTemp++)) = "Sampling frequency: ";
	*(title + (titleIndexTemp++)) = "Initial time: ";
	*(title + (titleIndexTemp++)) = "Amplitude: ";
	*(title + (titleIndexTemp++)) = "Frequency: ";
	*(title + (titleIndexTemp++)) = "Phase: ";
	double num_sample;//store it in a local variable to represent the number of samples.
	double* paramAdr[6] = {&num_sample,&so_f0,&so_t0,&wf_A,&wf_f,&wf_phi};
	for (titleIndexTemp = 0; titleIndexTemp < 6; titleIndexTemp++) {//Repeat this procedure 
		std::string lineReceived;
		std::getline(ifs, lineReceived); //Read the line from the file
		bool validity = readSpft_extract(lineReceived, *(paramAdr[titleIndexTemp]), *(title + titleIndexTemp));//performing input validation each time
		if (validity == 0) {//If this line does not begin with
			std::cout << "ERROR! Invalid input file header.";//print the following error message to standard output,
			std::getchar();
			std::exit(2);//and exit the program with the failure termination code 
		}
	}
	ifs.close();//Close the input file.
	unsigned int toReturn = (unsigned int)(*(paramAdr[0]));
	delete[] title;//free consecutive memorys used in title
	return toReturn; //Return the number of samples.
}
void Signal::roundSignal() {//Write a new member function for the class that rounds the values in the signal array by
	for (int i = 0; i < nosp; i++) {// It simply loops through the elements in the signal array
		*(sgnp + i) = round(*(sgnp + i));//calls the round function, and stores the rounded value back in the same element of the signal array.
	}
}
///////Source.cpp///////
int main() {//Write a main function
	double var_so[2] = { 0 };//Define variables for the sampling frequency, and initial time of a signal object.
	double var_wf[3] = { 0 };//Define variables for the amplitude, frequency, and phase of a sine wave.
	unsigned int nms_so = 0;//Define variables for the number of samples of signal objects
	nms_so = readSpft(var_so[0], var_so[1], var_wf[0], var_wf[1], var_wf[2]);//Call the file-reading function to set the values of all of the variables just defined
	Signal inst(nms_so, var_so[0], var_so[1]);//efine an instance of the signal class by calling the alternate constructor,
	inst.fillSignal(var_wf[0], var_wf[1], var_wf[2]);//Call the member function to fill the object with a sinusoidal signal
	inst.roundSignal();//it calls the new member function to round the signalvalues.
	inst.fnam_set("time_domain_signal_samples");//Set the filename template to “time_domain_signal_samples”.
	inst.write();//Call the member function to write the signal to the text file.
	std::getchar();
	//return 1;
}