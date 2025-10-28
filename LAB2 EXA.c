#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int gcd(int a,int b)
{
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main()
{
    int n, a0;
    scanf("%d %d", &n, &a0);
    srand(time(NULL));
    int Result = 0;
    int Max_Queries = 30;

    for (int Query_Count = 0; Query_Count < Max_Queries; Query_Count++)
    {
        printf("? %d\n", rand() % n);
        fflush(stdout);
        int ai;
        scanf("%d", &ai);
        
        int difference = (ai - a0);
        if (difference != 0)
        {
           if (Result == 0)
               Result = abs(difference);
           else
               Result = gcd(Result, abs(difference));
        }
        if (Result > 0 && Query_Count >= 5)
            {
                break;
            }
    }

    printf("! %d\n", Result);
    fflush(stdout);

    return 0;
}



