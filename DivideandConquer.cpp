#include <iostream>
#include <climits>
using namespace std;

struct MinMax {
    int min;
    int max;
};

MinMax findMinMax(int arr[], int low, int high) {
    MinMax result, left, right;
    int mid;

    // If the array has only one element
    if (low == high) {
        result.min = arr[low];
        result.max = arr[low];
        return result;
    }

    // If the array has two elements
    if (high == low + 1) {
        result.min = std::min(arr[low], arr[high]);
        result.max = std::max(arr[low], arr[high]);
        return result;
    }

    // If there are more than two elements, divide the array and recursively find min and max
    mid = (low + high) / 2;
    left = findMinMax(arr, low, mid);
    right = findMinMax(arr, mid + 1, high);

    // Compare min and max values from left and right subarrays
    result.min = std::min(left.min, right.min);
    result.max = std::max(left.max, right.max);

    return result;
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr) / sizeof(arr[0]);

    MinMax result = findMinMax(arr, 0, size - 1);

    std::cout << "Minimum element: " << result.min << std::endl;
    std::cout << "Maximum element: " << result.max << std::endl;

    return 0;
    //CONTRIBUTED BY SHAFAAT
}
