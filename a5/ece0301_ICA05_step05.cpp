#include <iostream>//initiate preprocessor from header files
#include <fstream>//initiate preprocessor from header files
#include <string>//initiate preprocessor from header files
#include <stdlib.h>//initiate preprocessor from header files
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
string writeMinterm(int pmt){//define function with parameters
    if(pmt>7||pmt<0){//set error check condition
        cout<<"ERROR! Invalid minterm index.";//output to terminal
        exit(1);//exit program when there's error
    }
    else{//normal condition
        int binRep[3]={0,0,0};//binary representation
        int tempIndex=2;//define new var
        while(pmt>0){//set condition for coverting dec to bin
            binRep[tempIndex]=pmt%2;//take modulus to get binary digit
            pmt=(pmt/2);//divide by two to get ready for the next round
            tempIndex--;//index -1
        }
        string toOutput="x'y'z'";//default output: with ' on all terms
        if(binRep[2]==1)//if z is 1
        toOutput.erase(toOutput.begin()+5);//delete ' on z
        if(binRep[1]==1)//if y is 1
        toOutput.erase(toOutput.begin()+3);//delete ' on y
        if(binRep[0]==1)//if x is 1
        toOutput.erase(toOutput.begin()+1);//delete ' on x
        return toOutput;//return calculated string back
    }
}
string writeMaxterm(int pmt){//define function with parameters
    if(pmt>7||pmt<0){//set error check condition
        cout<<"ERROR! Invalid minterm index.";//output to terminal
        exit(1);//exit program when there's error
    }
    else{//normal condition
        int binRep[3]={0,0,0};//binary representation
        int tempIndex=2;//define new var
        while(pmt>0){//set condition for coverting dec to bin
            binRep[tempIndex]=pmt%2;//take modulus to get binary digit
            pmt=(pmt/2);//divide by two to get ready for the next round
            tempIndex--;//index -1
        }
        string toOutput="x' + y' + z'";//default output: with ' on all terms
        if(binRep[2]==0)//if z is 0
        toOutput.erase(toOutput.begin()+11);//delete ' on z
        if(binRep[1]==0)//if y is 0
        toOutput.erase(toOutput.begin()+6);//delete ' on y
        if(binRep[0]==0)//if x is 0
        toOutput.erase(toOutput.begin()+1);//delete ' on x
        return toOutput;//return calculated string back
    }
}

int main(){//define main functiong
    cout<<"ECE 0301: Boolean Functions of 3 Variables.\nRealization in Canonical Forms.\n";//display text to terminal
    ofstream ofs;//define new ofstream object
    ifstream ifs;//define new ifstream object
    ofs.open("Bool_func_3var_CSOP_CPOS.txt");//open file for ofstream object
    ifs.open("Bool_func_3var.txt");//open file for ifstream object
    int parameterOfCircuit;//define new var
    ifs>>parameterOfCircuit;//read text from files
    ofs<<"ECE 0301: Boolean Functions of 3 Variables.\nRealization in Canonical Forms.\n";//display text to files
    ofs<<"\nm"<<parameterOfCircuit<<" = "<<writeMinterm(parameterOfCircuit);//display text into files
    ofs<<"\nM"<<parameterOfCircuit<<" = "<<writeMaxterm(parameterOfCircuit);//display text into files
    return 0;//return 0 for main if programs runs right
}