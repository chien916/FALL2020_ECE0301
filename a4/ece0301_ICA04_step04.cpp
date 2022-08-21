#include <iostream>//initiate preprocessor from header files
#include <fstream>//initiate preprocessor from header files
#include <string>//initiate preprocessor from header files
using namespace std;//initiate the extension used by cin and cout
int main(){//declaire main func
    string temp;//declare new string
    cout<<"ECE 0301: Circuit Solver for Voltage Divider"//print text
        <<"and Wheatstone bridge example circuits.\n";//print text
    ifstream ifs;//declare new ifstream object
    ifs.open("divider_wheatstone_circuits.txt");//print text
    ifs>>temp;//extract text from txt
    if(temp!="Divider"&&temp!="Wheatstone"){//print text
        cout<<"ERROR! Invalid header.";//print text
        return -1;//print -1 to terminal as error condition
    }
    else if(temp=="Divider"){//set condition
        int r1,r2;//declare new var
        double vs;//declare new var
        ifs>>vs>>r1>>r2;//extract text from txt 4 times
        ofstream ofs;//declare new ofstream object
        ofs.open("divider_wheatstone_solutions.txt");//inject text into txt
        ofs <<"ECE 0301: Circuit Solver for Voltage Divider\n"
            <<"and Wheatstone bridge example circuits.\n"
            <<"-----\n"
            <<"Circuit #1 (Voltage Divider)\n"
            <<"---\n";
        //step4
        double i,v1,v2;//declare new var
        i=vs/(r1+r2);//calculate mathmatical value from the given formula
        v1=vs*r1/(r1+r2);//calculate mathmatical value from the given formula
        v2=vs*r2/(r1+r2);//calculate mathmatical value from the given formula
        ofs <<"Source voltage: Vs = "<<vs <<" Volts.\n"//inject text into txt
            <<"Resistor: R1 = "<<r1 <<" Ohms.\n"
            <<"Resistor: R2 = "<<r2 <<" Ohms.\n\n"
            <<"Loop current: I = "<<i <<" Amperes.\n"
            <<"Resistor voltage: V1 = "<<v1 <<" Volts.\n"
            <<"Resistor voltage: V2 = "<<v2 <<" Volts.\n";

    }
return 0;//return 0 to terminal if program runs right
}