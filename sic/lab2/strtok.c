#include <stdio.h>
#include <string.h>

int main()
{
    char inbuf[200];    
    char *tok;
    FILE *p;
    p=fopen("in.txt","r");
    while(fscanf(p,"%s",inbuf)!=EOF){
        printf("Input: %s\n",inbuf);
    }
    
    fclose(p);
    tok = strtok(inbuf," ");
    while (tok!= NULL)
    {
        printf ("%s\n",tok);
        tok = strtok(NULL,"';");
     }
}