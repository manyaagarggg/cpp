#include <iostream>
#include <queue>
#include "treeNode.h"
using namespace std;

void print (treeNode <int> *root){
    cout << root->data << " : " ;
    
    for(int i= 0 ; i < root->children.size() ; i ++){
        cout << root->children[i]->data <<" , " ;
    }
    cout<< endl;
    for(int i =0 ; i < root->children.size(); i ++){
        print(root->children[i]);
    }    
}

// void prin

int main(){
    treeNode <int> *root = new  treeNode <int>  (10);
    treeNode <int> *child1 = new  treeNode <int> (20);
    treeNode <int> *child2 = new  treeNode <int> (30);

    root->children.push_back(child1);
    root->children.push_back(child2);

    cout<< root->data << endl;
    print(root);

}