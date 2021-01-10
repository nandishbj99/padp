#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
int main(){

printf("sizes: 500,1000,1500,2000 \n");
printf("threads : 1,2,4,8,16\n");

int r, c, i, j, count=0, sum =0, k;
int threads[5] = {1,2,4,8,16};
long long int sizes[4]={500,1000,1500,2000};
//dynamically allocate arrays

printf("\t\t1\t\t2\t\t4\t\t8\t\t16\n");
for(int sizeloop = 0; sizeloop<4; sizeloop++)
{
printf("\n%lld", sizes[sizeloop]);
for(int threadloop =0; threadloop<5;threadloop++)
{
r = c = sizes[sizeloop];

int **arr1 = (int **)malloc(r * sizeof(int *));
for (i=0; i<r; i++)
arr1[i] = (int *)malloc(c * sizeof(int));
int **arr2 = (int **)malloc(r * sizeof(int *));
for (i=0; i<r; i++)
arr2[i] = (int *)malloc(c * sizeof(int));
int **arr3 = (int **)malloc(r * sizeof(int *));
for (i=0; i<r; i++)
arr3[i] = (int *)malloc(c * sizeof(int));

for(i = 0;i < r; i++)
for(j = 0;j < c; j++)
arr1[i][j] = count++;

for(i = 0;i < r; i++)
for(j = 0;j < c; j++)
arr2[i][j] = count++;
double x = omp_get_wtime();
omp_set_num_threads(threadloop);
#pragma omp parallel for private(j, k)
for(i = 0;i < r; i++)
for(j = 0;j < c; j++)
for(k = 0;k < r; k++)
arr3[i][j] += arr1[i][k] * arr2[k][j];

double y = omp_get_wtime();
printf("\t%lf", y-x);

}//threadloop

}//sizeloop
return 0;
}
