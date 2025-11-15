#include <iostream>
#include <climits>
using namespace std;

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " , ";
    }
    cout << endl;
}

void printArray_char(char a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " , ";
    }
    cout << endl;
}




void BubbleSort(int a[], int n) // O(n^2)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool isSwap = false; // optimization for sorted array

        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                isSwap = true;
            }
        }
        if (!isSwap) // array already sorted
        {
            break;
        }
    }
    printArray(a, n);
}



void selectionSort(int a[], int n) // O(n^2)
{
    for (int i = 0; i < n - 1; i++)
    {
        int smallestIdx = i;            // unsorted part starting
        for (int j = i + 1; j < n; j++) // Loop for finding minimum
        {
            if (a[j] < a[smallestIdx])
            {
                smallestIdx = j;
            }
        }
        swap(a[i], a[smallestIdx]);
    }
    printArray(a, n);
}



void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int curr = a[i];
        int prev = i - 1;

        while (prev >= 0 && a[prev] > curr)
        {
            a[prev + 1] = a[prev];
            prev--;
        }
        a[prev + 1] = curr; // placing the curr ele. in current position
    }
    printArray(a, n);
}


void insertionSort_char(char arr[], int size){ //Descending order mein
    for (int i = 1; i < size; i++)
    {
        int curr = arr[i];
        int prev = i-1;

        while(prev >= 0 && arr[prev] < curr){
            swap(arr[prev], arr[prev+1]);
            prev--;
        }

        arr[prev+1] = curr;
    }
     printArray_char(arr, size);
}



void countSort(int a[], int size)
{
    int freq[100000]; // Range
    int minVal = INT_MAX, maxVal = INT_MIN;

    for (int i = 0; i < size; i++) // to find the range
    {
        minVal = min(minVal, a[i]);
        maxVal = max(maxVal, a[i]);
    }

    // 1st step -- O(n)
    for (int i = 0; i < size; i++)
    {
        freq[a[i]]++;
    }

    // 2nd step -- O(range) = max - min
    for (int i = minVal, j = 0; i <= maxVal; i++) // Imp.....
    {
        while (freq[i] > 0)
        {
            a[j++] = i;
            freq[i]--;
        }
    }
    printArray(a, size);
}



int main()
{
    int a[] = {4, 1, 5, 2, 3};
    int b[] = {5, 3, 1, 6, 7, 8};
    int c[] = {1,2,3,1,5,5,7,1,3};
    char arr[] = {'b', 'n', 'a', 'v', 'r'};

    int size_a = sizeof(a) / sizeof(int);
    int size_b = sizeof(b) / sizeof(int);
    int size_c = sizeof(c) / sizeof(int);
    int size_char = sizeof(arr) / sizeof(char);

    BubbleSort(b, size_b);
    countSort(c, size_c);
    insertionSort_char(arr,size_char);

    return 0;
}