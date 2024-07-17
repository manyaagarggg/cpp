#include <iostream>
using namespace std ;

int knapSack(int *weight , int * values , int n, int maxWeight){
    if( n ==0 || maxWeight == 0){
        return 0 ;
    }

    if(weight[0] >maxWeight){
        return knapSack(weight+1 ,values+1 , n-1 , maxWeight);
    }

    int x = knapSack(weight+1 , values+1 , n-1 , maxWeight - weight [0]) + values[0];
    int  y = knapSack(weight+1 , values+1 , n-1 , maxWeight );

    return max(x,y);
}

int knapsack2(int *weight , int *values , int n , int maxWeight){
    int **output = new int*[n];
    for(int i =0 ; i =<n ; i++ ){
        output[i] = new int[n];
        for(int j =0 ; j <=n ; j++){
            output[i][j]=0;
        }
    }

    for(int i =0 ; i <=n ;i++){
        output[i][n] = 0;
    }
    
}



int main(){
    int n ;
    cin>>n;
    int * m = new int[n];
    int * v = new int[n];

    for(int i = 0 ; i <n ; i++){
        cin >> m[i];
    }

    for(int i = 0 ; i <n ; i++){
        cin >> v[i];
    }

    int maxweight;
    cin>> maxweight;

    int ans = knapSack(m , v , n , maxweight);
    cout<<ans;


}