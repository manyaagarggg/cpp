#include <iostream>
using namespace std;
#include <string.h>

class Student {
    int rollNumber;

    public :

    int age;

    Student(int r) {
        rollNumber = r;
    }

    int getRollNumber() {
        return rollNumber;
    }

};


int main() {
    Student s1(101);
    s1.age = 20;

    Student const s2 = s1;
    cout << s2.getRollNumber();
}
/*
class Student
{
public:
int rollNum ;
const int age;
Student(int r ,int a) : rollNum (r) , age(a){

}
void print(){
    cout<<this->age<<" "<<this->rollNum;
}
};


int main(){
    Student s1 (201,14);
    s1.print();
    Student s2 (321,15);
    s2.print();
}*/
/*
class Student
{
public:
int rollNO;
char *name;

Student(int r , char *n){
    this->rollNO = r;
    this->name = new char[strlen(n)+1];
    strcpy(this->name,n);
}
void print(){
    cout<<this->rollNO << " "<<this->name<<endl;
}
Student (const Student &s){
    this->rollNO = s.rollNO;
    // this->name = s.name;
    this-> name = new char [ strlen(s.name)+1];
    strcpy(this->name,s.name);
}
};



int main(){
    int rollNO = 2;
    char name[] = "manya";
Student s1(2,name);
s1.print();
       
    Student s2(s1);
    s2.name[0]='t';
    s1.print();
    s2.print();
}
*/