#include <iostream>
#include <queue>
using namespace std;

void printDFS( int **edges , int n , int sv , bool * visited){
    cout << sv << endl;
    visited[sv] = true;

    for( int i =0 ; i < n ; i++){
        if(i == sv){
            continue;
        }
        if(edges[i][sv]==1){
            if(visited[i]){
                continue;
            }
            printDFS( edges , n ,i , visited);
        }
    }
}

void print1BFS(int **edges , int n , int sv){
    queue <int> pendingVertiecs;
    bool * visited = new bool[n];
    for(int i =0 ; i <n ; i ++){
        visited[i] = false;
    }

    pendingVertiecs.push(sv);
    visited[sv]= true;
    while(!pendingVertiecs.empty()){
        int currentVertex = pendingVertiecs.front();
        pendingVertiecs.pop();

        cout << currentVertex <<endl;

        for(int i =0 ; i <n ; i++){
            if(i ==  currentVertex){
                continue;
            }
            if(!visited[i] && edges[currentVertex][i]==1){
                pendingVertiecs.push(i);
                visited[i]=true;
            }
        }
    }
}

bool hasPath (int ** edges , int n , int sv , int ev){
    queue<int> pendingVertices ;
    bool *visited = new bool[n];
    for(int i =0 ; i <n ; i++){
        visited[i]= false;
    }

    //!pendingVertices.empty()

    pendingVertices.push(sv);
    visited[sv]= true;
    while (pendingVertices.front()!= ev)
    {
        int currentVertices = pendingVertices.front();
        pendingVertices.pop();

        for(int i = 0; i < n ;i++){
            if(edges[i][currentVertices]==1 && !visited[i]){
                pendingVertices.push(i);
                visited[i]=true;
            }
        }
    }
    return true;
}

void printBFS(int ** edges , int n , int sv){
    queue<int> pendingVertices;
    bool * visited = new bool [n];
    for(int i =0 ; i < n; i++){
        visited[i]=false;
    }

    pendingVertices.push(sv);
    visited[sv]= true;

    while (!pendingVertices.empty())
    {
        int currentVertices = pendingVertices.front();
        pendingVertices.pop();
        cout<< currentVertices<<endl;
        for(int i =0 ;i <n ; i++){
            if(i == currentVertices){
                continue;
            }
            if(edges[i][currentVertices]==1 && !visited[i]){
                pendingVertices.push(i);
                visited[i]= true;
            }
        }
    }
    
}

int main(){
    int n;
    int e;
    cin>>n>>e;


    int ** edges = new int*[n];
    for(int i =0 ; i < n; i++){
        edges[i] = new int [n];
        for(int j = 0 ; j < n ; j++ ){
            edges[i][j]= 0;
        }
    }

    for(int i =0 ; i <e ;i++){
        int f , s ;
        cin >>f >>s;

        edges[f][s]=1;
        edges[s][f]=1;
    }

    bool *visited = new bool[n];

    for(int i =0 ; i < n; i++){
        visited[i] = 0;
    }

    cout << hasPath(edges , n , 1, 3);

    // cout << "BFS" <<endl;
    // printBFS(edges, n , 0);

    // cout <<"DFS" <<endl;
    // printDFS(edges, n ,0 , visi)


}