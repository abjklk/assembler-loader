#include <stdio.h>
 
int main()
{
    char inbuf[50];
    FILE *p;
    p=fopen("in.txt","r");
    while(fscanf(p,"%s",inbuf)!=EOF)
    {
        printf("%s",inbuf);
    }
    return 0;
}
