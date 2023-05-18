#include<bits/stdtr1c++.h>
using namespace std;

vector<int> pfA(vector<int> A){
    vector<int>pf;
    pf.push_back(A[0]);
    for(int i=1;i<A.size();i++){
        pf.push_back(pf[i-1]+A[i]);
    }
    return pf;
}

vector<long> rangeSum(vector<int> &A, vector<vector<int> > &B) {
    int x,y;
    vector<long>v;
    vector<int>pf=pfA(A);
    for(int i=0;i<pf.size();i++){
        cout<<pf[i]<<" ";
    }
    cout<<endl;

    for (int i = 0; i < B.size(); i++)
	{
		for (int j = 0; j < B[i].size(); j++)
		{
            if(j==0){
                x=B[i][j]-1;
            }
            else{
                y=B[i][j]-1;
            }            
		}
        if(x==0){
            v.push_back(pf[y]);
        }
        else{
            v.push_back(pf[y]-pf[x-1]);        	
        }
	}
    return v;
}

int main(){
    vector<int> AA={7, 3, 1, 5, 5, 5, 1, 2, 4, 5};
    vector<vector<int>> BB= {{7,10},{3,10},{3,5},{1,10}};
    vector<long> res=rangeSum(AA,BB);
    for (int i = 0; i < res.size(); i++)
	{
        cout<<res[i]<<" ";
    }
    return 0;
}
