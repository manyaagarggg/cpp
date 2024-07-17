#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int x=0;
    int y = nums.size();
    for(int i = 0 ; i < nums.size() ; i ++){
        if(nums[x] == val){
            nums[i] = nums[i+1];
            x++;
        }
    }
    return nums.size()-x;
    // int y = nums.size()-x;
    // for(int i = 0 ; i <y ;i++){
    //     nums[i]=
    // }
}

int main(){
    vector<int> nums = {3,2,2,3};
    cout<< removeElement(nums,2)<<endl;
    for(int i = 0 ; i <nums.size() ;i ++){
        cout<<nums[i]<<endl;
    }
}