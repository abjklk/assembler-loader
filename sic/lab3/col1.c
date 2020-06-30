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
  
    fo=fopen("col1.txt","w");
    while ((fscanf(fp, "%[^\n]%*c", inbuf)) != EOF )
	{
		//printf("%s\n",inbuf);
        tok = strtok(inbuf," ");
        int i=1;
        while (tok!= NULL)
        {
            if(i==1 || i==2)
            {
                printf ("%s ",tok);
                fprintf(fo,"%s ",tok);
            }
            
            // fprintf(fo,"%d\t%s\n",i,tok);
            tok = strtok(NULL," ");
            i++;
            
        }
        printf("\n");
        fprintf(fo,"\n");
    }
    fclose(fo);
    fclose(fp);
    
    
    
}