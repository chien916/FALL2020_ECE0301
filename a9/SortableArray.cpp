#ifndef s_a_cpp
#define s_a_cpp
#include "SortableArray.h"
//A class specification file named SortableArray.h. This file must contain the
//class declaration, with prototypes and access specifiers for all members, and it must
//have an include guard.
	SortableArray::SortableArray() {//A default constructor that:
		n = 10;//Sets the number of elements to 10
		adr = new double[10];//Allocates memory for an array of type double with 10 elements, and assigns it to the data array pointer
		fillZero();//Calls the member function to initialize all array elements to 0 (see below).
	}
	SortableArray::SortableArray(unsigned int unsignedint) {//Write a second constructor for your sortable array class that accepts a parameter of type u nsigned int.
		n = (int)unsignedint;//Sets the number of elements equal to the value of the parameter
		adr = new double[n];//Allocates memory for an array of type double with the proper number of elements, and assigns it to the data array pointer.
		fillZero();// Calls the member function to fill the array with zeros
	}
	void SortableArray::destruct() {//A destructor that de-allocates the memory that was previously allocated for the data array
		adr = nullptr;//de-allocates the memory that was previously allocated for the data array
	}
	double* SortableArray::accessAdr() {//An accessor function that 
		return adr;//returns the pointer to the data array
	}
	unsigned int SortableArray::accessN() {//An accessor function that 
		return n;//returns the number of elements in the array.
	}
	void SortableArray::fillZero() {//A member function that fills the data array with zeros.This function takes no parameters, and returns nothing.
		for (unsigned int i = 0; i < n; i++) {//A member function that fills the data array with zeros.
			*(adr + i) = 0;
		}
	}
	void SortableArray::writeHeader(ofstream& ofs, bool b) {//Modify your file-writing function so that it accepts a second parameter of type bool.
		if (b == 0) {//If this parameter is false
			ofs << "ECE 0301 - Sorting Arrays\n";// then the function must write two lines of text to the output file
			ofs << "Unsorted Array:\n";// then the function must write two lines of text to the output file

		}
		else if (b == 1) {//If the bool parameter is true, 
			ofs << "Sorted Array:\n";//this function writes one line of text to the output file,
		}
		for (unsigned int i = 0; i < n; i++) {//followed by the elements of the array in the calling object, one per line.
			ofs << *(adr + i) << endl;//Next, write the elements of the array from the calling object to the file, one per line
		}
	}
	void SortableArray::mergeArray(double* pre, double* post, unsigned int i_pre_left, unsigned int i_pre_mid, unsigned int i_pre_right) {//Modify your merge function so that it can merge two sub-arrays that jointly comprise only a
		double* black_l = pre + i_pre_left;//Initialize the black, gray, red, blue and green pointers.
		double* grey_r = pre + i_pre_mid;//Initialize the black, gray, red, blue and green pointers.
		double* red = pre + i_pre_mid;//Initialize the black, gray, red, blue and green pointers.
		double* blue = pre + i_pre_right;//Initialize the black, gray, red, blue and green pointers.
		double* green = post + i_pre_left;//Initialize the black, gray, red, blue and green pointers.
										  //Note that the behavior of the merge function will be no different here than that described in step 3. The only difference will be in the initialization of the pointers.
		while ((black_l < red) && (grey_r < blue)) {//As long as the black pointer is less than the red pointer, and the gray pointer is less than the blue pointer :
			if (*black_l < *grey_r) {//If the contents of the black pointer are less than the contents of the gray pointer,
				*green = *black_l;//set the contents of the green pointer equal to the contents of the black
				black_l++;//and increment the black pointer.
			}
			else {//Otherwise, 
				*green = *grey_r;//set the contents of the green pointer equal to the contents of the gray pointer,
				grey_r++; //and increment the gray pointer.
			}
			green++;//In either case, increment the green pointer.
		}//Go back to the top of this loop.
		 //At this point, one of the sub-arrays will be empty, but we’re not sure which one.
		while (black_l < red) {//As long as the black pointer is less than the red pointer:
			*green = *black_l;//Set the contents of the green pointer equal to the contents of the black pointer.
			black_l++;//Increment the black pointer and the green pointer
			green++;//Increment the black pointer and the green pointer
		}//Go back to the top of this loop.
		while (grey_r < blue) {//As long as the gray pointer is less than the blue pointer
			*green = *grey_r;//Set the contents of the green pointer equal to the contents of the gray pointer.
			grey_r++;//Increment the gray pointer and the green pointer
			green++;//Increment the gray pointer and the green pointer
		} //Go back to the top of this loop.

	}
	void SortableArray::splitArray(double* pre, double* post, unsigned int i_pre_sub_left, unsigned int i_pre_sub_right) {//Modify your splitting function so that it implements all of the required steps :
		unsigned int i_pre_mid;
		//If the second integer parameter is one more than the first integer parameter, do nothing
		if (!(i_pre_sub_left + 1 == i_pre_sub_right)) {//Otherwise,
			i_pre_mid = (i_pre_sub_right + i_pre_sub_left) / 2;//Compute the midpoint index of the array to be split, where the second sub-array
			splitArray(post, pre, i_pre_sub_left, i_pre_mid);//Recursively call the split function on the first half of the data array
			splitArray(post, pre, i_pre_mid, i_pre_sub_right);//Recursively call the split function on the second half of the data array,
			mergeArray(pre, post, i_pre_sub_left, i_pre_mid, i_pre_sub_right);//Call the merge function.
		}
	}
	void SortableArray::completeMerge() {
		double* adr_thisArray = adr;//Define a pointer to double, and assign to it the data array pointer for the calling
		SortableArray workingArray(n);//Define a new sortable array object that that has the same number of elements as the
		double* adr_workingArray = workingArray.accessAdr();//Define a pointer to double, and assign to it the data array pointer for the working array.
		for (int i = 0; i < n; i++) {
			*(adr_workingArray + i) = *(adr_thisArray + i);//Copy the data from the calling object to the working array. Use the two pointers that
		}
		splitArray(adr_workingArray, adr_thisArray, 0, n);//Call the split function. Pass the pointer to the working array as the pre-split pointer,
	}
	void SortableArray::fillRand() {
		//I choose not to use the rand() the old fashioned way :)
		//because there is this new implementation from <random>
		//from C++ 11 that is more efficient and safer than rand()
		//Although the codes are vastly different 
		//It will achieve the same goal as rand()
		random_device randomDevice;
		mt19937 mt19937_ins(randomDevice());
		uniform_real_distribution<double> dist(-1.000, 1.000);
		for (int i = 0; i < n; i++) {
			*(adr + i) = dist(mt19937_ins);
		}
	
};
#endif