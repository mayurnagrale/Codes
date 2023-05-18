#include<bits/stdc++.h>
using namespace std;

//Max Sub Array of size k
//windows size = j-i+1
int slidingWindow(int S[],int T){
    int i=0,j=0,sum=0;
    int k = T;
    int max = 0;
    int n= sizeof(S) / sizeof(S[0]);
    while(j<n)
    {
        sum = sum + S[0];
        if(j-i+1 < k)
        {
            j++;
        }
        else if(j-i+1 == k)
        {
            max = std::max(max,sum);
            sum = sum - S[i];
            i++;j++;
        }
    }

    return max;
}

int main()
{
    int n=0;
    int T=0;
    cout<<"Enter the size of S: ";
    cin>>n;
    int S[n];
    for(int i=0;i<n;i++)
    {
        cin>>S[i];
    }
    cout<<"Enter the value of Window:";
    cin>>T;
    cout<<slidingWindow(S,T);
    return 0;
}