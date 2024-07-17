#include<iostream>
using namespace std;

    int evenlyDivides(int N){
        int num = N;
        int count = 0 ;
        while(num!=0){
            num = num%10;
            if(N%num == 0){
                count++;
            }
        }
        return count;
        //code here
    }


int main(){

    int ans[] = {1,2,3,4,5};
    int * point =NULL ;
    point = &ans[3];
    *point = 5;
    for(int i = 0 ; i < 5 ; i ++){
        cout << ans[i] << endl;
    }

    // string s = "20";
    // char c = s[0];
    // int y = c -'0';
    // cout<<y;
    
    // cout << evenlyDivides(12);
    // int x = -2147483648 , y = -10;
    // x = -x ;
    // y= -y;
    // cout<<x <<" "<<y;
    // int x = 100;
    // int y = !x;
    // cout<<y;
//    int n;
//    cin>>n;
//    int arr[n];
//    for(int i = 0 ; i <n ; i++){
//     cin>>arr[i];
//    }
//    int mihai = 0;
//    int bianca =0;
//    for(int  i = 0 ; i <n;i++){
//     if(arr[i]%2==0){
//         mihai = arr[i]+mihai;
//     }
//     else{
//         bianca = arr[i]+bianca;
//     }
//    }
//    if(mihai>bianca){
//     cout<<"yes"<<endl;
//    }
//    else{
//     cout<<"no"<<endl;
//    }
//    cout << ~n<<endl;
}