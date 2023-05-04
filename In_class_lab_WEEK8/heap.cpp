#include <iostream>
#include <vector>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
  int l = (root * 2) + 1;
  int r = (root * 2) + 2;
  int largest;
  if (l < n && arr[l] > arr[root])
    largest = l;
  else
    largest = root;
  if (r < n && arr[r] > arr[largest])
    largest = r;
  if (largest != root)
  {
    int temp = arr[root];
    arr[root] = arr[largest];
    arr[largest] = temp;
    heapify(arr, n, largest);
  }
}

// implementing heap sort
void heapSort(int arr[], int n)
{
  int heapsize = n;
  for (int i = (heapsize - 1) / 2; i >= 0; i--)
    heapify(arr, n, i);
  for (int i = heapsize - 1; i > 0; i--)
  {
    int temp = arr[i];
    arr[i] = arr[0];
    arr[0] = temp;
    heapify(arr, i, 0);
  }
}

// print contents of array
void displayArray(int arr[], int n)
{
  for (int i = 0; i < n; ++i)
    cout << arr[i] << " ";
  cout << "\n";
}

// main program
int main()
{
  // Predefined array.
  int heap_arr[] = {4, 17, 3, 12, 9, 6};
  int n = sizeof(heap_arr) / sizeof(heap_arr[0]);
  cout << "Input array" << endl;
  displayArray(heap_arr, n);
  heapSort(heap_arr, n);
  cout << "Sorted array" << endl;
  displayArray(heap_arr, n);

  // User input.
  vector<int> list;
  int a;
  cout << endl
       << "Enter numbers one by one. (Enter -1 to terminate)" << endl;
  for (;;)
  {
    cin >> a;
    if (a == -1)
      break;
    list.push_back(a);
  }
  int m = list.size();
  int arr[m];
  for (int i = 0; i < m; i++)
    arr[i] = list[i];
  cout << "Input array" << endl;
  displayArray(arr, m);
  heapSort(arr, m);
  cout << "Sorted array" << endl;
  displayArray(arr, m);
}
