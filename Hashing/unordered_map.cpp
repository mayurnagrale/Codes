// TOPIC std:: unodered_map in C++

//NOTES
// Key - value pairs with unique key
// Search Insertion and Removal has cosntant time complexity
// It uses hashing to insert elements into bucket

#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<int, char> umap ={{1,'a'},{2,'b'}};
    //Access
    cout<<umap[1] << endl;
    cout<<umap[2] << endl;

    //update
    umap[1] = 'c';

    //Iterate
    for(auto & elm: umap){
        cout<<elm.first<<" "<<elm.second<<endl;
    }

    //Find 
    auto result = umap.find(2);
    if(result !=umap.end()){
        cout<<"Found "<<result->first<<" "<<result->second<<endl;
    }
    else{
        cout<<"Not Found\n";
    }

    return 0;
}