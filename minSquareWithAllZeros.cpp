#include <iostream>
using namespace std ;

int findMaxSquareWithAllZeros(int ** arr , int n , int m){

    
    int ** a = new int*[n];
    for(int i =0 ; i<n ; i ++){
        a[i]  = new int [m];
    }

    if(arr[0][0]== 0){
        a[0][0] =1 ;
    }

    for(int i =0 ; i < n ; i++){
        if(arr[0][i]==0){ 
        a[0][i] = 1;
        }
        else{
                a[0][i] = 0 ;
            }
        }
    

    for(int i=0 ; i < m ; i++){
        if(arr[i][0] == 0){ 
        a[i][0] = 1;
        }
        else{
                a[i][0] = 0 ;
            }
        
    }

    for(int i=1; i <n ; i++){
        for(int j =1 ; j <m ;j++){
            if(arr[i][j]==0){ 
            int ans  = min(a[i-1][j-1] , min(a[i-1][j] , a[i][j-1]));
            a[i][j] = ans +1;
            }
            else{
                a[i][j] = 0 ;
            }
        }
    }

    return a[n-1][m-1];

}

int main(){
    int n , m ;
    cin >>n>> m;
    int **arr = new int*[n];
    for(int i =0 ; i <n ; i++){
        arr[i] = new int[m];
        for(int j =0 ; j <m ; j++){
            cin >>arr[i][j];
        }
    }

    int ans = findMaxSquareWithAllZeros(arr, n ,m);
    cout<<ans << endl;



}