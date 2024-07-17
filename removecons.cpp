#include <iostream>
#include <cstring>
using namespace std;



void removeAllOccurrencesOfChar(char input[], char c) {
    for(int i=0;i<strlen(input);i++){
        if(input[i]==c){
            for(int j =i ; j<strlen(input);j++){
            input[j]=input[j+1];
            }
        }
    }

    // Write your code here
}

int main() {
   int size = 1e6;
    char str[size];
    
    cin >> str;
    removeAllOccurrencesOfChar(str, 'a');
      cout << str;
}