#include <stdio.h>
#include <string.h>

int main()
{
    char inbuf[200];
    char *d;
    FILE *p;
    p=fopen("in.txt","r");
    while(fscanf(p,"%s",inbuf)!=EOF){}
    fclose(p);
    printf("Input: %s",inbuf);
    d=strdup()
}