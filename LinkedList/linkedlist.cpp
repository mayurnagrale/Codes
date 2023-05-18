#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};

void insertAtTail(node* &head,int val){
    node* n1=new node(val);
    if(head==NULL){
        head=n1;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n1;
}

void insertAtHead(node* &head,int val){
    node* n2 = new node(val);
    n2->next=head;
    head=n2;
}

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

bool search(node* head,int key){
    if(head->data==key){
        return true;
    }
    while(head->next!=NULL){
        head=head->next;
        if(head->data==key){
        return true;
        }   
    }
    return false;
}

void deleteNode(node* &head,int key){
    node* deleteHead;
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        delete head;
    }
    if(head->data==key){
        deleteHead=head;
        head=head->next;
        delete deleteHead;
        return;
    }
    node* temp=head;
    while(temp->next->data!=key){
        temp=temp->next;
    }
    node* toDelete=temp->next;
    temp->next=temp->next->next;

    delete toDelete;
}

//Print ll using linked list
void printData(node* &head){
    if(head==NULL){
        return;
    }
    cout<<head->data<<" ";
    printData(head->next);
    cout<<head->data<<" ";
}

int main(){
    node* head = NULL;
    insertAtTail(head,5);
    insertAtTail(head,10);
    insertAtHead(head,1);
    printData(head);
    // display(head);
    // cout<<search(head,5)<<endl;
    // deleteNode(head,5);
    // display(head);
    // deleteNode(head,1);
    // display(head);
    // deleteNode(head,10);
    // display(head);
    return 0;
}