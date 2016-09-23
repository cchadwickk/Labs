#include<stdio.h>
#include<string.h>
#define true 1
#define false 0
int main()
{
    int t,len,i;
    char str[100001];
    scanf("%d\n",&t);
    while(t--)
    {
        scanf("%s\n",str);
        len=strlen(str);
        for(i=0;i<len-2;i++)
        {
            if(((str[i]=='0')&&(str[i+1]=='1')&&(str[i+2]=='0'))||((str[i]=='1')&&(str[i+1]=='0')&&(str[i+2]=='1')))
            {
                printf("Good\n");
                break;
            }
        }
        if(i==len-2)
            printf("Bad\n");
    }
    return 0;
}
