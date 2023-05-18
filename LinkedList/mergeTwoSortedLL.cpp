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

//merging two sorted linkedlist
node * mergeLL(node* &head1,node* &head2){
    node* p1=head1;
    node* p2=head2;
    node* dummyNode=new node(-1);
    node* p3=dummyNode;
    while(p1!=NULL && p2!=NULL){
        if(p1->data<p2->data){
            p3->next=p1;
            p1=p1->next;
        }
        else{
            p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;
    }

    while(p1!=NULL){
        p3->next=p1;
        p1=p1->next;
        p3=p3->next;
    }
    while(p2!=NULL){
        p3->next=p2;
        p2=p2->next;
        p3=p3->next;
    }
    
    return dummyNode->next;
}

//Merge two linked list recursively
node* mergerecursively(node* &head1,node* &head2){
    node* result;

    //base case
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }

    if(head1->data<head2->data){
        result=head1;
        result->next=mergerecursively(head1->next,head2);
    }
    else{
        result=head2;
        result->next=mergerecursively(head1,head2->next);
    }

    return result;
}


int main(){
    node* head1 = NULL;
    node* head2 = NULL;
    int arr1[]={1,4,5,7};
    int arr2[]={2,3,6};
    for(int i=0;i<4;i++){
        insertAtTail(head1,arr1[i]);
    }
    for(int i=0;i<3;i++){
        insertAtTail(head2,arr2[i]);
    }
    display(head1);
    display(head2);
    node* newHead=mergerecursively(head1,head2);
    display(newHead);
    return 0;
}