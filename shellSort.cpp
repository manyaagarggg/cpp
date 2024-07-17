#include <iostream>  
using namespace std;  

int shell(int a[], int n)  
{  
   
    for (int interval = n/2; interval > 0; interval /= 2)  
    {  
        for (int i = interval; i < n; i += 1)  
        {  
            
            int temp = a[i];  
            int j;        
            for (j = i; j >= interval && a[j - interval] > temp; j -= interval)  
                a[j] = a[j - interval];  
              
            
            a[j] = temp;  
        }  
    }  
    return 0;  
}  
void printArr(int a[], int n) 
{  
    int i;  
    for (i = 0; i < n; i++)  
        cout<<a[i]<<" ";  
}      
int main()  
{  
    int a[] = { 32, 30, 39, 7, 11, 16, 24, 41 };  
    int n = sizeof(a) / sizeof(a[0]);  
    cout<<"Before sorting array elements are - \n";  
    printArr(a, n);  
    shell(a, n);  
    cout<<"\nAfter applying shell sort, the array elements are - \n";    
    printArr(a, n);  
    return 0;  
}