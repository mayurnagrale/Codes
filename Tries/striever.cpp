#include<bits/stdc++.h>
using namespace std;

struct TrieNode{
    TrieNode* links[26];
    bool end;

    bool containsKey(char ch){
        return links[ch -'a'] != NULL;
    }

    void put(char ch,TrieNode* curr){
        links[ch-'a']=curr;
    }
    TrieNode* get(char ch){
        return links[ch-'a'];
    }

    bool setEnd(){
        end=true;
    }

    bool isEnd(){
        return end;
    }

};

class Trie{
    public:
        TrieNode* root;
        Trie(){
            root = new TrieNode();
        }
        //tc O(len)
        void insert(string word){
            TrieNode* node=root;
            for(int i=0;i<word.length();i++){
                    if(!node->containsKey(word[i])){
                        node->put(word[i],new TrieNode());
                    }
                    //moves to the referance trie
                    node=node->get(word[i]);
            }
            node->setEnd();   
        }

        bool search(string word){
            TrieNode* node=root;
            for(int i=0;i<word.length();i++){
                if(!node->containsKey(word[i])){
                    return false;
                }
                node=node->get(word[i]);
            }
            return node->isEnd();
        }

        bool startsWith(string word){
            TrieNode* node=root;
            for(int i=0;i<word.length();i++){
                if(!node->containsKey(word[i])){
                    return false;
                }
                node=node->get(word[i]);
            }
            return true;
        }
};

int main(){ 
    string w="abcde";
    Trie t;
    t.insert(w);
    cout<<t.search(w);
    return 0;
}