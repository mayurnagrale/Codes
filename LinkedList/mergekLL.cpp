#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

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

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

//need merge two sorted linked list for using recursion
node* mergeTwoSortedLL(node* head1,node* head2){
    node* result=NULL;
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    if(head1->data<head2->data){
        result=head1;
        result->next=mergeTwoSortedLL(head1->next,head2);
    }
    else{
        result=head2;
        result->next=mergeTwoSortedLL(head1,head2->next);
    }
    return result;
}

//merge linked list using Simple Method using O(NK) time complexity
//1st method
node* mergeK(node* head1,node* head2,node* head3,node* head4){
    node* result=NULL;
    result=mergeTwoSortedLL(head1,head2);
    display(result);
    result=mergeTwoSortedLL(result,head3);
    result=mergeTwoSortedLL(result,head4);
    return result;
}

//find minimum from the first k node and add it into new linked list and update the first of the smallest to the next of it
//using O(NK) time complexity
//2nd method 
int getMin(int arr[],int size){
    int min=MAX;
    for(int i=0;i<size;i++){
        if(arr[i]<min){
            min=arr[i];
        }
    }
    return min;
}
node* mergeK2(node** heads,int size){
    node* result=NULL;
    int arr[size];
    //to get the first element of the k linked list
    for(int i=0;i<size;i++){
        node* temp=heads[i];
        arr[i]=temp->data;
    }
    //we need numbers of total nodes in k linked list to check if all the nodes are included in the linked list
    int min=getMin(arr,size);
    // node* n=new node(min);
    // if(heads[min]->next != NULL){
    //     node* newTemp=heads[min]->next;
    // }
    // arr[min]=newTemp->data;
    // // 
    // if(result==NULL){
    //     result=n;
    // }
    // else{
    //     result->next=n;
    // }
    return result;
}


//Array of linked list
//this array will contain the address of head nodes
// void concept(node* heads){
//     //we will pass the size of the heads to the n
//     int n=26;
//     node* A[n];
//     for(int i=0;i<n;i++){
//         A[i]=NULL;//this will initialise the array of null values;
//     }
//     //or we can pass heads array values(head node)
//     // for(int i=0;i<n;i++){
//     //     A[i]=heads[i];
//     // }
// }

int main(){
int k=4;
node* head1=NULL;
node* head2=NULL;
node* head3=NULL;
node* head4=NULL;

//string heads[k];
    //for(int i=0;i<k;i++){
      //  heads[i]=i+"";
    //}
//creating linked list for the heads
int arr1[]={1,4,7,9};
int arr2[]={0,2,6};
int arr3[]={3,8};
int arr4[]={5};
    for(int i=0;i<4;i++){
        insertAtTail(head1,arr1[i]);
    }
    for(int i=0;i<3;i++){
        insertAtTail(head2,arr2[i]);
    }
    for(int i=0;i<2;i++){
        insertAtTail(head3,arr3[i]);
    }
    for(int i=0;i<1;i++){
        insertAtTail(head4,arr4[i]);
    }

node* heads[]={head1,head2,head3,head4};
    //node* newNode=mergeK(head1,head2,head3,head4);
    //display(newNode);
    int size=sizeof(heads)/sizeof(node*);
    cout<<size<<endl;
    node* newNode2=mergeK2(heads,size);
}