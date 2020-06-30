#include <stdio.h>
#include <string.h>

int main()
{
    char inbuf[200];
    char check[]="is";
    FILE *p;
    p=fopen("in.txt","r");
    while(fscanf(p,"%s",inbuf)!=EOF){}
    fclose(p);
    printf("Input: %s",inbuf);
    char *pos;
    pos = strstr(inbuf,check);
    printf("\nPosition is %d",pos-inbuf+1);
}