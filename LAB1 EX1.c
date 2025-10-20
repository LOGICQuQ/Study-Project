#include <stdio.h>
#include <math.h>

int Calculus_One_C;
int Introductory_Programming_C;
int Anonymous_C;
int Calculus_One_G;
int Introductory_Programming_G;
int Anonymous_G;


int main()
{
    printf("Enter the credit of Calculus One, IntroductoryProgramming, Anonymous: ");
    scanf("%d %d %d", &Calculus_One_C, &Introductory_Programming_C, &Anonymous_C);
    printf("Enter the grade of Calculus One, IntroductoryProgramming, Anonymous: ");
    scanf("%d %d %d", &Calculus_One_G, &Introductory_Programming_G, &Anonymous_G);
    float GPA = (Calculus_One_C * Calculus_One_G + Introductory_Programming_C * Introductory_Programming_G + Anonymous_C * Anonymous_G) / (float)(Calculus_One_C + Introductory_Programming_C + Anonymous_C);
    int GPAI= round(GPA);
    printf("Rounded GPA: %d\n", GPAI);
    return 0;
}