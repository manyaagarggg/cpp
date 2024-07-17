#include <iostream>
using namespace std;
#include<bits/stdc++.h>

int board[11][11];


bool isPossible(int n , int row , int col){
    for(int i=row-1 ; i >=0 ; i--){
        if(board[i][col]== 1){
            return false;
        }
    }

    for(int i = row - 1 , j = col -1 ; i>=0 && j>=0 ; i-- , j-- ){
        if(board[i][j]==1){
            return false;
        }
    }
    for(int i = row -1 , j = col +1 ; i>=0 && j<n ; i-- , j++){
        if(board[i][j]==1){
            return false;
        }
    }
    return true;
}

void placeNQueenHelper(int n , int row){
    if(n==row){
        for(int i =0 ; i<n;i++){
            for(int j=0 ; j<n ; j++){
                cout<< board[i][j]<<" ";
            }
        }
        cout<<endl;
        return;
    }

    for(int j -0 ; j <n ; j ++){
        if(isPossible(n , row , j)){
            board[row][j]= 1;
            placeholders(n, row+1); 
        }

    }

}

void placeNQueen(int n){
    placeNQueenHelper(n,0);
}

int main(){

}