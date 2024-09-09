//3.Binary search
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
int i, n, a[1000], key, bottom, top, mid, j, temp;
double clk;
clock_t starttime,endtime;
printf("Enter the number of products \n");
scanf("%d", &n);
printf("The product ID are: \n");
for (i=0; i<n; i++)
{
a[i] = rand()%100;
printf ("%d\t", a[i]);
}
for (i=0; i<n-1; i++)
{for(j=0;j<n-i-1;j++){
if (a[j]>a[j+1]){
temp = a[j];
a[j]=a[j+1];
a[j+1] = temp;
}}}
printf("\n Sorted product ID list is: \n"); 
for (i=0; i<n; i++)
{printf("\t%d", a[i]);}
printf("\n Enter the product ID to be searched: \n"); 
scanf("%d", &key);
starttime=clock();
bottom=0;
top=n-1;
do
{
 
while (key!=a[mid] && bottom <=top); 
if (key == a [mid])
{
printf("Product found!! \n"); 
printf("\n Product %d found in position: %d \n", key, mid+1);
}
else
{printf("\n Search failed \n %d not found \n", key);}
endtime = clock();
clk = (double) (endtime-starttime)/CLOCKS_PER_SEC;
printf ("Run Time: %f\n", clk);
return 0;
}