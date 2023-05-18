#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* random;
    node(int val){
        data=val;
        next=NULL;
        random=NULL;
    }
};

node* Duplicate(node* head){
    //Inserting new node in between
    node* curr = head;
    while(curr != NULL){
        node* temp = curr->next;
        curr->next = new node(curr->data);
        curr->next->next = temp;
        curr = temp;
    }
    curr = head;

    //Setting random pointers of new node
    while(curr != NULL){
        if(curr->next != NULL){
            curr->next->random = (curr->random != NULL)? curr->random->next:NULL;
        }
        curr = curr->next->next;
    }

    //Separating both linked list
    node* Orig = head;
    node* Copy = head->next;
    node* temp= Copy;

    while(Orig != NULL){
        Orig->next = Orig->next->next;
        Copy->next = Copy->next->next;
        Orig=Orig->next;
        Copy=Copy->next;
    }
    return temp;
}

int main(){
    node* n = new node(10);
    cout<<n->data<<endl;
    cout<<n->next<<endl;
    cout<<n->random<<endl;

    return 0;
}