// This program demonstrates a simple class.
#include <iostream>//port in precessor
#include <cmath>//port in precessor to use atan2()
using namespace std;

// Rectangle class declaration.
class Rectangle
{
private:
	double width;
	double length;
public:
	void setWidth(double);
	void setLength(double);
	double getWidth() const;
	double getLength() const;
	double getArea() const;
};

class Cpl {//defines a class for a complex number
private://Your class must have private member variables 
	double real;//for the real and - parts of thecomplex number.
	double imag;//for the - and imaginary parts of thecomplex number.
public://It must also have public member functions as follows:
	int setCpl(double ireal, double iimag) {//Mutator functions that
		real = ireal;// set the real and - parts
		imag = iimag;// set the - and imaginary parts
		return 1;//return 1 if no error
	}
	double* getCpl() {//Accessor functions that return the real and imaginary parts
		static double realAndImag[2] = { 0 };//real,imag
		realAndImag[0] = real;
		realAndImag[1] = imag;
		return realAndImag;//returns POINTER of array real and imag
	}
	double* computeCpl() {//Accessor functions that compute and return the magnitude and phase angle. Use theatan2 function from the cmath library to compute the phase.
		static double magAndPha[2] = { 0 };//magnitude,phase angle
		magAndPha[0] = pow(pow(real, 2) + pow(imag, 2), 0.5);
		magAndPha[1] = atan2(imag , real);
		return magAndPha;//returns POINTER of array magnitude and phase angle
	}

};

//**************************************************
// setWidth assigns a value to the width member.   *
//**************************************************

void Rectangle::setWidth(double w)
{
	width = w;
}

//**************************************************
// setLength assigns a value to the length member. *
//**************************************************

void Rectangle::setLength(double len)
{
	length = len;
}

//**************************************************
// getWidth returns the value in the width member. *
//**************************************************

double Rectangle::getWidth() const
{
	return width;
}

//****************************************************
// getLength returns the value in the length member. *
//****************************************************

double Rectangle::getLength() const
{
	return length;
}

//*****************************************************
// getArea returns the product of width times length. *
//*****************************************************

double Rectangle::getArea() const
{
	return width * length;
}

//*****************************************************
// Function main                                      *
//*****************************************************

int main()
{
	/*Rectangle box;     // Define an instance of the Rectangle class
	double rectWidth;  // Local variable for width
	double rectLength; // Local variable for length

	// Get the rectangle's width and length from the user.
	cout << "This program will calculate the area of a\n";
	cout << "rectangle. What is the width? ";
	cin >> rectWidth;
	cout << "What is the length? ";
	cin >> rectLength;

	// Store the width and length of the rectangle
	// in the box object.
	box.setWidth(rectWidth);
	box.setLength(rectLength);

	// Display the rectangle's data.
	cout << "Here is the rectangle's data:\n";
	cout << "Width: " << box.getWidth() << endl;
	cout << "Length: " << box.getLength() << endl;
	cout << "Area: " << box.getArea() << endl;
	return 0;*/
	double realPart, imagPart;
	//Prompt the user with this message:
	cout << "This program will calculate the magnitude and phase" << endl;
	cout << "angle of a complex number." << endl << endl;
	cout << "What is the real part?" ;
	cin >> realPart;//Read user input from the keyboard.
					//Prompt the user with this message:
	cout << "What is the imaginary part?" ;
	cin >> imagPart;//Read user input from the keyboard.
	Cpl c1;
	c1.setCpl(realPart, imagPart);//Use the mutator functions to set the real and imaginary parts accordingly.

	double* realAndImagAdd = c1.getCpl();//Use the accessor functions to get the real and imaginary parts.
	double* magAndPhaAdd = c1.computeCpl();//Use the accessor functions to get the magnitude and phase angle.
										//Print messages to standard output to report information about the complex number.
	cout << "Here are the data on complex number z:" << endl;
	cout << "Real part: " << *realAndImagAdd << endl;
	cout << "Imaginary part: " << *(realAndImagAdd + 1) << endl;
	cout << "Magnitude: " << *magAndPhaAdd << endl;
	cout << "Phase angle (radians): " << *(magAndPhaAdd + 1) << endl;
	
}