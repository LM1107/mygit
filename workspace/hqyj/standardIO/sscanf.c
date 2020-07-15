#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#if 0 
int main()
{
    char line[128] = "2020-7-10 chengdu Sat lm study";
    char date[20] = {0};
    char place[20] = {0};
    char time[20] = {0};
    char person[20] = {0};
    char action[20] = {0};
    sscanf ( line, "%[^\t]%*[\t]%[^\t]%*[\t]%[^\t]%*[\t]%[^\t]%*[\t]%[^\r\n]",date,place,time,person,action);
    printf("%s %s %s %s %s\n",date,place,time,person,action);
}
#else
int main()
{
    int day, year;
    char weekday[20], month[20], dtm[100];

    strcpy(dtm, "Saturday March 25 1989" );
    sscanf(dtm, "%s %s %d  %d", weekday, month, &day, &year );

    printf("%s %d, %d = %s\n", month, day, year, weekday );
        
    return(0);
}
#endif