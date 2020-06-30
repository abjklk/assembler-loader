#include <stdio.h>
#include <string.h>

int main()
{
    char inbuf[200];
    char cstr[]="HelloThisisSslab";
    FILE *p;
    p=fopen("in.txt","r");
    while(fscanf(p,"%s",inbuf)!=EOF){
        printf("%s",inbuf);
    }
    fclose(p);
    if(strcmpi(inbuf,cstr)==0)
        printf("\nStrings are Equal");
    else
        printf("\nNot Equal");
}