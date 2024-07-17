#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minStepsToOne1(int n){
    
    if( sqrt(n) - floor(sqrt(n)) == 0){
        return 1;
    }

    if(n<=3){
        return n;
    }

    int res = n;

    for(int i=0 ; i<=n ; i++){
        int temp = i*i ;
        if(temp>n){
            break;
        }
        else{
            res = min(res , 1+ minStepsToOne1(n-temp));
        }

    }

    return res ;
}

void minStepsToOne_helper(int n , int *ans){
    if(n<=1){
        ans[n] = n;
    }

    for(int i = 2 ; i<n ; i++){
        if( (i*i) < n){ 
        minStepsToOne_helper( n - (i*i), ans) ;
        ans[i] = ans[n-(i*i)] +1 ;
        }
    }


}

int minStepsToOne(int n){
    int * ans = new int[n+1];
    for(int i =0 ; i <=n ; i++){
        ans[i] =0;
    }
    minStepsToOne_helper(n, ans);

    int ans1 = INT8_MAX;
    for(int  i=0 ; i<=n ; i++){
        if(ans1 < ans[i] ){
            ans1 = ans[i];
        }
    }

    return ans1;
}

int main(){
    int n ;
    cin >> n ;
    cout<<minStepsToOne1(6);

}