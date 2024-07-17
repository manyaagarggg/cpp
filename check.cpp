long long power(long long x, int y, int p)
{
    long long res = 1;
 
    x = x % p; 
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
long long modInverse(long long n, int p)
{
    return power(n, p - 2, p);
}
long long mul(long long x,
                       long long y, int p)
{
    return x * 1ull * y % p;
}
long long divide(long long x,
                          long long y, int p)
{
    return mul(x, modInverse(y, p), p);
}
long long nCrModPFermat(long long n,
                                 int r, int p)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
    if (n - r < r)
        return nCrModPFermat(n, n - r, p);
    long long res = 1;
    for (int i = r; i >= 1; i--)
        res = divide(mul(res, n - i + 1, p), i, p);
    return res;
}

long long solve(int n, int k, string s) {
    vector<int> freq(26,0);
    for(int i=0;i<n;i++) {
        freq[s[i]-'a']++;
    }
    sort(freq.begin(),freq.end(),greater<int>());
    int cnt=0,cnt1=0;
    for(int i=0;i<26;i++) {
        if(freq[i]==freq[k-1]) {
            cnt++;
            if(i<k) cnt1++;
        }
    }
    long long M = 1e9+7;
    long long ans = nCrModPFermat(cnt,cnt1,M);
    for(int i=0;i<k;i++) {
        ans=(ans*freq[i])%M;
    }
    return ans;
}

// #include <bits/stdc++.h>
// using namespace std;

// const int MOD = 1e9+7;

// int digitSum[1001];

// void addMod(int &a, int b){
//     a += b;
//     if(a >= MOD) a -= MOD;
// }

// void solve(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(auto &num: arr)
//         cin >> num;

//     vector<vector<int>> dp(n, vector<int>(1001, -1));
//     function<int(int, int)> calc = [&](int pos, int last)->int{
//         if(pos == n) return 1;
//         int &result = dp[pos][last];
//         if(result != -1) return result;
//         result = 0;
//         for(int i = 1; i <= 1000; i++)
//             if(digitSum[i] == digitSum[arr[pos]] && i > last)
//                 addMod(result, calc(pos+1, i));
//         return result;
//     };

//     cout << calc(0, 0) << endl;
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     for(int i = 1; i <= 1000; i++){
//         int x = i;
//         while(x){
//             digitSum[i] += x % 10;
//             x /= 10;
//         }
//     }

//     int t;
//     cin >> t;
//     while(t--)
//         solve();
// }


// #include <iostream>
// #include <vector>
// #include <cstring>
// using namespace std;

// const int MOD = 1000000007;
// const int MAXN = 1005;
// const int MAX_SUM = 9005;

// int dp[MAXN][MAX_SUM];

// int countDistinctArrays(int N, vector<int>& S) {
//     memset(dp, 0, sizeof(dp));
//     dp[0][0] = 1;
    
//     for (int i = 1; i <= N; i++) {
//         int sum = 0;
//         for (int j = i; j >= 1; j--) {
//             sum += S[j-1];
//             sum %= MAX_SUM;
//             for (int k = sum; k < MAX_SUM; k++) {
//                 dp[i][k] = (dp[i][k] + dp[j-1][k-sum]) % MOD;
//             }
//         }
//     }
    
//     int result = 0;
//     for (int i = 1; i < MAX_SUM; i++) {
//         result = (result + dp[N][i]) % MOD;
//     }
    
//     return result;
// }

// int main() {
//     int T;
//     cin >> T;
    
//     while (T--) {
//         int N;
//         cin >> N;
        
//         vector<int> S(N);
//         for (int i = 0; i < N; i++) {
//             cin >> S[i];
//         }
        
//         int result = countDistinctArrays(N, S);
//         cout << result << endl;
//     }
    
//     return 0;
// }


// #include <iostream>
// #include <vector>
// #include <string>
// #include <cstring>
// using namespace std;

// const int MOD = 1000000007;
// const int MAXN = 1005;

// int dp[MAXN][MAXN][2];

// int countDistinctSpecialSubsequences(string& s, int K) {
//     int N = s.length();
    
//     memset(dp, 0, sizeof(dp));
//     dp[0][0][0] = 1;
    
//     for (int i = 1; i <= N; i++) {
//         for (int j = 0; j <= K; j++) {
//             dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1]) % MOD;
            
//             if (s[i-1] <= 'z' && j > 0) {
//                 dp[i][j][1] = (dp[i-1][j-1][0] + dp[i-1][j-1][1]) % MOD;
//             }
//         }
//     }
    
//     return (dp[N][K][0] + dp[N][K][1]) % MOD;
// }

// int main() {
//     int T;
//     cin >> T;
    
//     while (T--) {
//         int N, K;
//         cin >> N >> K;
        
//         string S;
//         cin >> S;
        
//         int result = countDistinctSpecialSubsequences(S, K);
//         cout << result << endl;
//     }
    
//     return 0;
// }