#include <iostream>
#include <vector>
using namespace std;

int help(int index, int n , vector<int> arr ,  int check){
    // int x = (check & arr[index+1]);
    if(n==0 && check == 0) return 0;
    if(n==0 && check != 0) return 1;
    if(n==1 && (check & arr[index+1]) == 0) return 0;
    if(n==1 && (check & arr[index+1]) != 0) return 1;

    int m =0, v=0;

    // if((check & arr[index+1])!=0){
        // check=(check & arr[index+1]);
        m = help(index+1,n-1,arr,(check & arr[index+1]));
    // }
    // if((check & arr[index+1]) ==0){
        v = help(index+2,n-2,arr,(check & arr[index+2]));
    // }
    return max(m,v) +1;

}

int getMaxLength(int n , vector<int> arr) {
    // int check = arr[0];
    int m = help(0,n-1,arr,arr[0]);
    int v = help(1,n-2,arr,arr[1]);
    return max(m,v);
}

int main(){
    vector<int> arr ;
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(6);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(2);
    int x = getMaxLength(6,arr);
    cout<<x<< endl;
}