#include<bits/stdc++.h>
using namespace std;

//sort in ascending order
vector<int> sortAsc(vector<int> &v){
    sort(v.begin(), v.end());
    cout << "Sorted \n";
    for (auto x : v)
        cout << x << " ";

    return v;
}

//sort in descending order
void sortDesc(){
    vector<int> v{ 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 }; 
    sort(v.begin(), v.end(), greater<int>()); 
    cout << "Sorted \n";
    for (auto x : v)
        cout << x << " ";
}

int nobelEle(vector<int> &A){
    sort(A.begin(), A.end());
    cout << "Sorted \n";
    for (auto x : A)
        cout << x << " ";
    cout<<endl;
    int ans=0;
    int count=0;
    if(A[0]==0){
        ans++;
    }
    for(int i=1;i<A.size();i++){
        if(A[i] != A[i-1]){
            count=i;
        }
        if(A[i]==count){
            ans++;
        }
    }
    return ans;
}

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

int lastDigitFromRight(int x){
    int temp;
    while(x){
        temp=x;
        x=x/10;
    }
    return temp;
}
bool comp(int x,int y){
    if(lastDigitFromRight(x)>lastDigitFromRight(y)){
        return true;
    }
    else if(lastDigitFromRight(x)<lastDigitFromRight(y)){
        return false;
    }
    else{
        if(countDigit(x)==countDigit(y)){
            if((x/10)%10>=y){
                return true;
            }
            else{
                return false;
            }
        }
        else if(x>=y){
            return true;
        }
        else{
            return false;
        }
    }
}


string largestNumber(vector<int> &A) {
    sort(A.begin(),A.end(),comp1);
    string str="";
    for(int i=0;i<A.size();i++){
        str+= to_string(A[i]);
        //str+= '0'+A[i];
    }
    return str;
}


int main(){
    // vector<int> A={1,-5,3,5,-10,4};
    // vector<int> B={-10,1,1,2,4,4,4,8,10};
    // vector<int> C={5,6,2};
    // cout<<nobelEle(A)<<endl;
    // cout<<nobelEle(B)<<endl;
    // cout<<nobelEle(C)<<endl;
    vector<int> D={472, 663, 964, 722, 485, 852, 635, 4, 368, 676, 319, 412};
    cout<<largestNumber(D)<<endl;
    for(int i=0;i<D.size();i++){
        cout<<countDigit(D[i])<<" ";
    }
    return 0;
}