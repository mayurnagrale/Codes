#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> A = {1, 2, 3, 4, 5};
    vector<int> left;
    vector<int> right;
    vector<int> ans;
    left.push_back(1);
    for(int i=0;i<A.size();i++){
        right.push_back(1);
    }

    for (int i = 1; i < A.size(); i++)
    {
        left.push_back(A[i - 1] * left[i - 1]);
    }

    for (int j = A.size() - 2; j >= 0; j--)
    {
        right[j]=A[j + 1] * right[j + 1];
    }

    for (int i = 0; i < A.size(); i++)
    {
        ans.push_back(left[i] * right[i]);
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}