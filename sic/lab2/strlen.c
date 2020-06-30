#include <stdio.h>
#include <string.h>

int main()
{
    char inbuf[200];
    FILE *p;
    p=fopen("in.txt","r");
    while(fscanf(p,"%s",inbuf)!=EOF){
        printf("%s",inbuf);
    }
    fclose(p);
    printf("\nLength is: %d",strlen(inbuf));
}