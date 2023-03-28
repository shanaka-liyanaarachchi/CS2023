#include <iostream>
#include <stack>
#include <vector>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;



// recursive quicksort
void recursive_quicksort(int arr[], int l, int h) {
    // pi = pivot index
    // l =lower index
    // h = higher index
    if (l < h) {
        int pivot = arr[h]; // rightmost element considered as the pivot
        int i = l - 1;

        for (int j = l; j <= h - 1; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i+1], arr[h]);

        int pi = i + 1;
        recursive_quicksort(arr, l, pi - 1);
        recursive_quicksort(arr, pi + 1, h);
    }
}

// non-recursive quicksort using a stack
void non_recursive_quicksort(int arr[], int n) {
    stack<pair<int, int>> stack;
    int l = 0;
    int h = n - 1;
    stack.push(make_pair(l, h));

    while (!stack.empty()) {
        pair<int, int> p = stack.top();
        stack.pop();
        l = p.first;
        h = p.second;

        // partition the array
        int pivot = arr[h]; // pivot element
        int i = l - 1; // index of smaller element

        for (int j = l; j <= h - 1; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i+1], arr[h]);

        int pi = i + 1; // index of pivot

        // push subarrays to stack
        if (pi - 1 > l) {
            stack.push(make_pair(l, pi - 1));
        }
        if (pi + 1 < h) {
            stack.push(make_pair(pi + 1, h));
        }
    }
}


int main() {
    srand(time(NULL)); // initialize random seed

    for (int i = 1; i < 8; i++) {
        int n = i*50000;
        int* arr_1= new int[n]; // create two identical arrays
        int* arr_2= new int[n];

        // add values to the arrays
        for (int j = 0; j < n; j++) {
            int num = rand() % 501; // random number in range [0, 10000]
            arr_1[j]=num;
            arr_2[j]=num;
        }

        // measure time taken to sort array using recursive merge sort
        auto start_time_rec = high_resolution_clock::now();
        recursive_quicksort(arr_1,0,n-1);
        auto end_time_rec = high_resolution_clock::now();
        auto duration_rec = duration_cast<milliseconds>(end_time_rec - start_time_rec);

        // measure time taken to sort array using non recursive merge sort
        auto start_time_non_rec= high_resolution_clock::now();
        non_recursive_quicksort(arr_2,n);
        auto end_time_non_rec = high_resolution_clock::now();
        auto duration_non_rec = duration_cast<milliseconds>(end_time_non_rec - start_time_non_rec);



        // print array length and time taken for each algorithm
        cout << "_________________________________________________________________________________________"<< endl;
        cout <<" Total elements in the array " << n <<endl;
        cout <<  " time taken using non recursive quick sort  " << duration_non_rec.count() << " milliseconds" << endl;
        cout << " time taken using recursive quick sort  " << duration_rec.count() << " milliseconds" << endl;
    }}
