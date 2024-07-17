#include <iostream>
using namespace std ;

int solve(int  A[] , int n , int k , int i , int sum){
    if(i == n){
        if( sum == k ){
            return 1;
        }
        else {
            return 0 ;
        }
        
    }

    int opt1 = solve(A , n , k , i+1 , sum +A[i]);
    int opt2 = solve(A , n , k , i+1 , sum );

    return opt1 +opt2;
}

int subsetSum(int  A[] , int n , int k){
    int ans = solve(A ,n , k , 0 , 0);
    return ans ;
}

int main(){

    int n , k ;
    cin >> n >> k ;

    int A[n];
    for(int i = 0 ; i < n ; i++){
        cin>>A[i];
    }

    cout << subsetSum(A , n , k);

}