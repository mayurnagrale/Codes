int rec(vector<int> value,vector<int>wt,int maxwt,int n){
//     //base condition
//     if(n==0 || maxwt==0){
//         return 0;
//     }
//     if(wt[n-1]<=maxwt){
//         return value[n-1]+rec(value,wt,maxwt-wt[n-1],n-1);
//     }
//     if(wt[n-1]>maxwt){
//         return rec(value,wt,maxwt,n-1);
//     }
// }