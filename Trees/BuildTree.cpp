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

struct TreeNode* postAndIn(vector<int> postOrder,vector<int>inOrder,int start,int end){
    static int idx=end;

    int val = postOrder[idx];
    idx--;
    struct TreeNode* curr = new TreeNode(val);

    if(start == end){
        return curr;
    }

    struct TreeNode* root = new TreeNode(postOrder[end]);

    cout<<root->data;
    return root;
}


void lvlorder1(struct TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>1){
        if(q.front() == NULL){
            cout<<endl;
            q.pop();
            q.push(NULL);
        }
        struct TreeNode* x = q.front();
        cout<<x->data<<" ";
        q.pop();

        if(x->left != NULL){
            q.push(x->left);
        }
        if(x->right != NULL){
            q.push(x->right);
        }
    }
}

int searchEle(vector<int> inorder,int start,int end,int curr){

    for(int i=start;i<=end;i++){
        if(curr==inorder[i]){
            return i;
        }
    }
    return -1;
}

void inorder(TreeNode* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(TreeNode* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

//Building tree from preorder and inorder sequence

// TreeNode* BuildTree(int preorder[],int inorder[],int start,int end){
//     static int idx=0;
//     //base case
//     if(start>end){
//         return NULL;
//     }
//     //pick element from preorder and create node
//     int curr=preorder[idx];
//     idx++;
//     TreeNode* node =  new TreeNode(curr);

//     //if there is only one element in array
//     if(start==end){
//         return node;
//     }
    
//     int pos=searchEle(inorder,start,end,curr);

//     node->left=BuildTree(preorder,inorder,start,pos-1);
//     node->right=BuildTree(preorder,inorder,pos+1,end);

//     return node;
// }

//Building tree from postorder and inorder sequence
// TreeNode* BuildTreePost(int postorder[],int inorder[],int start,int end){
//     static int idx=end;

//     if(start>end){
//         return NULL;
//     }

//     int curr=postorder[idx];
//     idx--;
//     TreeNode* node = new TreeNode(curr);

//     if(start==end){
//         return node;
//     }

//     int pos=searchEle(inorder,start,end,curr);

//     node->right = BuildTreePost(postorder,inorder,pos+1,end);
//     node->left = BuildTreePost(postorder,inorder,start,pos-1);

//     return node;
// }

//vector instead of array Building tree from postorder and inorder sequence
TreeNode* BuildTreePostNIn(vector<int> postorder,vector<int> inorder,int start,int end){
    static int idx=end;

    if(start>end){
        return NULL;
    }

    int curr=postorder[idx];
    idx--;
    TreeNode* node = new TreeNode(curr);

    if(start==end){
        return node;
    }

    int pos=searchEle(inorder,start,end,curr);

    node->right = BuildTreePostNIn(postorder,inorder,pos+1,end);
    node->left = BuildTreePostNIn(postorder,inorder,start,pos-1);

    return node;
}


int main(){
    vector<int> postOrder = {4,2,5,3,1};
    vector<int> inOrder = {4,2,1,5,3};

    //int pre[]={1,2,4,3,5};
    //int in[]={2,1,3};
    //int post[]={2,3,1};

    //inorder(BuildTree(pre,in,0,4));
    //cout<<endl;
    //inorder(BuildTreePost(post,in,0,2));

    vector<int> in={2,1,3};
    vector<int> post={2,3,1};


    preorder(BuildTreePostNIn(post,in,0,post.size()-1));

    //struct TreeNode* res=postAndIn(postOrder,inOrder,0,inOrder.size()-1);
    return 0;
}