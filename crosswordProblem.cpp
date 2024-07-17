#include<bits/stdc++.h>
using namespace std;

bool checkRow(int i , int j ,  int** box , string word){
    int z =j + word.length();
    for(int k = j ; k < z ; k++){
        if(box[i][k] == 0){
            return true;
        }
    }
    return false;
}


bool checkCol( int  i , int j , int** box , string word){
    int z = i + word.length();
    for( int  k = i ; k < z ;k++){
        if(box[k][j] == 0){
            return true;
        }
    }
    return false;
}


bool check( int i , int j ,int** box , string word ){
    if( checkRow(i,j ,box, word) || checkCol (i , j , box , word)){
        return true;
    }
    return false;
}

void replaceWordInRow(int** box , string word , int  i , int j){
    int z = j + word.length();
    int x =0;
    for(int k = j ; k < z ; k ++){
        box[i][k] = word.at(x);
        x++;
    }
}

void replaceWordInCol(int** box , string word , int  i , int j){
    int z = i + word.length();
    int x =0;
    for(int k = i ; k < z ; k ++){
        box[k][j] = word.at(x);
        x++;
    }
}


void solveCrossword(int** box , string word , int n){
    for(int i =0 ; i < n ;i ++ ){
        for(int j =0 ; j <n ; j++){
            if(checkRow(i , j , box , word)){
                replaceWordInRow(box , word , i , j) ;
            }
            else 
            if(checkCol(i,j,box,word)){
                replaceWordInCol(box , word , i , j) ;
            }

            
        }
    }
}

int main(){

    int ** box = new int*[6];
    for(int i =0 ; i <6 ; i++){
        box[i]= new int[6];
        for(int j = 0 ; j <6 ; j++){
            cin >> box[i][j];
        }
    }

    solveCrossword(box , "Manya" , 6);
    
    // write your code here
    return 0;
}