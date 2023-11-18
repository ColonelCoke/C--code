#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int Partition(vector<int>& a, int p, int r) {
    int x = a[r];
    int i = p - 1;
    int temp;
    for (int j = p; j <= r - 1; j++) {
        if (a[j] <= x) {
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[i + 1];
    a[i + 1] = a[r];
    a[r] = temp;
    return i + 1;
}

void QuickSort(vector<int>& a, int p, int r) {
    int q;
    if (p < r) {
        q = Partition(a, p, r);
        QuickSort(a, p, q - 1);
        QuickSort(a, q + 1, r);
    }
}

int main()
{
    vector<int> arr = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    for(int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    int p = 0; 
    int r = arr.size() - 1;
    QuickSort(arr, p, r);
    cout << endl;
    for(int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}