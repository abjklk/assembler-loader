#include <stdio.h>
#include <string.h>

int main()
{
    char inbuf[200];
    char newstr[]="this is the concatenated string.";
    FILE *p;
    p=fopen("in.txt","r");
    while(fscanf(p,"%s",inbuf)!=EOF){}
    printf("Input: %s",inbuf);
    fclose(p);
    strncat(inbuf,newstr,4);
    p=fopen("out.txt","w");
    fprintf(p,inbuf);
    fclose(p);
    printf("Output: %s",inbuf);
    return 0;
}
