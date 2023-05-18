//Gas station problem

#include<iostream>
using namespace std;

//brute force approach
int gasStation(int gas[],int cost[]){
    int tank;
    bool possible=true;
    int j;
    for(int i=0;i<sizeof(gas);i++){
        tank=0;
        for(j=0;j<i%sizeof(gas);j++){
            tank=tank+gas[j]-cost[i];
            if(tank<0){
                possible = false;
                break;
            }
        }
        if(possible){
            return j;
        }
    }
    return -1;
}
int gasStationGridy(int gas[],int cost[]){
    //Determine if there is any starting gas station
    diff=[gas[i]-cost[i] for i in range(len(gas))];
    diff_total=sum(diff);

    if(diff_total<0){
        return -1;
    }
    else{
        //run improved simulation
        starting =0; tank=0;
        for i in range(len(gas)){
            tank=tank+gas[i]-cost[i];
            if(tank<0){
                starting = i+1;
                tank=0;
            }
        }
        return starting;
    }
}

int main(){
    int gas[5]={1,2,3,4,5};
    int cost[5]={3,4,5,1,2};

    int out = gasStation(gas,cost);
    cout<<out<<endl;
    return 0;
}