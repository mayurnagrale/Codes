#include<bits/stdc++.h>
using namespace std;

int MaxAreaHisto(int* a,int n){
     vector<int>left;
     stack<pair<int,int>>st;
     int psudoIndex = -1;
    vector<int>right;
    stack<pair<int,int>>st1;
    int psudoIndexR = 7;
    vector<int>width;
    vector<int>area;
     int max=0;
    for(int i=0;i<n;i++){
        if(st.size()==0){
            left.push_back(psudoIndex);
        }
        else if(st.size() != 0 && st.top().first<a[i]){
            left.push_back(st.top().second);
        }
        else if(st.size() != 0 && st.top().first>=a[i]){
            while(st.size() != 0 && st.top().first>=a[i]){
                st.pop();
            }
            if(st.size()==0){
                left.push_back(psudoIndex);
            }
            else{
                left.push_back(st.top().second);
            }
        }
        st.push({a[i],i});
    }
    for(int i=n-1;i>=0;i--){
        if(st1.size()==0){
            right.push_back(psudoIndexR);
        }
        else if(st1.size() != 0 && st1.top().first<a[i]){
            right.push_back(st1.top().second);
        }
        else if(st1.size() != 0 && st1.top().first>=a[i]){
            while(st1.size() != 0 && st1.top().first>=a[i]){
                st1.pop();
            }
            if(st1.size()==0){
                right.push_back(psudoIndexR);
            }
            else{
                right.push_back(st1.top().second);
            }
        }
        st1.push({a[i],i});
    }
    for(int i=0;i<n;i++){
        width.push_back((right[i]-left[i])-1);
        area.push_back(a[i]*width[i]);
    }
    // for(int i=1;i<n;i++){
    //     max=area[0];
    //     if(area[i]>max){
    //         max=area[i];
    //     }
    // }
    for(int i=0;i<n;i++){
        cout<<left[i]<<"  ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<right[i]<<"  ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<width[i]<<"  ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<area[i]<<"  ";
    }
    cout<<endl;
    return max;
}

int main(){
    int a[7]={6,2,5,4,5,1,6};
    int n = sizeof(a)/sizeof(a[0]); 
    cout<<MaxAreaHisto(a,n);
    return 0;
}
