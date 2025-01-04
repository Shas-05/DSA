#include <iostream>
#include <vector>
#include<cmath>
#include<climits>
using namespace std;

int findMax(vector<int> &v)
{
    int maxi = INT_MIN;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

int calculateTotalHours(vector<int> &v, int hourly)
{
    int totalhours = 0;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        totalhours += ceil((double)v[i] / (double)hourly);
    }
    return totalhours;
}

int minRate(vector<int> &v, int h)
{
    int s = 1, e = findMax(v);
    while (s <= e)
    {
        int mid = (s + e) / 2;
        int totalh = calculateTotalHours(v, mid);
        if (totalh <= h)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return s;
}

int main()
{
    vector<int> v = {3, 6, 7, 11};
    int h = 8;
    int k = minRate(v, h);
    cout << "Minimum rate which Koko takes to eat all bananas is : " << k;
}