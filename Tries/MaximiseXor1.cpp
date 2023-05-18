#include<bits/stdc++.h>
using namespace std;

struct TrieNode{
    int val;
    TrieNode* links[2];
    TrieNode(int bit){
        val=bit;
        for(int i=0;i<2;i++){
            links[i]=NULL;
        }
    }
};

void insert(TrieNode* root,int num){
    TrieNode* curr=root;
    for(int i=31;i>=0;i--){
        int bit=(num>>i) & 1;
        if(curr->links[bit]==NULL){
            curr->links[bit]=new TrieNode(bit);
        }
        curr=curr->links[bit];
    }
}



int main(){
    TrieNode* root = new TrieNode(-1);
    vector<int> A={9,8,7,5,4};

    for(int i=0;i<A.size();i++){
        insert(root,A[i]);
    }
    return 0;
}

