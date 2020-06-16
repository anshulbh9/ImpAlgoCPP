#include<bits/stdc++.h>
using namespace std;
void buildheap(int input[],int n){
    for(int i=0;i<n;i++){
        int parent=(i-1)/2;
        int child=i;
        while(parent>=0){
            if(input[parent]>input[child]){
                swap(input[parent],input[child]);
            child=parent;
            parent=(child-1)/2;

            }
            else{
                break;
            }
        }
    }
}
void inplaceHeapSort(int input[], int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Change in the given input itself.
     * Taking input and printing output is handled automatically.
     */
    buildheap(input,n);
    int ptr=n-1;
    while(ptr!=0){
        swap(input[0],input[ptr]);
        int largest=0,curr=0;
        while(largest<ptr){
            int l=2*largest+1;
            int r=2*largest+2;
            if(l<ptr&&input[l]<input[largest]){
                largest=l;
            }
            if(r<ptr&&input[r]<input[largest]){
                largest=r;
            }
            if(curr==largest){
                break;
            }
            swap(input[largest],input[curr]);
            curr=largest;
        }
           ptr--;
    }
    
}
