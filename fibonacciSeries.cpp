#include <iostream>
using namespace std;

int fibbo_helper( int n , int * ans){
    if( n  =< 1){
        return n ;
    }

    if( ans [n] != -1){
        return ans[n];
    }

    int a = fibbo_helper(n-1 , ans);
    int b = fibbo_helper(n-2 , ans);

    ans [n] = a +b ;

    return ans[n];

}

int fibboSeries( int n){
    int * ans = new int[n+1];
    int x = fibbo_helper( n , ans);
    return x;
}


int main(){
    int n ;
    cin >> n ;
    int ans = fibboSeries(n);
    cout<< ans;

}