#include <iostream>
using namespace std;

void printDFS(int**edges , int n , int sv, bool*visited){
    cout<<sv<<endl;
    visited[sv]=1;

    for(int i=1; i <= n;i++){
        if(i==sv){
            continue;
        }
        if(edges[sv][i]==1){
            if(visited[i]==1){
                continue;
            }
            printDFS(edges,n,i,visited);
        }
    }
}

int main(){
    int n;
    int e;
    cin>>n>>e;
    int **edges = new int*[n];
    for(int i =0 ;i <n ;i++){
         edges[i] = new int[n];
         for(int j=0;j<n;j++){
            edges[i][j]=0;
         }
    }

    for(int i =0 ; i<e ; i++){
        int s , e;
        cin>>s>>e;
        edges[s][e]=1;
        edges[e][s]=1;
    }

    bool* visited = new bool[n];
    for(int i =0 ; i <n ; i++){
        visited[i]=0;
    }

    printDFS(edges,n,1, visited);
}