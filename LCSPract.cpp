#include<iostream>
using namespace std;

int LCS_DP(string s1 , string s2){
    int m = s1.size();
    int n = s2.size();

    string s ;

    int ** output = new int*[m+1];
    for(int i=0 ; i <=m ;i++){
        output[i] = new int[n+1];
    }
     for(int i =0 ; i<=m ; i++){
        output[i][0]=0;
     }

     for(int i =0 ; i <=n ; i++){
        output[0][i]=0;
     }

     for(int i = 1 ;i <=m ; i++ ){
        for(int j =1 ; j<=n ; j++){
            if(s1[m-i] == s2[n-j]){
                output[i][j] = 1+output[i-1][j-1];
            }
            else{
                int a = output[i-1][j];
                int b = output[i][j-1];
                int c = output[i-1][j-1];
                output[i][j] = max(a, max(b,c));
            }
        }
     }
     return output[m][n];
}

int LCS(string s1, string s2){
    if(s1.size() ==0 || s2.size()==0){
        return 0;
    }
    if(s1[0] == s2[0]){
        return 1+ LCS(s1.substr(1), s2.substr(1));
    }
    else{
        int a = LCS(s1.substr(1), s2);
        int b = LCS(s1 , s2.substr(1));
        int c = LCS(s1.substr(1),s2.substr(1));

        return max(a , max(b,c));
    }
}

int main(){
    string s1;
    string s2 ;
    cin>> s1 >>s2;
    int ans = LCS(s1 , s2);
    int ans1 = LCS_DP(s1, s2);
    cout<< ans1 << endl;

}