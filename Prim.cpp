#include <bits/stdc++.h>
using namespace std;
int findmin(int visited[],int distance[],int v){
    int minidx=-1;
    for(int i=0;i<v;i++){
        if(!visited[i]&&(minidx==-1||distance[i]<distance[minidx])){
            minidx=i;
        }
    }
    return minidx;
}

int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;

  /*
       Write Your Code Here
	   Complete the Rest of the Program
	   You have to Print the output yourself
  */
    int**edge=new int*[V];
    for(int i=0;i<V;i++){
        edge[i]=new int[V];
        for(int j=0;j<V;j++){
            edge[i][j]=0;
        }
    }
    for(int i=0;i<E;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edge[a][b]=c;
        edge[b][a]=c;
    }
    int visited[V];
    int distance[V];
    for(int i=0;i<V;i++){
        visited[i]=0;
        distance[i]=INT_MAX;
    }
    distance[0]=0;
    for(int i=0;i<V;i++){
        int minvertex=findmin(visited,distance,V);
        visited[minvertex]=1;
        for(int j=0;j<V;j++){
            if(!visited[j]&&edge[minvertex][j]!=0){
                if(distance[j]>distance[minvertex]+edge[minvertex][j]){
                    distance[j]=distance[minvertex]+edge[minvertex][j];
                }
            }
        }
    }
    for(int i=0;i<V;i++){
        cout<<i<<" "<<distance[i]<<"\n";
    }

  return 0;
}
