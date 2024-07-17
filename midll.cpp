#include <iostream>
using namespace std;

class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

 /*void *insertNode(Node* head , int j, int data){
     Node *newNode = new Node(data);
     Node *temp = head;
     int x=0;
     while (x<j-1&&temp!=NULL)
     {
         temp=temp->next;
         x++;
     } 
     if(temp!=NULL){
         Node *a= temp->next;
         temp->next=newNode;
         newNode->next=a;
     }    
 }
*/
void print(Node* head){
    while(head!=NULL){
    cout<<head->data<<endl;
    head=head->next;
    }
}

void printNode( Node *head , int i){
    Node *temp = head;
    int x=0;
    while (x<i-1 && temp!=NULL){
        temp = temp->next;
        x++;
    }
    if(temp==NULL)
    return;
    cout<<temp->data<<endl;
}

void printmid(Node *head ){
    Node *temp = head;
    Node *slow = temp;
    Node *fast= temp->next;
    while (fast!=NULL){
        slow = slow->next;
        fast =fast->next->next;
        if(fast==NULL||fast->next==NULL){
            cout<<slow->data<<endl;
        }
    }
    
        
    
}

void deleteIthNode(Node* head , int k){
    Node *temp= head;
    Node *prev = head;
    int i =0;
    for (i;i<k;i++){
        temp = temp->next;
    }
    for(int j = 0 ; j<k-1; j++){
        prev = prev->next;
    }
    prev->next=temp->next;
}
Node* deleteNode(Node* head, int pos){
   if(head == NULL) {
        return NULL;
    }
    
    Node *temp= head;
    if(pos == 0) {
        head = head -> next;
        delete temp;
        return head;
    }

    //Node *prev = head;
    //int i =0;
    for (int i=0; temp -> next != NULL && i < pos-1; i++) {
        temp = temp->next;
    }
    // for(int j = 0 ; j<pos-1; j++){
    //     prev = prev->next;
    // }
    // prev->next=temp->next;

    if(temp -> next != NULL) {
    	Node *a = temp -> next;
    	Node *b = a -> next;
    	temp -> next = b;
        delete a;
    }
    return head;
   
}

Node *sortTwoList(Node *head1,Node *head2){
    Node *head = NULL ;
    Node *tail = NULL;
    if(head1==NULL){
        return head2;
    }else if(head2==NULL){
        return head1;
    }
    if(head1->data > head2->data){
        tail = head2;
        head = head2;
        head2 = head2->next;
    }
    else {
        tail = head1;
        head = head1;
        head1 =head1 ->next;
    }
    while (head1!=NULL && head2!=NULL)
    {
          if (head1->data < head2->data) {
      tail->next = head1;
      tail = head1;
      head1 = head1->next;
    } else {
      tail->next = head2;
      tail = head2;
      head2 = head2->next;
    }
    }
    
   if (head1 != NULL) {

    tail->next = head1;
    
  }
  if (head2 != NULL) {

    tail->next = head2;
   
  }

  return head;
    
}

Node *appendLastToFirst(Node * head , int n){
   // Two pointers, one for traversal and 
	// other for finding the new head of LL
	Node *temp = head, *t = head;           
	//index maintained for finding new head
	int i = -n;
	while(temp->next!=NULL){
		//When temp went forward n nodes from t
		if(i>=0){                           
			t = t->next;
		}
		temp = temp ->next;
		i++;
	}
	//Connecting the tail to head
	temp->next = head;                      
	//Assigning the new node
	head = t->next;                         
	//Deleting the previous connection
	t->next = NULL;                         
	return head;
}

Node *appendNLastToFirst(Node * head , int n){
    int l=0;
    Node* temp = head;
    while (temp!= NULL)
    {
       temp=temp->next;
       l++;
    }
    temp= head;
    for(int i=0;i<l-n-1;i++){
        temp=temp->next;
    }
    Node* curr =temp;
    Node* curr1 =temp->next;
    Node* head2 =curr1;
    curr->next=NULL; 
    while (curr1->next!=NULL)
    {
        curr1=curr1->next;
    }
    curr1->next=head;
    return head2;
}

Node *removeDuplicate(Node *head){
    Node *temp =head;
      if(head==NULL){return head;}
    while (temp->next!= NULL)
    {
    if(temp->data==temp->next->data){
        temp->next=temp->next->next;
    }
    else{
    temp= temp->next;
    }
   }
    return head; 
}

Node *reverseList(Node * head ){
    Node* temp= head;
    
}

  Node *insertNode(Node *head ,int k , int element){
    if(head==NULL){
        return NULL;
    }
    
    Node* newNode = new Node(element) ;
    // newNode->data= element;
    Node * temp= head;
    if(k==0){
        newNode->next= head;
        return newNode;
    }
    else{
    for(int i = 0 ; i<k-1&&temp->next!=NULL;i++){
        temp=temp->next;
    }
    if(temp->next!=NULL){
        Node *a = temp->next;
        temp->next= newNode;
        newNode->next=a;
    }
    return head;
    }
}

Node *InsertNode(Node *head, int k, int element){
    if(head==NULL|| k==0){
        Node *newNode = new Node(element);
        newNode->next=head;
        head=newNode;

    }

    else{
        head->next= InsertNode(head->next,k-1,element);
    }
    return head;
    // if(head==NULL){
    //     return NULL;
    // }
      
    // else{
    //     if(k==0){
    //         Node *head2 = new Node(element);
    //         head2->next= head;
    //     }
    //     head->next= InsertNode(head->next,k-1,element);
         
    // }
    // return head;
   
}
int main(){
Node *head1 = takeinput();

 Node* x = InsertNode(head1,4 ,10);
print(x);

}

