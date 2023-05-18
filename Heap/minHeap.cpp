#include<bits/stdc++.h>
using namespace std;

class minHeap{
    public:
        int capacity=10;
        int size=0;
        int items[10];

        int getLeftChildIndex(int parentIndex){return 2*parentIndex+1;}
        int getRightChildIndex(int parentIndex){return 2*parentIndex+2;}

        int getParentIndex(int childIndex){return (childIndex-1)/2;}

        bool hasLeftChild(int index){return getLeftChildIndex(index)<size;}
        bool hasRightChild(int index){return getRightChildIndex(index)<size;}

        bool hasParent(int index){return getParentIndex(index)>=0;}

        int leftChild(int index){return items[getLeftChildIndex(index)];}
        int rightChild(int index){return items[getRightChildIndex(index)];}

        int parent(int index){return items[getParentIndex(index)];}
        int getSize(){
            return size;
        }

        void swap(int idx1,int idx2){
            int temp=items[idx1];
            items[idx1]=items[idx2];
            items[idx2]=temp;
        }

        void ensureExtraCapacity(){
            if(size==capacity){
                capacity*=2;
            }
        }

        int checkMin(){
            if(size==0){
                return -1;
            }
            return items[0];
        }

        void heapifyUp(){
            int index=size-1;
            while(hasParent(index) && parent(index)>items[index]){
                swap(getParentIndex(index),index);
                index=getParentIndex(index);
            }
        }

        void heapifyDown(){
            int index=0;
            while(hasLeftChild(index)){
                int smallerChildIndex=getLeftChildIndex(index);
                if(hasRightChild(index) && rightChild(index)<leftChild(index)){
                    smallerChildIndex=getRightChildIndex(index);
                }
                if(items[index]<items[smallerChildIndex]){
                    break;
                }
                else{
                    swap(index,smallerChildIndex);
                }
                index=smallerChildIndex;
            }
        }

        int extractMin(){
            if(size==0){
                return -1;
            }
            int item=items[0];
            items[0]=items[size-1];
            size--;
            heapifyDown();
            return item;
        }

        int insert(int item){
            //ensureExtraCapacity();
            items[size]=item;
            size++;
            heapifyUp();
        }

        void print(){
            for(int i=0;i<size;i++){
                cout<<items[i]<<" ";
            }
            cout<<endl;
        }
};

int main(){
    vector<int> v={1,2,3,4,5};
    minHeap A;
    int cost=0;
    int sum;
    for(int i=0;i<v.size();i++){
        A.insert(v[i]);
    }
    A.print();
    while(A.getSize()>=1){
        sum=A.extractMin()+A.extractMin();
        cost+=sum;
        cout<<cost<<endl;
        if(A.getSize() != 0){
            A.insert(sum);
        }
        else{
            break;
        }
        A.print();
    }
    cout<<cost<<endl;
    A.print();
    return 0;
}