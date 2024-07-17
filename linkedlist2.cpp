#include <iostream>
using namespace std;
#include "node.cpp"

Node *takeInput(){
    int data;
    cin>>data;
    Node *head= NULL;
    Node *tail = NULL;
    while(data!=-1){
        Node *newNode = new Node(data);
        if(head== NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail= tail->next;
        }
        // if(head==NULL){
        //     head=newNode;
        // }
        // else{
        //     Node *temp = head;
        //     while (temp->next!=NULL)
        //     {
        //         temp = temp->next;
        //     }
        //     temp->next = newNode;
        // }
        cin>>data;
    }
    return head;
}
Node* insertNode(Node *head , int i , int data){
    Node *newNode = new Node(data);
    int count= 0;
    Node *temp = head;
    if(i==0){
        newNode->next= head;
        head = newNode;
        return head;
    }
    while(temp!= NULL && count < i-1){
        temp = temp->next;
        count++;
    }
    if(temp!= NULL){
    newNode->next=temp->next;
    temp->next= newNode;
    }
    return head;
}


Node * deleteNode(Node * head , int i ){
    int count = 0 ;
    Node *temp = head;
    if(i==0){
        head = head->next;
        delete temp;
        return head; 
    }
    while (temp != NULL && count<i-1)
    {
      temp = temp->next;
      count++;
    }
    if(temp!= NULL){
        Node *a = temp->next;
        Node *b = a->next;
        temp->next=b;
        return head;
    }
    
}
Node* insertNodeRecursively(Node* head, int i , int data){
    if(i==0){
        Node *newNode = new Node(data);
        newNode->next= head ;
        head = newNode;
    }
    else{
        head->next= insertNodeRecursively(head->next, i-1 , data);
    }
    return head;
}

Node* insertatk(Node* head, int k, int data)
{
	if (head == NULL)
		return NULL;

	if (k == 0) {
		Node* newnode = new Node(data);
		newnode->next = head;
		head = newnode;
		return head;
	}
	else
		head->next=insertatk(head->next, k-1, data);
        //we do k-1 so as to reach the required place

	return head;
}

Node *deleteAtK (Node *head , int k ){
    if(head == NULL){
        return NULL;
    }
    if(k==0){
        Node * temp = head ;
        head = head->next;
        return head; 
    }
    else{
        head->next = deleteAtK(head->next, k-1);
    }
    return head;
}

int findNode(Node *head, int n){
    Node *temp = head;
    int count=0;
    while(temp!= NULL){
    if(temp->data == n){
        return count;
       
    }
    // else{
    //     return -1;
    // }
    temp = temp->next;
    count++;
     
    }
    // for(int i=0;temp!=NULL;i++){
    //     if(temp->data==n){
    //         return count;
    //     }
    //     temp=temp->next;
    //     count++;
    // }
    // Write your code here.
}


Node *mergeTwoSortedLL(Node *head1 , Node *head2){
    Node *head;
    Node *tail;
    if(head1 == NULL){
        return head2;
    }
    
    if(head2 == NULL){
        return head1;
    }

    if(head1->data<head2->data){
        head = head1;
        tail= head1;
        head1= head1->next;
    }
    else{
        head = head2;
        tail = head2;
        head2 = head2->next;
    }

    while (head1 != NULL && head2 != NULL)
    {
        if(head1->data<head2->data){
            tail->next= head1;
            tail=head1;
            head1= head1->next;
        }
        
        else{
            tail->next= head2;
            tail=head2;
            head2 = head2->next;
        }
    }
    if(head1 != NULL){
        tail->next = head1;
    }
     if(head2!= NULL){
        tail->next = head2;
     }

     return head;
    
}

Node *mergeSort (Node *head){
    if(head== NULL || head->next == NULL ){
        return head;
    }

    Node *slow = head;
    Node *fast = head;
    while ( fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node * head2 = slow->next;
     slow->next = NULL;
     Node * head1 = head ;
     Node * x = mergeSort (head1);
     Node * y = mergeSort(head2);
      Node * z = mergeTwoSortedLL(x,y);
       return z;
    
}


Node *reverseLL(Node *head){
    

    if(head == NULL || head->next == NULL){
        return head;
    }

    Node * smallAns = reverseLL(head->next);
    Node *temp = smallAns;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
     temp->next = head ;
     head->next =NULL;
     return smallAns ;
}


void print(Node *head){
    
    while (head!= NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    
}
int main(){
    Node *n = takeInput();
    print(n);
    Node * j = reverseLL (n);

    // Node * j = mergeSort (n);
     
     print (j);
    // print(n);
    // Node * m = takeInput();
     
    //  Node * ans = mergeTwoSortedLL(n,m);
    //  print ( ans);
    // int i , data;
    // cin>>i>>data;
    // n = insertatk(n,i,data);
    // print(n);
    // int j = findNode(n , 6);
    // cout<<j;
    // Node n(30);
    // cout<<n.data<<endl;
    // Node n1(40);
    // n.next = &n1;
    // cout<<n.data<<" "<<n.next->data<<endl; 
}