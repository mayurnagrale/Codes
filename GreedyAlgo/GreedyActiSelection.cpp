//Greedy activity selection
//Returns the count of maximum activity 
/* Psudo algorithm
void maxActivity(Activity arr[], int n){
    //sort jobs according to finish time 
    sort(arr,arr+n,activityCompare);

    //select the first job and print
    int i=0;
    cout<<arr[i].start<<","<<arr[i].finish<<endl;

    //consider the rest of the activities
    for(int j=1;j<n;j++){
        //If the activity start time is grater than the previous activity finish time 
        if(arr[j].start > arr[i].finish){
            cout<<arr[j].start<<","<<arr[j].finish<<endl;
            i=j;
        }
    }
}
*/

//struct array

#include<iostream>
using namespace std;

struct Activity{
    int start;
    int finish;
};

int main(){
    Activity activity[5];
    activity[0].start = 10;
    activity[0].finish = 20;

    activity[1]={15,25};

    Activity activities[4]={
        {12,25},{10,20},{20,30},{30,40}
    };

    cout<<"Printing all the activities time"<<endl;
    for(int  i=0; i<5;i++){
        cout<<activities[i].start<<" "<<activities[i].finish<<endl;
    }
    return 0;
}
