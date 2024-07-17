#include<iostream>
using namespace std;

int binarySearch(int a[], int n , int key){
    int low = 0, high = n-1;
    int mid;
    while(low<=high){
        mid = (low + high)/2;
        if(key == a[mid]){
            return mid;
        }
        else if(key < a[mid]){
            high = mid - 1;
        }
        else{
            low = mid +1;
        }
    }
    return -1;
}

int main(){
    int n, i;
    cin>>n;
    int a[n];
    for(i=0; i<n; i++){
        cin>>a[i];
    }
    int res = binarySearch(a, n, 5);
    if(res>=0){
        cout<<"element found at index: "<<res<<endl;
    }
    else{
        cout<<"element not found"<<endl;
    }
}