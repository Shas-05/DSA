//Same code for Painter's Partition problem
#include<iostream>
#include<vector>
using namespace std;
//for partition of pages among 'm' students
bool isPossiblesol(vector<int>& arr, int n, int m , int mid){
    int studentCount=1;
    int pageSum=0;
    for(int i=0;i<n;i++){
        if(pageSum+arr[i]<=mid)
        pageSum+=arr[i];

        else{
            studentCount++;
            if(studentCount > m || arr[i]>mid){//agar arr[i] jo last hoga wo >mid then also 'false'
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}
//to find minimum pages
int findPages(vector<int>& arr, int n, int m) {
   int s=0;
   int sum=0;
   for(int i=0;i<n;i++){
       sum += arr[i];
   }
   int e=sum ;
   int ans=-1;
   if(m>n)//edge case
   return -1;
   while(s<=e){
       int mid=s+(e-s)/2;
       if(isPossiblesol(arr,n,m,mid)){
           ans = mid;
           e = mid-1;
       }
       else{
           s=mid+1;
       }
   }
   return ans;
}

int main(){
    vector<int> arr = {25, 46, 28 ,49 ,24};
    int n = 5;
    cout<<"Enter number of students: ";
    int m;
    cin>>m;
    int pages = findPages(arr , n,m);
    cout<<"Minimum number of pages =  "<<pages;
}