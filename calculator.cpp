//*********EXERCISE ODF INHERITANCE***********

//  Create two classes :
// 1. SimmpleCalculator- Takes input of 2 number using a utility function and perfoms +,-,*,/
// and displays the result using another function
// 2. ScientificCalculator - Takes input of 2 numbers using a utility functionand performs any four scientific operations
// of your choice and displays the results using another functions

// create a class hybridcalculator and inhherit it usinng these 2 classes:
// Q1. What type of inheritance you are using ?--> Multiple
// Q2. Which mode of inheritance are you using?--> public
// Q3. Create an object of hybridcalculator and displaybresults of simple and scientific calculator.
// Q4. How is code reusibility implemented?*/

#include<iostream>
#include<cmath>
using namespace std;
class simpleCalculator{
  public:
  double num1 ,num2 ;
  void getdata(){
    cout<<"enter the values of two numbers "<<endl;
    cin>>num1>>num2;
  }
  double operate(){
    char d;
    cout<<"enter the operation you want to perform (+,-,*,/) "<<endl;
    cin>>d;
    switch(d){
      case '+':
      cout<<"the addition of two numbers is "<<num1+num2<<endl;
      break;
      case '-':
      cout<<"the subtraction of two numbers is "<<num1-num2<<endl;
      break;
      case '*':
      cout<<"the multiplication of two numbers is "<<num1*num2<<endl;
      break;
      case '/':
      cout<<"the division of two numbers is "<<num1/num2<<endl;
      break;
      default:
      cout<<"invalid data"<<endl;
      break;
        }
  }

};
class ScientificCalculator{
  public:
  double num;
  void getdata(){
    cout<<"enter the value of number "<<endl;
    cin>>num;
  } 
  double operate(){
    char d;
    cout<<"enter the operation you want to perform (log(l),cos(c),sqrt(s),exp(e)) "<<endl;
    cin>>d;
    switch(d){
      case 'l':
      cout<<"the log of the given number is "<<log(num)<<endl;
      break;
      case 'c':
      cout<<"the cos of the number is "<<cos(num)<<endl;
      break;
      case 's':
      cout<<"the square root of the number is "<<sqrt(num)<<endl;
      break;
      case 'e':
      cout<<"the exponent of the number is "<<exp(num)<<endl;
      break;
      default:
      cout<<"invalid data"<<endl;
      break;
        }
  } 
};
class hybridCalculator : public simpleCalculator ,public ScientificCalculator{
  public:
  void choose(){
    char x;
    cout<<"enter which calculator you wanna use, c for simple amd s fr scientific  "<<endl;
    cin>>x;
    switch(x){
      case 'c':
      simpleCalculator::getdata();
      simpleCalculator::operate();
      break;
      case 's':
      ScientificCalculator::getdata();
      ScientificCalculator::operate();
      break;
      default:
      cout<<"invalid response"<<endl;
    }
  }
};
int main(){
hybridCalculator s1;
s1.choose();
return 0;
}
