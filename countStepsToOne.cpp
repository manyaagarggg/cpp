#include <iostream>
using namespace std; 

int countStepsToOne(int n)
{
	int *ans = new int[n+1];

	ans[0]=0;
	ans[1]=0;
	ans[2]=1;
	ans[3]=1;

	for(int i =4 ; i<=n ;i++){
		int a = 1 + ans[i-1];

        int b = INT8_MAX  , c = INT8_MAX;

		if(i%2==0){
			b = 1 + ans[i/2];
		}
		if(i%3==0){
			c = 1+ ans[i/3];
		}

		ans[i] = min(a, min(b,c));
	}

	return ans[n];
	//Write your code here
}

int main(){
    int n ;
    cin >> n ;
    cout<< countStepsToOne(n) <<endl;
}