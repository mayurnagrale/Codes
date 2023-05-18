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

node* reverserec(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* newhead=reverserec(head->next);
    head->next->next=head;
    head->next=NULL;

    return newhead;
}

node* reverseK(node* &head,int k){
    node* prevptr=NULL;
    node* curr=head;
    node*next;
    int count=0;
    while(curr!=NULL && count<k){
        next=curr->next;
        curr->next=prevptr;
        prevptr=curr;
        curr=next;
        count++;
    }
    if(next!=NULL){
        head->next=reverseK(next,k);
    }
}

bool detectCycle(node* head){
    node* slow=head;
    node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}

void makeCycle(node* &head, int pos){
    node* temp=head;
    node* startNode;

    int count=1;
    while(temp->next !=NULL){
        if(count==pos){
            startNode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startNode;
}

void removeCycle(node* &head){
    node* slow=head;
    node* fast=head;

    do{
        slow=slow->next;
        fast=fast->next->next;
    }while(slow!=fast);
    fast=head;
    while(slow->next!=fast->next){
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=NULL;
}

int main(){
    node* head = NULL;
    insertAtTail(head,5);
    insertAtTail(head,10);
    insertAtHead(head,1);
    insertAtTail(head,2);
    insertAtTail(head,9);
    insertAtHead(head,6);
    //node* newhead=reverseK(head,2);
    makeCycle(head,3);
    //display(head);
    cout<<detectCycle(head)<<endl;
    removeCycle(head);
    cout<<detectCycle(head)<<endl;
    display(head);     
    return 0;
}