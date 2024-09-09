//4.insertion
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, n;
    double clk;
    long phoneNo[100], temp;
    clock_t starttime, endtime;

    printf("Enter the number of phone numbers \n");
    scanf("%d", &n);

    printf("The phone numbers are: \n");
    srand(time(0)); 

    for (i = 0; i < n; i++) {
        phoneNo[i] = 9000000000 + (rand() % 99999999) + 1;
        printf("%ld \n", phoneNo[i]);
    }

    starttime = clock();
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (phoneNo[j] > phoneNo[j + 1]) {
                temp = phoneNo[j];
                phoneNo[j] = phoneNo[j + 1];
                phoneNo[j + 1] = temp;
            }
        }
    }
    endtime = clock();

    printf("\nSorted phone numbers are: \n");
    for (i = 0; i < n; i++) {
        printf("%ld\n", phoneNo[i]);
    }

    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("Run Time: %f \n", clk);

    return 0;
}