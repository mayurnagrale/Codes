#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};


struct TreeNode* prev=NULL;
struct TreeNode* first=NULL;
struct TreeNode* second=NULL;

//Inorder of bst is sorted so we can check if inorder is sorted or not or we can check it while travelling the nodes
void inorder(TreeNode* curr){
    if(curr==NULL){
        return;
    }
     inorder(curr->left);
     cout<<curr->data<<" ";
//     if(prev != NULL && prev->data>curr->data){
//         if(first==NULL){
//             first=prev;
//         }
//         second=curr;
//     }
    prev=curr;
     inorder(curr->right);
}


int main(){
    struct TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);

    inorder(root);
    // cout<<first->data<<endl;
    // cout<<second->data<<endl;

    return 0;
}