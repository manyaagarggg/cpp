#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// class Edge{
//     int source;
//     int dest;
//     int weight;
// };

int findMinVertex(int *weight , bool* visited , int n ){

    int minVertex = -1;
    for(int i =0 ; i < n ; i++){

        if(!visited[i] && (minVertex == -1 || weight[i] < weight[minVertex])){
            minVertex = i;
        }
    }
    return minVertex;
}

void prims(int **edges , int n){

    int *parents = new int[n];
    int *weight = new int[n];
    bool *visited = new bool[n];

    for(int i = 0 ; i < n ; i++){
        visited[i] = false;
        weight[i] = INT_MAX;
    }

    parents[0] = -1;
    weight[0] =0 ;

    for(int i =0 ; i<n ; i++){
        int minVertex = findMinVertex(weight , visited , n);
        visited[minVertex]= true;

        for(int j =0 ; j < n ; j++){
            if(edges[minVertex][j] != 0 && !visited[j]){
                if(edges[minVertex][j] <weight[j]){
                    weight [ j] = edges[minVertex][j];
                    parents[j] = minVertex;
                }
            }
        }
    }

    for(int i =1 ;i <n ; i++){
        if(parents[i] <i ){
            cout<< parents[i] <<" "<<i<<" "<<weight[i]<<endl;
        }
        else{
            cout<<i<<" "<<parents[i]<<" "<<weight[i]<<endl;
        }
    }



}

int main(){
    int n ,e;
    cin>>n>>e;

    int ** edges = new int*[n];
    for(int i=0 ; i<n; i++){
        edges[i] = new int[n];
        for(int j =0 ; j <n ;j++ ){
            edges[i][j] = 0;
        }
    }

    for(int i =0 ; i <e ; i++){
        int f , s , weight ;
        cin >>f >>s>>weight;
        edges[f][s]= weight;
        edges[s][f] = weight;
    }

    cout <<endl;

    prims(edges,n);
    
}



    // int * unvisited = new int[n];
    // int *visited = new int[n];

    // for(int i =0 ; i <n ; i++){
    //     unvisited[i]=i;
    // }

    // // int initial = unvisited[0];
    // // visited[0] = unvisited[0];
    // // int count = 1 ;

    // int *parent = new int[n];

    // for(int i =0 ; i <n ;i++){
    //     parent[i] = INT8_MAX;
    // }

    // int *weight = new int[n];

    // for(int i=0 ; i<n ;i++){
    //     weight[i] = INT8_MAX;
    // }

    // int first = unvisited[0];
    // parent[0] = -1;
    // weight[0]=0;
    // int count = 1;

    // while(count != n-1){
    //     for
    // }