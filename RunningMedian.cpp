#include<bits/stdc++.h>
using namespace std;
void findMedian(int arr[], int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output as specified in the question.
     */
    double median=0;
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
    for(int i=0;i<n;i++){
        if(arr[i]>median){
            minheap.push(arr[i]);
        }
        else{
            maxheap.push(arr[i]);
        }
        if(maxheap.size()>minheap.size()+1){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if(minheap.size()>maxheap.size()+1){
            maxheap.push(minheap.top());
            minheap.pop();
        }
        if(minheap.size()==maxheap.size()){
            median=(minheap.top()+maxheap.top())/2;
        }
        else if(maxheap.size()>minheap.size()){
            median=maxheap.top();
        }
        else{
            median=minheap.top();
        }
        cout<<median<<endl;
    }
}
