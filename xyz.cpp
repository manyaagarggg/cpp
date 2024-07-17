#include <iostream>
using namespace std;

int main(){
int n;
cin>>n;

for (int d=1;d<n;d++){
for(int i=2;i<d;i++){
if(d%i!=0){
    cout<<d<<endl;
}
}
}	
return 0;

    /* Read input as specified in the question.
	 * Print output as specified in the question.
	 */
  
}
