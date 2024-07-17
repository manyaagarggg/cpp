#include <iostream>
#include<vector>
#include <algorithm>
#include<string>
using namespace std;

bool check(int arr[], int n ,  int i){
    int count1 = 0 , count2= 0;

    for(int x = 0 , y = n-1 ; x <= i , y >i ; x++ , y--){
        
        if(arr[x] == 2){
            count1++;
        }
        if(arr[y]==2){
            count2++;
        }
    }
    if(count1 == count2){
        return true;
    }
    else{
        return false;
    }
}

void solve(int arr[] , int n ){
    if(n==1){
        cout<<1<<endl;
    }

    for(int i = 0 ; i <n; i++){
        if(check(arr, n ,i)){
            cout << i+1<<endl;
        }
        // else{
        //     continue;
        // }
    }
}




int main() {

    int n ; ;
    cin>>n;

    int arr[n];

    for(int i = 0 ; i <n ;i++){
        cin>>arr[i];
    }

    solve(arr,n);

    // string s = "manya";
    // string s1 = " garg";
    // // s.append(s1);
    // s += s1;
    // cout<<s<<endl;
    
    // int n;
    // cin>>n;
    // string s[n];
    // for(int i =0 ; i <n ; i++){
    //     char c;
    //     cin>>c;
    //     s->insert(i,c);
    // }
    // cout<<s->size()<<endl;

    
}



















    //     int N,K,L;
    // cin>>N>>K>>L;

    // pair<int,int> p [N]; 
    // for(int i = 0 ; i < N; i++){
    //     cin>>p[i].first>>p[i].second;
    // }
    // // int sum = 0;
    // // int y = 0;
    // // for(int i = 0 ; i <N ;i++){
    // //     if(p[i].second == L  ){
    // //         sum += p[i].first;
    // //         y++;
    // //     }
    // //     else{
    // //         sum = -1;
    // //     }
    // // }
    // // cout << y <<" " <<sum<<endl;

    // // int max = 0;
    // vector<int> vec;
    // int sum = 0;

    
    //     for(int i = 0 ; i <N ;i++){
    //     if(p[i].second == L  ){
    //         vec.push_back(p[i].first);
    //     }
       
    //     }

    //     if(!vec.empty()){ 
    //     sort(vec.begin(), vec.end() , greater<int>());

    //     // if(vec.size() == 0){
    //     //     sum =-1;
    //     // }

    //     for(int i = 0 ; i <K ;i++){
    //         sum += vec[i];
    //     }
    //     }
    //     else{
    //         sum = -1;
    //     }

        // if(sum == 0){
        //     sum = -1;
        // }
        // cout<<-1<<endl;
        // cout<<sum<<endl;
	// your code goes here
	// return 0;


















// #include<iostream>
// #include <vector>
// #include<algorithm>
// using namespace std;

// int main(){
//     int N,K,L;
//     cin>>N>>K>>L;

//     pair<int,int> p [N]; 
//     for(int i = 0 ; i < N; i++){
//         cin>>p[i].first>>p[i].second;
//     }
//     int sum = 0;
//     int y = 0;
//     int arr[K];
//     for(int i = 0 ; i <N ;i++){
//         if(p[i].second == L  ){
//             // sum += p[i].first;
//             arr[i] = p[i].first;
//             y++;
//         }
//         else{
//             sum = -1;
//         }
//     }

//     sort(arr, greater<int>());

//      for(int i = 0 ; i <K ;i++){
//             sum += arr[i];
//         }


//     cout << y <<" " <<sum<<endl;





//     // int max = 0;






    // vector<int> vec;
    // int sum = 0;

    
    //     for(int i = 0 ; i <N ;i++){
    //     if(p[i].second == L  ){
    //         vec.push_back(p[i].first);
    //     }
       
    //     }
    //     sort(vec.begin(), vec.end() , greater<int>());

    //     if(vec.size() == 0){
    //         sum =-1;
    //     }

    //     for(int i = 0 ; i <K ;i++){
    //         sum += vec[i];
    //     }
    //     cout<<sum<<endl;
