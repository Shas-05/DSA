#include<iostream>
using namespace std;

int krotations(int arr[],int n){
int s = 0, e = 5;
    int mid;

    while (s < e) {
        mid = s + (e - s) / 2;
        if (arr[mid] > arr[e]) {
            s = mid + 1;
        }
        else if (arr[mid] < arr[e]) {
            e = mid;
        }
        else {
            e--;
        }
    }
    return s;
}

int main(){
    int arr[5]={6,9,1,2,3};
    int numberofRotations=krotations(arr,5);
    cout<<"Number of times array has been rotated is: "<<numberofRotations;
}