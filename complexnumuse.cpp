class complexNumber
{
    public:
 int realNum;
 int complexNum;
 complexNumber(int r, int c){
   this->realNum = r;
   this->complexNum = c;
 }
void print(){
    cout<<realNum<<'+'<<complexNum<<"i"<<endl;
}
void sum (complexNumber const &c2){
   int rsum = this->realNum + c2.realNum;
   int csum = this->complexNum + c2.complexNum;
   cout<<"sum:- "<<rsum <<'+'<<csum<<"i"<<endl;
}
void multiply ( complexNumber const &c2){
    int rpart = this->realNum*c2.realNum + this->complexNum*c2.complexNum*(-1);
    int cpart =this->realNum*c2.complexNum + this->complexNum*c2.realNum;
    cout<<"multiply:- "<<rpart<<'+'<<cpart<<"i"<<endl;
}
};
