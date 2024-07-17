#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printSolution(int** output,int n){
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
cout << output[i][j] << " ";
}
}
cout<<endl;
}

void mazeHelp(int Maze[][20] ,int **output , int n , int row , int col){
    if(row == n-1 && col  == n-1){
        output[row][col] == 1;
        printSolution(output, n);
    }

    if(row >= n || row < 0 || col >= n || col<0 || Maze[row][col] == 0 || output[row][col] == 1){
        return;
    }

    output[row][col] = 1 ;

    mazeHelp(Maze , output , n , row -1 , col);
    mazeHelp(Maze , output , n , row +1 , col);
    mazeHelp(Maze , output , n , row  , col+1);
    mazeHelp(Maze , output , n , row  , col-1);
}

void ratInMaze(int Maze[][20] , int n){
    int **output = new int*[n];
    for(int i = 0 ; i <n ; i ++){
        output[i] = new int[n];
    }
    
    for(int i =0 ; i <n ; i++){
        memset(output[i], 0, n*sizeof(int));
    }

    mazeHelp(Maze, output , n, 0 , 0);
}



int main(){
    int n;
    cin>>n;

    int Maze[20][20];

    for(int i =0 ; i <n ; i++){
        for(int j = 0 ; j <n ; j++){
            cin>> Maze[i][j];
        }
    }
    ratInMaze( Maze , n);

}







// void ratINMaze( int ** intput , int row , int col){
//     int ** output = new int*[row];
//     for(int i =0 ; i <row ; i++){
//         output[i] = new int[col];
//         for(int j = 0 ; j < col ; j ++){
//             output[i][j]=0;
//         }
//     }

//     while(output[row-1][col-1] != 0){

//     }

// }







// void mazeHelp ( int Maze[][20] , int n , int **solution , int x , int y){
//     if( x == n-1 && y == n-1){
//         solution[x][y] = 1;
//         printSolutin
//     }
// }

// void ratInMaze ( int Maze[][20] , int n){
//     int **solution = new int*[n];
//     for(int i = 0 ; i <n ;i++){
//         solution[n] = new int [n];
//         // for(int j= 0 ; j <n ; j++){
//         //     solution[i][j]=0;
//         // }
//     }

//     for(int i =0 ; i <n ; i++){
//         memset(solution[i], 0, n*sizeof(int));
//     }

//     mazeHelp(Maze , n , solution , 0 , 0);
// }