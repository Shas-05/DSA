/*#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    vector<int> arr = {1, 3, 5, 7, 9};
    if (binary_search(arr.begin(), arr.end(), 5)) {
        cout << "5 is present\n";
    } else {
        cout << "5 is not present\n";
    }
    return 0;
}*/


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 3, 5, 7, 9};

    auto lb = lower_bound(arr.begin(), arr.end(), 5);
    auto ub = upper_bound(arr.begin(), arr.end(), 5);

    cout << "Lower bound of 5: " << (lb - arr.begin()) << "\n";  // Output: 2
    cout << "Upper bound of 5: " << (ub - arr.begin()) << "\n";  // Output: 3

    return 0;
}