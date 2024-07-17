#include <iostream>
#include <queue>
#include <vector>
using namespace std;


void printBFS (int **edges , int n  , int sv , bool * visited){
    queue <int > pendingVertices ;

    pendingVertices.push(sv);

    // bool * visited = new bool [n];

    // for(int i = 0 ; i< n ;i ++){
    //     visited[ i] = false;
    // }

    visited[sv] = true; 

    while(!pendingVertices.empty()){
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();

        cout << currentVertex << endl;
        for(int i = 0 ; i <n ; i ++){
            if(i == currentVertex){
                continue;
            }
            if(edges[i][currentVertex]==1 && !visited[i]){
                pendingVertices.push(i);
                visited[i] = true;
            }
        }

    }

    // delete[] visited ;
}



void BFS(int **edges , int n ){
    bool * visited = new bool[n];

    for(int i = 0; i <n ; i++){
        visited [ i] = false;
    }

    for(int i =0 ;i <n ; i++){
        if(!visited[i]){
            printBFS(edges , n , i , visited);
        }
        // delete [] visited ;
    }
}

void printDFS(int ** edges , int n , int sv , bool* visited){
    cout << sv << endl;
    visited[sv] = true;

    for(int i = 0 ; i < n ;  i++){
        if(i == sv){
            continue;
        }

        if(edges[i][sv]==1){
            if(visited[i]){
                continue;
            }
            printDFS(edges , n , i , visited);
        }
    }
}

void DFS(int **edges , int n ){
    bool * visited = new bool[n];

    for(int i = 0; i <n ; i++){
        visited [ i] = false;
    }

    for(int i =0 ;i <n ; i++){
        if(!visited[i]){
            printDFS(edges , n , i , visited);
        }
        // delete [] visited ;
    }
}

bool hasPath1(int **edges , int n , int sv , int ev , bool * visited){
    if(sv == ev){
        return true;
    }

    visited[sv]= true;

    for(int i =0 ;i <n ;i ++){
        if(i==sv){
            continue;
        }
        if(edges[i][sv]==1 && !visited[i]){
            bool ans = hasPath1(edges, n , i, ev , visited);
            if(ans){
                return true;
            }
        }
    }
    return false;
}

bool hasPath(int ** edges , int n , int sv , int ev , bool * visited){
    if(sv==ev){
        return true;
    }

    bool ans ;

    if(edges[sv][ev]==1){
        return true;
        
    }

    // bool * visited = new bool [n];
    // for(int i =0 ; i <n ;i++){
    //     visited[i]= false;
    // }

    visited[sv] = true;
    
    for(int i =0 ; i <n ; i ++){
        if(i ==  sv){
            continue;
        }
        if(edges[i][sv]==1 && !visited[i]){ 
        ans = hasPath(edges , n , i , ev , visited);
        // return ans;
        if(ans){
            return true;
        }
        
        }

        // visited[i]= true;
        // if( edges[i][ev] == 1){
        //     return true;
        // }
    }
    
    return false;
}


/* 
int * getPathDFS(int **edges , int n , int sv, int ev , bool * visited){
    if(sv == ev){
        return sv;
    }
    if(edges[sv][ev]== 1){
        return sv;
    }

    visited[sv]= true ;

    for(int i =0 ; i<n ; i++){
        if(i==sv){
            continue;
        }
        if(edges[i][sv]==1 && !visited[i]){
            int * ans = getPathDFS(edges , i , ev , visited);
        }
    }

}

*/

vector<int> getPath_DFS_helper(int **edges , int n , int sv , int ev, bool* visited){
    vector<int> output ;
    if(sv == ev){
        output.push_back(sv);
        return output;
    }
    visited[sv] = true ;
    for(int i = 0 ; i <n ;i++){
        if(edges[i][sv] == 1 && !visited[i]){
            output = getPath_DFS_helper(edges , n , i , ev , visited);
            if(output.size() != 0){
                output.push_back(sv);
                return output;
            }
        }
    }
    return output;
}

vector <int> getPath_DFS(int ** edges , int n , int sv , int ev ){
    bool * visited = new bool[n];
    for(int i =0 ; i<n ;i++){
        visited[i]= false;
    }
    vector<int> output = getPath_DFS_helper(edges , n , sv , ev , visited);
    delete[] visited;
    return output;
}

int main(){
    
    int n;
    int e ;
    cin >> n >>e;

    int **edges = new int *[n];
    for(int i =0 ; i<n ;i++){
        edges[i] = new int[n];
        for(int j =0 ; j < n; j++){
            edges[i][j] = 0;
        }
    }

    for(int i =0 ; i < e ; i ++) {
        int u , v ;
        cin >> u >> v;
        edges[u][v] = 1;
        edges[v][u] =1;

    }

    int sv , ev ;
    cin >> sv , ev;

    vector<int> ans = getPath_DFS(edges , n, sv , ev);
    for( int i=0 ; i<ans.size() ; i++){
        cout<< ans.at(i)<<" ";
    }

    for(int i=0 ; i <n ; i++){
        delete [] edges[i];
    }

    delete []  edges;


    // bool * visited = new bool[n];

    // for(int i =0 ; i <n ; i ++){
    //     visited[i] = false;
    // }

    // BFS(edges , n );
    //  bool ans = hasPath(edges , n , 1 , 3 , visited);
    //  cout <<ans<<endl;
}