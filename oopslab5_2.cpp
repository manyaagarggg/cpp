#include<iostream>
using namespace std;

void swapElements(int *a, int i1, int i2){
    int temp;
    temp = *(a+i1-1);
    *(a+i1-1) = *(a+i2-1);
    *(a+i2-1) = temp;

}

int main(){
    int n, max1;
    max1 = -999;
    cout<<"enter number of elements in array: ";
    cin>>n;
    int *ptr;
    ptr = new int[n];
    cout<<"\nenter elements of the array: "<<endl;
    for(int i=0; i<n; i++){
        cin>>*(ptr + i);
    }
    for(int i=0; i<n; i++){
        cout<<*(ptr+i)<<"  ";
        max1 = max(max1, *(ptr+i));
    }
    cout<<"\n";
    cout<<"reverse order: "<<endl;

    for (int i=n-1; i>=0; i--){
        cout<<*(ptr+i)<<"  ";
    }
    cout<<"\nmax element of the array is: "<<max1<<endl;
    swapElements(ptr, 4, 7);
    for(int i=0; i<n; i++){
        cout<<*(ptr+i)<<"  ";
    }

}
