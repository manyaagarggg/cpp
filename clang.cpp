#include<iostream>
using namespace std;
 
int main(){
   
        int n ;

        cin>>n;
        for (int  i = 0; i <  n; i++)
        {
            for (int j= 0; j < i; j++)
            {
                cout<<"*";
            
                /* code */
            }
            cout<<endl;
            /* code */
        }
        
        for (int  i = n; i >0; i--)
        {
            for (int j= i; j >0; j--)
            {
                cout<<"*";
            
                /* code */
            }
            cout<<endl;
            /* code */
        }
       
    
    return 0;
}
