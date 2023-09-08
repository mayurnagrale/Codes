#include<bits/stdc++.h>

using namespace std;


//Print all the substring of a string using recursion
void helper(string s,string tempAns,int i){
    //base case
    if(s.size()==i){
        cout<<tempAns<<" ";
        return;
    }
    //take
    helper(s,tempAns+s[i],i+1);
    //not take
    helper(s,tempAns,i+1);

    return;
}

//Returns all the substring using recursion
void helpers(string s,string tempAns,int i, unordered_map<string,int> &hm){
     if(s.size()==i){
        sort(tempAns.begin(),tempAns.end());
        hm[tempAns]++;
        return;
    }
    //take
    helpers(s,tempAns+s[i],i+1,hm);
    //not take
    helpers(s,tempAns,i+1,hm);

    return;
}

//Time complexity of the below solution is O(n^3).
//Prints all the substring using iterative approach
void printAllSubstrings(const std::string& str) {
    int length = str.length();

    // Generate all substrings
    for (int start = 0; start < length; start++) {
        for (int end = start; end < length; end++) {
            for (int i = start; i <= end; i++) {
                std::cout << str[i];
            }
            //std::cout << std::endl;
            std::cout<<" ";
        }
    }
}

//Anagram using sliding window for a given pattern inside a string
int printAngrams(string str,string ptr){
    unordered_map<char,int> hm;
    int anagramCount=0;
    for(int i=0;i<ptr.size();i++){
        hm[ptr[i]]++;
    }
    int i,j=0;
    int count=hm.size();
    while(j<str.size()){
        //calculations
        if(hm.find(str[j]) != hm.end()){
            hm[str[j]]--;
            if(hm[str[j]]==0){
                count--;
            }
        }
        //winodow size < k
        if(j-i+1 < ptr.size()){
            j++;
        }
        //window size == k
        if(j-i+1 == ptr.size()){
            if(count==0){
                anagramCount++;
            }
        }
        //slide the window but before that reverse the calculation or shrink the widow
        if (j-i+1 > ptr.size())
        {
            hm[str[i]]++;
            if (hm[str[i]] == 1)
            {
                count++;
            }
            i++;
        }

    }

    return anagramCount;
}

int main(){
    string sdata = "abba";//abfbba
    string ptr= "ab";
    //printAllSubstrings(sdata);
    //helper(sdata,"",0);

    // map<char,int> um;
    // for(char c: sdata){
    //     um[c]++;
    // }

    // for(auto& pair:um){
    //     if(pair.second==1){
    //         cout<<pair.first<<" ";    
    //     }
    //     else
    //         cout<<pair.first<<pair.second<<" ";
    // }

    // unordered_map<string,int> hm;
    // helpers(sdata," ",0,hm);
    // int count=0;
    // for(auto& pair:hm){
    //     cout<<pair.first<<" "<<pair.second<<endl;
    //     int val=pair.second;
    //     if(val>1)
    //         count += (val * (val-1))/2;
    // }
    // cout<<count;
    cout<<printAngrams(sdata,ptr);
    return 0;
} 