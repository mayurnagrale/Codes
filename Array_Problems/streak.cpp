#include<bits/stdc++.h>
using namespace std;


void winner(vector<int> &A, vector<int> &B){
    int count1 = 0;
    int count2 = 0;
    int zerocount1 = 0;
    int zerocount2 = 0;
     for (size_t i = 0; i < A.size(); i++)
    {
        if(A[i] == 0)
        {
            if(zerocount1 > count1){
                    count1 = zerocount1;
                    zerocount1 = 0;
            }
        }
        else if(i == A.size()-1){
            if(zerocount1 > count1){
                count1 = zerocount1;
            }
        }
        else{
            zerocount1++;
        }

    }
    for (size_t i = 0; i < B.size(); i++)
    {
        if(B[i] == 0)
        {
            if(zerocount2 > count2){
                    count2 = zerocount2;
                    zerocount2 = 0;
            }
        }
         else if(i == B.size()-1){
            if(zerocount2 > count2){
                count2 = zerocount2;
            }
        }
        else {
            zerocount2++;
        }

    }
    if(count1 == count2){
        cout<<"Draw";
    }
    else if(count1 > count2){
        cout<<"om";
    }
    else{
        cout<<"Addy";
    }

}

int main(){
    vector<int> om={1,2,4,0,7,99,1};
    vector<int> Addy={4,7,0,3,5,6,0};

    winner(om,Addy);

    return 0;
}