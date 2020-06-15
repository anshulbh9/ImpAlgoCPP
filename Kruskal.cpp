#include <bits/stdc++.h>
using namespace std;
class edge{
    public:
    int v;
    int e;
    int w;
};
bool com(edge e1,edge e2){
    if(e1.w==e2.w){
        if(e1.v==e2.v){
            return e1.e<e2.e;
        }
        return e1.v<e2.v;
    }
    return e1.w<e2.w;
}
void print(edge*arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i].v<<" "<<arr[i].e<<" "<<arr[i].w<<endl;
    }
}

int findparent(int parent[],int i){
    if(parent[i]!=i){
        parent[i]=findparent(parent,parent[i]);
    }
    return parent[i];
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
    edge*arr=new edge[E];
    for(int i=0;i<E;i++){
        int v,e,w;
        cin>>v>>e>>w;
        arr[i].v=v;
        arr[i].e=e;
        arr[i].w=w;
    }
    sort(arr,arr+E,com);
   edge*output=new edge[V-1];
    int parent[V];
    for(int i=0;i<V;i++){
        parent[i]=i;
    }
    int count=0,i=0;
    while(count<V-1){
        int x=findparent(parent,arr[i].v);
        int y=findparent(parent,arr[i].e);
        if(x==y){
            i++;
        }
        else{
            output[count].v=min(arr[i].e,arr[i].v);
            output[count].e=max(arr[i].e,arr[i].v);
            output[count].w=arr[i].w;
            parent[x]=y;
            count++;
            i++;
        }
    }
    print(output,V-1);

  return 0;
}
