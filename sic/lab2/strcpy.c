#include <stdio.h>
#include <string.h>

int main()
{
    char inbuf[200];
    int i=0;
    char newstr[200];
    FILE *p;
    p=fopen("in.txt","r");
    while(fscanf(p,"%s",inbuf)!=EOF){}
    printf("Input: %s",inbuf);
    fclose(p);
    strcpy(newstr,inbuf);
    p=fopen("out.txt","w");
    fprintf(p,newstr);
    fclose(p);
    printf("\nOutput: %s",newstr);
    return 0;
}
