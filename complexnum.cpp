#include <iostream>
using namespace std;
#include "complexnumuse.cpp"

int main(){
    int real1 , imaginary1 , real2, imaginary2;
    cin>>real1>>imaginary1;
    cin>>real2>>imaginary2;

    complexNumber c1 (real1 ,imaginary1);
    complexNumber c2 (real2,imaginary2);
    c1.print();
    c2.print();
   
   
    int choice;
    cin>>choice;
    if(choice==1){
 c1.sum(c2);
 c1.print();
    }
    else if(choice==2){
         c1.multiply(c2);
         c1.print();


    }
    else{
        return 0;
    }
}
