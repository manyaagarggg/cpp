#include <iostream>
using namespace std;
#include "numdenouse.cpp"

int main (){
    int n , d , n1, d1;
    cin>>n>>d>>n1>>d1;
    Fraction f1 (n ,d);
    f1.print();
    Fraction f2 (n1,d1);
    f2.print();
    Fraction f3 = f1++;
    f3.print();
}
