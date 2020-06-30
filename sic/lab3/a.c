#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    FILE *fo;
    
    if ((fp = fopen("input.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        exit(1);         
    }
    char inbuf[200];    
    char *tok;
    int i=4096;
    fo=fopen("out.txt","w");
    while ((fscanf(fp, "%[^\n]%*c", inbuf)) != EOF )
	{
        
		//  fgetc(stream); 
		//printf("%s\n",inbuf);
        fprintf(fo,"%x %s\n",i,inbuf);
        i=i+3;
        tok = strtok(inbuf," ");
        while (tok!= NULL)
        {
            printf ("words: %s\n",tok);
            // fprintf(fo,"%d\t%s\n",i,tok);
            tok = strtok(NULL," ");
            
        }
    }
    fclose(fo);
    fclose(fp);

}