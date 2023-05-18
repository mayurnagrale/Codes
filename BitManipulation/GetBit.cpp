#include<bits/stdc++.h>
using namespace std;

int getBit(int n,int pos){
    return ((n & (1<<pos)) != 0); 
}

int setBit(int n,int pos){
    return (n | (1<<pos)); 
}

//clear n bits till pos
int clearBit(int n,int pos){
    int mask=0;
    for(int i=0;i<pos;i++){
        mask = ~(1<<i);
        n=n & mask;
    }
    return n;
}

int updateBit(int n,int pos,int value){
    int mask = ~(1<<pos);
    n = n & mask;
    return(n |(value<<pos));
}

bool checksetbit(int n,int pos){
    return ((n>>pos)&1) == 1;
}

int countsetbit(int A){
    int c=0;
    for(int i=0;i<=31;i++){
        if((A>>i)&1 == 1){
            c++;
        }
    }
    return c;
}

//and or
int solve(vector<int> &A){
    int j=1;
    int temp;
    int xorsum=0;
    for(int i=0;i<A.size()-1;i++,j++){
        temp=A[i];
        A[i]=A[i]&A[j];
        A[j]=temp|A[j];
    }
    for(int i=0;i<A.size();i++){
        xorsum^=A[i];
    }
    return xorsum;
}

int printsub(vector<int> &A){
    int i,j,c=0,res=0;
    vector<int> temp;
    for(i=0;i<A.size();i++){
        for(j=0;j<A.size();j++){
            res=0;
            temp.clear();
            for(int k=i;k<=j;k++){
                temp.push_back(A[k]);
            }
            for(int l=0;l<temp.size();l++){
                res|=temp[l];
            }
            if(res==1){
                c++;
            }       
        }
    }
    return c;
}

int printsubop(vector<int> &A){
    long C=0,Z=0;
    for(int i=0;i<A.size();i++){
        if(A[i]==0){
            Z++;
        }
    }

    C=(A.size()*(A.size()+1)/2)-(1+(Z-1)*2);
    
    return C;
}

int main(){
   // cout<<getBit(5,2)<<endl;
    //cout<<setBit(5,1)<<endl;
    //cout<<clearBit(93,4)<<endl;
    //cout<<updateBit(5,1,1)<<endl;
    //cout<<checksetbit(150,4);
    vector<int> A={0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0};
    //cout<<solve(A);
    //cout<<printsub(A);
    vector<int>B={0,1,0,0,0};
    cout<<printsubop(B);
    return 0;
}


    