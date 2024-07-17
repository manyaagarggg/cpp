#include <iostream>
using namespace std;

class Account{
    public:
    double balance;
    double getBal();
    double getCred(int x);
    double getDeb(int x);
};

double Account :: getBal(){
    return balance;
}
double Account :: getCred(int x){
    balance = balance + x;
    return balance;
}
double Account :: getDeb(int x) {
    balance = balance - x;
    return balance;
}

int main() {
    

    Account acc1;
    acc1.balance = 450;
    acc1.getBal();
    double Credit = acc1.getCred(45);
    double Debit = acc1.getDeb(34);
    
    cout << "credit: " << Credit << "\nDebit: " << Debit << endl;



return 0;
}