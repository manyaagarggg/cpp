#include<iostream>
#include<string>
#include<vector>
using namespace std;

int strStr(string haystack, string needle) {
    string str1 = haystack;
    string str2 = needle;
    int j =0 ;
    int x = -1;
        for(int i = 0 ; i< str1.length();i++){
            // if(j==str2.length()){
            //     break;
            // }
            // if(str1[i]==str2[j]){
            // j++;
            // x=i+1;
            // }
            // else{
            // continue;
            // }
            int y = str2.length();
            if(str1.substr(i,y)==str2.substr(0,y)){
                // j++;
                x=i;
                break;
            }
        }
        return x;
        
     
    }

    

int main(){
    int x = strStr("leetcode" ,"leeto");
    cout<<x<<endl;
}