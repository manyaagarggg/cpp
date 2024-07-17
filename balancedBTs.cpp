#include <iostream>
using namespace std;
#include <cmath>

int balancedBTsDP(int h){
    int * ans = new int[h+1];

    ans[0]=1;
    ans[1]=1;

    for(int i=2 ; i <=h ; i++){
    
    int mod = (int)(pow(10,9))+7;
    int  x = ans[i-1];
    int y = ans[i-2];

    int temp1 = (int)(((long)(x)*x)%mod);
    int temp2 = (int)((2*(long)(x)*y)%mod);
     ans[i] = (temp1+temp2)% mod;

    }

    return ans[h];
}


int balancedBTs(int h){
    if(h<= 1){
        return 1;
    }

    int mod = (int)(pow(10,9))+7;
    int  x = balancedBTs(h-1);
    int y = balancedBTs(h-2);

    int temp1 = (int)(((long)(x)*x)%mod);
    int temp2 = (int)((2*(long)(x)*y)%mod);
    int ans = (temp1+temp2)% mod;

    return ans;
    
}

int main(){
    int h;
    cin>> h;

    cout<< balancedBTsDP(h) << endl;
}