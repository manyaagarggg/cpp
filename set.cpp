#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main() {
    string S,T;
    cin>>S>>T;
    
    string M;
    
    for(int i = 0 ; i <S.length();i++){
        if(S[i] == T[i]){
            M[i]='G';
        }
        else{
            M[i] ='B';
        }
    }
    
    for(int i = 0 ; i <S.length(); i ++){
        std::cout << M[i];
    }
	// your code goes here
	return 0;
}











// #include <iostream>
// #include<set>
// #include <unordered_set>
// #include<string>
// #include<string.h>
// using namespace std;

// int main(){
//     char * s = "manya";
//     char * t ="tanya";
    
//     if(strcmp(s,t) == 0){
//         cout<<"yes"<<endl;
//     }
//     else{
//         cout<<"false"<<endl;
//     }

//     set<int> s1 ;
//     // = {4 ,5, 2 ,1,3};
//     s1.insert(1);
//     s1.insert(2);
//     s1.insert(3);
//     s1.insert(4);
//     s1.insert(5);
//     // set <int> :: iterator itr;
    
//     const int i = 7;
//     cout<<i<<endl;
//     // i++;
//     // cout<<i;

//     unordered_set<int> s2 = { 10 ,30,20,50,70};
    

//     // cout<<s1.max_size()<<endl;
//     // cout<<s2.max_size()<<endl;

//     // swap(s1,s2);

//     for(auto itr = s1.begin() ; itr != s1.end(); itr++){
//         cout<< *itr<<endl; 
//     }

//     for(auto vale : s2){
//         cout<< vale<<" ";
//     }
//     cout<<endl;

//     pair<char,int> p1('a',1);
//     // p1.swap();
//     cout<<p1.first<<" " << p1.second<<endl;


    
// }