#include <iostream>
#include<string>
using namespace std;

void grassHopper(int x , int k){
    if(x%k != 0 ){
        cout<<1<<endl;
        cout<<x<<endl;
    }
    else{ 
    cout << 2 <<endl;
    cout << x-1 <<" "<<1<<endl;
    }
}

void comparison(string s){
    int j=2;
    for(int i=0; i<= s.length(); i++){
        if(s[i]==s[i+1]){
            j++;
        }
    }
    cout<<j;
}

int main(){
    grassHopper(10,3);

    comparison(">>>>>");

    // string s ;
    // cin >> s;
    // int arr[s.length()];
    //  for(int i =0 ; i < s.length();i++){
    //     if(s[i] == 'a'){
    //         arr[i]= 0;
    //     }
    //     if( s[i] ==  'b'){
    //         arr[i] = 1;
    //     }
    //     if(s[i]== 'c'){
    //         arr[i]=1;
    //     }
    //  }
    //  for(int i =0 ; i <s.length() ; i++){
    //     cout<< arr[i] <<" ";
    //  }

    //  for( int i =0 ; i < s.length(); i ++){
    //     if(arr[i]== arr[i+1]){
    //         cout <<" false";
    //     }
    //     else{
    //         cout << " true";
    //     }
    //  }

}