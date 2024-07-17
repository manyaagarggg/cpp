#include "trieNode1.h"
#include <string>
using namespace std;


class trie{
    trieNode *root;
     public:
    trie() { 
        root = new trieNode('\0'); 
    }

    void insertWord( trieNode *root , string word) {
    if(word.size() == 0){
        root->terminal = true;
        return;
    }

    int index = word[0] - 'a' ;
    trieNode *child ;
    if(root->children[index] != NULL){
        child = root->children[index];
    }
    else{
        child = new trieNode (word[0]);
        root->children[index]= child;
    }

    insertWord(child , word.substr(1));
}



    void insertWord(string word){
      insertWord(root , word);
    }

    bool search(trieNode *root , string word){
        if(word.size() == 0){
            return root->terminal;
        }
        // if(root->terminal == true){
        //     return true;
        // }
        int index = word[0] - 'a';
        trieNode *child ;
        if(root->children[index]!= NULL){
            child = root->children[index];
        }
        else{
            return false;
        }
        return search(child, word.substr(1));
    }

    bool search ( string word){
        return search( root , word);
    }

    void removeWord( trieNode *root , string word){
        if(word.size() == 0){
            root->terminal = false;
            return;
        }

        int index = word[0] -'a';
        trieNode *child;
        if(root->children[index]!= NULL){
            child = root->children[index];
        }
        else{
            return;
        }

        removeWord (child , word.substr(1));


        if(child->terminal == false){
            for(int i=0 ; i < 26; i++){
                if(child->children[i]!= NULL){
                    return;
                }
            }
            delete child ;
            root->children[index] = NULL;
        }
    }


    void removeWord(string word){
        removeWord(root , word);
    }



};    