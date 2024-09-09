//5.merger sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 500000
int a[MAX];
void merge(int low, int mid, int high) {
    int temp[MAX];
    int i = low, j = mid + 1, k = 0;
    while (i <= mid && j <= high) {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while (i <= mid)
        temp[k++] = a[i++];
    while (j <= high)
        temp[k++] = a[j++];
    for (i = low, k = 0; i <= high;)
        a[i++] = temp[k++];
}
void merge_sort(int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        merge(low, mid, high);
    }
}
int main() {
    int n;
    double clk;
    clock_t starttime, endtime;

    printf("MERGE SORT \n");
    printf("Enter the number of employee records: \n");
    scanf("%d", &n);

    printf("The Employee IDs are: \n");
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
        printf("\t%d", a[i]);
    }
    printf("\n");
    starttime = clock();
    merge_sort(0, n - 1);
    endtime = clock();
    printf("\nEmployee IDs in sorted order: \n");
    for (int i = 0; i < n; i++)
        printf("\t%d", a[i]);
    printf("\n"); 
    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("\nThe run time is %f \n", clk);
    return 0;
}