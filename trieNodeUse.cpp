#include <iostream>
#include "trieNode.h"
using namespace std;

int main (){
    trie t ;
    t.insertWord("manya");
    t.insertWord("vidit");
    t.insertWord("garg");

    cout<< t.search("garg") <<endl;


    t.removeWord("garg");
    cout<< t.search("garg") <<endl;

    cout<< t.search ("manya")<<endl;
    cout<< t.search ("vidit")<<endl;

    
}    