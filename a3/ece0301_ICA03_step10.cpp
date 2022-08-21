#include <iostream>//initiate preprocessor from header files
#include <iomanip>//initiate preprocessor from header files
#include <string>//initiate preprocessor from header files
#include <cmath>//initiate preprocessor from header files
using namespace std;//initiate the extension used by cin and cout
double memoryRtn[9]={8888,8888,8888,8888,8888,8888,8888,8888,0};//cartesian1,polar1,cartesian2,polar2--memory buffer--last digit:iteration temp var
const double CONST_PAI=3.141592653;//define Pi
    const int CONST_MAX=99999;//const max val for cin.ignore()
int runStep6(){//define run method
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
        memoryRtn[(0+(int)(memoryRtn[8]))]=vct;//set memory var
        memoryRtn[(1+(int)(memoryRtn[8]))]=cpl;//set memory var
        memoryRtn[(2+(int)(memoryRtn[8]))]=rds;//set memory var
        memoryRtn[(3+(int)(memoryRtn[8]))]=tta;//set memory var
        memoryRtn[8]+=4;//iteration++
    }
    else if(crd=="P"||crd=="p"){
        cout<<"You entered polar coordinates.\n";//display text
        double xvl,yvl;//define x and y
        xvl=vct*cos(cpl);//calc x and y from formula
        yvl=vct*sin(cpl);//calc x and y from formula
        cout<<"The equivalent Cartesian coordinates are:\nx = "
        <<xvl<<", y = "<<yvl<<endl;
        memoryRtn[(2+(int)(memoryRtn[8]))]=vct;//set memory var
        memoryRtn[(3+(int)(memoryRtn[8]))]=cpl;//set memory var
        memoryRtn[(0+(int)(memoryRtn[8]))]=xvl;//set memory var
        memoryRtn[(1+(int)(memoryRtn[8]))]=yvl;//set memory var
        memoryRtn[8]+=4;//iteration++
    }
    else{
        cout<<"ERROR! Invalid selection, exiting.\n";//display text
        return -1;//return error as requested
    }
return 0;//return 0 from main() if everything runs right
}
void print4eqn(string ltr){//print 4 eqns based on ltr input from main()
    cout<<"Which of the following sums or differences"
        <<"\nwould you like to compute?\n"
        <<"(1) "<<ltr<<"1 + "<<ltr<<"2"<<endl
        <<"(2) "<<ltr<<"1 - "<<ltr<<"2"<<endl
        <<"(3) "<<ltr<<"2 - "<<ltr<<"1"<<endl
        <<"(4) -"<<ltr<<"1 - "<<ltr<<"2"<<endl<<endl;

}
int main(){//define main method
    int returnFromRunStep6;//return value to return from main method
    cout<<"ECE 0301 – Vectors in R2 and Complex Numbers"<<endl//display text
        <<"Please enter two numbers, separated by a space,"<<endl//display text
        <<"that will represent a vector or a complex number.\n"<<endl;//display text
    returnFromRunStep6=runStep6();//Run Program for the 1st time and return value if needed
        if(returnFromRunStep6==-1){
        return -1;//return -1 if runStep6() was interrupted
    }
    cout<<"Please enter another pair of numbers, separated by a\n"//display text
        <<"space, to represent a second vector or complex number.\n\n";//display text
    returnFromRunStep6=runStep6();//Run Program for the 1st time and return value if needed
    if(returnFromRunStep6==-1){
        return -1;//return -1 if runStep6() was interrupted
    }
    cout<<"\nDo the values you entered represent vectors (v) or complex numbers (c)?\n"//display text
        <<"Please enter a single character as your choice.\n";
    string voc;//char identifier for knowing input
    cin>>voc;//standard input
    string opt;//z or v based on complex or vector
    if(voc=="v"||voc=="V"){
        cout<<"Cartesian:       v1 = ("<<memoryRtn[0]<<", "<<memoryRtn[1]<<")\n";
        cout<<"Polar:           v1 = ("<<memoryRtn[2]<<", "<<memoryRtn[3]<<")\n\n";
        cout<<"Cartesian:       v2 = ("<<memoryRtn[4]<<", "<<memoryRtn[5]<<")\n";
        cout<<"Polar:           v2 = ("<<memoryRtn[6]<<", "<<memoryRtn[7]<<")\n\n";
        opt="v";
        print4eqn(opt);//initiate custom function
    }
    else if(voc=="c"||voc=="C"){
        cout<<"Cartesian:       z1 = "<<memoryRtn[0]<<" + j "<<memoryRtn[1]<<"\n";
        cout<<"Polar:           z1 = "<<memoryRtn[2]<<" exp(j "<<memoryRtn[3]<<")\n\n";
        cout<<"Cartesian:       z2 = "<<memoryRtn[4]<<" + j "<<memoryRtn[5]<<"\n";
        cout<<"Polar:           z2 = "<<memoryRtn[6]<<" exp(j "<<memoryRtn[7]<<")\n\n";
        opt="z";
        print4eqn(opt);//initiate custom function
    }
    else{
        cout<<"ERROR! Invalid selection, exiting.\n";//display text
        return -1;//return error   
    }
    int ceq;//char identifier for inputting 1-4
    cin>>ceq;//standard input
    double sel[4];//define Summed Element double type array
    switch(ceq){//define switch conditional
        case 1://z1+z2
        sel[0]=memoryRtn[0]+memoryRtn[4];//perform calc from formula given
        sel[1]=memoryRtn[1]+memoryRtn[5];//perform calc from formula given
        //sel[2]=memoryRtn[2]+memoryRtn[6];//perform calc from formula given
        //sel[3]=memoryRtn[3]+memoryRtn[7];//perform calc from formula given
        break;
        case 2://z1-z2
        sel[0]=memoryRtn[0]-memoryRtn[4];//perform calc from formula given
        sel[1]=memoryRtn[1]-memoryRtn[5];//perform calc from formula given
        //sel[2]=memoryRtn[2]-memoryRtn[6];//perform calc from formula given
        //sel[3]=memoryRtn[3]-memoryRtn[7];//perform calc from formula given
        break;
        case 3://z2-z1=-z1+z2
        sel[0]=-memoryRtn[0]+memoryRtn[4];//perform calc from formula given
        sel[1]=-memoryRtn[1]+memoryRtn[5];//perform calc from formula given
        //sel[2]=-memoryRtn[2]+memoryRtn[6];//perform calc from formula given
        //sel[3]=-memoryRtn[3]+memoryRtn[7];//perform calc from formula given
        break;
        case 4://-z1-z2
        sel[0]=-memoryRtn[0]-memoryRtn[4];//perform calc from formula given
        sel[1]=-memoryRtn[1]-memoryRtn[5];//perform calc from formula given
        //sel[2]=-memoryRtn[2]-memoryRtn[6];//perform calc from formula given
        //sel[3]=-memoryRtn[3]-memoryRtn[7];//perform calc from formula given
        break;
        default://error if input something other than 1-4
        cout<<"ERROR! Invalid selection, exiting.\n";//display text
        return -1;//return error 
        break;
    }
        sel[2]=pow((pow(sel[0],2)+pow(sel[1],2)),0.5);//calc R
        //calc theta
        if(sel[0]>=0){//test theta calc conditions
            sel[3]=atan(sel[1]/sel[0]);//calc theta from formula
        }
        else if(sel[0]<0&&sel[1]>=0){
            sel[3]=atan(sel[1]/sel[0])+CONST_PAI;//calc theta from formula
        }
        else if(sel[0]<=0&&sel[1]<0){
            sel[3]=atan(sel[1]/sel[0])-CONST_PAI;//calc theta from formula
        }
    if(voc=="v"||voc=="V"){
        cout<<"Sum, Cartesian:  v_sum = ("<<sel[0]<<", "<<sel[1]<<")\n";//display text
        cout<<"Sum, Polar:      v_sum = ("<<sel[2]<<", "<<sel[3]<<")\n";//display text
    }
    else{
        cout<<"Sum, Cartesian:  z_sum = "<<sel[0]<<" + j "<<sel[1]<<"\n";//display text
        cout<<"Sum, Polar:      z_sum = "<<sel[2]<<" exp(j "<<sel[3]<<")\n";//display text
    }

    
    
    return 0;//return 0 if no error
    
}