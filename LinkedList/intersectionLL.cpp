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

//find intersection of two linkedlist
int is(node * &head1,node * &head2){
    int len1=len(head1);
    int len2=len(head2);
    int d=0;
    node* ptr1=head1;
    node* ptr2=head2;

    if(len1>len2){
        d=len1-len2;
        ptr1=head1;
        ptr2=head2;
    }
    else{
        d=len2-len1;        
        ptr2=head1;
        ptr1=head2;
    }
    while(d){
        ptr1=ptr1->next;
        if(ptr1==NULL){
            return -1;
        }
        d--;
    }
    while(ptr1!=NULL && ptr2!=NULL){
        //for linked linked list that is intersected by nodes
        if(ptr1==ptr2){
            return ptr1->data;
        }
        //because we have two different node
        if(ptr1->data==ptr2->data){
            return ptr1->data;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return -1;
}

void intersect(node* &head1,node* &head2,int pos){
    node* temp1=head1;
    node* temp2=head2;
    pos--;
    while(pos--){
        temp1=temp1->next;
    }
    while(temp2->next!= NULL){
        temp2=temp2->next;
    }
    temp2->next=temp1;
}

int main(){
    node* head1 = NULL;
    node* head2 = NULL;
    int arr1[]={1,2,3,4,5,6};
    int arr2[]={9,10,5,6};
    for(int i=0;i<6;i++){
        insertAtTail(head1,arr1[i]);
    }
    for(int i=0;i<4;i++){
        insertAtTail(head2,arr2[i]);
    }
    display(head1);
    display(head2);
    intersect(head1,head2,5);
    cout<<is(head1,head2);
    return 0;
}