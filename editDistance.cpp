#include <iostream>
using namespace std;

//DP

int editDistance_DP( string s, string t){
    int m = s.size();
    int n = t.size();

    // if(s.size()==0 || t.size() ==0 ){
    //     return max(s.size(), t.size());
    // }

    int **output = new int* [m+1];
    for(int i = 0; i <=m ; i++){
        output[i] = new int[n+1];
    }

    for(int i =0 ; i<=n ; i ++){
        output[0][i] = i;
    }

    for(int i = 1 ; i <= m ;i++){
        output[i][0] = i;
    }

    for(int i = 1 ; i <= m ; i++){
        for(int j =1 ; j <= n ; j++){
            if(s[m-i] ==  t[ n-j]){
                output[i][j]= output[i-1][j-1];
            }
            else{ 
                int a = output[i-1][j];
                int b = output[i][j-1];
                int c = output[i-1][j-1];

                output[i][j] = min(a , min(b,c))+1;
        }
        }

    }

    return output[m][n];


}

//memoization

int editDistance_memo(string s , string t, int ** output ){
    int m = s.size();
    int n = t.size();

    if( s.size() == 0|| t.size()==0){
        return max(s.size() , t.size());
    }

    if(output[m][n] !=-1){
        return output[m][n];
    }

    int ans;

    if(s[0]==t[0]){
        ans = editDistance_memo(s.substr(1), t.substr(1), output)+1;

    }

    else{
        // insert

        int x = editDistance_memo(s.substr(1), t , output)+1;

        //delete

        int y = editDistance_memo(s, t.substr(1) , output) +1;

        // /replace

        int z = editDistance_memo(s.substr(1), t.substr(1), output)+1;

        ans = min(x , min(y,z));
    }

    //save the answer

    output[m][n]= ans;

    // return ans

    return ans;
}

int editDistance_memo(string s, string t ){
    int m = s.size();
    int n = t.size();

    int ** ans =new int* [ m+1];
    for(int i = 0 ; i <=m ; i++){
        ans[i] = new int [n+1];
        for(int j = 0; j<= n ; j++){
            ans[i][j] = -1;
        }
    }

    return editDistance_memo(s, t , ans);
}

//brute force

int editDistance(string s , string t){
    if(s.size()==0 || t.size()==0){
        return max(s.size(), t.size());
    }

    if(s[0]==t[0]){
        return editDistance(s.substr(1), t.substr(1));
    }
    else{
        int x = editDistance(s.substr(1),t)+1;
        int y = editDistance(s, t.substr(1))+1;
        int z = editDistance(s.substr(1) , t.substr(1))+1;

        return min(x , min(y , z));
    }
}

int main(){
    string s, t;
    cin>>s>>t;

   
    cout<<editDistance_DP(s,t)<<endl;
     cout<<editDistance(s,t)<<endl;

}