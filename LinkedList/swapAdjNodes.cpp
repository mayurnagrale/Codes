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

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

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
//work for even length of linked list by swapping the values
node* swapAdj(node* head){
    node* temp=head->next;
    node* temp1=NULL;
    node* temp2=head;
    int prevdata=head->data;
    int nextdata=head->data;
    while(temp2->next!=NULL){
        temp1=temp2->next;
        temp2=temp2->next->next;;
        if(temp2==NULL){
            node* newtemp=new node(prevdata);
            temp1->next=newtemp;
            break;
        }
        else{
            if(temp2->next==NULL){
                node* newtemp=new node(prevdata);
                temp2->next=newtemp;
                break;
            }
        }
        nextdata=temp2->data;
        temp2->data=prevdata;
        prevdata=nextdata;
    }
    return temp;
}

//without swapping values 
node* swappairs(node *head){
    node* p1=head,*p2=head->next;
        node* rnode=p2;
        node* temp=p2->next;
        while(temp!=NULL){
            p1->next=p2->next;
            p2->next=p1;
            p1=temp;
            p2=temp->next;
            temp=p2->next;
        }
        return rnode;
}
int main(){
    node* head1=NULL;
    int arr1[]={1,2,3,4,5,6,7};
    int l=sizeof(arr1)/sizeof(int);
    for(int i=0;i<l;i++){
        insertAtTail(head1,arr1[i]);
    }
    display(head1);
    node* newNode=swappairs(head1);
    display(newNode);
    return 0;
}