#include <stdio.h>
#include <string.h>

int main()
{
    char inbuf[200];
    FILE *p;
    p=fopen("in.txt","r");
    while(fscanf(p,"%s",inbuf)!=EOF){}
    fclose(p);
    printf("Input: %s",inbuf);
    char *pos;
    pos = strchr(inbuf,'t');
    printf("\nPosition is %d",pos-inbuf+1);
}