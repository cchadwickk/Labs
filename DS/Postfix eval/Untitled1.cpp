#include<stdio.h>
#include<string.h>
#define true 1
#define false 0
int main()
{
    int t,len,flag;
    char str[100001];
    scanf("%d\n",&t);
    while(t--)
    {
        scanf("%s\n",str);
        len=strlen(str);
        flag=false;
        for(int i=0;i<len-2;i++)
        {
            if(((str[i]=='0')&&(str[i+1]=='1')&&(str[i+2]=='0'))||((str[i]=='1')&&(str[i+1]=='0')&&(str[i+2]=='1')))
            {
                flag=true;
                break;
            }
        }
        if(flag)
            printf("Good\n");
        else
            printf("Bad\n");
    }
    return 0;
}
