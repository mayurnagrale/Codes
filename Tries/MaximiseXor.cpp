#include<bits/stdc++.h>
using namespace std;

struct TrieNode
{
    int value;
    TrieNode* links[2];

    bool containsKey(int bit){
        return (links[bit] != NULL);
    }

    TrieNode* get(int bit){
        return links[bit];
    }

    TrieNode* put(int bit,TrieNode* node){
        links[bit]=node;
    }
};

void insert(TrieNode* root,int num){
    TrieNode* curr=root;
    for(int i=31;i>=0;i--){
        int bit=(num>>i) & 1;
        if(!curr->containsKey(bit)){
            curr->put(bit,new TrieNode());
        }
        curr=curr->get(bit);
    }

}

int getMax(TrieNode* root,int n){
    TrieNode* node=root;
    int maxNum=0;
    for(int i=31;i>=0;i--){
        int bit=(n>>i) & 1;
        if(node->containsKey(1-bit)){
            maxNum = maxNum | (1<<i);
            node=node->get(1-bit);
        }
        else{
            node=node->get(bit);
        }
    }
    return maxNum;
}

int main(){
    TrieNode* root = new TrieNode();
    vector<int> A={1, 2, 3, 4, 5};
    vector<int> B={1, 2, 3, 4, 5};
    int maxi=0;
    for(int i=0;i<A.size();i++){
        insert(root,A[i]);
    }

    for(int i=0;i<B.size();i++){
        maxi = max(maxi,getMax(root,B[i]));
    }

    cout<<maxi<<endl;
    cout<<max(5,3);
    return 0;
}
