#include<bits/stdc++.h>
using namespace std;

// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

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

int getNumber(node* head){
    node* temp=head;
    int val=0;
    int m=10;
    int count=0;
    while(temp!=NULL){
        if(count>0){
            val=val + temp->data*m;
            for(int i=0;i<count;i++){
                m=m*10;
            }
        }
        else{
            val=val+temp->data;
        }
        temp=temp->next;
        count++;
    }
    return val;
}

node* addTwoNumbers(node* &head1,node* &head2){
    node* head=NULL;
    int r=getNumber(head1)+getNumber(head2);
    int val=0;
    while(r){
        val=r%10;
        insertAtTail(head,val);
        r=r/10;
    }
    return head;
}

//solution using right shift carry
node* addNumbers(node* &head1,node* &head2){
    node* ans=new node(0);
    node* p=head1;
    node* q=head2;
    node* temp=ans;
    int carry=0;
    while(p!=NULL || q !=NULL){
        int x= (p!=NULL) ? p->data:0;
        int y= (q!=NULL) ? q->data:0;
        int sum=carry + x+y;
        carry=sum/10;
        temp->next=new node(sum%10);
        temp=temp->next;
        if(p!=NULL) p=p->next;
        if(q!=NULL) q=q->next;
    }
    if(carry>0){
        temp->next=new node(carry);
    }
    return ans->next;
}

//solution using recursion
node* addNumbersRecursive(node* &head1,node* &head2,int carry){
    node* result;
    if(head1==NULL && head2==NULL){
        return result;
    }
    int sum=carry+head1->data+head2->data;
    carry=sum/10;
    result=new node((sum%10));
    result->next=addNumbersRecursive(head1->next,head2->next,carry);
    return result;
}

int main(){
    node* head1=NULL;
    node* head2=NULL;
    int arr1[]={2,4,3};
    int arr2[]={5,6,4};
    for(int i=0;i<3;i++){
        insertAtTail(head1,arr1[i]);
    }
    for(int i=0;i<3;i++){
        insertAtTail(head2,arr2[i]);
    }
    node* a=addTwoNumbers(head1,head2);
    display(head1);
    display(head2);
    cout<<getNumber(head1)<<endl;
    cout<<getNumber(head2)<<endl;
    display(a);
    display(addNumbers(head1,head2));
    display(addNumbersRecursive(head1,head2,0));
    return 0;
}