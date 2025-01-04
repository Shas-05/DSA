#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//min(max) ----> type problem
bool isPossible(vector<int> &stalls, int k, int mid) {
  int cowCount = 1;
  int lastPos = stalls[0];

  for (int i = 0; i < stalls.size(); i++) {
    if (stalls[i] - lastPos >= mid) {
      cowCount++;
      if (cowCount == k) {
        return true;
      }
      lastPos = stalls[i];
    }
  }
  return false;
}
int aggressiveCows(vector<int> &stalls, int k) {
  sort(stalls.begin(), stalls.end());
  int s = 0;
  int maxi = *max_element(stalls.begin(), stalls.end());
  int e = maxi;
  int ans = -1;
  while (s <= e) {
    int mid = s + (e - s) / 2;
    if (isPossible(stalls, k, mid)) {
      ans = mid;
      s = mid + 1;
    } else
      e = mid - 1;
  }
  return ans;
}

int main(){
vector<int> stalls = {4, 2, 1, 3, 6};
int k=2; //k=no. of cows
int minDis = aggressiveCows(stalls,k);
cout<<"Maximum of minimum distances between cows is :  "<<minDis;
}