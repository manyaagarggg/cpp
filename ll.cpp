#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

    Node* takeInput(){
        int data;
        cin>>data;
        int count = 0;
        Node *head = NULL;
        while (data!= -1)
        {
            Node *newNode = new Node(data);
            if(head == NULL){
                head =newNode;
            }
            else{
                Node *temp =head;
                while (temp->next !=NULL)
                {
                    temp=temp->next;
                    /* code */
                }
                temp->next = newNode;
            }
            cin>>data;
            count ++;
            /* code */
        }

       
        return head;

        
    }




void print(Node *head){
    Node *temp = head;
   int count =0;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
        count++;
    }
    cout<<endl<<count;
    cout << endl;
}

void printi(Node *head ,int i){
    Node *temp = head;
   for(int j =0 ; j=i;j++){
    cout<< temp->data<<" ";
   }

}
int main(){
   Node *head = takeInput();
   print(head);
   int i;
   cin>>i;
   printi(head,i);
}
