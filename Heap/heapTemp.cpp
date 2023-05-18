#include<bits/stdc++.h>
using namespace std;

class Heap {

    int *heap;
    int heapSize;
    int heapCapacity;

    public:
        Heap() {
            heapSize = 0;
            heapCapacity = 0;
        }

        Heap(int N) {
            heapSize = 0;
            heapCapacity = N;
            heap = new int[N];
        }

        void insert(int X);
        void deleteMax();
        void swap(int i, int j);
        int getMax();
        int getSize();
        bool isEmpty();
};

void Heap::insert(int X) {
    if(heapSize == heapCapacity)
        return;
   
    heap[heapSize++] = X;
   
    int index = heapSize - 1;
    int parentIndex = (index - 1) >> 1;

    while(index > 0 && heap[index] > heap[parentIndex]) {
        swap(index, parentIndex);
        index = parentIndex;
        parentIndex = (index - 1) >> 1;
    }
}

void Heap::deleteMax() {
    heap[0] = heap[heapSize - 1];
    heap[heapSize - 1] = -1;
    heapSize--;

    int index = 0;
    while(2*index + 1 < heapSize) {
        int leftChild = (2 * index) + 1;
        int rightChild = (2 * index) + 2;

        int maxVal = max(heap[index], heap[leftChild]);
        maxVal = (rightChild < heapSize) ? max(maxVal, heap[rightChild]) : maxVal;

        if(maxVal == heap[leftChild]) {
            swap(index, leftChild);
            index = leftChild;
        }
        else if(rightChild < heapSize && maxVal == heap[rightChild]) {
            swap(index, rightChild);
            index = rightChild;
        }
        else {
            break;
        }
    }
}

void Heap::swap(int i, int j) {
    heap[i] = heap[i] + heap[j];
    heap[j] = heap[i] - heap[j];
    heap[i] = heap[i] - heap[j];
}

int Heap::getMax() {
    return heap[0];
}

int Heap::getSize() {
    return heapSize;
}

bool Heap::isEmpty() {
    return (heapSize == 0);
}



int Solution::nchoc(int A, vector<int> &B) {
    long chocolateCount = 0, MOD = 1000000007;

    Heap bags(B.size());
   
    for(int i=0; i<B.size(); i++)
        bags.insert(B[i]);
   
    while(A--) {
        int currChocolateCount = bags.getMax();
        chocolateCount = (chocolateCount % MOD  +  currChocolateCount % MOD) % MOD;

        bags.deleteMax();

        bags.insert(currChocolateCount >> 1);
    }

    return (int)chocolateCount;
}