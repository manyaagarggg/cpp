#include<iostream>
using namespace std;

int countVowel(char *arr, int n){
    int counter = 0;
    for(int i=0; i<n; i++){
        if(*(arr+i) == 'a' || *(arr+i) == 'e' || *(arr+i) == 'i' || *(arr+i) == 'o' || *(arr+i) == 'u' || *(arr+i) == 'A' || *(arr+i) == 'E' || *(arr+i) == 'I' || *(arr+i) == 'O' || *(arr+i) == 'U'){
            counter ++;
        }
    }
    return counter;
}

int main(){
    char *ptr;
    int n;
    cout<<"enter no. of elements: ";
    cin>>n;
    ptr = new char[n];
    cout<<"\nenter elements: ";
    for(int i=0; i<n; i++){
        cin>>*(ptr+i);
    }
    for(int i=0; i<n; i++){
        cout<<*(ptr+i)<<"  ";
    }
    cout<<"no. of vowels in the array = "<<countVowel(ptr, n)<<endl;

}
