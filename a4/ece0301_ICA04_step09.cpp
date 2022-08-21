#include <iostream>//initiate preprocessor from header files
#include <fstream>//initiate preprocessor from header files
#include <string>//initiate preprocessor from header files
#include <tgmath.h>//initiate preprocessor from header files
using namespace std;//initiate the extension used by cin and cout
int main(){//declaire main func
    int circuitNum=1;//count circuit number for display
    string temp;//declare new string
    ifstream ifs;//declare new ifstream object
    ofstream ofs;//declare new ofstream object
    ifs.open("divider_wheatstone_circuits.txt");//open txt
    ofs.open("divider_wheatstone_solutions.txt");//inject text into txt
    while(ifs>>temp){
        double vs,is,r1,r2,r3,r4,r5,a,b,c,d,e,f,w,x,y,z,v1,v2,v3,v4,v5,i1,i2,i3,i4,i5,r1t,r2t,r3t,r4t,r5t;//declare new var    
        if(temp!="Divider"&&temp!="Wheatstone"){//print text
            cout<<"ERROR! Invalid header.";//print text
            return -1;//print -1 to terminal as error condition
        }
        else if(temp=="Divider"){//set condition
            ifs>>vs>>r1t>>r2t;//extract text from txt 3 times

                if (circuitNum==1)//only output this at first time running
                ofs <<"ECE 0301: Circuit Solver for Voltage Divider\n"<<"and Wheatstone bridge example circuits.\n";
                
                ofs <<"-----\n"
                    <<"Circuit #"<<circuitNum<<" (Voltage Divider)\n";
                    
            //step4
            int cou;//declare counter var
            ifs>>cou;
            for(int id1=1;id1<=cou;id1++){
                for(int id2=1;id2<=cou;id2++){
                    r1=id1*r1t;
                    r2=id2*r2t;
                    double i,v1,v2;//declare new var
                    i=vs/(r1+r2);//calculate mathmatical value from the given formula
                    v1=vs*r1/(r1+r2);//calculate mathmatical value from the given formula
                    v2=vs*r2/(r1+r2);//calculate mathmatical value from the given formula
                    ofs <<"---\nSource voltage: Vs = "<<vs <<" Volts.\n"//inject text into txt
                        <<"Resistor: R1 = "<<r1 <<" Ohms.\n"
                        <<"Resistor: R2 = "<<r2 <<" Ohms.\n\n"
                        <<"Loop current: I = "<<i <<" Amperes.\n"
                        <<"Resistor voltage: V1 = "<<v1 <<" Volts.\n"
                        <<"Resistor voltage: V2 = "<<v2 <<" Volts.\n";
                }
            }
            circuitNum++;//circuit number display +1
        }
        else{//set condition temp=="WheatStone
            
            
            if (circuitNum==1)//only output this at first time running
            ofs <<"ECE 0301: Circuit Solver for Voltage Divider\n"<<"and Wheatstone bridge example circuits.\n";
            ofs <<"-----\n"//output text into txt
                <<"Circuit #"<<circuitNum<<" (Wheatstone Bridge)\n";    
            ifs>>vs>>is>>r1t>>r2t>>r3t>>r4t>>r5t;//inject text from txt
            //check calculatibility:
            
            int cou;//declare counter var
            ifs>>cou;//inject text from txt
            for(int id1=1;id1<=cou;id1++){//set conditions for iteration
                for(int id2=1;id2<=cou;id2++){//set conditions for iteration
                    for(int id3=1;id3<=cou;id3++){//set conditions for iteration
                        for(int id4=1;id4<=cou;id4++){//set conditions for iteration
                            for(int id5=1;id5<=cou;id5++){//set conditions for iteration
            /////
                    
                r1=id1*r1t;//r=times*old r
                r2=id2*r2t;//r=times*old r
                r3=id3*r3t;//r=times*old r
                r4=id4*r4t;//r=times*old r
                r5=id5*r5t;//r=times*old r
                //check calculatibility:
                if(r2==0||r3==0||((vs-is*r4)>pow(-10,-13)&&(vs-is*r4)<pow(10,-13))||((vs+is*r5)>pow(-10,-13)&&(vs+is*r5)<pow(10,-13))){
                    cout<<"ERROR! Unstable floating-point division.";//display text
                    return -1;//return -1 as error message val
                }
                a=(1+r4/r2);//calculate from formula
                b=vs-is*r4;
                c=(1+r5/r3);
                d=vs+is*r5;
                e=r1/r2;
                f=r1/r3;
                w=(a+e)/b;
                x=f/b;
                y=e/d;
                z=(c+f)/d;
                v3=(y-w)/(x*y-w*z);
                v2=(1-x*v3)/w;
                v1=e*v2+f*v3;
                v5=vs-v1-v3;
                v4=vs-v1-v2;
                i1=v1/r1;
                i2=v2/r2;
                i3=v3/r3;
                i4=v4/r4;
                i5=v5/r5;
                ofs <<"---\n"
                    <<"Source voltage: Vs = "<<(vs )<<" Volts."<<endl
                    <<"Source current: Is = "<<(is )<<" Amperes."<<endl
                    <<"Resistor: R1 = "<<(r1 )<<" Ohms."<<endl
                    <<"Resistor: R2 = "<<(r2 )<<" Ohms."<<endl
                    <<"Resistor: R3 = "<<(r3 )<<" Ohms."<<endl
                    <<"Resistor: R4 = "<<(r4 )<<" Ohms."<<endl
                    <<"Resistor: R5 = "<<(r5 )<<" Ohms."<<endl<<endl
                    <<"Resistor voltage: V1 = "<<(v1 )<<" Volts."<<endl
                    <<"Resistor current: I1 = "<<(i1 )<<" Amperes."<<endl
                    <<"Resistor voltage: V2 = "<<(v2 )<<" Volts."<<endl
                    <<"Resistor current: I2 = "<<(i2 )<<" Amperes."<<endl
                    <<"Resistor voltage: V3 = "<<(v3 )<<" Volts."<<endl
                    <<"Resistor current: I3 = "<<(i3 )<<" Amperes."<<endl
                    <<"Resistor voltage: V4 = "<<(v4 )<<" Volts."<<endl
                    <<"Resistor current: I4 = "<<(i4 )<<" Amperes."<<endl
                    <<"Resistor voltage: V5 = "<<(v5 )<<" Volts."<<endl
                    <<"Resistor current: I5 = "<<(i5 )<<" Amperes."<<endl;
                            }
                        }
                    }
                }
            }
            circuitNum++;//circuit number display +1
        }
        
    }
    ifs.close();//close ifstream obj after use
    ofs.close();//close ofstream obj after use
return 0;//return 0 to terminal if program runs right
}