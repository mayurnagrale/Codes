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

//Calculate the length of the linked list
int len(node* head){
    int count=0;
    node* temp =head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

//Put even position nodes after odd position nodes
void oe(node* &head){
    node* odd=head;
    node* even=head->next;
    node* evenStart=even;

    while(odd->next!=NULL && even->next!=NULL){
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    odd->next=evenStart;
    if(odd->next==NULL){
        even->next=NULL;
    }

}

int main(){
    node* head = NULL;
    int arr[]={1,2,3,4,5,6};
    for(int i=0;i<6;i++){
        insertAtTail(head,arr[i]);
    }
    display(head);
    oe(head);
    display(head);
    return 0;
}