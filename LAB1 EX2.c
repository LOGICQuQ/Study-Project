#include "stdio.h"


float series(float Ra, float Rb)
{
   float R_total;
   R_total = Ra + Rb; 
   return R_total;
}
float parallel(float Ra, float Rb)
{
    float R_total;
    R_total = (Ra * Rb) / (Ra + Rb); 
    return R_total;
}
float Ohm_law(float U, float R)
{
    float I;
    I = U / R; 
    return I;
}


int main()
{
    int R[8];
    printf("Please enter the resistance values:\n");
for (int i = 0; i < 8; ++i) 
{
    scanf("%d", &R[i]);
}

float R_Total_1 = series(R[0], R[1]);
float R_Total_2 = parallel(R[2], R[3]);
float R_Total_3 = series(series(R[4],  parallel(R[5], R[6])), R[7]);
float R_Sum = parallel(parallel(R_Total_1, R_Total_2), R_Total_3);
float I = Ohm_law(12, R_Sum);
printf ("%.2f\n", I*1000);
    return 0;
}
