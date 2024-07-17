#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class edges{

    public :

    int source ;
    int dest;
    int weight;

    // public:
    

    // getSource(int s ){
    //     this->source = s;
    //     cout<<"working";
    // }

    // getDestination(int d){
    //     this->dest=d;
    //     cout<<"2";
    // }

    // getWeight(int w){
    //     this->weight = w;
    //     cout<<"3";
    // }

   
};

bool compare (edges e1, edges e2){
    return e1.weight < e2.weight;
}


int findParent(int v , int*parent){
    if(parent[v] == v){
        return v;
    }

    return findParent(parent[v],parent);
}



void kruskals(edges * input , int n , int e){
    sort(input, input+e , compare);

    edges *output = new edges[n-1];

    int *parent = new int[n];

    for(int i =0 ; i <n ;i++){
        parent[i]=i;
    }

    int count =0 ;
    int i =0 ;
    while(count != n-1){
        edges currentEdge = input[i];

        int sourceParent = findParent(currentEdge.source , parent);
        int destParent = findParent(currentEdge.dest , parent);

        if(sourceParent != destParent){
            output[count] = currentEdge;
            count++;

            parent[sourceParent] = destParent;
        }
        i++;
    }

    for(int i =0 ; i < n-1; i++){
        if(output[i].source <output[i].dest){ 
        cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
        }
        else{
            cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;
       
        }
    }
}

int main(){

    int n , e ;
    cin >> n>>e;

    edges * input = new edges[e];
    // for(int i = 0 ; i <e ; i++ ){
    //     int s , d , w ;
    //     cin>> s>>d >>w;
    //     input[i].getData(s,d,w);
    // }

    // sort(input->getData , input->getData+e);

    // edges input[e];
    for(int i =0 ; i<e; i++){
        int s,d,w;
        cin>>s>>d>>w;
        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;
    }

    kruskals(input,n,e);
    

    // sort(input, input+e);


}

    // int n ;
    // cin>>n;

    // int arr[n] ;

    // for(int i = 0 ; i < n; i++){
    //     cin>>arr[i];
    // }

    // sort(arr, arr+n);

    // for(int i = 0 ; i < n;i++){
    //     cout<<arr[i]<<endl;
    // }

    
    
    // edges *input = new edges[n-1];