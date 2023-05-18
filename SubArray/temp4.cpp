#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> ar={ 978, 847, 95, 729, 778, 586, 188, 782, 813, 870, 871, 940, 312, 693, 580, 101, 760, 837, 564, 633, 680, 155, 241, 374, 682, 290, 850, 601, 433, 922, 773, 959, 530, 290, 990, 50, 516, 409, 868, 131, 664, 851, 721, 880, 20, 450, 745, 387, 787, 823, 392, 242, 674, 347, 65, 135, 819, 324, 651, 678, 139, 940};
    string A="b";
    string S1="aeiou";
    cout<<S1.find("c")<<endl;
    cout<<ar[0]<<" "<<ar[ar.size()-1]<<endl;
    cout<<ar.size();
    return 0;
}


    // int count = 0;
    // int res = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     if (a[i] == 1 && count % 2 == 0)
    //         continue;
    //     else if(a[i] == 0 && count % 2 != 0)
    //         continue;
    //     else if (a[i] == 1 && count % 2 != 0)
    //     {
    //         res++;
    //         count++;
    //     }
    //     else if (a[i] == 0 && count % 2 == 0)
    //     {
    //         res++;
    //         count++;
    //     }
    // }
    // return res;
