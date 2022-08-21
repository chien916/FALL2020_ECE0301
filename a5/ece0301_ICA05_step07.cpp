#include <iostream>//initiate preprocessor from header files
#include <fstream>//initiate preprocessor from header files
#include <string>//initiate preprocessor from header files
#include <stdlib.h>//initiate preprocessor from header files
#include <cmath>//initiate preprocessor from header files
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
int writeMinterm(int a,int b,int c,int pmt){//define overloaded function with parameters
    if(pmt>7||pmt<0){//set error check condition
        cout<<"ERROR! Invalid minterm index.";//output to terminal
        exit(1);//exit program when there's error
    }
    else{//normal condition
        int bin[3]={0,0,0};//binary representation
        int tempIndex=2;//define new var
        while(pmt>0){//set condition for coverting dec to bin
            bin[tempIndex]=pmt%2;//take modulus to get binary digit
            pmt=(pmt/2);//divide by two to get ready for the next round
            tempIndex--;//index -1
        }
        int toOutput[3]={a,b,c};//define new output var
        if(bin[0]==0){
            toOutput[0]=1-toOutput[0];//flip true/false value
        }
        if(bin[1]==0){
            toOutput[1]=1-toOutput[1];//flip true/false value
        }
        if(bin[2]==0){
            toOutput[2]=1-toOutput[2];//flip true/false value
        }
        return gate_and(toOutput[0],toOutput[1],toOutput[2]);//return calculated and value
    }

}
int writeMaxterm(int a,int b,int c,int pmt){//define overloaded function with parameters
    if(pmt>7||pmt<0){//set error check condition
        cout<<"ERROR! Invalid minterm index.";//output to terminal
        exit(1);//exit program when there's error
    }
    else{//normal condition
        int bin[3]={0,0,0};//binary representation
        int tempIndex=2;//define new var
        while(pmt>0){//set condition for coverting dec to bin
            bin[tempIndex]=pmt%2;//take modulus to get binary digit
            pmt=(pmt/2);//divide by two to get ready for the next round
            tempIndex--;//index -1
        }
        int toOutput[3]={a,b,c};//define new output var
        if(bin[0]!=0){
            toOutput[0]=1-toOutput[0];//flip true/false value
        }
        if(bin[1]!=0){
            toOutput[1]=1-toOutput[1];//flip true/false value
        }
        if(bin[2]!=0){
            toOutput[2]=1-toOutput[2];//flip true/false value
        }
        return gate_or(toOutput[0],toOutput[1],toOutput[2]);//return calculated and value
    }
}
void writeGate(ofstream& ofs,int pmt,int gate){//define function with parameters
    int res=-1;//define output var
    if(gate==1)
        ofs<<"\nTruth table for minterm "<<pmt<<".\n\n";
    else if(gate==0)
        ofs<<"\nTruth table for maxterm "<<pmt<<".\n\n";
    ofs<<"x\ty\tz\tf(x,y,z)\n--------------------------------\n";//output text to file
    for(int x=0;x<=1;++x){//iteration for x
        for(int y=0;y<=1;++y){//iteration for y
            for(int z=0;z<=1;++z){//iteration for z
                switch(gate){//and/or gate switcher
                    case 0://case for or gate(max term)
                        res=writeMaxterm(x,y,z,pmt);//call function and receive return from function
                        break;//end of switch case
                    case 1://case for and gate(min term)
                        res=writeMinterm(x,y,z,pmt);//call function and receive return from function
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
    ifstream ifs;//define new ifstream object
    ofs.open("Bool_func_3var_CSOP_CPOS.txt");//open file for ofstream object
    ifs.open("Bool_func_3var.txt");//open file for ifstream object
    int parameterOfCircuit;//define new var
    ifs>>parameterOfCircuit;//read text from files
    ofs<<"ECE 0301: Boolean Functions of 3 Variables.\nRealization in Canonical Forms.\n";//display text to files
    ofs<<"\nm"<<parameterOfCircuit<<" = "<<writeMinterm(parameterOfCircuit)<<endl;//display text into files
    writeGate(ofs,parameterOfCircuit,1);
    
    
    ofs<<"\nM"<<parameterOfCircuit<<" = "<<writeMaxterm(parameterOfCircuit)<<endl;//display text into files
    writeGate(ofs,parameterOfCircuit,0);

    return 0;//return 0 for main if programs runs right
}