#include <iostream>
using namespace std;

#define N 9

bool isEmpty( int grid[N][N] , int & row , int & col){
    for(int i =0 ; i <N ; i++){
        for(int j =0 ; j < N ; j++){
            if(grid[i][j]==0){
                return true;
            }
        }
    }

    return false;
}


bool isSafeInRow(int grid[N][N] , int row , int i){
    for(int j = 0 ; j < N ; j ++){
        if(grid[row][j] == i){
            return false;
        }
    }

    return true;
}


bool isSafeInCol(int grid[N][N] , int col , int i){
    for(int j = 0 ; j < N ; j ++){
        if(grid[j][col] == i){
            return false;
        }
    }

    return true;
}

bool isSafeInGrid(int grid[N][N], int row , int col , int i){
    int rowFactor = row - (row%3);
    int colFactor = col - (col%3);
    for( int k =0 ; k <3 ; i ++){
        for(int j = 0 ; k <3 ; k++){
            if(grid[k+rowFactor][j+colFactor]==i){
                return false;
            }

        }
    }

    return true;
}

bool isSafe(int grid[N][N], int row , int col , int i){
    if(isSafeInRow(grid , row , i) && isSafeInCol(grid , col , i) && isSafeInGrid(grid , row , col , i)){
        return true;
    }
    return false;
}

bool solveSudoku(int grid[N][N]){
    int row , col ;
   if(!isEmpty(grid , row , col)){
    return true;
   }

   for(int i =0 ; i < 9 ; i ++){
    if(isSafe(grid, row , col , i)){
        grid[row][col] = i ;
        if(solveSudoku(grid)){
            return true;
        }

    }
   }
}



int main(){
    int grid [N][N];
    for(int i =0 ; i < N ; i++){
        string S;
        cin>> S;

        for(int j =0 ; j< S.length(); j++){
            grid[i][j] = S[j] - '0';
        }
    }

    solveSudoku(grid);

    for(int i = 0; i<N ; i++){
        for(int j =0 ; j < N ; j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}










// bool findEmptyPlace ( int grid[N][N] , int & row , int & col){
//     for( int i = 0 ; i < N; i++){
//         for(int  j = 0 ; j < N ; j++){
//             if( grid [i] [j]==0){
//                 row = i ;
//                 col = j ;
//                 return true;
//             }
//         }
//     }

//     return false;
// }

// bool isSafeInRow( int grid[N][N] , int row , int i){
//     for( int  j= 0 ; j < N ; j++){
//         if( grid [ row ] [ j] == i){
//             return false ;
//         }
//     }

//     return true;
// }


// bool isSafeInCol ( int grid[N][N] , int col , int i){
//     for( int j = 0 ; j< N ; j++){
//         if( grid [ j][ col]== i){
//             return false;
//         }
//     }

//     return true;
// }

// bool isSafeInGrid(int grid[N][N] , int row , int col , int i){
//     int rowFactor = row - (row%3);
//     int colFactor = col - (col%3);

//     for( int k =0 ; k < 3 ; k ++){
//         for( int  j =0 ; j < 3 ; j++){
//             if( grid [ k+ rowFactor ][ j+ colFactor ] == i){
//                 return false;  
//             }
//         }
//     }

//     return true;


// }

// bool isSafe( int grid[N][N] , int row , int col , int i){

//     if( isSafeInRow && isSafeInCol && isSafeInGrid){
//         return true;
//     }
// }

// bool solveSudoku ( int grid[N][N]){

//     int row , col ;
//     if(!findEmptyPlace(grid , row , col) ){
//         return true;
//     }

//     for( int  i = 0; i < 9 ; i++){
//         if(isSafe(grid , row , col , i)){
//             grid [ row] [ col] = i;
//             if(solveSudoku(grid)){
//                 return true;
//             }

//         }

//         grid [ row] [ col] = 0;
//     }
// }
