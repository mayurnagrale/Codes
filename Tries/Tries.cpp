#include<bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode{
    char data;
    struct TrieNode* child[26];
    bool isEndOfWord;
    TrieNode(char a){
        data = a;
        isEndOfWord=false;
        for (int i = 0; i < ALPHABET_SIZE; i++){
            child[i] = NULL;
        }
    }
};


bool search(TrieNode* root,string word){
    TrieNode* curr = root;
    for(int i=0;i<word.length();i++){
        int idx=word[i]-'a';//this will return index for letter to store in children array
        if(curr->child[idx]==NULL){
            return false;
        }
        curr = curr->child[idx];
    }
    return curr->isEndOfWord;
}

void insert(TrieNode* root,string word){
    TrieNode* curr = root;
    for(int i=0;i<word.length();i++){
        int idx = word[i]-'a';
        if(curr->child[idx] == NULL){
            curr->child[idx]= new TrieNode(word[i]);
        }
        curr=curr->child[idx];
    }
    curr->isEndOfWord =true;
}

//shortest unique prefix
//sup to represent each word assuming no word is a sup of another word or string should be given like that only
string get(TrieNode* root,string str){
    TrieNode* curr=root;
    int n=str.size();
    string prefix="";
    for(int i=0;i<n;i++){
        int idx=str[i]-'a';
        if(curr->count==1){
            break;
        }
        prefix+=str[i];
        curr=curr->child[idx];
    }
    return prefix;
}


//string and dictionary of word ->break the string and check if all the broken are present in dictionary 
//in bruteforce we need to get all the substrings  check substrings that exist in trie and trie to form a given string if done then return true else return false
bool wordBreak(TrieNode* root,string word){
    if(word.length() == 0){
        return true;
    }
    for(int i=1;i<=word.length();i++){
        string firstPart=word.substr(0,i);
        string secondPart=word.substr(i,word.length());
        if(search(root,firstPart) && wordBreak(root,secondPart)){
            return true;
        }
    }
    return false;
}

//similar to search 

bool startsWith(TrieNode* root,string prefixWord){
    TrieNode* curr=root;
    for(int i=0;i<prefixWord.length();i++){
        int idx=prefixWord[i]-'a';
        if(curr->child[idx]==NULL){
            return false;
        }
        curr = curr->child[idx];
    }
    return true;
}

//get all the suffixes
vector<string> getALlSuffix(string word){
    vector<string> res;
    for(int i=0;i<word.length();i++){
        res.push_back(word.substr(i,word.length()));
    }
    return res;
} 

//count all the nodes of trie
int countNodes(TrieNode* root){
    int count=0;
    if(root==NULL){
        return 0;
    }
    for(int i=0;i<26;i++){
        if(root->child[i] != NULL){
           count+=countNodes(root->child[i]);
        }
    }
    return count+1;
}

int main(){
    struct TrieNode* root= new TrieNode('#');
    //string keys[] = {"trap","track"};
    string keys[] = {"i","like","sam","samsung","mobile"};
    string word="ilikesamsung";
    int n= sizeof(keys)/sizeof(keys[0]);
    for(int i=0;i<n;i++){
        insert(root,keys[i]);
    }
    //string word="track";
    //cout<<search(root,word);
    //cout<<wordBreak(root,word);

    // vector<string> res=getALlSuffix(word);
    // for(int i=0;i<res.size();i++){
    //     cout<<res[i]<<" ";
    // }
    // cout<<endl;

    cout<<countNodes(root);
    return 0;
}