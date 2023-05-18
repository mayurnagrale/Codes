#include<bits/stdc++.h>
using namespace std;

//Tree traversal using recursion and iterative approach

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int val){
            data=val;
            left=NULL;
            right=NULL;
        }
};

//tree traversal using recursion

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    inorder(root->left);
    inorder(root->right);
}

void postorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    inorder(root->right);
    cout<<root->data<<" ";
}

//Level order traversal

void levelorder(Node* &root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* x = q.front();
        q.pop();
        cout<<x->data<<" ";
        if(x->left != NULL){
            q.push(x->left);
        }
        if(x->right != NULL){
            q.push(x->right);
        }
    }
    cout<<endl;
}

//Level order traversal print each level in one line

void levelorder1(Node* &root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>1){
        if(q.front()==NULL){
            cout<<endl;
            q.pop();
            q.push(NULL);
        }
        Node* x = q.front();
        q.pop();
        cout<<x->data<<" ";
        if(x->left != NULL){
            q.push(x->left);
        }
        if(x->right != NULL){
            q.push(x->right);
        }
    }
    cout<<endl;
}


//Search function that returns index of element in array
int search(vector<int> inOrder,int ele){
    for(int i=0;i<inOrder.size();i++){
        if(ele == inOrder[i]){
            return i;
        }
    }
    return -1;
}

//Build tree from inorder and preorder
Node* Construct(vector<int> pre,vector<int> in, int ps,int pe,int is,int ie){
    if(is>ie){
        return NULL;
    }
    int c_root = pre[ps];
    Node* curr = new Node(c_root);

    int idx=search(in,c_root);

    int l = idx-is;

    curr->left = Construct(pre,in,ps+1,ps+l,is,idx-1);
    curr->right = Construct(pre,in,ps+l+1,pe,idx+1,ie);

    return curr;
}

//Build tree from postorder and inorder
Node* Construct(vector<int> pos,vector<int> in, int ps,int pe,int is,int ie){
    if(is>ie){
        return NULL;
    }
    int c_root = pre[ps];
    Node* curr = new Node(c_root);

    int idx=search(in,c_root);

    int l = idx-is;

    curr->left = Construct(pos,in,ps+1,ps+l,is,idx-1);
    curr->right = Construct(pos,in,ps+l+1,pe,idx+1,ie);

    return curr;
}

int main(){
    // Node* root = new Node(10);
    // root->left = new Node(20);
    // root->right = new Node(30);
    // root->left->left = new Node(40);
    // root->left->right = new Node(50);
    // root->right->left = new Node(60);
    // root->right->right = new Node(70);
    // levelorder1(root);
    // inorder(root);
    // cout<<endl;
    // preorder(root);
    // cout<<endl;
    // postorder(root);
    // return 0;
    vector<int> pre={3,7,9,12,19,4,14,15,21,2,1,6,18,25};
    vector<int> in={12,9,19,7,3,21,15,2,14,1,6,4,18,25};
    inorder(Construct(pre,in,0,pre.size()-1,0,in.size()-1));
    return 0;
}