#include <stdio.h>
#include <string.h>
 //Define your structure first
typedef struct Record
 {
    char name[50];
    int s;
    int t;
 } Record;

int t_to_minutes(char t_temp[6])
{
    int hours, minutes;
    sscanf(t_temp, "%2d:%2d", &hours, &minutes);
    return hours * 60 + minutes;
}

int compare(Record a, Record b)
{
  if (a.s != b.s)
    {
      return b.s - a.s;
    }
  if(a.t != b.t)
    {
      return a.t - b.t;
    }
  return strcmp(a.name, b.name);
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
    getchar();
    Record Students[1000];
    for(int i=0;i<n;i++)
      {
        char ch[256];
        fgets(ch, sizeof(ch), stdin);
        char name[100];
        int s1;
        char t_temp[6];
        sscanf(ch, "%s %d %s", name, &s1, t_temp);
        if (sscanf(ch, "%s %d %s", name, &s1, t_temp) == 3) 
        {
            Students[i].s = s1;
            Students[i].t = t_to_minutes(t_temp);
            strcpy(Students[i].name, name);
        }
      }

    Bubble_Sort(Students, n);

    for(int i=0;i<n;i++)
      {
        printf("%s\n", Students[i].name);
      }
      return 0;
}