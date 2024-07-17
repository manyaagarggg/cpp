#include<iostream>
using namespace std;

int linearSearch(int a[], int n, int key){
    int i;
    for(i=0; i<n; i++){
        if(a[i]==key){
            return i;
        }
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    int a [n];
    for(int i =0 ; i<n; i++){
        cin>>a[i];
    }
    int result = linearSearch(a,n,3);
    if(result>0){
        cout<<"element found at index " << result;
    }
    else{
        cout<<" element not found";
    }
}