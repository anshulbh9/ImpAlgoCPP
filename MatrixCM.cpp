#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int mcm1(int*p,int s,int e,int m[][100]){
    if(s==e-1){
        return 0;
    }
    if(m[s][e]!=-1){
        return m[s][e];
    }
    int ans=INT_MAX;
    for(int i=s+1;i<=e-1;i++){
        ans=min(ans,mcm1(p,s,i,m)+mcm1(p,i,e,m)+p[s]*p[i]*p[e])%mod;
    }
    m[s][e]=ans%mod;
    return m[s][e];
}
int mcm(int* p, int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
  */ 
    int m[100][100];
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            m[i][j]=-1;
        }
    }
    int ans=mcm1(p,0,n,m);
    return ans;
}
