// topic :- bubble sort
// author :- Rudreswar Pal
#include <iostream>
using namespace std;
void swap(int arr[], int j, int i);
void bubblesort(int arr[], int n);
void selectionsort(int arr[], int n);
void insertionsort(int arr[], int n);
void countingsort(int arr[], int n);
void countingsort(int arr[], int n, int pow10);
void radixsort(int arr[], int n);
void mergesort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);
int getmax(int arr[], int n);
void quicksort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void makeheap(int arr[], int i, int n);
/*2nd one*/void makeheap2(int arr[], int i, int n);
void heapsort(int arr[], int n);
void adjustheap(int arr[], int i, int n);

int main(void)
{
    int n = 18;
    int arr[n] = {5, 2, 1, 4, 2, 3, 8, 7, 6, 4, 5, 2, 1, 3, 4, 8, 0, 1};
    quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cin >> n;
    return 0;
}
void swap(int arr[], int j, int i)
{
    int temp = arr[j];
    arr[j] = arr[i];
    arr[i] = temp;
}
void bubblesort(int arr[], int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        for (int j = 0; j <= n - 2 - i; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr, j, j + 1);
        }
    }
}
void modified_bubblesort(int arr[], int n)
{
    bool flag = 0;
    for (int i = 0; i <= n - 2; i++)
    {
        for (int j = 0; j <= n - 2 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr, j, j + 1);
                flag = 1;
            }
        }
        if (flag = 0)
            break;
    }
}
void selectionsort(int arr[], int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        int min_index = i;
        for (int j = i + 1; j <= n - 1; j++)
        {
            if (arr[min_index] > arr[j])
                min_index = j;
        }
        if (i != min_index)
            swap(arr, i, min_index);
    }
}
void insertionsort(int arr[], int n)
{
    for (int i = 1; i <= n - 1; i++)
    {
        int x = i - 1;
        int temp = arr[i];
        while (x >= 0 && arr[x] > temp)
        {
            arr[x + 1] = arr[x];
            x--;
        }
        arr[x + 1] = temp;
    }
}
void countingsort(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    int aux_arr[max + 1];
    for (int i = 0; i <= max; i++)
        aux_arr[i] = 0;
    for (int i = 0; i < n; i++)
    {
        aux_arr[arr[i]]++;
    }
    for (int i = 1; i <= max; i++)
    {
        aux_arr[i] = aux_arr[i] + aux_arr[i - 1];
    }
    int final[n];
    for (int i = n - 1; i >= 0; i--)
    {
        int x = aux_arr[arr[i]] - 1; // final[--aux_arr[arr[i]]]=arr[i]
        aux_arr[arr[i]]--;
        final[x] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = final[i];
    }
}
void radixsort(int arr[], int n)
{
    int max = getmax(arr, n);
    int pow10 = 1;
    while (max != 0)
    {
        countingsort(arr, n, pow10);
        pow10 *= 10;
        max /= 10;
    }
}
int getmax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    return max;
}
void countingsort(int arr[], int n, int pow10)
{
    int count[10] = {0};
    int output[n];
    for (int i = 0; i < n; i++)
    {
        int digit = (arr[i] / pow10) % 10;
        count[digit]++;
    }
    for (int i = 1; i <= 9; i++)
    {
        count[i] = count[i] + count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / pow10) % 10;
        int index = count[digit] - 1;
        count[digit]--;
        output[index] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}
void mergesort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
void merge(int arr[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low, c[100];
    while (i <= mid && j <= high)
    {
        if (arr[i] > arr[j])
        {
            c[k] = arr[j];
            j++;
        }
        else
        {
            c[k] = arr[i];
            i++;
        }
        k++;
    }
    while (i <= mid)
    {
        c[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        c[k] = arr[j];
        j++;
        k++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = c[i];
    }
}
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}
int partition(int arr[], int low, int high)
{
    int i = low - 1, pivot = arr[high];
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return i + 1;
}
void heapsort(int arr[], int n)
{
    int temparr[n+1];
    for (int i = 1; i <= n; i++)
        temparr[i] = arr[i - 1];
    makeheap(temparr, n);
    for (int i = n; i >= 2; i--)
    {
        swap(temparr,i,1);
        adjustheap(temparr, 1, i - 1);
    }
    /* storing the value to arfinal array */
    for (int i = 0; i <= n - 1; i++)
        arr[i] = temparr[i + 1];
}
void makeheap(int arr[], int n)
{
    for (int i = n / 2; i >= 1; i--)
        adjustheap(arr, i, n);
}
void adjustheap(int arr[], int i, int n)
{
    int j = 2 * i;
    int key = arr[i];
    while (j <= n)
    {
        if (j < n && arr[j] < arr[j + 1])
            j = j + 1;
        if (key > arr[j])
            break;
        arr[j / 2] = arr[j];
        j = j * 2;
    }
    arr[j / 2] = key;
}
void heapsort2(int arr[], int n)
{
    for (int i = n / 2; i >= 0; i--)
        makeheap2(arr, i, n);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr, i, 1);
        makeheap2(arr, 0, i);
    }
}
void makeheap2(int arr[], int i, int n)
{
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if(left<n && arr[largest]<arr[left])
        largest=left;
    if(right<n && arr[largest]<arr[right])
        largest=right;
    if(largest!=i)
    {
        swap(arr,i,largest);
        makeheap2(arr,largest,n);
    }
}
