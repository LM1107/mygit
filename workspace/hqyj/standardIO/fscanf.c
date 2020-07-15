#include<stdio.h>

int main()
{
#if 0
    char date[20] = {0};
    char place[20] = {0};
    char time[20] = {0};
    char person[20] = {0};
    char action[20] = {0};
    FILE *fp;
    fp = fopen("file.txt","w+");
    fputs("2020-7-10 chengdu Sat lm study", fp);
    
    rewind(fp);
    fscanf(fp, "%[^\t]%*[\t]%[^\t]%*[\t]%[^\t]%*[\t]%[^\t]%*[\t]%[^\r\n]",date,place,time,person,action);
    printf("%s %s %s %s %s\n",date,place,time,person,action);
#else
    char str1[10], str2[10], str3[10];
    int year;
    FILE * fp;

    fp = fopen ("file.txt", "w+");
    fputs("We are in 2014", fp);
    
    rewind(fp);
    fscanf(fp, "%s %s %s %d", str1, str2, str3, &year);
    
    printf("Read String1 |%s|\n", str1 );
    printf("Read String2 |%s|\n", str2 );
    printf("Read String3 |%s|\n", str3 );
    printf("Read Integer |%d|\n", year );

    fclose(fp);
    
#endif 
    return 0;
}