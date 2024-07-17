#include<iostream>
#include <queue>
#include "binaryTree.h"
using namespace std;

binaryTreeNode<int> * takeInputLevelWise(){
    int data;
    cout<<"enter the data : "<<endl;
    cin>> data;
    if(data == -1){
        return NULL;
    }
    binaryTreeNode<int> * root = new binaryTreeNode<int>(data);
    queue<binaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        binaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<< " enter left child "<< front->data<<  endl;
        int leftChildData;
        cin>> leftChildData;
        if(leftChildData!= -1){
            binaryTreeNode<int> * child = new binaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }
        
        cout<< " enter right child "<< front->data << endl;
        int rightChildData;
        cin>> rightChildData;
        if(rightChildData!= -1){
            binaryTreeNode<int> * child = new binaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
        // front->left = takeInputLevelWise();
        // front->right = takeInputLevelWise();
        // root->left = front->left;
        // root->right = front->right;
        // pendingNodes.push(front->left);
        // pendingNodes.push(front->right);
    }
    return root;
    
}


binaryTreeNode<int> * takeInput(){
    int rootData;
    cout<<" enter data "<<endl;
    cin>> rootData;
    if(rootData==-1){
        return NULL;
    }
    binaryTreeNode<int> * root = new binaryTreeNode<int>(rootData);
    binaryTreeNode<int>* left = takeInput();
    binaryTreeNode<int>* right = takeInput();
    root->left = left;
    root->right = right;
    return root;
}

int countNode( binaryTreeNode<int> * root){
    if(root == NULL){
        return 0;
    }
    return 1 + countNode(root->left)+ countNode(root->right);
}

void printTreeLevelWise(binaryTreeNode<int> * root){
    if(root == NULL) {
        return;
    }

    queue<binaryTreeNode<int>*> pendingChild;
    pendingChild.push(root);

    while (pendingChild.size()!=0)
    {
        binaryTreeNode<int>* front = pendingChild.front();
        cout << front->data << " : ";
        pendingChild.pop();
        if(front->left!= NULL){
            pendingChild.push(front->left);
            cout<< front->left->data << ",";
        }
        if(front->right!= NULL){
            pendingChild.push(front->right);
            cout<<front->right->data<<",";
        }
        cout<<endl;
    }
    
}

void printTree(binaryTreeNode<int> * root){
    if(root == NULL){
        return ;
    }
    cout<< root->data<<" : " ;
    if(root->left != NULL){
        cout <<  " L " << root->left->data<<" ";
    }
    if(root->right != NULL){
        cout<< " R "<<root->right->data<<" ";
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}

bool  isNodePresent(binaryTreeNode<int> *root, int x) {
    if(root == NULL){
        return false;
    }
    if(root->data == x){
        return true;
    }

    bool ans1 = isNodePresent(root->left, x);
    if ( ans1 == true){
        return true;
    }

    bool ans2 = isNodePresent (root->right , x);
    if(ans2 == true){
        return true;
    }
}

int height(binaryTreeNode<int> * root){
    if(root == NULL){
        return 0;
    }
    int ans1 =1;
    if(root->left!=NULL){
        ans1= height(root->left)+1;
    }
    int ans2= 1;
    if(root->right!= NULL){
        ans2 = height(root->right)+1;
    }
    int ans = max(ans1,ans2);
    return ans;
}

void mirrorBinaryTree(binaryTreeNode<int>* root) {
    if(root==NULL){
        return;
    }
    else{
    binaryTreeNode<int> * temp ;

    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);

    temp = root->left;
    root->left = root->right;
    root->right = temp;

    // queue<binaryTreeNode<int>*> pendingNodes;
    // pendingNodes.push(root);
    // while (pendingNodes.size()!= 0)
    // {
    //     binaryTreeNode<int> * front = pendingNodes.front();
    //     pendingNodes.pop();
    //     if(root->left!=NULL && root->right!= NULL){
    //     cout<<front->right<<" "<<front->left<< endl;
        
    //     pendingNodes.push(root->left);
    //     pendingNodes.push(root->right);
    //     }

    }
    
    // mirrorBinaryTree(root->right);
    // mirrorBinaryTree(root->left);
    // // Write your code here
}

void inOrder( binaryTreeNode<int> * root){
    if(root == NULL){
        return;
    }
    
    cout<<root->data<<" ";
    inOrder(root->left);
    inOrder(root->right);
}

int getSum(binaryTreeNode<int>* root) {
    if( root == NULL){
        return 0 ;
    }
	int ans = root->data;

	if(root->left == NULL && root->right == NULL ){
		return ans;
	}

	if(root->right == NULL){
		return ans + root->left->data;
		getSum(root->left);
	}

	if(root->left == NULL){
		return ans + root->right->data;
		getSum(root->right);
	}

    if(root->right != NULL && root->left != NULL){
       int ans1 = getSum(root->left);
       int ans2 = getSum(root->right);
       return  ans +ans1 + ans2;
    }
    // Write your code here
}

binaryTreeNode<int> * buildTreeHelper(int * in , int * pre , int inS, int inE, int preS, int preE){  
    if( inS> inE){
        return NULL;
    }

    int rootData = pre[preS];
    int rootIndex = -1;
    for(int i = inS ; i<= inE; i++){
        rootIndex = i;
        break;
    }

    int lInS = inS ;
    int lInE = rootIndex -1;
    int lPreS = preS +1;
    int lPreE = lInE - lInS + lPreS;
    int rPreS = lPreE +1;
    int rPreE = preE;
    int rInS = rootIndex +1;
    int rInE = inE ;

    binaryTreeNode<int> * root = new binaryTreeNode<int>(rootData);
    root->left= buildTreeHelper(in , pre, lInS, lInE, lPreS, lPreE);
    root->right = buildTreeHelper(in , pre , rInS, rInE, rPreS, rPreE);
    return root;

}

binaryTreeNode<int> * buildTree(int* in , int* pre , int size){
    return buildTreeHelper(in , pre , 0 , size -1 , 0 , size -1);
}


bool searchInBST(binaryTreeNode<int>*root, int k){
    bool ans = false;
    if(root== NULL){
        return ans;
    }
    if( root->data== k){
        ans = true;
        return ans;
    }
    if( k < root->data){
        bool ans1 = searchInBST(root->left,k);
        if(ans1 == true){
            ans = true;
        }
    }
    if(root->data < k){
        bool ans2 = searchInBST( root->right, k);
        if(ans2== true){
            ans = true;
        }
    }
    return ans;

    // if(root== NULL){
    //     return false;
    // }
    // if(root->data==k){
    //     return true;
    // }
    // else{
       
    // if(root->data > k){
    //     bool ans1 = searchInBST(root->right,k);
    //     return ans1;
    //     // if(ans1 == true){
    //     //     return true;
    //     // }
    // }
    // else{
    //     bool ans2= searchInBST(root->left,k);
    //     return ans2;
    // }
    //     if(root->data < k)
    //   {
    //     bool ans2 = searchInBST(root->left,k);
    //     return ans2;
    //     // if(ans2 == true){
    //     //     return true;
    //     // }
    // }
    
}

void elementsInRangeK1K2(binaryTreeNode<int>* root, int k1, int k2) {
	if(root== NULL){
        return;
    }
    if( k1 <= root->data && root->data  <= k2){
        
        elementsInRangeK1K2(root->left,k1,k2);
        cout << root->data<< " ";
        elementsInRangeK1K2(root->right,k1,k2);
    }
    if(root->data>k2){
        elementsInRangeK1K2(root->left , k1, k2);
    }
    if(root->data < k1){
        elementsInRangeK1K2(root->right,k1,k2);
    }
}

bool helper(binaryTreeNode<int>* root , int min , int max){
    if(root== NULL){
        return true;
    }
    if(root->data>max || root->data < min){
        return false;
    }
    bool ans1= helper(root->left, min, root->data-1);
    bool ans2 = helper(root->right, root->data+1, max);

    return ans1 && ans2;
}

bool isBST(binaryTreeNode<int>* root){
    return helper(root, INT8_MIN , INT8_MAX);
}

int minimum(binaryTreeNode<int>* root){
    if(root== NULL){
        return INT8_MAX;
    }
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

int maximum(binaryTreeNode<int>* root){
    if(root== NULL){
        return INT8_MIN;
    }

    return max(root->data , max(maximum(root->left),maximum(root->right)));
}

bool isBST2(binaryTreeNode<int>* root){
    if (root == NULL)
    {
        return true;
    }
    int leftMax = maximum(root->left);
    int rightMax = minimum(root->right);
    bool output = (root->data> leftMax) && (root->data <= rightMax) && isBST2(root->left) && isBST2(root->right);
    return output;
    
}

bool isBST3(binaryTreeNode<int>* root , int min  = INT8_MIN , int max = INT8_MAX){
    if(root == NULL){
        return true;
    }

    if(root->data< min || root->data > max){
        return false;
    }
    bool isLeftOk = isBST3(root->left , min , root->data-1);
    bool isRightOk = isBST3(root->right , root->data , max);
    return isLeftOk && isRightOk;
}

// binaryTreeNode<int> * constructTree (int arr[ ], int start , int end){
//     if(start>end){
//         return NULL;
//     }
//     int mid = (start +end)/2;
//     binaryTreeNode<int >* root ;
//     root->data= arr[mid];
//     root->left = constructTree(arr, start, mid-1);
//     root->right = constructTree(arr,mid+1,end);
//     return root;

// }

void preOrder(binaryTreeNode<int> * root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
//1 2 3 4 5 6 7
// bst 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
//1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1

class BST{
    binaryTreeNode<int>* root;
    public:
    BST(){
        root = NULL;
    }
    ~BST(){
        delete root;
    }
    private:
    
    bool hasData(int data , binaryTreeNode<int> * node){
        if(node==NULL){
            return false;
        }
        if(node->data==  data){
            return true;
        }
        else if( data < node->data){
            return hasData(data, node->left);
        }
        else{
            return hasData(data,node->right);
        }
    }

    

    binaryTreeNode<int> * insert (int data , binaryTreeNode<int> * node){
        if(node == NULL){
            binaryTreeNode<int> * newNode = new binaryTreeNode<int>(data);
            return newNode;
        }

        if(data <= node->data){
            node->left = insert(data,node->left);
        }
        else{
            node->right = insert(data,node->right);
        }
        return node;
    }

    binaryTreeNode<int> * deleteData(int data , binaryTreeNode<int>* node){
        if(node==NULL){
            return NULL;
        }
        if(data < node->data){
            node->left = deleteData(data, node->left);
            return node;
        }
        else if (data > node->data){
            node->right = deleteData(data , node->right);
            return node;
        }
        else{
            if (node->left == NULL && node->right == NULL){
                delete node;
                return NULL;
            } else if(node->left == NULL){
                binaryTreeNode<int> * temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            } else if(node->right == NULL){
                binaryTreeNode<int> * temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else{
                binaryTreeNode <int> * minNode = node->right;
                while (minNode->left != NULL)
                {
                    minNode= minNode->left;
                }
                int rightMin = minNode->data;
                node->data = rightMin;
                node->right = deleteData(rightMin, node->right);
                return node;

            }
        }

    }

    void printTree(binaryTreeNode<int> * node){
        if(node==NULL){
            return ;
        }
        cout<<node->data<<" : ";
        if(root->left!= NULL){
            cout<<" L "<< node->left->data<<",";
        }
        if(root->right!=NULL){
            cout<<" R "<<node->right->data;
        }
        cout<<endl;
        printTree(node->left);
        printTree(node->right);
    }

    public:
    bool hasData(int data){
        return hasData(data, root);
    }

    void deleteData(int data){
        this->root = deleteData(data, this->root);
    }

    void insert(int data){
        this->root =  insert(data, this->root);
    }

    void printTree( ){
        printTree(root);
    }

};

int heightBinaryTree ( binaryTreeNode <int> * root){
    if(root == NULL){
        return 0 ;
    }

    return 1 + max(heightBinaryTree(root->left) , heightBinaryTree (root->right)) ; 
}


int Diameter(binaryTreeNode<int> * root){
    if(root==NULL){
        return 0;
    }

    int option1= heightBinaryTree(root->left) + heightBinaryTree(root->right);
    int option2 = Diameter ( root->left);
    int option3 = Diameter (root->right);

    return max(option1 , max (option2 , option3));
}

pair<int , int > heightDiameter ( binaryTreeNode<int> * root){
    if(root == NULL){
        pair<int, int > p;
        p.first= 0;
        p.second = 0;
        return p ;
    }

    pair<int, int > left  = heightDiameter(root->left);
    pair<int , int> right = heightDiameter(root->right);

    int ld = left.first; 
    int lh = left.second;
    int rd = right.first;
    int rh = right.second;

    int height = 1+ max ( lh , rh);
    int diameter = max( lh + rh , (max ( ld , rd)));

    pair<int, int > p;
    p.first = diameter ;
    p.second = height ;
    return p;

}

pair<int, int> getMinAndMax(binaryTreeNode<int> * root) {
	if(root== NULL){
		pair<int, int> p;
		p.first = INT8_MAX;
		p.second = INT8_MIN;
		return  p;
	}

	pair<int , int > left = getMinAndMax(root->left);
	pair<int , int > right = getMinAndMax(root->right);

	int lmax = left.second; 
	int lmin = left.first;
	int rmax = right.second;
	int rmin = right.first;

    int max  ;

    // 10 20 60 -1 -1 3 50 -1 -1 -1 -1 
    
    if(root->data > lmax) {
        if( root->data > rmax){
            max = root->data;
        }
        else{
            max = rmax ;
        }
    }
    else 
    {
        if(lmax > rmax){
            max = lmax;
        }
        else{
             max= rmax;
        }
    }

    int min;

    if(root->data < lmin) {
        if( root->data < rmin){
            min  = root->data;
        }
        else{
            min = rmin;
        }
    }
    else 
    {
        if(lmin < rmin){
            min = lmin;
        }
        else{
             min = rmin;
        }
    }
    

	// int max = max ( lmax , max( root->data , rmax));
	// int min = min( rmin , min ( root->data , lmin));

	pair<int , int > p ;
	p.first = min;
	p.second = max ;

	return  p;
	// Write your code here
}



bool isBalanced(binaryTreeNode<int> *root) {
    if(root == NULL){
        return true ;
    }

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    int lh = heightBinaryTree (root->left);
    int rh = heightBinaryTree (root->right);

    int i = rh - lh ;

    if( left == true && right == true){
        if( i == 1 || i == 0 || i== -1){
        return true ;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }

	// Write your code here
}

void printNodesWithoutSibling(binaryTreeNode<int> *root) {
    if( root == NULL){
        return ;
    }
    if(root->left!= NULL && root->right != NULL){ 

    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
    
    }

    if(root->left == NULL && root->right == NULL){
        return;
    }

    if( root->right == NULL){
        cout << root->left->data<<" ";
        printNodesWithoutSibling(root->left);
    }
    if( root->left == NULL){
        cout<< root->right->data;
        printNodesWithoutSibling(root->right);
    }
    // Write your code here
}


binaryTreeNode<int>* removeLeafNodes(binaryTreeNode<int> *root) {

    if(root == NULL){
        return NULL;
    }

    if(root->left== NULL&& root->right == NULL){
        return NULL;
        delete root;
    }

   binaryTreeNode<int> * left = removeLeafNodes(root->left);
    
   binaryTreeNode<int> * right =removeLeafNodes(root->right);

   root->left = left;
   root->right = right;

    return root;
    // Write your code here
}


void printLevelWise(binaryTreeNode<int> *root) {
	if(root== NULL){
        return ;
    }

    cout<<root->data<<" ";

    printLevelWise(root->left);
     
    // Write your code here
}


void levelOrderTraversal(binaryTreeNode<int> *root) {
	if(root == NULL) {
        return;
    }

    // binaryTreeNode<int> * root1 = new binaryTreeNode<int>(-1);

    queue<binaryTreeNode<int>*> pendingChild;
    pendingChild.push(root);
    pendingChild.push(NULL);

    while (pendingChild.size()!=0){
        binaryTreeNode<int>* front = pendingChild.front();

        if(front == NULL){
            cout<<endl;
            pendingChild.pop();
            if(!pendingChild.empty()){
                pendingChild.push(NULL);
            }
        }
        else{
            cout<<front->data<<" ";
            pendingChild.pop();
            if(front->left!= NULL){
                pendingChild.push(front->left);

            }
            if(front->right!= NULL){
                pendingChild.push(front->right);
            }
        }
        // if(front->data == -1){
        //     cout<<endl;
            
        //     pendingChild.pop();
        // }

        // else{

        // cout<<front->data<<" ";

        // pendingChild.push(front->left);
        // pendingChild.push(front->right);
        
        // pendingChild.pop();

        // }
        
    }
    
     
    // Write your code here
}

// 2 4 5 6 -1 -1 7 20 30 80 90 -1 -1 -1 -1 -1 -1 -1 -1
// 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

int main(){

      binaryTreeNode<int> * root = takeInputLevelWise();
      cout << getSum(root)<<endl;

    //   binaryTreeNode<int> * root1 = removeLeafNodes(root);

    //   printTreeLevelWise(root1);

      levelOrderTraversal(root);




    //   pair<int , int > p = heightDiameter(root);

    //   cout << " height : "<< p.second<<endl;
    //   cout<< " diameter : "<<p.first<<endl; 

    //   pair<int , int > m = getMinAndMax (root);

    //   cout << " min : " << m.first <<endl;
    //   cout <<" max : " << m.second <<endl;

    //   cout << isBalanced (root)<<endl;

    //   printNodesWithoutSibling(root);
    // BST bTree;
    // bTree.insert(10);
    // bTree.insert(5);
    // bTree.insert(7);
    // bTree.insert(21);
    // bTree.insert(11);
    // bTree.insert(9);
    // bTree.insert(12);
    // bTree.printTree();
    
    // int arr[]={1 ,2, 3, 4, 5, 6, 7};
    //  binaryTreeNode<int> * root = takeInputLevelWise();
    //  BST btree;
    
    //  cout<<btree.hasData(1);
   // binaryTreeNode<int>* root1 = constructTree(arr, 0 , 6);
    //preOrder(root1);
    //printTree(root1);
    
    
    //  bool x= isBST2(root);
    //  cout<<x<<endl;
    //  cout<< isBST3(root)<<endl;
     // binaryTreeNode<int> *root = new binaryTreeNode<int>(10);
    // binaryTreeNode<int> *left = new binaryTreeNode<int>(20);
    // binaryTreeNode<int> *right = new binaryTreeNode<int>(30);
    // root->left=left;
    // root->right= right;
    //  int k1 , k2;
    //  cin>> k1 >> k2;
    //  elementsInRangeK1K2(root, k1,k2);
    //  cout<< searchInBST(root,k)<<endl;

    // mirrorBinaryTree(root);
    // inOrder(root);
    // int in[] = {4,25,1,8,6,9,3,7};
    // int pre [] = {1,2,4,5,3,6,8,9,7};
    // binaryTreeNode<int> * root = buildTree(in , pre , 9);
    // printTree(root);

    // int x= height(root);
    // cout<<x;
    // int j = countNode(root);
    // cout<<  endl << j << endl;
    // printTree(right);
    // cout<<root->data<<endl;
    // cout<<root->left->data<<endl;
    // cout<<root->right->data<<endl;
}
/*bool isBST(binaryTreeNode<int> *root) {
    bool ans = false;
    if(root== NULL){
        ans = true;
        return ans;
    }
    if(root->data > root->left->data && root->data < root->right->data){
        ans = true;
        return ans;
        // ans = true;
        //bool ans1 = isBST(root->left);
        // if (ans1 == true)
        // {
        //     ans = true;
        // }
       // bool ans2 = isBST(root->right);
        //if()
        // if(ans2== true){
        //     ans = true;
        // }
        
    }
    else{
        ans = false;
        return ans;
    }
    bool ans1 = isBST(root->left);
    bool ans2 = isBST(root->right);
    if(ans1== true && ans2 == true){
        ans= true;
        return ans;
    }
    return ans;
	// Write your code here
}*/

//binaryTreeNode<int>* constructTree(int *input, int n) {
//     binaryTreeNode<int> * root ;
//     if(input[0]==n){
//         root->data = input[0];
//         return root;
//     }
//     binaryTreeNode<int> *left = constructTree( input , n/2);
//     binaryTreeNode<int> *right = constructTree( input + n/2 , n);
//     root->left = left;
//     root->right = right;
//     return root;

// }
