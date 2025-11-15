#include <stdio.h>
#include <string.h>
 //Define your structure first
typedef struct Record
 {
    char name[100];
    int s;
    char t[6];
 } Record;

int t_to_minutes(char t_temp[])
{
    int hours, minutes;
    sscanf(t_temp, "%d:%d", &hours, &minutes);
    return hours * 60 + minutes;
}

int compare(Record a, Record b)
{
  if (a.s != b.s)
    {
      return b.s - a.s;
    }
    int t1 = t_to_minutes (a.t);
    int t2 = t_to_minutes(b.t);
  if(t1 != t2)
    {
      return t1 - t2;
    }
  return strcmp(a.name, b.name);
  return 0;
}

void Bubble_Sort(Record arr[], int n)
{
    for (int i = 0; i < n-1; i++)       
    {
        for (int j = 0; j < n-i-1; j++)  
        {
            if (compare(arr[j], arr[j+1]) > 0) 
            {
                Record temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}




 // Then your program. Remember to define helper functions
int main() 
{
    int n;
    scanf("%d", &n); 
    Record Students[1000];
    for(int i=0;i<n;i++)
      {
         scanf("%s %d %s", Students[i].name, &Students[i].s, Students[i].t);
      }

    Bubble_Sort(Students, n);

    for(int i=0;i<n;i++)
      {
        printf("%s\n", Students[i].name);
      }
      return 0;
}