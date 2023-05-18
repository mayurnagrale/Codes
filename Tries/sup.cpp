#include<bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode{
    char data;
    struct TrieNode* child[26];
    int count;
    TrieNode(char a){
        data = a;
        count=0;
        for (int i = 0; i < ALPHABET_SIZE; i++){
            child[i] = NULL;
        }
    }
};



void insert(TrieNode* root,string word){
    TrieNode* curr = root;
    for(int i=0;i<word.length();i++){
        int idx=word[i]-'a';
        if(curr->child[idx] == NULL){
            curr->child[idx]= new TrieNode(word[i]);
        }
        curr->child[idx]->count++;
        curr=curr->child[idx];
    }
}

string get(TrieNode* root,string str){
    TrieNode* curr=root;
    string prefix;
    for(int i=0;i<str.size();i++){
        int idx=str[i]-'a';
        if(curr->data!='#' && curr->count==1){
            break;
        }
        prefix+=str[i];
        curr=curr->child[idx];
    }
    return prefix;
}


int main(){
    vector<string> A={"zebra", "dog", "duck", "dove"};
    TrieNode* root=new TrieNode('#');
    for(int i=0;i<A.size();i++){
        insert(root,A[i]);
    }
    vector<string> res;
    for(int i=0;i<A.size();i++){
        res.push_back(get(root,A[i]));
    }

    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}



// string search(TrieNode* root,string word){
//     TrieNode* curr = root;
//     string str="";
//     for(int i=0;i<word.length();i++){
//         int idx=word[i]-'a';
//         if(curr->child[idx] && curr->count==1){
//             str+=word[i];
//             break;
//         }
//         str+=word[i];
//         curr = curr->child[idx];
//     }
//     cout<<str<<" ";
//     return str;
// }