template <typename T , typename U>
class triplet
{
T x;
U y ;
T z;
public :
void setX (T x){
    this->x = x;
}
void setY (U y){
    this->y = y;
}
void setZ (T z){
    this->z = z;
}
T getX (){
return x;
}
U getY (){
   return y;
}
T getZ (){
    return z;
}
};


#include <iostream>
using namespace std;


int main(){
    triplet<triplet<int,int>, char> t1;
    triplet <int , int>t2;
    t2.setX(3);
    t2.setY(3);
    t2.setZ(3);
    t1.setX(t2);
    t1.setY (3);
    t1.setZ(t2);
    cout<<t1.getX().getX()<<" "<<t1.getX().getY()<<" "<<t1.getX().getZ()<<" "<<t1.getY()<<" "<<endl;
     cout<<t1.getZ().getX()<<" "<<t1.getZ().getY()<<" "<<t1.getZ().getZ()<<endl;
    }