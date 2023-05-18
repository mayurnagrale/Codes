//1.Intersection of two array
//2.Union of two array
//3.Common Element
//4.Subsequence
//5.check if exist a pair(a,b) of having sum a+b= K and a!=b
//6.Get number of distinct element in every window of size K
//7.Find the longest subarray with length zero

#include<bits/stdc++.h>
using namespace std;

//check if exist a pair(a,b) of having sum a+b= K and a!=b
//a!=b
bool sumK1(vector<int> &A, int k){
    unordered_map<int,int> HMA;
    for(int i=0;i<A.size();i++){
        HMA[A[i]]++;
    }
    for(int i=0;i<A.size();i++){
        int b=k-A[i];
        if(A[i] !=b){
            if(HMA.find(b) != HMA.end()){
                return true;
            }
        }
        else{
            if(HMA[b]>1){
                return true;
            }
        }
    }
    return false;
}

//A[i]-A[j]=B and i!=j
bool pairIJ(vector<int> &A,int B){
    unordered_map<int,int> hm;
    for(int i=0;i<A.size();i++){
        hm[A[i]]++;
    }

    for(int i=0;i<A.size();i++){
        int a,b;
        a=A[i];
        b=a-B;
        if(a!=b){
            if(hm.find(b) != hm.end()){
                return 1;
            }
        }
        else{
            if(hm[b]>1){
                return 1;
            }
        }
    }
    return 0;
}

//using hashset
bool sumK2(vector<int> &A,int k){
    unordered_set<int> hs;
    for(int i=0;i<A.size();i++){
        int a=A[i];
        int b=k-a;
        if(hs.find(b)!=hs.end()){
            return true;
        }
        hs.insert(a);
    }
    return false;
}

//Get number of distinct element in every window of size K
vector<int> distinctInSubarrayK(vector<int> &A,int k){
    unordered_map<int,int> hm;
    vector<int> res;
    for(int i=0;i<k;i++){
        if(hm.find(A[i]) != hm.end()){
            hm[A[i]]++;
        }
        else{
            hm.insert(make_pair(A[i],1));
        }
    }
    res.push_back(hm.size());
    for(int s=1;s<=A.size()-k;s++){
        int e=s+k-1;
        hm[A[s-1]]--;
        if(hm[A[s-1]] == 0){
            hm.erase(A[s-1]);
        }
        if(hm.find(A[e]) != hm.end()){
            hm[A[e]]++;
        }
        else{
            hm.insert(make_pair(A[e],1));
        }
        res.push_back(hm.size());
    }
    return res;
}

//colorful
int colorful(int A) {
    vector<int> B;
    unordered_set<int> hs;
    int n;
    int temp;
    while(A!=0){
        B.push_back(A%10);
        A=A/10;
    }
    n=B.size();

    for(int i=0;i<B.size();i++){
        cout<<B[i]<<" ";
    }
    cout<<endl;
    for(int i=B.size()-1;i>=0;i--){
        hs.insert(B[i]);
        int prod=B[i];
        for(int j=i-1;j>=0;j--){
            prod *= B[j];
            hs.insert(prod);
        }
    }
    for(auto &it:hs){
        cout<<it<<" ";
    }
    cout<<endl;
    int x=(n*(n+1))/2;
    cout<<hs.size()<<" "<<x<<endl;
    if(hs.size()==(n*(n+1))/2){
        return 1;
    }
    else{
        return 0;
    }
}

//Shaggy min distance between pairs
int minDpair(vector<int> &A) {
    unordered_map<int,int> hm;
    int minLen = A.size();
    for(int i=0;i<A.size();i++){
        if(hm.find(A[i])!=hm.end()){
            hm[A[i]]=i-hm[A[i]];
            if(hm[A[i]]<minLen){
                minLen=hm[A[i]];
                cout<<minLen<<endl;
            }
        }
        else{
            hm[A[i]]=i;
        }

    }
    // for(auto &it:hm){
    //     cout<<it.first<<":"<<it.second<<" ";
    // }
    cout<<endl;
    if(minLen==A.size()){
        return -1;
    }
    return minLen;
}

//Is Dictionary
int solved(vector<string> &A, string B){
    unordered_map<char,int> hm;
    bool flag=false;
    int first=0,sec=0;
    for(int i=0;i<B.length();i++){
        hm[B[i]]=i+1;
    }
    
    for(int i=1;i<A.size()-1;i++){
        if(hm[A[i][0]] > hm[A[i-1][0]]){
            flag=true;
        }
        else{
            flag=false;
        }

    }
    if(flag){
        return 1;
    }
    else{
        return 0;
    }
}

// bool comp(pair<int,int> a,pair<int,int> b){
//     if(a.second<b.second){
//         return true;
//     }
//     else if(a.second>b.second){
//         return false;
//     }
//     else{
//         if(a.first<b.first){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
// }

vector<int> twoSum(vector<int> &A, int B) {
    unordered_map<int,int> hm;
     vector<paint,int> res;
    vector<int> ans;
    // for(int i=0;i<A.size();i++){
    //     hm[A[i]]=i+1;
    // }
    // for(int i=0;i<A.size();i++){
    //     int a=A[i];
    //     int b=B-a;
    //     if(a!=b){
    //         if(hm.find(b) != hm.end()){
    //             //res.push_back(make_pair(hm[a],hm[b]));
    //         }
    //     }
    //     else{
    //         if(hm[b]>1){
    //             //res.push_back(make_pair(hm[a],hm[b]));
    //         }
    //     }
    // }
    // if(res.size()==0){
    //     return ans;
    // }
    // sort(res.begin(),res.end(),comp);
    // ans.push_back(res[0].first);
    // ans.push_back(res[0].second);
    return ans;
}

int main(){
    //vector<int> A={8,9,1,-2,4,5,11,-6,7};
    vector<int> A={2, 7, 11, 15};
    vector<int> B={2,4,3,8,3,9,4,9};
    int k=22;
    vector<int> C={7, 1, 3, 4, 1, 7};
    //vector<int> D={81760, 79550, 22559, 75299, 16955, 88462, 61786, 75867, 70648, 3369, 22975, 96532, 25025, 66395, 93487, 99745, 18113, 53612, 27186, 46537, 45321, 66174, 17988, 41507, 1917, 17613, 20118, 97218, 49013, 69220, 7583, 17748, 64613, 99073, 32976, 84997, 96961, 1757, 9565, 19937, 20844, 52727, 84400, 2459, 29910, 92266, 56997, 95895, 14078, 62465, 56931, 58056, 31338, 85194, 35782, 85090, 75386, 13941, 4115, 25904, 20784, 87872, 60888, 48447, 95087, 54725, 91079, 22263, 88947, 79672, 45292, 81355, 18933, 29522, 44401, 73426, 6301, 75670, 77769, 58508, 67734, 41227, 26015, 97582, 3651, 56043, 74721, 18679, 65400, 33055, 19979, 7691, 484, 93470, 40183, 67462, 81564, 99434, 4884, 38894};
    // vector<int> res=distinctInSubarrayK(B,4);
    vector<int> res=twoSum(A,9);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    //cout<<colorful(23);
    vector<string> D={"hello", "scaler", "interviewbit"}; 
    string E="adhbcfegskjlponmirqtxwuvzy";
    //cout<<minDpair(D)<<endl;
    //cout<<solved(D,E)<<endl;
    return 0;
}