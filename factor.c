#include <stdio.h>
void pf(int num)
{
    int count;
    for(count = 2;num >1; count++)
    {
        while(num % count ==0)
        {
            printf("%d ",count);
            num = num / count;
          
        }
      
    }
  
}
int main()
{
    int num;
    printf("Enter factor :");
    scanf("%d",&num);
    pf(num);
    return 0;

}