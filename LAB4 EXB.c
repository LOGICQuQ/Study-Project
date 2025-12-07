 #include <stdio.h>
 long long XOR(long long a, long long b) 
 {
    long long t = 0;
     for (int i = 0; i < 64; ++i) 
     {
         long long ai = (a >> i) & 1LL;
         long long bi = (b >> i) & 1LL;
         long long ti = (ai + bi) & 1LL; 
         t |= (ti << i);
     }
     return t;
 }
 int main() 
 {
    long long n;
    if (scanf("%lld", &n) != 1) return 0;

    long long path[128];
    int m = 0;
    long long t = n;

    while (t >= 1) 
    {
        path[m++] = t;
        if (t == 1) break;
        t = t >> 1; 
    }

    for (int i = 0; i < (m >> 1); ++i) 
    {
        long long temp = path[i];
        path[i] = path[m - 1 - i];
        path[m - 1 - i] = temp;
    }
    //printf("%d\n", m);
    
    long long s = 0;

    for (int i = 0; i < m; ++i) 
    {
        s = XOR(s, path[i]);
        //printf("%lld\n", s);
    }
    printf("%lld\n", s);
    /*for (int i = 0; i < m; ++i) 
    {
        printf("%lld ", path[i]);
    }*/
    return 0;
 }
