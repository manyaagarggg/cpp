#include <iostream>
using namespace std;

int minStepsHelper3(int n , int *ans){
    int *ans = new int[ n+1];
     if(n<=1){
        a[n]=0;
     }
     a[2] = 1;
     a[3] = 1;

     int x = INT8_MAX , y = INT8_MAX;

     if(n%2 == 0){

     }

     for(int i =4 ; i <= n ; i ++){
        if(i%2==0){

        }
        if(i%3== 0){
            
        }
     }

     int output = min( z , min (x,y))+1;

     ans[n] = output ;

     return output;


}

int minSteps_3(int n){
    int *ans = new int[n+1];

    for(int i =0 ; i <= n ; i ++){
        ans[i] = -1;
    }

    return
}

int minStepsHelper(int n , int *ans){
    if( n <= 1){
        return 0 ;
    }

    if(ans[n]!= -1){
        return ans[n];
    }

    int x = minStepsHelper( n-1 , ans);

    int y = INT8_MAX , z = INT8_MAX ;
    if(n %2 == 0){
        y = minStepsHelper(n/2 , ans);

    }

    if(n%3 == 0){
        z= minStepsHelper(n/3, ans);
    }

    int output = min(x , min (y,z)) +1;

    ans[n] = output ;
    return output;
}

int minSteps_2(int n){
    int *ans = new int[n+1];

    for(int i =0 ; i <=n ; i++){
        ans[i] = -1;
    }

    return minStepsHelper (n , ans);
}

int minSteps( int n ){
    if( n <=1 ){
        return 0;
    }

    int x = minSteps ( n-1);

    int y = INT8_MAX , z = INT8_MAX ;

    if(n%2== 0){
        y = minSteps(n/2);
    }

    if(n%3==0){
        z = minSteps(n/3);
    }

    int ans = min( x , min ( y , z)) + 1;
}



int main(){
    int n ;
    cin >> n;

    cout << minSteps_2(n)<<endl;
}