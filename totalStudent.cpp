#include <iostream>
using namespace std;


class Students
{
    public:
int rollNum;
int age;
static int totalStudents;
Students(){
    totalStudents++;
}
};

int Students :: totalStudents =0;

int main(){
    Students s1;
    s1.rollNum = 109;
    s1.age = 18;
    Students s2, s3 , s4;
    cout<<s1.rollNum <<" "<<s1.age<<endl;
    cout<<Students::totalStudents<<endl;


}
