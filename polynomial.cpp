#include <iostream>
using namespace std;
#include "polynomialuse.cpp"

int main(){
polynomial p1(5);
p1.add(1);
p1.add(2);
p1.add(3);
p1.add(0);
p1.add(4);
p1.print();
polynomial p2(5);
p2.add(2);
p2.add(0);
p2.add(0);
p2.add(0);
p2.add(4);
p2.print();
polynomial p3 = p1 + p2;
p3.print();

}