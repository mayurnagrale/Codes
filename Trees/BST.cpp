#include<bits/stdc++.h>
using namespace std;

class Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        dat=val;
        left=NULL;
        right=NULL;
    }
}


bool searchInBST(Node* root,int k){
    Node* temp=root;
    while (temp != NULL)
    {
        if (temp->data == k){
            return true;
        }
        else if (temp->data < k){
            temp = temp->right;
        }
        else if (temp->data > k){
            tmep=temp->left;
        }
    }
    return false;
}

//Insert in bst considering that we cant have duplicates in bst
void insertInBST(Node* root,int k){
    Node* n = new Node(k);
    Node* temp=root;
    Node* parent=NULL;

    while (temp != NULL)
    {
        parent = temp;
        if (temp->data < k){
            temp = temp->right;
        }
        else{
            tmep=temp->left;
        }
    }
    
    if(k < parent->data){
        parent->left = n;
    }
    else{
        parent->right = n;
    }
}

//Insert in bst considering that we cant have duplicates in bst
void insertInBST(Node* root,int k){
    Node* n = new Node(k);
    Node* temp=root;
    Node* parent=NULL;

    while (temp != NULL)
    {
        parent = temp;
        if (temp->data < k){
            temp = temp->right;
        }
        else{
            tmep=temp->left;
        }
    }
    
    if(k <= parent->data){
        parent->left = n;
    }
    else{
        parent->right = n;
    }
}

//
Node* bbst(vector<int> &A,int start,int end){
    if(start>end){
        return NULL;
    }
    int mid= (start+end)/2;
    Node * root = new Node(A[mid]);

    root->left = bbst(A,start,mid-1);
    root->right = bbst(A,mid+1,end);

    return root;
}

//Optimised approach for checking if tree is BST or not
//initially l=INT_MIN and r=INT_MAX
bool isBST(Node* root,int l,int r){
    if(root==NULL){
        return true;
    }
    if(root->data >= l && root->data <= r){
        return (isBST(root->left,l,root->data - 1) && isBST(root->right,root->data+1,r));
    }
    return false;
}

int main(){

    return 0;
}