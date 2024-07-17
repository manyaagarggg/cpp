class Fraction
{
 int Numerator;
 int Denominator;
public:
Fraction(int n, int d){
this->Numerator =n;
this->Denominator = d;
}
void print(){
    cout<<this->Numerator<<"/"<<this->Denominator<<endl;
}
};
