#include <iostream>
using namespace std;
class Node{
    //Public  
    public:
        int data;
        Node* next;
    // Constructor
    Node(int data){
        this-> data=data;
        this-> next=NULL;
    }
    ~Node(){
        int value=this->data;
        //Memory free
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"Memory Freed of Node with value  "<<value<<endl;
        
    }
};
int length(Node* &head){
    int cnt=0;
    Node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        cnt++;
    }
    return cnt;
}
//--------->>>>> Inserting an element at starting of Linkedlist
void insertATHead(Node* &head,int data){
    Node* temp= new Node(data);
    temp->next=head;
    head=temp;
}
void insertATtail(Node* &tail,int data){
    Node* temp= new Node(data);
    tail->next=temp;
    tail=temp; // or tail=tail->next;
}
//--------->>>>> Printing element of Linkedlist
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void insertAtposition(Node* &tail,Node* &head,int position,int data){
    // Inserting at first position
    if(position==1){
        insertATHead(head,data);
        return;
    }
    Node* temp=head;
    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        insertATtail(tail,data);
        return;
    }
    Node* NodetoInsert=new Node(data);
    NodetoInsert->next=temp->next;
    temp->next=NodetoInsert;
    
}
void deletion(int pos,Node* &head){
    if (pos==1){
        Node* temp=head;
        head=head->next;
        //Memory free
        temp->next=NULL;
        delete temp;
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
        prev->next=curr->next;
        //tail=curr->next;
        curr->next=NULL;
        delete curr;
        }
}
int main()
{
    cout<<" Singly Linkedlist-->"<<endl;
    Node* node1= new Node(1);
    Node* head=node1;
    Node* tail=node1;
    print(head);
    insertATHead(head,2);
    print(head);
    insertATHead(head,3);
    insertATtail(tail,4);
    print(head);
    insertAtposition(tail,head,2,5);
    print(head);
    insertAtposition(tail,head,1,6);
    insertAtposition(tail,head,5,7);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    deletion(6,head);
    print(head);
    cout<<"length of Linkedlist "<<length(head)<<endl;
    return 0;
}
