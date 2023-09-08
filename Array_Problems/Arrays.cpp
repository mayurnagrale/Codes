#include<bits/stdc++.h>
using namespace std;    

std::vector<std::vector<int>> divideArrayIntoKBatches(const std::vector<int>& arr, int k) {
    int s = arr.size();
    int j=0;
    vector<vector<int>> batches;
    for(int i=0;i<s;){
        int l=0;
        vector<int> batch;
        for(int j=0;j<k && j<s;j++){
            l++;
            if(i+l<s){
                batch.push_back(arr[i+j]);
            }
            else{
                while(i<s){
                    batch.push_back(arr[i]);
                    i++;
                }
            }              
        }
        batches.push_back(batch);
        i=i+l;
    }
    return batches;
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 3;

    std::vector<std::vector<int>> batches = divideArrayIntoKBatches(arr, k);

    for (const std::vector<int>& batch : batches) {
        for (int num : batch) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
