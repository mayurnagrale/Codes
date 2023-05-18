#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()  {
    // YOUR CODE GOES HERE
    // Please take input and print output to standard input/output (stdin/stdout)
    // E.g. 'cin' for input & 'cout' for output
    int T,N;
    vector<int> odd;
    vector<int> even;
    cin>>T;
    while(T){
        cin>>N;
        int arr[N];
        for(int i=0;i<N;i++){
            cin>>arr[i];
        }
        for(int i=0;i<N;i++){
            if(arr[i]%2==0){
                even.push_back(arr[i]);
            }
            else{
                odd.push_back(arr[i]);
            }
        }
        for(int i=0;i<odd.size();i++){
            cout<<odd[i]<<" ";
        }
        odd.clear();
        cout<<endl;
        for(int i=0;i<even.size();i++){
            cout<<even[i]<<" ";
        }
        even.clear();
        cout<<endl;
        T--;
    }
    return 0;
}