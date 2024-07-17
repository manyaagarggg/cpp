class Fraction{
    public:

    int numerator;
    int denominator;

    Fraction (int n , int d){
        this->numerator =n;
        this->denominator =d;
    }
   int  min(int n, int d){
     int num= n;
     int deno=d;

        if(num>deno){
            return deno;
        }
        return num;

    }

void simplify(){
    int gcd =1;
    int j = min(numerator,denominator);
    for(int i = 1 ; i<=j ;i++){
        if(numerator%i==0 && denominator%i==0){
            gcd=i;
        }
    }
    this->numerator=this->numerator/gcd;
    this->denominator=this->denominator/gcd;
}

void print(){
    simplify();
 cout << this->numerator<<"/"<<this->denominator << endl;
};
Fraction operator++(int){
   Fraction fNew(numerator,denominator);
   numerator = numerator + denominator;
   simplify();
   fNew.simplify();
   return fNew;
}
};