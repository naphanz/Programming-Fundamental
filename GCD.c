#include <stdio.h>
int main()
{
    int x,y,i,gcd;
    printf("Enter first number : ");
    scanf("%d",&x);
    printf("Enter second number : ");
    scanf("%d",&y);
    for(i=1;i<=x && i<=y;i++)
    {
        if(x % i ==0 && y % i ==0)
        {
            gcd = i;
        }
    }
    printf("Greatest common divisor = %d",gcd);
    return 0;
}