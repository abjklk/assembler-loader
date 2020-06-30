#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    FILE *fp;
    if ((fp = fopen("in.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        exit(1);         
    }
    char inbuf[200];    
    char *tok;
    while ((fscanf(fp, "%[^\n]%*c", inbuf)) != EOF )
	{
		//  fgetc(stream); 
		printf("%s\n",inbuf);

        tok = strtok(inbuf," ");
        while (tok!= NULL)
        {
            printf ("words: %s\n",tok);
            tok = strtok(NULL," ");
        }
    }
    
    fclose(fp);
    
}