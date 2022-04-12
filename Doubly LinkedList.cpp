#include <iostream>
using namespace std;
class Node{
  public:
    int data;
    Node* prev;
    Node* next;
    //Constructor
    Node(int d){
        this->data=d;
        this->prev=NULL;
        this->next=NULL;
    }
    ~Node(){
        int val=this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
    cout<<"Memory Freed of Node with value  "<<val<<endl;
    }
};
// Length of Doubly-Linkedlist
int length(Node* &head){
    int cnt=0;
    Node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        cnt++;
    }
    return cnt;
}
//Traversing
void Traversing(Node* &head){
   Node* temp=head;
   while(temp!=NULL){
       cout<<temp->data<<" ";
       temp=temp->next;
   }
   cout<<endl;
}
void InsertatHead(Node* &head,int data){
    Node* temp=new Node(data);
    temp->next=head;
    head->prev=temp;
    head=temp;
}
void InsertatTail(Node* &tail,int data){
    Node* temp=new Node(data);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}
void InsertatPosition(Node* &tail,Node* &head,int position,int data){
    // Inserting at first position
    if(position==1){
        InsertatHead(head,data);
        return;
    }
    Node* temp=head;
    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        InsertatTail(tail,data);
        return;
    }
    Node* NodetoInsert=new Node(data);
    NodetoInsert->next=temp->next;
    temp->next->prev=NodetoInsert;
    temp->next=NodetoInsert;
    NodetoInsert->prev=temp;
}
void deleteNode(Node* &tail,Node* &head,int pos){
    if (pos==1){
        Node* temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
    }
    else{
        Node* prev=NULL;
        Node* curr=head;
        int cnt=1;
        while(cnt<pos){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
    if(curr->next == NULL) {
			tail = prev;
		}
    curr->prev=NULL;
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;
    }
}
int main()
{
    cout<<"Doubly-Linkedlist"<<endl;
    Node* node1=new Node(10);
    Node*head=node1;
    Node*tail=node1;
    Traversing(head);
    InsertatHead(head,20);
    InsertatHead(head,30);
    InsertatTail(tail,40);
    InsertatHead(head,50);
    Traversing(head);
    InsertatPosition(tail,head,4,60);
    Traversing(head);
    deleteNode(tail,head,5);
    Traversing(head);
    cout<<"length "<<length(head)<<endl;
    //cout<<"head data:"<<head->data<<endl;
    //cout<<"tail data:"<<tail->data<<endl;
    return 0;
}
