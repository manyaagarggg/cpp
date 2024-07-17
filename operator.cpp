#include <iostream>
using namespace std;
#include "operatoruse.cpp"

int main(){
    int n , d , n1 , d2;
    cin>>n>>d>>n1>>d2;
    Fraction f1(n,d);
    Fraction f2(n1,d2);
    f1.print();
    f2.print();
}