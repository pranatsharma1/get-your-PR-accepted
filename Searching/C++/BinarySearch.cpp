//Binary Search C++ Implementation
#include <iostream>
using namespace std;
//Binary Search function
//TC = O(logn)
int binary_search(int a[], int n, int key)
{
    int s = 0, e = n - 1; //start and end variables

    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (a[mid] == key)
        {
            return mid;
        }
        else if (a[mid] < key)
        {
            s = mid + 1;
        }
        else if (a[mid] > key)
        {
            e = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cout << "Enter no of elements in array: ";
    cin >> n;

    int a[n]; //Input array
    for (int i = 0; i < n; i++)
    {
        cin >> a[i]; //taking input
    }

    int key; //element to be searched
    cout << "Enter key :";
    cin >> key;

    cout << binary_search(a, n, key) << endl;

    return 0;
}
