#include <stdio.h>

int size;

void merge(int arr[], int l, int m, int r) {
    int b[size];
    int ai=l, bi=m+1, i=0;
    for (i = 0; ai<=m && bi<=r; ++i)
    {
        if(arr[ai]<arr[bi]) {
            b[i]=arr[ai];
            ai++;
        } else {
            b[i]=arr[bi];
            bi++;
        }
    }
    while(ai<=m) {
        b[i]=arr[ai];
        ai++;
        i++;
    }
    while(bi<=r) {
        b[i]=arr[bi];
        bi++;
        i++;
    }
    i=0;
    for (int ind = l; ind <= r; ++ind, i++)
    {
        arr[ind] = b[i];
    }
}

void mergesort(int arr[], int l, int r) {
    if(l>=r) return;
    int m=(l+r)/2;
    mergesort(arr, l, m);
    mergesort(arr, m+1, r);
    merge(arr, l, m, r);
}

int main(int argc, char const *argv[])
{
    freopen("/Users/namansrivastava/Documents/projects/datastr/input.txt", "r", stdin); 
    freopen("/Users/namansrivastava/Documents/projects/datastr/output.txt", "w", stdout); 
    printf("enter size\n");
    scanf("%d",&size);
    printf("enter elements\n");
    int arr[size];
    for (int i = 0; i < size; ++i)
    {
        scanf("%d", arr+i);
    }
    mergesort(arr, 0, size-1);
    printf("sorted array:\n");
    for (int i = 0; i < size; ++i)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}