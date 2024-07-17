class Student
{
public:
int rollNO;
char *name;

Student(int r , char *n){
    this->rollNO = r;
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
}
void print(){
    cout<<this->rollNO << " "<<this->name<<endl;
}
};

