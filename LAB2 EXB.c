#include<stdio.h>
#include<stdlib.h>
#define max(a,b) ((a)>(b)?(a):(b))

void transpose(int *matrix, int m, int n, int ld)
{
    if (m <= 0 || n <= 0 || m > 1024 || n > 1024)
    {
        return;
    }
    for(int i=0; i< ld; ++i)
    {
        for(int j=i+1; j< ld; ++j)
        {
            printf("%d\n", j);
            int temp = matrix[i * ld + j];
            matrix[i * ld + j] = matrix[j * ld + i];
            matrix[j * ld + i] = temp;
            for (int i = 0; i < ld; i++) 
            {
                 for (int j = 0; j < ld; j++)
                    {
                        printf("%d ", matrix[i * ld + j]);
                    }
                        printf("\n");
            }
        }
    }
}

 int main()
 {//Please delete the main function when you hand in.
     int m,n;
     scanf("%d %d", &m, &n);
    int ld = max(m, n);//leading dimension

    
 /* Sampleinput1:
 23
 123456
 matrix(row-majororder):
 123
 456
 000
 Sampleinput2:
 32
 123456
 matrix(row-majororder):
 120
 340
 560*/
    int *matrix = (int *)calloc(ld * ld, sizeof *matrix);
    for(int i=0; i<m; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            scanf("%d", &matrix[i * ld + j]);
        }
    }
    
 
transpose(matrix, m, n, ld);

    

    for(int j=0;j<n;++j)
 {
     for(int i=0; i<m; ++i)
     {
         printf("%d ", matrix[j * ld + i]);
     }
 }
    free(matrix);
    return 0;
 }
