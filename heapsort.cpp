#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
void MaxHeapify(vector<int>& a, int i, int heapSize) 
{
    int l = 2*i + 1;
    int r = 2*i + 2;
    int largest = i;
    int temp;
    if (l < heapSize && a[l] > a[largest]) 
    {
        largest = l;
    }
    
    if (r < heapSize && a[r] > a[largest]) 
    {
        largest = r;
    }
    
    if (largest != i) 
    {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        MaxHeapify(a, largest, heapSize);
    }
}

void BuildMaxHeap(vector<int>& a) 
{
    int heapSize = a.size();
    for (int i = floor(heapSize / 2) - 1; i >= 0; i--) 
    {
        MaxHeapify(a, i, heapSize);
    }
}

void HeapSort(vector<int>& a) 
{
    BuildMaxHeap(a);
    int heapSize = a.size();
    for (int i = a.size() - 1; i > 0; i--) 
    {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapSize--;
        MaxHeapify(a, 0, heapSize);
    }
}

int main()
{
    vector<int> arr = {12, 3, 7, 9, 14, 6, 11, 2};

    for(int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    int p = 0; 
    int r = arr.size();
    cout << endl;
    HeapSort(arr);
    for(int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}