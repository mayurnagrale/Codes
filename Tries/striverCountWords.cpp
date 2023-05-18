#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[26];
    int cntEnd;
    int cntPrefix;

    bool containsKey(char ch){
        return (links[ch-'a'] !=NULL);
    }

    Node get(char ch){
        return links[ch-'a'];
    }

    Node put(Node* node,char ch){
        links[ch-'a'] = node;
    }

    void increaseEnd(){
        cntEnd++;
    }

    void increasePrefix(){
        cntPrefix++;
    }

    void deleteEnd(){
        cntEnd--;
    }

    void reducePrefix(){
        cntPrefix--;
    }

    int getEnd(){
        return cntEnd;
    }

    int getPrefix(){
        return cntPrefix;
    }
};

class Trie{
    public:
        Node* root;
        Trie(){
            root = new Node();
        }
        
        void insert(string word){
            Node* node=root;
            for(int i=0;i<26;i++){
                if(!node->containsKey(word[i])){
                    node->put(new Node(),word[i]);
                }
                node=node->get(word[i]);
                node->increasePrefix();
            }
            node->increaseEnd();
        }

        int countWordsEqualTo(string &word){
            Node* node=root;
            for(int i=0;i<word.size();i++){
                if(node->containsKey(word[i])){
                    node=node->get(word[i]);
                }
                else{
                    return 0;
                }
            }
            return node->getEnd();
        }

        int countWordsStartingWith(string &word){
            Node* node=root;
            for(int i=0;i<word.size();i++){
                if(node->containsKey(word[i])){
                    node=node->get(word[i]);
                }
                else{
                    return 0;
                }
            }
            return node->getPrefix();
        }

        void erase(string &word){
            Node* node=root;
            for(int i=0;i<word.size();i++){
                if(node->containsKey(word[i])){
                    node=node->get(word[i]);
                    node->reducePrefix();
                }
                else{
                    return 0;
                }
            }
            node->deleteEnd();
        }
};