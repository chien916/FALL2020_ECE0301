#include <iostream>//initiate preprocessor from header files
#include <fstream>//initiate preprocessor from header files
#include <string>//initiate preprocessor from header files
#include <tgmath.h>//initiate preprocessor from header files
using namespace std;//initiate the extension used by cin and cout
////I substituted bool type with int type for better recognition////
int gate_or(int a, int b, int c){//define function with parameters
    if(a==1||b==1||c==1)//set condition for or gate
        return 1;
    else
        return 0;
}
int gate_and(int a, int b, int c){//define function with parameters
    if(a==1&&b==1&&c==1)//set condition for and gate
        return 1;
    else
        return 0;
}

void writeGate(ofstream& ofs,int gate){//define function with parameters
    int res=-1;//define output var
    ofs<<"x\ty\tz\tf(x,y,z)\n--------------------------------\n";//output text to file
    for(int x=0;x<=1;++x){//iteration for x
        for(int y=0;y<=1;++y){//iteration for y
            for(int z=0;z<=1;++z){//iteration for z
                switch(gate){//and/or gate switcher
                    case 0://case for or gate
                        res=gate_or(x,y,z);//call function and receive return from function
                        break;//end of switch case
                    case 1://case for and gate
                        res=gate_and(x,y,z);//call function and receive return from function
                        break;//end of switch case
                }
                ofs<<x<<"\t"<<y<<"\t"<<z<<"\t"<<res<<"\n";//output text to file
                
            }
        }
    }
}


int main(){//define main function
    cout<<"ECE 0301: Boolean Functions of 3 Variables.\nRealization in Canonical Forms.\n";//display text to terminal
    ofstream ofs;//define new ofstream object
    ofs.open("Bool_func_3var_CSOP_CPOS.txt");//open file for ofstream object
    ofs<<"ECE 0301: Boolean Functions of 3 Variables.\nRealization in Canonical Forms.\n";//display text to files
    ofs<<"\nTruth table for OR gate.\n\n";//display text to files
    writeGate(ofs,0);//call function
    ofs<<"\nTruth table for AND gate.\n\n";//display text to files
    writeGate(ofs,1);//call function



    return 0;//return 0 for main if programs runs right
}