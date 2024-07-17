#include <iostream>
using namespace std;

int sum(int *input, int n){
    int *temp= input;
    int s = temp[0];
    if(n!=0){
        int x =s + sum(input+1 , n-1);
    return x;
 }
     return 0;
}


int main (){
    int n , k;
    cin>>n>>k;
    int *input = new int[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    int x = sum(input,n);
   
    int j = x%k;
    cout<< j;
}