template<int size>
int Partition(int(&arr)[size], int low, int high);

//{ -5, -7, 0, -8, 1, 65, 2, 822, 9, 11, 22, 3, 47 }
//{ -5, -7, 0, -8, 1, 2, 65, 822, 9, 11, 22, 3, 47 }

template<int size>
void QuickSort(int(&arr)[size], int low, int high)
{
  if (low < high) {
    int mid = Partition(arr, low, high);
    QuickSort(arr, low, mid-1);
    QuickSort(arr, mid, high);
  }
}

template<int size>
int Partition(int(&arr)[size], int low, int high)
{
  int l = low-1;
  int h = high+1;
  int mid = arr[(low + high) / 2];

  while (true) {
    do {
      l++;
    } while (arr[l] < mid);

    do {
      h--;
    } while (arr[h] > mid);

    if (l > h)
      return l;

    int temp = arr[l];
    arr[l] = arr[h];
    arr[h] = temp;
  }
}
