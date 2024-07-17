#include <bits/stdc++.h>

using namespace std;
#include<uno

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'GetMaxPoints' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY markers as parameter.
 */

int GetMaxPoints(vector<int> markers) {
    int n = markers.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    
    for(int i =0 ; i<=n ;i+=2){
        for(int j = 0 ; i+j<=n ; ++j){
            int x = j+i-1;
            if(j==x){
                dp[j][x] == markers[j];
            }
            else if(j+1 == x){
                dp[j][x] == max(markers[j],markers[x]);
            }
            else{
                int left = markers[j]  + min(dp[j+2][x] ,dp[j+1][x-1]);
                int right = markers[x] + min(dp[j+1][x-1],dp[j][x-2]);
                dp[j][x] = max(left,right);
            }
        }
    }
    return dp[0][n-1];
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string markers_count_temp;
    getline(cin, markers_count_temp);

    int markers_count = stoi(ltrim(rtrim(markers_count_temp)));

    vector<int> markers(markers_count);

    for (int i = 0; i < markers_count; i++) {
        string markers_item_temp;
        getline(cin, markers_item_temp);

        int markers_item = stoi(ltrim(rtrim(markers_item_temp)));

        markers[i] = markers_item;
    }

    int result = GetMaxPoints(markers);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
