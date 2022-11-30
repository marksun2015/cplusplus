#include <stdio.h>

int main()
{
    int n,i;
    while (scanf("%d",&n)!=EOF)
    {

        printf("%d=",n);
        i=2;
        while(i<n)
        {
            if(n%i==0)
            {
                printf("%d*",i);
                n=n/i;
            }
            else
                i++;
        }

        printf("%d\n",n);
    }
    return 0;
}
