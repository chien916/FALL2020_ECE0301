#include <iostream>//initiate preprocessor from header files
#include <iomanip>//initiate preprocessor from header files
#include <string>//initiate preprocessor from header files
#include <cmath>//initiate preprocessor from header files
using namespace std;//initiate the extension used by cin and cout
int runStep6(){//define run method
    const double CONST_PAI=3.141592653;//define Pi
    const int CONST_MAX=99999;//const max val for cin.ignore()
    double vct,cpl;//define vector and complex
    cin>>vct>>cpl;//user input
    cout<<setprecision(3)<<fixed<<"You entered "<<vct<<" and "<<cpl<<".\n";//display text with formatting
    cout<<"Are these numbers in Cartesian (C) or polar (p) coordinates?"<<endl
        <<"Please enter a single character as your choice.\n";
    string crd;//coordinates directives var
    cin.ignore(CONST_MAX,'\n');//clear buffer
    getline(cin,crd);//get the entire line and store it to cin
    if(crd=="c"||crd=="C"){//input check conditions
        cout<<"You entered Cartesian coordinates.\n";//display text
        double rds,tta;//define R and theta
        rds=pow((pow(vct,2)+pow(cpl,2)),0.5);//calc R
        //calc theta
        if(vct>=0){//test theta calc conditions
            tta=atan(cpl/vct);//calc theta from formula
        }
        else if(vct<0&&cpl>=0){
            tta=atan(cpl/vct)+CONST_PAI;//calc theta from formula
        }
        else if(vct<=0&&cpl<0){
            tta=atan(cpl/vct)-CONST_PAI;//calc theta from formula
        }
        else{
            cout<<"ERROR! Invalid polar coordinates, exiting.";//display text
            return -1;//return error as requested
        }
        cout<<"The equivalent polar coordinates are:\nR = "//display text
            <<rds<<", theta = "<<tta<<endl;

    }
    else if(crd=="P"||crd=="p"){
        cout<<"You entered polar coordinates.\n";//display text
        double xvl,yvl;//define x and y
        xvl=vct*cos(cpl);//calc x and y from formula
        yvl=vct*sin(cpl);//calc x and y from formula
        cout<<"The equivalent Cartesian coordinates are:\nx = "
        <<xvl<<", y = "<<yvl<<endl;
    }
    else{
        cout<<"ERROR! Invalid selection, exiting.\n";//display text
        return -1;//return error as requested
    }
return 0;//return 0 from main() if everything runs right
}
int main(){//define main method
    int returnFromRunStep6;//return value to return from main method
    cout<<"ECE 0301 – Vectors in R2 and Complex Numbers"<<endl//display text
        <<"Please enter two numbers, separated by a space,"<<endl//display text
        <<"that will represent a vector or a complex number.\n"<<endl;//display text
    returnFromRunStep6=runStep6();//Run Program for the 1st time and return value if needed
    cout<<"Please enter another pair of numbers, separated by a\n"//display text
        <<"space, to represent a second vector or complex number.\n\n";//display text
    returnFromRunStep6=runStep6();//Run Program for the 2nd time and return value if needed
    return returnFromRunStep6;//return 0 if no error, -1 if interrupted
    
}