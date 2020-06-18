#include <bits/stdc++.h>
using namespace std;

int main()
{
    long m,n;
    cin>>m>>n;
    long arr[m][n];
    for(long i=0;i<m;i++){
        for(long j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    long best=INT_MIN;
 for(long idx2=0;idx2<n;idx2++){
     for(long idx=idx2;idx<n;idx++){
    
    long row[m]={0};
    for(long i=idx2;i<=idx;i++){
        for(long j=0;j<m;j++){
            row[j]+=arr[j][i];
        }
    }
         
    long max1=INT_MIN;
         for(int i=0;i<m;i++){
             if(row[i]>max1){
                 max1=row[i];
             }
         }
         if(max1<0){
             best=max(best,max1);
             continue;
         }
         else{
             max1=0;
         }
    for(long i=0;i<m;i++){
        max1=max1+row[i];
        if(max1<0){
            max1=0;
        }
        best=max(max1,best);
    }
     }
 }
    cout<<best<<endl;
    return 0;
}
