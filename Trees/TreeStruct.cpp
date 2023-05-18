#include<bits/stdc++.h>
using namespace std;

//Tree traversal using recursion and iterative approach

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


void preorder(struct TreeNode* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct TreeNode* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(struct TreeNode* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);   
    postorder(root->right);
    cout<<root->data<<" ";
}

//Level order traversal
void lvlorder(struct TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
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

//Level order traversal print each level in new line
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

//right view of the tree
vector<int> rightView(struct TreeNode* root){
    queue<TreeNode*> q;
    struct TreeNode* x=NULL;
    vector<int> ans;
    q.push(root);
    q.push(NULL);
    while(q.size()>1){
        if(q.front() == NULL){
            if(x){
                ans.push_back(x->data);
            }
            cout<<endl;
            q.pop();
            q.push(NULL);
        }
        x = q.front();
        cout<<x->data<<" ";
        q.pop();

        if(x->left != NULL){
            q.push(x->left);
        }
        if(x->right != NULL){
            q.push(x->right);
        }
    }
    ans.push_back(x->data);
    return ans;
}

//Leftview of the tree
vector<int> leftView(struct TreeNode* root){
    queue<TreeNode*> q;
    struct TreeNode* x=NULL;
    vector<int> ans;
    bool temp;
    q.push(root);
    q.push(NULL);
    while(q.size()>1){
        if(q.front() == NULL){
            temp=true;
            cout<<endl;
            q.pop();
            q.push(NULL);
        }

        x = q.front();
        if(temp){
            ans.push_back(x->data);
            temp=false;
        }
        cout<<x->data<<" ";
        q.pop();

        if(x->left != NULL){
            q.push(x->left);
        }
        if(x->right != NULL){
            q.push(x->right);
        }
    }
    return ans;
}

//Top view of the tree
vector<int> topView(struct TreeNode* root){
}

//Inorder traversal iteratively
void inorderitr(struct TreeNode* root){
    stack<TreeNode*> s;
    struct TreeNode* curr = root;
    while(!s.empty() || curr!=NULL){
        while(curr!=NULL){
            s.push(curr);
            curr = curr->left;
        }
        curr=s.top();
        cout<<curr->data<<" ";
        s.pop();
        curr = curr->right;
    }
    cout<<endl;
}

//Vertical order traversal
// void verticalTeaversal(struct TreeNode* root){
//     unordered_map<int,vector<int>> hm;
//     queue<pair<TreeNode*,int>> q;
//     int minl=0,maxl=0;
//     q.push((root,0));
//     while(!q.empty()){
//         struct TreeNode* x = q.front().first;
//         int l = q.front().second;
//         q.pop();

//         //Insert l and node in hm
//         hm[l].push_back(x->data);

//         if(x->left != NULL){
//             q.push(make_pair<x->left,l-1>);
//         }
//         if(x->right != NULL){
//             q.push(make_pair<x->right,l+1>);
//         }
        
//         //update min and max
//         minl=min(minl,l);
//         maxl=max(maxl,l);
//     }

//     for(int i=minl;i<maxl;i++){
//         for(int j=0;j<hm[i].size();j++){
//             cout<<hm[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }

int countDigit(long long n)
{
    if (n == 0)
        return 1;
    int count = 0;
    while (n != 0) {
        n = n / 10;
        ++count;
    }
    return count;
}

int dig(int A){
    int temp=12;
    if(A==9){
        return A+2;
    }
    else if(countDigit(A) == countDigit(A+1)){
        if(A%10==9)
            return A+2;
        return A+1;
    }
    else if(countDigit(A) != countDigit(A+1)){
        if(countDigit(A)==2){
            return A+temp;
        }
        for(int i=2;i<countDigit(A);i++){
            cout<<temp<<endl;
            cout<<pow(10,i)<<endl;
            temp = temp + pow(10,i)+1;
        }
    }
    return A+temp;
}

// if(countDigit(A)==2){
//             return A+12;
//         }
//         else{
//             cout<<pow(10,countDigit(A)-1)<<endl;
//             return A+pow(10,countDigit(A)-1)+12;
//         }

int main(){
    /*
                    1
                   /  \
                  2    3
                /  \ 
              4      5      

    */
    struct TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    //root->right->right = new TreeNode(7);

    // preorder(root);
    // cout<<endl;
    // inorder(root);
    // cout<<endl;
    // postorder(root);
    // cout<<endl;
    // vector<int> res=topView(root);
    // cout<<endl;
    // for(int i=0;i<res.size();i++){
    //     cout<<res[i]<<" ";
    // }
    //verticalTeaversal(root);
    //inorderitr(root);
    //postorder(root);
    cout<<dig(3999);
    return 0;
}