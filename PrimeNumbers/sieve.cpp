#include<bits/stdc++.h>
using namespace std;

//Sive of erotasthenes 

void primeSieve(int n){
    int prime[n+1] = {0};

    for(int i=2;i*i<n;i++){
        if(prime[i]==0){
            for(int j=i*i;j<=n;j+=i){
                prime[j]=1;
            }
        }
    }

    for(int i=2;i<n;i++){
        if(prime[i]==0){
            cout<<i<<endl;
        }
    }
}

//Prime factor using sieve
void primeFactor(int n){
    int spf[n+1]={0};
    int count=2;
    for(int i=2;i<=n;i++){
        spf[i]=i;
    }

    for(int i=2;i<=n;i++){
        if(spf[i]==i){
            for(int j=i*i;j<=n;j+=i){
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
    }

    while(n!=1){
        //cout<<spf[n]<<" ";
        count+=1;
        n=n/spf[n];
    }
    cout<<count;
}

int main(){
    //primeSieve(50);
    primeFactor(30);
    return 0;
}