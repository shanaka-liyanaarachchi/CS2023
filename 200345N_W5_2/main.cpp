#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

void printMedian(double median, vector<int> sortedArr) {
    cout<<" [ ";
    for (int i = 0; i < sortedArr.size(); i++) {
        cout << sortedArr[i] << ", ";
    }
    cout<<"] ";
    cout << fixed << setprecision(1) << median << endl;
}

void runningMedian(vector<int> &arr) {
    vector<int> sortedArr; // stores the sorted array of integers

    for (int i = 0; i < arr.size(); i++) {
        int x = arr[i];

        // insert element into sortedArr
        sortedArr.insert(lower_bound(sortedArr.begin(), sortedArr.end(), x), x);

        // calculate and print median
        int n = sortedArr.size();
        if (n % 2 == 0) { // for even length
            double median = ((double) sortedArr[n/2] + (double) sortedArr[n/2 - 1]) / 2.0;
            printMedian(median, sortedArr);
        }
        else { // for odd length
            printMedian(sortedArr[n/2], sortedArr);
        }
    }
}

int main() {
    vector<int> arr = {7,3,5,2};

    runningMedian(arr);

    return 0;
}
