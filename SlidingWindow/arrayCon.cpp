#include<bits/stdc++.h>
using namespace std;

void dynamicArr(){
    int *values  =new int[4];
    values[0] = 1;
    values[1] = 3;
    values[2] = 5;
    values[3] = 7;

    for(int i=0;i<4;i++){
        cout<<values[i]<<" ";
    }
}

void vectorArr(){
    vector<int> valuev;
    valuev.push_back(2);
    valuev.push_back(4);
    valuev.push_back(3);
    valuev.push_back(8);

    for(int i=0;i<valuev.size();i++){
        cout<<valuev[i]<<" ";
    }
}

void clearVector()
{
    vector<int>valuecv;
    valuecv.push_back(44);
    if(valuecv.empty() == false){
        valuecv.clear();
    }
    valuecv.push_back(2);
    valuecv.push_back(4);

    for(int i = 0 ;i<valuecv.size();i++){
        cout<<i<<": "<<valuecv[i]<<" ";
    }
}

int main()
{
    int src[] = {2,4,6,8}; // static array
    int dest[10]; // static array

    int s_size = sizeof(src)/sizeof(*src); // src[0]
    int d_size = sizeof(dest)/sizeof(*dest);
    copy(src,src+10,dest);
    //cout<<s_size<<endl;
    //cout<<d_size<<endl;
    dest[6] = 12;
    //for(int i=0;i<d_size;i++)//s_size
    //{
        //cout<<src[i]<<endl;
    //    cout<<dest[i]<<endl;
    //}
    dynamicArr();
    cout<<endl;
    vectorArr();
    cout<<endl;
    clearVector();
    return 0;
}