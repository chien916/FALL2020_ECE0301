//A program file named ece0301_ICA09_step10.cpp that contains only a 
//preprocessor directive to include the class implementation file, and your main function.
#include"SortableArray.h"
#include"SortableArray.cpp"
int main() {//Write a main function that:
	ofstream ofs;//Defines an ofstream object, and uses it to open the output file.
	ofs.open("ece0301_merge_sort_results.txt");//  and uses it to open the output file.
	ifstream ifs;//Defines an ifstream object, 
	ifs.open("ece_0301_unsorted_array.txt");//and uses it to open the input file.
	SortableArray rand256(256);//Defines a sortable array object with 256 elements
	rand256.fillRand();//Fills the object with pseudo-random values between -1 and +1
	rand256.writeHeader(ofs,0);//Calls the file-writing function to write the original array to the output file, with the bool parameter set to false
	rand256.completeMerge();//Calls the member function that implements the complete merge sort algorithm.
	rand256.writeHeader(ofs,1);//Calls the file-writing function again to write the merged array to the output file, with the bool parameter set to true.
	ifs.close();//Closes the input file
	ofs.close();//Closes the output file
}








