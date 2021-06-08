#include <stdio.h>

int size,temp;

int partition(int arr[],int low,int high) {
    int ind = low-1;
    int pivot = arr[high];
    for (int i = low; i < high; ++i)
    {
        if(arr[i]<pivot) {
            ind++;
            temp = arr[ind];
            arr[ind] = arr[i];
            arr[i] = temp;
        }
    }
    ind++;
    arr[high] = arr[ind];
    arr[ind] = pivot;
    return ind;
}

void quicksort(int arr[],int low,int high) {
    if(low < high) {    
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi-1);
        quicksort(arr, pi+1, high);
    }
}

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    printf("enter size\n");
    scanf("%d",&size);
    printf("enter elements\n");
    int arr[size];
    for (int i = 0; i < size; ++i)
    {
        scanf("%d", arr+i);
    }
    quicksort(arr, 0, size-1);
    printf("sorted array:\n");
    for (int i = 0; i < size; ++i)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}