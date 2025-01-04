
#include<iostream>
using namespace std;
int firstocc(int arr[],int n,int key){
int start = 0,end=n-1,ans=-1;
int mid=start +(end-start)/2;
while(start<=end){
    if(arr[mid]==key){
     ans=mid;
    end=mid-1;
    }
    else if(arr[mid]>key){
        end=mid-1;
    }
    else
    start=mid+1;

    mid=start +(end-start)/2;
}
return ans;
}

int lastocc(int arr[],int n,int key){
int start = 0,end=n-1,ans=-1;
int mid=start +(end-start)/2;
while(start<=end){
    if(arr[mid]==key){
     ans=mid;
    start=mid+1;
    }
    else if(arr[mid]>key){
        end=mid-1;
    }
    else
    start=mid+1;

    mid=start +(end-start)/2;
}
return ans;
}

int main(){
    int arr[5]={1,2,3,3,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int key=3;
    cout<<firstocc(arr,n,key);
    cout<<"\n";
    cout<<lastocc(arr,n,key);
}