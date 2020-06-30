#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    FILE *fo;
    
    if ((fp = fopen("out.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        exit(1);         
    }
    char inbuf[200];    
    char *tok;
   
    fo=fopen("col3.txt","w");
    while ((fscanf(fp, "%[^\n]%*c", inbuf)) != EOF )
	{
		//  fgetc(stream); 
		//printf("%s\n",inbuf);
        tok = strtok(inbuf," ");
        int i=1;
        while (tok!= NULL)
        {
            if(i==3)
            {
                printf ("words: %s\n",tok);
                fprintf(fo,"%s\n",tok);
            }
            // fprintf(fo,"%d\t%s\n",i,tok);
            tok = strtok(NULL," ");
            i++;
            
        }
    }
    fclose(fo);
    fclose(fp);
    
    
    
}