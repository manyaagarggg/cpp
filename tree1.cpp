#include <iostream>
#include <queue>
#include "tree1.h"
using namespace std;

treeNode <int> * takeInputLevelWise(){
    int data;
    cout<<"enter the data : "<<endl;
    cin>> data;
    treeNode<int> * root = new treeNode <int>(data);
    queue<treeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size()!=0)
    {
       treeNode<int> *front =  pendingNodes.front();
       pendingNodes.pop();
       cout<<"enter number of child of "<< front->data<<endl;
       int numChild;
       cin>>numChild;
       for(int i =0 ; i< numChild;i++){
        int childData;
        cout<<"enter "<<i<<"th child of"<< front->data<<endl;
        cin>>childData;
        treeNode<int>* child = new treeNode<int>( childData);
        front->children.push_back(child);
        pendingNodes.push(child);
       }
    }
    return root;
}

treeNode <int> * takeInput(){
    int data;
    cout<<"enter the data :"<<endl;
    cin>>data;
    treeNode<int> * root = new treeNode <int>(data);
    cout << " enter number of children :"<<endl;
    int n;
    cin>>n;
    for(int i=0; i<n;i++){
       treeNode<int> * child =  takeInput();
       root->children.push_back(child);
    }
    return root;

}


treeNode<int> * maxNode(treeNode<int>* root){
    treeNode<int> * max = new treeNode<int>(root->data) ;
    for(int i=0;i<root->children.size();i++){
        treeNode<int>* a = maxNode(root->children[i]);
        if(a->data >= max->data){
            max->data = a->data;
        }
    }
    return max;
}


void printLevelWise(treeNode<int>* root) {
    // Write your code here
    if(root == NULL) {
        return;
    }

    queue<treeNode<int>*> pendingChild;
    pendingChild.push(root);

    while(pendingChild.size() != 0) {
        treeNode<int>* front = pendingChild.front();
        cout << front -> data << ":";
        
        pendingChild.pop();
        for(int i = 0; i < front -> children.size(); i++) {
            pendingChild.push(front->children[i]);
            if(i == front->children.size()-1) {
                cout << front -> children[i] -> data;
            } else {
            	cout << front -> children[i] -> data << ",";
            }
        }
        cout << endl;
    }
}

int countNodes(treeNode<int> *root){
    int count = 1;
    for(int i=0; i<root->children.size();i++){
        count = count + countNodes(root->children[i]);
    }
    return count;
}


int sumOfNodes(treeNode<int> *root){
    int sum = root->data;
    for(int i =0; i< root->children.size(); i++){
        sum = sum + sumOfNodes(root->children[i]);
    }
    return sum;
}

int getHeight(treeNode<int> * root){
    int ans =0 ;

    for (int i =0; i< root->children.size();i++){
        ans  = max(ans , getHeight ( root->children[i]));

    }

    return ans +1;


   /* int height = 1;
    for(int i =0 ;i<root->children.size(); i++){
        int height2 =  getHeight(root->children[i]);
        if(height2 > height){
            height = height + height2;
        }
    }
    return height;*/
}

void NodeAtK(treeNode <int> * root , int k){
    if(root == NULL ){
        return ;
    }
    if(k==0){
        cout<<root->data<<endl;
    }

    for(int i =0 ; i< root->children.size(); i++){
        NodeAtK(root->children[i] , k-1);
    }

}

int getLeafNodeCount(treeNode<int>* root) {
   int ans =0 ;
   if(root== NULL){
    return 0;
   }
    if(root->children.size()==0){
         ans++;
    }
     else{
    for(int i = 0; i< root->children.size(); i++){
        ans = ans + getLeafNodeCount(root->children[i]);
    }
     }
     return ans;
}


void PostOrder (treeNode<int> *root){
    
    for (int i = 0; i < root->children.size(); i++)
    {
        PostOrder(root->children[i]);
        
    }
    cout<<root->data<<" ";
    
}


int getLargeNodeCount(treeNode<int>* root , int k){
    int ans = 0;
    if(root->data> k){
        ans++;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        ans = ans + getLargeNodeCount(root->children[i],k);
    }
    return ans;
    
}

// treeNode<int> * maxSumNode(treeNode<int>* root){
//     int sum = root->data;
//     for(int i =0 ; i< root->children.size();i++){
//         sum = sum +root->children[i]->data;
//     }
//     int m =0;// new treeNode<int>(sum);
//     for(int i =0 ; i< root->children.size(); i++){
//         treeNode<int> * max = maxSumNode(root->children[i]);
//         if(sum > m){
//             m=root->children[i]->data;

//         }
//     }
// }



treeNode<int>* getNextLargerElement(treeNode<int>* root, int x) {
    treeNode<int> * ans;
    if(root->data > x){
        ans = root;
        return ans;
     
    }
       

    for(int i = 0; i< root->children.size(); i++){
        treeNode<int> * y = getNextLargerElement(root->children[i], x);
        break;
    }
    // Write your code here
}


treeNode<int>* getSecondLargestNode(treeNode<int>* root) {
    
    // Write your code here
}

 void printNodeLevelWise(treeNode<int> *root){
    queue<treeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size()!=0){
        treeNode<int>* front = pendingNodes.front();
        cout<< front->data<<" : ";
        pendingNodes.pop();
        for(int i=0; i<front->children.size();i++){
            pendingNodes.push(front->children[i]);
            if(i==front->children.size()-1){
                cout<<front->children[i]->data;
            }
            else{
                cout<<front->children[i]->data<<",";
            }
        }
        cout<<endl;
    }
    
}


void printTree(treeNode<int> *root){
    cout<<root->data<<":";
    for(int i =0 ; i<root->children.size(); i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i =0 ; i< root->children.size(); i++){
        printTree(root->children[i]);
    }
}

// 1 3 2 3 4 2 5 6 2 7 8  0 0 0 0 1 9 0 

int main(){
    // treeNode<int> *root = new treeNode<int>(10);
    // treeNode<int> *node1 = new treeNode<int>(20);
    // treeNode<int> *node2 = new treeNode<int>(30);

    // root->children.push_back(node1);
    // root->children.push_back(node2);
    treeNode<int>* root = takeInputLevelWise();

    printTree(root);
    printLevelWise(root);

     printNodeLevelWise(root);
     
    //  treeNode<int>* k = getNextLargerElement(root ,1);
    //  cout<< k->data;
    //  cout<< k <<endl;
    //  PostOrder(root);
    // NodeAtK(root, 3);
    // int h = getHeight( root);
    // cout<< h;
    // treeNode<int> * max  = maxNode(root);
    // cout<< max->data ;
}