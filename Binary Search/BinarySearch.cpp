#include<bits/stdc++.h>
using namespace std;

int binarySearch(int* arr,int searchEle,int  n){
    int start= 0;
    int end =n-1;
    int mid = (start+end)/2;
    while(start<=end){
        mid=(start+end)/2;
        if(searchEle == arr[mid]){
            return mid;
        }
        else if(searchEle<arr[mid]){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }

}

int binarySearchInDesc(int* arr,int searchEle,int  n){
    int start =0;
    int end = n-1;
    int mid = 0;
    while(start<=end){
        mid = start + ((end-start)/2);
        if(searchEle == arr[mid]){
            return mid;
        }
        else if(searchEle < arr[mid]){
            start=mid+1;
        }
        else{
            end = mid-1;
        }
    }
}

//for first occurance of the search element
int binarySearchForFirstOcc(int* arr,int searchEle,int  n){
    int start=0;
    int end=0;
    int mid=0;
    int res=0;
    while(start<=end){
        mid=start+((end-start)/2);
        if(searchEle == arr[mid]){
            res=mid;
            end=mid-1;
        }
        else if(searchEle<arr[mid]){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return res;
}

//for the last occurance of the search element
int binaarySearchForLastOcc(int* arr,int searchEle,int  n){
    int start=0;
    int end=0;
    int mid=0;
    int res=0;
    while(start<=end){
        mid=start+((end-start)/2);
        if(searchEle == arr[mid]){
            res=mid;
            start=mid+1;
        }
        else if(searchEle<arr[mid]){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return res;
}

//count of the element in a sorted array
int countOftheElement(int* arr,int searchEle,int  n){
    int first=binarySearchForFirstOcc(arr,searchEle,n);
    int last=binaarySearchForLastOcc(arr,searchEle,n);
    int count= last-first+1;
    return count;
}

//no of times array should be rotated
int arrayRotationCount(int* arr,int  n){
    int start=0;
    int end=n-1;
    int mid=0;
    int prev=0;
    int next=0;
    while(start<=end){
        prev=(mid+n-1)%n;
        next=(mid+1)%n;
        if(arr[mid]<=arr[prev] && arr[mid]<=arr[next]){
            return mid;
        }
        else if(arr[start]<arr[mid]){
            start=mid+1;
        }
        else if(arr[mid]<arr[end]){
            end=mid-1;
        }
    }
}

//first occurance of 1 in infinite 0 1 sorted array
int indexoffirst(int* binarr,int n){
    int start= 0;
    int end=1;
    int res=0;
    int mid =0;
    while(binarr[end]<1){
        start=end;
        end=end*2;
    }
    while(start<=end){
        mid=(start+end)/2;
        if(binarr[mid]<1){
            start=mid+1;
        }
        else if(binarr[mid]==1){
            res=mid;
            end=mid-1;
        }
    }
    return res;
}

//finding peak element in unsorted array using binary search
int indexofpeak(int* unsortedarr,int n2){
    int start=0;
    int end=n2-1;
    int mid=0;
    int res =0;
    while(start<=end){
        mid=(start+end)/2;
        if(mid>0 && mid<(n2-1)){
            if(unsortedarr[mid]>unsortedarr[mid-1] && unsortedarr[mid]>unsortedarr[mid+1]){
                res=mid;
                return res;
            }
            else if(unsortedarr[mid]<unsortedarr[mid-1]){
                end=mid-1;
            }
            else if(unsortedarr[mid]<unsortedarr[mid+1]){
                start=mid+1;
            }
        }
    }
    return 0;
}


//Allocate books
int allocateBooks(int *arrofbooks, int n){
    int max=*max_element(arrofbooks,arrofbooks+n);
    int k=2;
    int start=max;
    int end = 0;
    end = accumulate(arrofbooks,arrofbooks+n,end);
    int mid=0;
    int res = -1;
    if(n<k){
        return -1;
    }
    while(start<=end){
        mid = start + ((end-start)/2);
        if(isValid(arrofbooks,n,k,max)){
            res=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
}

bool isValid(int *arrofbooks, int n,int k,int max){
    int st=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+arrofbooks[i];
        if(sum<max){
            st++;
        }
    }
    if(st>k){
        return false;
    }
    return true;
}

int main(){
    int binarr[]={0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int arrofbooks[]={10,20,30,40};
    int unsortedarr[] = {1,3,8,13,4,2};//{10,20,15,2,23,90,67};
    int searchEle = 2;
    int n = sizeof(arr)/sizeof(arr[0]); 
    int n1= sizeof(binarr)/sizeof(binarr[0]);
    int n2=sizeof(unsortedarr)/sizeof(unsortedarr[0]);
    int n3=sizeof(arrofbooks)/sizeof(arrofbooks[0]);
    //cout<<binarySearch(arr,searchEle,n);
    //cout<<indexoffirst(binarr,n1);
    //cout<<indexofpeak(unsortedarr,n2);
    cout<<allocateBooks(arrofbooks,n3);
    return 0;
}