#include <iostream>
using namespace std;


int fibbo_3(int n){
    int * ans = new int[n+1];

    ans[0]=0;
    ans[1]=1;

    for(int i=2 ; i<=n ; i++){
        ans[i]= ans[i-1]+ ans[i-2];
    }

    return ans[n];
}

int fibbo_2_helper(int n , int *ans){
    if(n<=1){
        return n;
    }

    if(ans[n] != -1){
        return ans[n];
    }

    int a = fibbo_2_helper(n-1,ans);
    int b = fibbo_2_helper(n-2, ans);

    ans[n]= a+b;
    return ans[n];

}

int fibbo_2(int n){
    int *ans = new int[n+1];
    for(int i=0 ; i <=n ; i++){
        ans[i] = -1;
    }

    return fibbo_2_helper(n,ans);
}

int fibbo(int n){
    if(n<=1){
        return n;
    }
    int a = fibbo(n-1);
    int b = fibbo(n-2);
    return a+b ;
}

int main(){
    int n;
    cin>>n;
    int ans = fibbo(n);
    cout<< ans<<endl;
    int ans2 = fibbo_2(n);
    cout<< ans2<<endl;
    int ans3 = fibbo_3(n);
    cout<<ans3<<endl;
}