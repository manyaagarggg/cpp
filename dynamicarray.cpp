#include <iostream>
using namespace std;
#include "dynamicarrayuse.cpp"

int main(){
dynamicArray d1;
d1.add(2);
d1.add(2);
d1.add(2);
d1.add(2);
d1.add(2);
d1.add(2);
d1.add(2);
d1.print();
d1.add(3,3);
d1.print();
}