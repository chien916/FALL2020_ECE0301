#include"Signal.cpp"
///////Source.cpp///////
int main() {//Write a main function
	double var_so[2] = { 0 };//Define variables for the sampling frequency, and initial time of a signal object.
	double var_wf[3] = { 0 };//Define variables for the amplitude, frequency, and phase of a sine wave.
	unsigned int nms_so = 0;//Define variables for the number of samples of signal objects
	nms_so = readSpft(var_so[0], var_so[1], var_wf[0], var_wf[1], var_wf[2]);//Call the file-reading function to set the values of all of the variables just defined
	Signal inst(nms_so, var_so[0], var_so[1]);//efine an instance of the signal class by calling the alternate constructor,
	inst.fillSignal(var_wf[0], var_wf[1], var_wf[2]);//Call the member function to fill the object with a sinusoidal signal
	inst.roundSignal();//it calls the new member function to round the signalvalues.
	inst.fnam_set("time_domain_signal_samples");//Set the filename template to ¡°time_domain_signal_samples¡±.
	inst.write();//Call the member function to write the signal to the text file.
	inst.plotSignal();// it calls the member function to draw a plot of the image to.eps and.png files
	return 1;
}