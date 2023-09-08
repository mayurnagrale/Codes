#include<bits/stdc++.h>
using namespace std;

vector<int> answers;

/*Each Pair Corrosponds to : (location,ServerId)*/
map<int,string> locationToServerMapping;

/*Each Pair Corrosponds to : (ServerId,<usernames>)*/
unordered_map<string,vector<string>> serverToKeyMappings;

int userHash(string username, int hashKey) {
    const int p = hashKey;
    const int n = 360;
    int hashCode = 0;
    long long p_pow = 1;
    for (int i = 0; i < username.length(); i++) {
        char character = username[i];
        hashCode = (hashCode + (character - 'A' + 1) * p_pow) % n;
        p_pow = (p_pow * p) % n;
    }
    return hashCode;
}

int assignRequest(string keyName,int hashKey){
    if (locationToServerMapping.size() == 0) {
        return -1;
    }
    int keyLocation = userHash(keyName, hashKey);
    auto it = locationToServerMapping.lower_bound(keyLocation);
    /* when no server to right on the ring, assign the first server from start of the ring */
    if (it == locationToServerMapping.end()) {
        it = locationToServerMapping.lower_bound(0);
    }
    string serverID = it -> second;
    serverToKeyMappings[serverID].push_back(keyName);
    return keyLocation;
}

void findRequestToServer(int serverLocation,int hashKey){
    if (serverToKeyMappings.size() == 0) {
        /* No requests to serve */
        return;
    }
    /* we need to find the requests which can now possibly be redirected to the added server */
    /* doing +1 because otherwise we'll get the location of the newly added server */
    auto it = locationToServerMapping.lower_bound(serverLocation + 1);
    if (it == locationToServerMapping.end()) {
        it = locationToServerMapping.lower_bound(0);
    }
    string serverID = it -> second;
    /* these are the usernames which can possibly be redirected */
    vector < string > keynames = serverToKeyMappings[serverID];
    serverToKeyMappings[serverID].clear();
    for (auto it = keynames.begin(); it != keynames.end(); it++) {
        /* may or may not get reassigned */
        assignRequest( * it, hashKey);
    }
}

int addServer(string serverId,int hashKey){
    int firstLocation = userHash(serverId, hashKey);
    locationToServerMapping[firstLocation] = serverId;
    findRequestToServer(firstLocation, hashKey);
    return serverToKeyMappings[serverId].size();
}

int removeServer(string serverId,int hashKey){
    for (auto it = locationToServerMapping.begin(); it != locationToServerMapping.end(); it++) {
        if (it -> second == serverId) {
            locationToServerMapping.erase(it -> first);
            break;
        }
    }
    vector < string > keynamesToReassign = serverToKeyMappings[serverId];
    serverToKeyMappings.erase(serverId);
    for (auto it = keynamesToReassign.begin(); it != keynamesToReassign.end(); it++) {
        assignRequest(( * it), hashKey);
    }
    return keynamesToReassign.size();
}

void performOperations(string A,string B,int C){
    string operation=A;
    if(operation=="ADD"){
        string serverId=B;
        answers.push_back(addServer(serverId,C));
    }
    else if(operation=="REMOVE"){
        string serverId=B;
        answers.push_back(removeServer(serverId,C));
    }
    else if(operation=="ASSIGN"){
        string keyName=B;
        answers.push_back(assignRequest(keyName,C));
    }
}

int main(){
    vector<string> A={"ADD", "ASSIGN", "ADD", "ASSIGN", "REMOVE", "ASSIGN"};
    vector<string> B={"INDIA", "NWFJ", "RUSSIA", "OYVL", "INDIA", "IGAX"};
    vector<int> C={7, 3, 5, 13, 23, 17};

    serverToKeyMappings.clear();
    locationToServerMapping.clear();
    answers.clear();

    for(int i=0;i<A.size();i++){
        performOperations(A[i],B[i],C[i]);
    }

    for(int i=0;i<answers.size();i++){
        cout<<answers[i]<<" ";
    }

    return 0;
}