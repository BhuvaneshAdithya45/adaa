//6. Quick Sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 200000
int a[MAX];
int partition(int low, int high) {
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;
    while (1) {
        while (i < high && a[i] <= pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        } else {
            temp = a[j];
            a[j] = a[low];
            a[low] = temp;
            return j;
        }
    }
}
void quick_sort(int low, int high) {
    if (low < high) {
        int j = partition(low, high);
        quick_sort(low, j - 1);
        quick_sort(j + 1, high);
    }
}
int main() {
    int n;
    double clk;
    clock_t starttime, endtime;
    printf("QUICK SORT \n");
    printf("Enter the number of Students records: \n");
    scanf("%d", &n);
    printf("The roll numbers are: \n");
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100; 
        printf("\t%d", a[i]);
    }
    printf("\n"); 
    starttime = clock();
    quick_sort(0, n - 1);
    endtime = clock();
    printf("\nSorted roll numbers are: \n");
    for (int i = 0; i < n; i++)
        printf("\t%d", a[i]);
    printf("\n"); 
    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("\nThe run time: %f\n", clk);
    return 0;
}