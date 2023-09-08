#include<bits/stdc++.h>
using namespace std;

//Reverse a String
string rs(string str){
    string res="";
    int n=str.length();
    for(int i=n-1;i>=0;i--){
        res+=str[i];
    }

    return res;
}

//Reverse a string using inbuilt function
string rsi(string str){
    reverse(str.begin(),str.end());
    return str;
}

//check for palindrome ]
bool checkPalindrome(string str){
    int n=str.length();
    for(int i=0;i<=n-1;i++){
        if(str[i]!=str[n-1-i]){
            return false;
        }
    }
    return true;
}

//using reverse method
bool chkPalRev(string str){
    string original=str;
    reverse(str.begin(),str.end());
    return original==str;
}

//String Anagrams using sorting which takes O(nlog) 
bool areAnagrams(string str1, string str2){
    if(str1.length() != str2.length()){
        return false;
    }
    sort(str1.begin(),str1.end());
    sort(str2.begin(),str2.end());
    return str1==str2;
}

//array approach time complexity will become O(n) also known as 
//histogram approach
bool Anagrams(string str1,string str2){
    if(str1.length() != str2.length()){
        return false;
    }
    int count[256] = {0};

    for(char c : str1){
        count[c]++;
    }

    for(char c : str2){
        count[c]--;
        if(count[c]<0){
            return false;
        }
    }
    return true;
}

//Longest substring without repeating character with O(n)
int lengthOfLongestSubstring(string s){
    int maxLength=0,i=0,j=0;
    unordered_set<char> us;

    while(j<s.length()){
        if(us.find(s[j]) == us.end()){
            us.insert(s[j++]);
            maxLength = max(maxLength,j-i);
        }
        else{
            us.erase(s[i++]);
        }
    }
    return maxLength;
}

//String compression aabbaccdd-> abacd
string compressString(string s){
    string res="";
    char prev='/0';

    for(int i=0;i<s.length();i++){
        if(prev!=s[i])
            res+=s[i];
        prev=s[i];
    }
    return res;
}


//String compression  
std::string compressString1(std::string s) {
    std::string compressed;
    int count = 1;
    for (int i = 1; i < s.length(); ++i) {
        if (s[i - 1] == s[i]) {
            count++;
        } else {
            compressed += s[i - 1] + std::to_string(count);
            count = 1;
        }
    }
    compressed += s.back() + std::to_string(count);

    return compressed.length() < s.length() ? compressed : s;
}

//String to Integer (atoi)
long atoi(string digit){
    long ans=0;
    int sign=0;
    int maxI=INT_MAX,minI=INT_MIN;
    for(int i=0;i<digit.length();i++){
        if(digit[i]!=' '){
            digit = digit.substr(i,digit.length()-i);
            break;
        }
    }
    if(digit[0]=='-'){
        sign=-1;
        digit=digit.substr(1,digit.length()-1);
    }
    else if(digit[0]=='+'){
        sign=1;
        digit=digit.substr(1,digit.length()-1);
    }

    for(int i=0;i<digit.length();i++){
        if(digit[i]-'0'<=9 && digit[i]-'0'>=0){
            ans = ans*10 + digit[i]-'0';
        }
        else{
            break;
        }
    }

    if(sign !=0){
        ans*=sign;
    }

    if(ans<minI){
       return minI;
    }
    else if(ans>maxI){
        return maxI;
    }
    return ans;
}

//Valid Parenthesis for ()
bool checkParenthesis(string str){
    stack<char> st;
    for(char c :str){
        if(c=='(' || c=='[' || c=='{'){
            st.push(c);
        }
        else{
            if(st.empty()) return false;
            char top = st.top();
            st.pop();
            if((c==')' && top !='(') || (c==']'  && top !='[') || (c=='}'  && top !='{') ){
                return false;
            }
        }
    }
    return st.empty();
}


//Input stirng containing non bracket character "(44)"
bool isValid(std::string s) {
    std::stack<char> charStack;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            charStack.push(c);
        } else if (c == ')' || c == ']' || c == '}'){
            if (charStack.empty()) return false;
            char top = charStack.top();
            charStack.pop();
            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                return false;
            }
        }
        else{
            continue;
        }
    }
    return charStack.empty();
}

//Implement strStr(): tc->O(mn) where m is heystack length and n is niddle length
int strstraa(string heystack,string niddle){
    int idx=-1;
    bool flag=false;
    for(int i=0;i<heystack.length()-niddle.length();i++){
        if(heystack[i]==niddle[0]){
            idx=i;
            for(int j=i;j<niddle.length();++j){
                if(heystack[j]!=niddle[j]){
                    idx=-1;
                    flag=true;
                    break;      
                }
            }
            if(!flag) return idx;
        }
    }

    return idx;
}

//we can optimize this more using lps array
vector<int> lps(string s){
    vector<int> res(s.length(),0);
    int len=0,i=1;
    res[0]=0;
    while(i<s.size()){
        if(s[len]==s[i]){
            len++;
            res[i]=len;
            i++;
        }
        else{
            if(len!=0){
                len=res[len-1];
            }
            else{
                res[i]=0;
                i++;
            }
        }
    }

    return res;
}

void strstrkmp(string heystack,string niddle){
    int i=0;
    int j=0;
    vector<int> lps1=lps(niddle);
    while(i<heystack.length()){
        if(heystack[i]==niddle[j]){
            i++;j++;
        }

        if(j==niddle.length()){
            cout<<i-j<<" ";
            j=lps1[j-1];
        }
        else if(i<heystack.length() && niddle[j] != heystack[i]){
            if(j!=0){
                j=lps1[j-1];
            }
            else{
                i++;
            }
        }
    }
}

//Prefix string function O(n3)
vector<int> prefix_funtion(string s){
    int n=s.length();
    vector<int> pi(n);

    for(int i=0;i<n;i++){
        for(int k=0;k<=i;k++){
            if(s.substr(0,k)==s.substr(i-k+1,k)){
                pi[i]=k;
            }
        }
    }
    return pi;
}


//Z-index array from string  Longest substring that matchest with the prefix of the string 
//tc-> O(n2) this is the bruteforce apporach lets see if we can optimize it more
vector<int> zIndex(string s){
    int n=s.length();
    int j,k;
    vector<int> zArray(n,0);
    for(int i=1;i<n;i++){
        j=i; //substring 
        k=0; //prefix
        while(j<n && s[j]==s[k]){
            j++;k++;
        }
        zArray[i]=k; //or zArray[i]=j-i
    }

    return zArray;
}

//If char is not inside the box we will do bruteforce 
//Else we will copy from the box
//if(z[box]<common elements){ then copy the value} 
//else if(z[box] >= common elements){common ele + bruteforce}

// TC-> O(n)

vector<int> zIndexOptimize(string s){
    int n=s.length();
    int j,k;
    int L=0,R=0;
    vector<int> zArray(n,0);
    for(int i=1;i<n;i++){
        if(i>R){ //this means do bruteforce as i does not come inside the box of LR
            j=i; //substring 
            k=0; //prefix
            while(j<n && s[j]==s[k]){
                j++;k++;
            }
            zArray[i]=k; //or zArray[i]=j-i

            //When we do bruteforce out left and right value will get updated
            L=i;R=j-1;
        }
        else{   
            if(zArray[i-L]<R-i+1){
                //copy
                zArray[i]=zArray[i-L];
            }
            else{ //Again bruteforce
                j=R+1;
                k=R-i+1;
                while(j<n && s[j]==s[k]){
                j++;k++;
                }
                zArray[i]=k;
                //When we do bruteforce out left and right value will get updated
                L=i;R=j-1;
            }
        }
    }
    return zArray;
}

//Given string s and pattern string t Find if there exist a substring in s which matches the pattern t
//s=mynameissare
//t=mei
//z[] == pattern length -> we found out pattern 
//update s to t+'$'+s
//this will the return the index of the pattern found
int findPattern(string s,string t){
    string ns = t+'$'+s;
    vector<int> z=zIndexOptimize(ns);

    for(int i=0;i<z.size();i++){
        if(z[i]==t.size()){
            return i-t.size()-1;
        }
    }
    return -1;
}


//Given 2 strings A and B. Find no of time B occurs int A as substring 
int findOccuranceOfPattern(string s,string t){
    string ns = t+'$'+s;
    vector<int> z=zIndexOptimize(ns);
    int count=0;
    for(int i=0;i<z.size();i++){
        if(z[i]==t.size()){
            count++;
        }
    }
    return count;
}


//Count and Say problem 
//if 1st term is given the 2nd term will be description of 1st term 
//similarly third term is description of 2nd term
/*
    Here are the first few terms of the Count and Say sequence for reference:

1st term: "1"
2nd term: "11"
3rd term: "21"
4th term: "1211"
5th term: "111221"
6th term: "312211"
*/

string nextTerm(int n){
    if(n==1){
        return "1";
    }
    string prev=nextTerm(n-1);
    string res="";
    int count=1;

    for(int i=0;i<prev.length();++i){
        if(i+1 <prev.length() && prev[i]==prev[i+1]){
            count++;
        }
        else{
            res+= to_string(count) + prev[i];
            count=1;
        }
    }

    return res;
}




//Reverse words in a string 
string reverseWord(string s){
    string res="";
    for(int i=s.length()-1;i>=0;i--){
        res+=s[i];
    }

    return res;
}

string reverseWordInString(string s){
    string res="";
    string word="";
    for(int i=0;i<s.length();i++){
        word+=s[i];
        if(s[i]==' '){
            res+=reverseWord(word)+" ";
            word="";
        }       
    }
    res+=reverseWord(word);

    return res;
}

//reverse the string but keep the words as it is
std::string reverseWords(std::string s) {
    std::istringstream iss(s);
    std::string word;
    std::string result;

    while (iss >> word) {
        if (!result.empty()) {
            result = word + " " + result;
        } else {
            result = word;
        }
    }

    return result;
}



//The longest common prefix (LCP) problem is the problem of finding the longest substring that is a prefix of all strings in a given set of strings.
//Naive approach or bruteforce approach
//O(S) where S=characters total of the all input

string largestCommonPrefix(vector<string> &A){\
    string prefix=A[0];
    for(int i=1;i<A.size();i++){
        while(A[i].find(prefix) != 0){
            prefix=prefix.substr(0,prefix.length()-1);
            if(prefix.empty()) return "";
        }
    }
    return prefix;
}

//Using trie  ->O(S)

//Using suffix array ->O(SLogS)

//String to roman
string intToRoman(int num){
    std::vector<std::pair<int, std::string>> roman = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    string res="";
    for(auto pair:roman){
        while(num>=pair.first){
            res+=pair.second;
            num-=pair.first;
        }
    }

    return res;
}

int RomanToInteger(string s){
    int res=0;
    int prev=0;
    std::unordered_map<char, int> romanValues = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };
    for(int i=s.size()-1;i>=0;i--){
        int val= romanValues[s[i]];
        if(val>=prev){
            res+=val;
        }
        else{
            res-=val;

        }
        prev=val;
    }

    return res;
}

//Minimum window substring
/*Given two strings, S (the "source string") and T (the "target string" or "Pattern string"), find the minimum window in S which will contain all the characters of T in any order.*/
//O(S + T) using sliding window technique
string mws(string s,string t) {
    int l = 0, r = 0;
    unordered_map<char, int> mp;
    for (char c : t) {
        mp[c]++;
    }

    int count = mp.size();
    int minLen = INT_MAX;
    int minStart = 0;

    while (r < s.length()) {
        if (mp.find(s[r]) != mp.end()) {
            mp[s[r]]--;
            if (mp[s[r]] == 0) {
                count--;
            }
        }

        while (count == 0) {
            if (r - l + 1 < minLen) {
                minLen = r - l + 1;
                minStart = l;
            }
            if (mp.find(s[l]) != mp.end()) {
                mp[s[l]]++;
                if (mp[s[l]] > 0) {
                    count++;
                }
            }

            l++;
        }

        r++;
    }

    if (minLen == INT_MAX) {
        return "";
    }

    return s.substr(minStart, minLen);
}

//Group anagrams
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagramGroups;

    for (const std::string& str : strs) {
        string sortedStr = str;
        sort(sortedStr.begin(), sortedStr.end());
        anagramGroups[sortedStr].push_back(str);
    }
    
    std::vector<std::vector<std::string>> result;
    for (const auto& pair : anagramGroups) {
        result.push_back(pair.second);
    }
    
    return result;
}

//Print all the permuation of a string 
void generatePermutations(string str, int start, int end) {
    if (start == end) {
        cout << str << std::endl;
        return;
    }

    for (int i = start; i <= end; i++) {
        // Swap the characters at positions start and i
        swap(str[start], str[i]);

        // Recursively generate permutations for the remaining characters
        generatePermutations(str, start + 1, end);

        // Restore the original order (backtrack)
        swap(str[start], str[i]);
    }
}

void printPermutations(string str) {
    int n = str.length();
    generatePermutations(str, 0, n - 1);
}

int main(){
    string str="hello";//"mynameissare";
    string str2="ll";//"mei";
    string sentence="hello world";
    //cout<<reverseWords(sentence);
    // vector<string> A ={"flower","flow","flight"};
    // cout<<intToRoman(58)<<endl;
    // cout<<RomanToInteger("LVIII");
    //cout<<mws("TOTMTAPTAT","TTA");

    // std::vector<std::string> words = {"eat", "tea", "tan", "ate", "nat", "bat"};
    // std::vector<std::vector<std::string>> result = groupAnagrams(words);
    // for (const auto& group : result) {
    //     for (const std::string& word : group) {
    //         std::cout << word << " ";
    //     }
    //     std::cout << std::endl;
    // }

    //printPermutations("abc");
    string str="Hello";
    cout<<tolower(str);

    return 0;
}