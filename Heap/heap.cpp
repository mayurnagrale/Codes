#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
        int arr[100];
        int size;

        heap(){
            arr[0]=-1;
            size=0;
        }


//TC:O(log n)
//Max Heap
        void insert(int val){
            size++;
            int idx=size;
            arr[idx]=val;

            while(idx>1){
                int parent=idx/2;
                if(arr[parent]<arr[idx]){
                    swap(arr[parent],arr[idx]);
                    idx=parent;
                }
                else{
                    return;
                }
            }
        }

//Delete node
        // void delete(){
        //     if(size==0){
        //         cout<<"Nothing to delete"<<endl;
        //         return;
        //     }

        //     arr[1]=arr[size];
        //     size--;

        //     //take root node to its correct position
        //     int i=1;
        //     while(i<size){
        //         int leftIdx=2*i;
        //         int rightIdx=2*i+1;

        //         if(arr[leftIdx]<size && arr[i]<arr[leftIdx]){

        //         }
        //     }
        // }


        void print(){
            for(int i=1;i<=size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }


};

int main(){
    heap h;
    h.insert(1);
    h.insert(5);
    h.insert(3);
    h.insert(2);
    h.insert(4);

    h.print();

    return 0;
}