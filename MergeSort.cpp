#include <iostream>

void Merge(int arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    // creating two subarrays dynamically in the heap as the sizes are not constant
    int *subarray1 = new int[n1];
    int *subarray2 = new int[n2];
    //assigning the values to the subarrays
    for (int i = 0; i < n1; i++)
    {
        subarray1[i] = arr[low + i];
    }
    for (int j = 0; j < n2; j++)
    {
        subarray2[j] = arr[mid + j + 1];
    }
    //intializing pointers to compare and sort
    int i = 0;
    int j = 0;
    int k = low;
    //comparing each element in both the subarrays and sorting simultaneously
    while (i < n1 && j < n2)
    {
        if (subarray1[i] < subarray2[j])
        {
            arr[k] = subarray1[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = subarray2[j];
            k++;
            j++;
        }
    }
    //checking if any element is left in the subarray1
    while (i < n1)
    {
        arr[k++] = subarray1[i++];
    }
    //checking if any element is left in the subarray2
    while (j < n2)
    {
        arr[k++] = subarray2[j++];
    }
    //freeing up the space by deleting the arrays created in heap
    delete[] subarray1;
    delete[] subarray2;
}
void MergeSort(int arr[], int low, int high)
{
    //checking if the array has more than one elment
    if (low < high)
    {
        int mid = (low + high) / 2;
        MergeSort(arr, low, mid);             //leftsubarray
        MergeSort(arr, mid + 1, high);        //rightsubarray

        Merge(arr, low, mid, high);            //merges and sorts the subarrays
    }
}
int main()
{
    int arr[] = {76, 23, 45, 1, 2, 88, 3, 34};
    int size = sizeof(arr) / sizeof(arr[0]);
    MergeSort(arr, 0, size - 1);
    std::cout << "The Sorted array is -> ";

    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    return 0;   //CONTRIBUTED BY SHAFAAT
}
