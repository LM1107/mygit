#include<stdio.h>

int main()
{
    int i,j,k;
    printf("plz input 3 integers\n");
#if 1    
    scanf("%d,%d,%d",&i,&j,&k);
#else
    //scanf("%d%d%d",&i,&j,&k);
    scanf("%d %d %d",&i,&j,&k);
#endif
    printf("%d,%d,%d",i,j,k);
    return 0;
}