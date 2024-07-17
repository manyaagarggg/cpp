#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int x = *max_element(height.begin(), height.end() );

//     }
// };
#include <bits/stdc++.h> 
#include <string>

string findDivision(int x, int y, int n) {
	string str;
	int i = 0 ;
	int j =0;
	while(i<=n){
		if(x/y>=y){
			str[j] = x/y;
			j++;
		}
		else{
			if(x/y==0){
				str[j]=0;
				j++;
				i++;
			}
			else{
				str[j]= (x*10)/y;
				j++;
				i++;
			}
		}

	}
	return str;
	// Write your code here.
}

int main(){
    string str;
    str = findDivision(5,4,1);
    cout<<str;
    // cout<< 6%4;
    // int num[] = {3,2,4};
    // int target = 6;
    // int sum =0 ;
    // for(int i = 0 ; i < sizeof(num) ; i ++){
    //     if(sum)
    // }
}