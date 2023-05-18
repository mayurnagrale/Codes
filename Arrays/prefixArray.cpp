#include<bits/stdc++.h>
using namespace std;

//prefix sum
vector<int> pfA(vector<int> A){
    vector<int>pf;
    pf.push_back(A[0]);
    for(int i=1;i<A.size();i++){
        pf.push_back(pf[i-1]+A[i]);
    }
    return pf;
}

//range sum ex [4,8]
int rangeSum(vector<int> A,int i,int j){
    vector<int>pf=pfA(A);
    //sum[i,j]
    if(i==0){
        return pf[j];
    }
    return pf[j]-pf[i-1];
}

//max of a range of size B
int maxRange(vector<int> A,int B){
    vector<int>pfS=pfA(A);
    int l=B-1;
    int max=INT_MIN;
    int rangeSum=INT_MIN;
    for(int i=0;i<A.size();i++){
        if(i==0){
            rangeSum=pfS[l];
            cout<<i<<" "<<rangeSum<<endl;
        }
        if(i==A.size()-B){
            rangeSum=pfS[l+i]-pfS[i-1];
            cout<<i<<" "<<rangeSum<<endl;
        }
        if(i>=A.size()-l){
            rangeSum=pfS[A.size()-1]-pfS[i-1]+pfS[i-(A.size()-l)];
            cout<<i<<" "<<rangeSum<<endl;
        }
        if(rangeSum>max){
            max=rangeSum;
        }
        rangeSum=INT_MIN;
    }
    return max;
}

//equilibrium index leftSum == rightSum
int SpecialIndexCount(vector<int>A){
    vector<int>pf=pfA(A);
    int count=0,left,right,n=A.size();
    //check SI for all I
    for(int i=0;i<n;i++){
        //left sum of i =left[0,i-1]
        if(i==0)
            left=0;
        left=pf[i-1];
        right=pf[n-1]-pf[i];
        if(left==right){
            count++;
        }
    }
    return count;
}

//even prefix sum array
vector<int> pfE(vector<int>A){
    vector<int>pfEven;
    pfEven.push_back(A[0]);
    for(int i=1;i<A.size();i++){
        if(i%2==0){
            pfEven.push_back(pfEven[i-1]+A[i]);
        }
        else{
            pfEven.push_back(pfEven[i-1]);
        }
    }
    return pfEven;
}

//odd prefix sum array
vector<int> pfO(vector<int>A){
    vector<int>pfOdd;
    pfOdd.push_back(0);
    for(int i=1;i<A.size();i++){
        if(i%2==0){
            pfOdd.push_back(pfOdd[i-1]);
        }
        else{
            pfOdd.push_back(pfOdd[i-1]+A[i]);
        }
    }
    return pfOdd;
}

//range even sum ex[2,6]
int rangeEvenSum(vector<int>A,int i,int j){
    vector<int>pfEven = pfE(A);
    if(i==0){
        return pfEven[j];
    }
    return pfEven[j]-pfEven[i-1];
}

//range odd sum ex[4,6]
int rangeOddSum(vector<int>A,int i,int j){
    vector<int> pfOdd=pfO(A);
    if(i==0){
        return pfOdd[j];
    }
    return pfOdd[j]-pfOdd[i-1];
}

//after removing check if evenSum == oddSum
int imp(vector<int> A){
    vector<int> pfEven = pfE(A);
    for(int i=0;i<pfEven.size();i++){
        cout<<pfEven[i]<<" ";
    }
    cout<<endl;
    vector<int> pfOdd = pfO(A);
    for(int i=0;i<pfOdd.size();i++){
        cout<<pfOdd[i]<<" ";
    }
    cout<<endl;
    int TE,TO,C=0;
    for(int i=0; i<A.size();i++){
        if(i==0){
            TE=pfOdd[pfOdd.size()-1]-pfOdd[i];
            TO=pfEven[pfEven.size()-1]-pfEven[i];
        }
        else{
            TE=pfEven[i-1]+pfOdd[A.size()-1]-pfOdd[i];
            TO=pfOdd[i-1]+pfEven[A.size()-1]-pfEven[i];
        }
        if(TE==TO){
            C++;
        }
    }
    return C;
}

int main(){
    // vector<int> A={-3,6,2,4,5,2,8,-9,3,1};
    // int x;
    // for(int i=0;i<A.size();i++){
    //     cout<<A[i]<<"  ";
    // }
    // vector<int>B=pfA(A);
    // cout<<endl;
    // for(int i=0;i<B.size();i++){
    //     cout<<B[i]<<"  ";
    // }
    // cout<<endl;
    // cout<<"range sum : "<<rangeSum(A,3,7)<<endl;

    // vector<int>C={3,-1,2,-1,1,2,1};
    // cout<<"spacial index count: "<<SpecialIndexCount(C)<<endl;

    // vector<int>D={2,-1,3,1,4,3,2,-1};
    // vector<int>E=pfE(D);
    // for(int i=0;i<E.size();i++){
    //     cout<<E[i]<<" "; 
    // }
    // cout<<endl;
    // vector<int>F=pfO(D);
    // for(int i=0;i<F.size();i++){
    //     cout<<F[i]<<" "; 
    // }
    // cout<<endl;
    // vector<int>G={3,4,-2,8,6,2,1,3};
    // cout<<"range even sum : "<<rangeEvenSum(G,3,7)<<endl;
    // cout<<"range odd sum : "<<rangeOddSum(G,3,7)<<endl;
    vector<int>J={5, -2, 3 , 1, 2};
    vector<int>H={-584, -714, -895, -512, -718, -545, 734, -886, 701, 316, -329, 786, -737, -687, -645, 185, -947, -88, -192, 832, -55, -687, 756, -679, 558, 646, 982, -519, -856, 196, -778, 129, -839, 535, -550, 173, -534, -956, 659, -708, -561, 253, -976, -846, 510, -255, -351, 186, -687, -526, -978, -832, -982, -213, 905, 958, 391, -798, 625, -523, -586, 314, 824, 334, 874, -628, -841, 833, -930, 487, -703, 518, -823, 773, -730, 763, -332, 192, 985, 102, -520, 213, 627, -198, -901, -473, -375, 543, 924, 23, 972, 61, -819, 3, 432, 505, 593, -275, 31, -508, -858, 222, 286, 64, 900, 187, -640, -587, -26, -730, 170, -765, -167, 711, 760, -104, -333};
    cout<<"Max range of Size : "<<maxRange(J,3)<<endl;
    // vector<int>I={4,3,2,7,6,-2};
    // cout<<imp(I)<<endl;
    return 0;
}