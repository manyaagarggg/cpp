#include<iostream>
#include<vector>
using namespace std;

int maximumOne(int matrix[][]){
    int arr[n];
    int x= 0;
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j <m ;i++){
            if(matrix[i][j] ==1){
                arr[x]=j;
                x++;
                break;
            }
        }
    }

    int min = INT8_MAX ;
    for(int i =0 ;i <n ; i++){
        if(arr[i]<min){
            min=arr[i];
        }
    }

    return x;
}

int main(){
    int n , m ;
    cin>>n>>m;

    int matrix[n][m];

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j <m ; j ++){
            cin>>matrix[i][j];
        }
    }
    cout << maximumOne(matrix);
}