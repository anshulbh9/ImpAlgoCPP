int solve(int n,int m,vector<int>u,vector<int>v)
{
	// Write your code here .
    int**edges=new int*[101];
    for(int i=0;i<101;i++){
        edges[i]=new int[101];
        for(int j=0;j<101;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<m;i++){
        edges[u[i]][v[i]]=1;
        edges[v[i]][u[i]]=1;
    }
    int count=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(edges[i][j]==1){
            for(int k=j+1;k<=n;k++){
                if(edges[i][k]==1&&edges[j][k]==1){
                    count++;
                }
            }
            }
        }
    }
    return count;
}
