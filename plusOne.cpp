#include <iostream>
#include <vector>
#include <algorithm>
// #include <unod
using namespace std;

// vector<int> plusOne( vector<int> & digits){
//     int n = digits.size();
//     if((n-1) == 9){

//     }
//     digits[n-1] += 1 ;
// }

    char nextGreatestLetter(vector<char>& letters, char target) {
        int num = target;
        for(int i = 0 ; i < letters.size() ; i++){
            int check = letters[i];
            if(check == num && (i+1) != letters.size()){
                return letters[i+1];
            }
            if( check > num){
                return letters[i];
            }
        }
        return letters[0];
    }

        bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int x = arr[1]- arr[0];
        for(int i = 1 ; i < arr.size(); i++){
            
            if((arr[i] - arr[i-1]) != x){
                return false;
            }
        }
        return true;
    }

int main(){

    vector<int> arr = {3,5,1};

    if(canMakeArithmeticProgression(arr)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }

    // vector<char> letters = {'c' , 'f' , 'j'};
    // char target = 'j';
    // char ans = nextGreatestLetter(letters, target);
    // cout<<ans<<endl;
    // cout<<ans+1<<endl;
    // cout<<ans+2<<endl;
    // cout<<ans+3<<endl;
}