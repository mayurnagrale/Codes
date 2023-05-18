#include<bits/stdc++.h>
using namespace std;

int merge(int A[],int l,int y,int r){
    int p1=l,p2=y,p3=0;
    int temp[r-l+1];
    int count=0;
    while(p1<y && p2<=r){
        if(A[p1]<A[p2]){
            temp[p3]=A[p1];
            p3++; p1++;
        }
        else{
            temp[p3]=A[p1];
            p3++; p2++; count=y-p1;
        }
    }

    while(p1<y){
        tmep[p3]=A[p1];
        p3++;p1++;
    }

    while(p2<=r){
        tmep[p3]=A[p2];
        p3++; p2++;
    }
    return count;
}

int invCount(int A[],int l, int r){
    int mid = (l+r)/2;
    int x= invCount(A,l,mid);
    int y= invCount(A,mid+1,r);
    int z= merge(A,l,mid,r);
    return x+y+x;
}

int main(){
    int A={10,3 8,15,6,12,2,18,7,1};

    return 0;
}