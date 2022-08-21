#ifndef s_a_h
#define s_a_h
//A class specification file named SortableArray.h.This file must contain the
//class declaration, with prototypes and access specifiers for all members, and it must
//have an include guard.
#include<iostream>
#include<fstream>
#include<string>
#include<random>
using namespace std;
class SortableArray {
private:
	double* adr;
	unsigned int n;
public:
	SortableArray();
	SortableArray(unsigned int unsignedint);
	void destruct();
	double* accessAdr();
	unsigned int accessN();
	void fillZero();
	void writeHeader(ofstream& ofs, bool b);
private:
	void mergeArray(double* pre, double* post, unsigned int i_pre_left, unsigned int i_pre_mid, unsigned int i_pre_right);//Modify your merge function so that it can merge two sub-arrays that jointly comprise only a
	void splitArray(double* pre, double* post, unsigned int i_pre_sub_left, unsigned int i_pre_sub_right); //Modify your splitting function so that it implements all of the required steps :
public:
	void completeMerge(); 
	void fillRand();
};

#endif