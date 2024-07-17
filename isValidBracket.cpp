#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

pair<int, int > solve(int n){
    pair<int , int> p ;
    if(n%2==0){
        // cout<<n/2<<" "<<n/2<<endl;
        p.first = n/2;
        p.second = n/2;
        return p;
    }
    else{
        if(n%10!=9){
            // cout<<(n-1)/2<<" "<<(n+1)/2<<endl;
            p.first = (n-1)/2;
            p.second = (n+1)/2;
            return p;
        }
        else{
            pair<int , int> x = solve(n/10);

            if(x.first == 0 || x.second == 1){ 
            p.first = 10*x.first +5;
            p.second = 10*x.second +4;
            }
            else{ 
            pair<int,int> y ,z;

            y.first = 10*x.first +5;
            y.second = 10*x.second +4 ;

            if((y.first - y.second) == 9){
                p.first = y.first;
                p.second = y.second;
            }
        

            z.first = 10*x.first +4;
            z.second = 10*x.second +5 ;

            if((z.first-z.second) ==9){
                p.first = z.first;
                p.second = z.second;
            }
            }
            
            return p;
        }
    }
}


    int getSum(int n)
    {
        int sum = 0;
        while (n != 0) {
            sum = sum + n % 10;
            n = n / 10;
        }
        return sum;
    }

void solve1(int n){
    for(int i =0 , j =n ; i<n , j >=0 ; i++ , j --){
        if(i>=j){
            break;
        }
        if((getSum(j) - getSum(i)) <= 1 && (getSum(i) - getSum(j)) <= 1){
            cout<<i<<" "<<j<<endl;
        }
        
    }
}



int main(){
    int n;
    cin>>n;
    solve1(n);
    // cout<<getSum(8);
    // pair<int,int> p = solve(n);
    // cout<<p.first <<" "<<p.second<<endl;
}























// bool isValid(string str){
//     stack<char> s1;
//     for(int i =0 ; i <str.length() ; i++){
//         if(str[i] == '(' || str[i] == '{' || str[i] == '['){
//             s1.push(str[i]);
//         }
//         else{
//             char x = s1.top();
//             if(x == str[i-1]){
//                 return true;
//                 s1.pop();
//             }
//             else{
//                 return false;
//                 break;
//             }
//         }
//     }
// }



    // string str = "{()]";
    // if(isValid(str)){
    //     cout<<"true"<<endl;
    // }