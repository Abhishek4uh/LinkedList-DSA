#include <iostream>
using namespace std;
//Class
class Node{
  public:
    int data;
    Node* next;
    //Constructor
    Node(int d){
        this->data=d;
        this->next=NULL;
    }
    //Destructor
    ~Node(){
        int val=this->data;
        if(this->next!=NULL){
            delete next;
            next=NULL;
        }
    cout<<"Memory Freed of Node with value "<<val<<endl;
    }
};
//INSERTION in Circular Linkedlist 
//we finding the ele then inserting data after ele:
void INSERT(Node* &tail,int ele,int data){
    //Empty List
    if(tail==NULL){
        Node* temp=new Node(data);
        tail=temp;
        temp->next=temp;
    }
    else{
        // Non Emptylist
        Node* curr=tail;
        while(curr->data!=ele){
            curr=curr->next;
        }
        Node* temp=new Node(data);
        temp->next=curr->next;
        curr->next=temp;
    }
}
//Traversal in Circular Linkedlist
void PRINTING(Node* &tail){
    Node* temp=tail;
    //empty list
    if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }
        do{
            cout<<tail->data<<" ";
            tail=tail->next;
        }while(tail!=temp);
        
        cout<<endl; 
    
}
//DELETION in Circular Linkedlist 
//Val wise DELETION first we find the val then deleting that val:
void DELETION(Node* &tail,int val){
    if (tail==NULL){
        cout<<"Linkedlist is already Empty"<<endl;
        return;
    }
    else{
        //Assuming val is present in the Linkedlist
        Node* prev=tail;
        Node* curr=prev->next;
        while(curr->data!=val){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        // when only one element present in Linkedlist
        if (curr==prev){
            tail=NULL;
        }
        // when >=2 element present in the Linkedlist
        if(tail==curr){
            tail=prev;
        }
        curr->next=NULL;
        delete curr;
    }
}
//LENGTH of Linkedlist
int LENGTH(Node* &tail){
    int cnt=1;
    Node* temp=tail;
    while(temp->next!=tail){
        temp=temp->next;
        cnt++;
    }
    return cnt;
}
int main()
{
    cout<<"Circular Linkedlist"<<endl;
    Node* tail=NULL;
    INSERT(tail,5,100);
    INSERT(tail,100,200);
    INSERT(tail,200,300);
    INSERT(tail,300,400);
    cout<<"LENGTH of Linkedlist"<<LENGTH(tail)<<endl;
    PRINTING(tail);
    DELETION(tail,200);
    PRINTING(tail);
    DELETION(tail,100);
    PRINTING(tail);
    return 0;
}
