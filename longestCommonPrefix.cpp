#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

    string longestCommonPrefix(vector<string>& v) {
        string ans="";
        sort(v.begin(),v.end());
        int n=v.size();
        string first=v[0],last=v[n-1];
        for(int i=0;i<min(first.size(),last.size());i++){
            if(first[i]!=last[i]){
                return ans;
            }
            ans+=first[i];
        }
        return ans;
    }


// string longestCommonPrefix(vector <string> & strs){
//     string str = strs[0];
//     int count = 0;
//     for(int i = 0 ; i < str.length();i++){
//         bool check = false;
//         for(int j = 0 ; j < strs.size(); j++){
//             if(str.substr(0,i+1)!= strs[j].substr(0,i+1)){
//                 check = false;
//                 break;
//             }
//             else{
//                 check = true;
//             }
//         }
//         if(check==true){
//             count++;
//         }
//         else{
//             break;
//         }

//     }
//     return str.substr(0,count);
// }


int main(){
    vector <string> strs = {"flower" , "flow " , "flight"};
    string ans = longestCommonPrefix(strs);
    cout<<ans<<endl;
    sort(strs.begin(),strs.end());
    for(int i = 0 ; i <strs.size();i++){
        cout<<strs[i]<<endl;
    }
}