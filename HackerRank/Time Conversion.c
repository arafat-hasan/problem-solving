#include <stdio.h>
int main()
{
    char time[11];
    scanf("%s",time);
    if((time[8]=='P'||time[8]=='p')&&!(time[0]=='1'&&time[1]=='2'))
    {
        time[0]=time[0]+1;
        time[1]=time[1]+2;
    }
    else if (time[0]=='1'&&time[1]=='2'&&(time[8]=='a'||time[8]=='A'))
             {
                 time[0]=time[1]='0';
             }
    printf("%c%c%c%c%c%c%c%c",time[0],time[1],time[2],time[3],time[4],time[5],time[6],time[7]);
    return 0;
}
