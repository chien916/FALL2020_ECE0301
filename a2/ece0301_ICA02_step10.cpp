#include <iostream>//initiate preprocessor from header files
#include <iomanip>//initiate preprocessor from header files
#include <string>//initiate preprocessor from header files
using namespace std;//initiate the extension used by cin and cout
int main(){//define main method
  int max=99999;//temp var used in cin.ignore
  printf("ECE 0301 Propositional Logic Example\n\n");//display text
  string p1,p2,p3;//define string object p1 p2 p3
  p1="Pigs can fly.";//initiate string obj with text
  p2="Earth is flat.";//initiate string obj with text
  p3="The moon is cheese.";//initiate string obj with text
  cout<<"P1: "<<p1<<"\n";//display output
  cout<<"P2: "<<p2<<"\n";//display output
  cout<<"P3: "<<p3<<"\n"<<endl;//display output
  bool b1,b2,b3;//define bool var b1 b2 b3
  cout<<"Enter P1 truth value:";//display prompt
  cin>>b1;//inject input into variable
  cin.ignore(max,'\n');//clear keyboard buffer
  cout<<"Enter P2 truth value:";//display prompt
  cin>>b2;//inject input into variable
  cin.ignore(max,'\n');//clear keyboard buffer
  cout<<"Enter P3 truth value:";//display prompt
  cin>>b3;//inject input into variable
  cin.ignore(max,'\n');//clear keyboard buffer
  cout<<"\nYou entered: P1 = ";//display text
  cout<<boolalpha<<b1;//display b1 in boolalpha form
  cout<<", P2 = ";//display text
  cout<<boolalpha<<b2;//display b2 in boolalpha form
  cout<<", P3 = ";//display text
  cout<<boolalpha<<b3;//display b3 in boolalpha form
  cout<<".\n";//display text end with endl
  bool b4=(b1&&(!b2))&&b3;//define b4 as requested
  string customTab="\t\t";//define temp tab exp string
  cout<<"\nTruth table:"<<endl//display text
      <<"Proposition"<<"\t"<<"Truth Value"<<customTab<<endl
      <<"-----------"<<"\t"<<"-----------"<<customTab<<endl
      <<"P1"<<customTab<<b1<<endl
      <<"P2"<<customTab<<b2<<endl
      <<"P3"<<customTab<<b3<<endl
      <<"P4"<<customTab<<b4<<endl;
  bool b5=((!b1)||b2)||b3;//define b5 as requested
  cout<<"P5"<<customTab<<b5<<endl;//display text
  //STEP10.CPP STARTS HERE.
  bool b6=(((b1&&(!b2))&&(!b3))||(((!b1)&&b2)&&(!b3)))||(((!b1)&&(!b2))&&b3);//define b6 as requested
  cout<<"P6"<<customTab<<b6<<endl;//display text
  bool b7=((!b1)&&(!b2))&&(!b3);//define b7 as requested
  cout<<"P7"<<customTab<<b7<<endl;//display text
  bool b8=((b1&&b2)&&b3)||((((!b1)&&b2)&&b3)||(((!b2)&&b1)&&b3))||(((!b3)&&b2)&&b1);//define b8 as requested
  cout<<"P8"<<customTab<<b8<<endl;//display text
  bool b9=(!b1)&&((b2&&(!b3))||(b3&&(!b2)));//define b8 as requested
  cout<<"P9"<<customTab<<b9<<endl<<endl<<endl;//display text
  printf("------------------");//display text
  return 0;//return 0 if everything runs correctly
}

