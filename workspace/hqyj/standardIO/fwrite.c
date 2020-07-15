#include<stdio.h>

int main()
{
#if 0    
    char output[] = "AA";
    FILE *fp = fopen("test.in","r+");
    FILE *fp = fopen("test.in","w");
    fseek(fp,3,SEEK_SET);
    fwrite(output,sizeof(output)-1,1,fp);
#else
    char array[5] = {'1','5','6','7','8'};
    FILE *fp = fopen("test1.in","r+");
    
    fwrite(array,sizeof(char),5,fp);
#endif
    fclose(fp);
    return 0;
}