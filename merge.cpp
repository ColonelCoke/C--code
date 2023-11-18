#include <iostream>
#include <array>
#include <vector>
#include <cmath>
using namespace std;
void Merge(vector<int>& intArr, int p, int q, int r) {
    int nL = q - p + 1;
    int nR = r - q;
    vector<int> lArr(nL); // Create left and right arrays with the correct size
    vector<int> rArr(nR);

    for (int i = 0; i < nL; i++) { // Use proper loop boundaries
        lArr[i] = intArr[p + i];
    }
    for (int j = 0; j < nR; j++) { // Use proper loop boundaries
        rArr[j] = intArr[q + j + 1]; // Adjust the starting index for the right array
    }

    int i = 0;
    int j = 0;
    int k = p;

    while (i < nL && j < nR) {
        if (lArr[i] <= rArr[j]) {
            intArr[k] = lArr[i];
            i++;
        } else {
            intArr[k] = rArr[j]; // Fixed the condition here
            j++;
        }
        k++;
    }

    while (i < nL) {
        intArr[k] = lArr[i];
        i++;
        k++;
    }
    while (j < nR) {
        intArr[k] = rArr[j];
        j++;
        k++;
    }
}

void MergeSort(vector<int>& intArr, int p, int r)
{  
    if(p >= r)
    {
        return;
    }
    int q = floor((p+r)/2);
    MergeSort(intArr, p, q);
    MergeSort(intArr, q+1, r);
    Merge(intArr, p, q, r);
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
    MergeSort(arr, p, r);
    cout << endl;
    for(int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}