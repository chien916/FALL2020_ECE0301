#include<iostream>//port in header file from standard library
using namespace std;//give permission for using "<<"" and "">>"cin,cout 
int main(){//declare main method
    //I1
    cout<<"ECE 0301 DC Resistive Circuit Simulation\n";//print
    cout<<"Modeled after www.falstad.com/circuit/\n";//print
    cout<<"Circuits -> Basics -> Ohm's Law\n";//print
    //I2
    double Vs=120;//Vs=120V
    double R1=10,R2=15;//R1=10Ω,E2=15Ω
    cout<<"Vs = "<<Vs<<" Volts\n";//print
    cout<<"R1 = "<<R1<<" Ohms\n";//print
    cout<<"R2 = "<<R2<<" Ohms\n";//print
    //I3
    double I1=Vs/R1,I2=Vs/R2;//compute I1 and I2 by Ohms law
    double P1=I1*Vs,P2=I2*Vs;//compute P1 and P2
    cout<<"I1 = "<<I1<<" Amperes\n";//print
    cout<<"P1 = "<<P1<<" Watts\n";//print
    cout<<"I2 = "<<I2<<" Amperes\n";//print
    cout<<"P2 = "<<P2<<" Watts\n";//print
    //I4
    double W[]={(P1+P2),(P1+P2)*60*60,(P1+P2)*60*60*24,(P1+P2)*60*60*24*365};//store energy value as [/sec,/hr,/day,/year]
    cout<<"Energy supplied in one second = "<<W[0]<<" Joules\n";//print
    cout<<"Energy supplied in one hour = "<<W[1]<<" Joules\n";//print
    cout<<"Energy supplied in one day = "<<W[2]<<" Joules\n";//print
    cout<<"Energy supplied in one year = "<<W[3]<<" Joules\n";//print
    //I5
    double C[4];
    for(int index=0;index<=3;index++){//for loop iteration
        W[index]=W[index]/3600000;//convert j to kwh
        C[index]=W[index]*0.10;//calculate cost with fixed price 0.1usd/kwh
    }
    //cout<<"The cost of electricity is "<<"$0.10/kWh"<<".\n";//print
    cout<<"Cost of supplying energy for one second at $0.10/kWh = $"<<C[0]<<"\n";//print
    cout<<"Cost of supplying energy for one hour at $0.10/kWh = $"<<C[1]<<"\n";//print
    cout<<"Cost of supplying energy for one day at $0.10/kWh = $"<<C[2]<<"\n";//print
    cout<<"Cost of supplying energy for one year at $0.10/kWh = $"<<C[3]<<"\n";//print
    



    return 0;//return 0 if main method runs correctly
}