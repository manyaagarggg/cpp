class student
{
private:
 char name;

    /* data */
public:

int rollNo ;
int age;
~student (){
        cout<<"destructor called!"<<endl;
    }
    
student (){
    cout<<"constructor called!" <<endl;
}
student(int r , int a){
    cout<< "this is"<< this<<endl;
cout<<"constructor 2 called!"<<endl;
this ->rollNo = r;
this ->age =a;

cout<<rollNo<<" "<<a<<endl;
}
 student(int r , int a, char n){
    cout<<"const 3 called!"<<endl;
    this-> rollNo =r;
    this-> age =a;
    this-> name =n;
    cout<<rollNo<<" "<< name<<" "<< age<<endl;
    cout<<r<<" "<< n<<" "<< a<<endl;
 }

 void display(){
    cout<<rollNo <<" "<<name <<" "<<age<<endl;

 }
    

};
