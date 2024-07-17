#include <iostream>
using namespace std;

int minCostDP(int ** input , int m , int n){
    int **output = new int*[m];
    for(int i = 0 ; i < m ; i++){
        output[i] = new int[n];
    }
    output[m-1][n-1]= input[m-1][n-1];

    for(int i = m-2 ; i>=0 ; i--){
        output[i][n-1]= output[i+1][n-1]+ input[i][n-1];
    }

    for(int i = n-2 ; i>=0 ; i--){
        output[m-1][i]= output[m-1][i+1]+ input[m-1][i];
    }

    for(int i = m-2; i >=0 ; i-- ){
        for(int j = n-2 ; j>= 0; j--){
            output[i][j]= input[i][j] + min(output[i+1][j+1],min(output[i+1][j], output[i][j+1]));
        }
    }

    return output[0][0];
}

int minCostPathHelper(int ** input , int m , int n ,int i , int j , int **ans){
    if(i == m-1 && j == n-1){
        return input[i][j];
    }

    if(i>= m|| j >= n){
        return INT8_MAX;
    }

    if(ans[i][j]!= -1){
        return ans[i][j];
    }

    int x = minCostPathHelper(input , m ,n , i+1 , j , ans);
    int y = minCostPathHelper(input , m ,n , i , j+1 , ans);
    int z = minCostPathHelper(input , m ,n , i+1 , j+1 , ans);

    int a = min(x,min(y,z)) + input[i][j];

    ans[i][j] = a;
    return a;

}

int minCostPath_2(int** input , int m, int n  ){
    int ** ans = new int* [m*n ];
    for(int i = 0 ; i< m ; i++){
        ans[i] = new int[n];
        for(int j=0 ; j < n ; j++){ 
        ans[i][j]= -1;
        }
    }
    int x = minCostPathHelper(input , m , n , 0, 0, ans);
    return x;
}

int minCostPath(int **input , int m , int n , int i , int j ){
    if(i == m-1 && j == n-1){
        return input[i][j];
    }

    if(i>=m|| j>= n){
        return INT8_MAX;
    }

    int x = minCostPath(input,m,n, i+1,j);
    int y = minCostPath(input,m,n, i,j+1);
    int z = minCostPath(input,m,n, i+1,j+1);

    int ans = min(x, min(y,z)) + input[i][j];

    return ans;
}

int minCostPath(int **input , int m , int n){
    return minCostPath(input, m ,n ,0,0);
}

// 3 4
// 3 4 1 2
// 2 1 8 9
// 4 7 8 1

int main(){
    int m,n;
    cin>>m >>n ;
    int **input = new int*[m];
    for(int i =0 ; i < m ; i++){
        input[i] = new int[n];
        for(int j =0 ; j < n ; j++){
            cin>> input[i][j];
        }
    }

    cout << minCostDP(input, m, n)<<endl;

}