#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char key[100][100];
    if ((fp = fopen("out.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        exit(1);         
    }
    char inbuf[200];    
    char *tok;
    int j=0;
    while ((fscanf(fp, "%[^\n]%*c", inbuf)) != EOF )
	{
        
		//  fgetc(stream); 
		//printf("%s\n",inbuf);
        tok = strtok(inbuf," ");
        int i=1;
       
        while (tok!= NULL)
        {
             if(i==2)
            {
                printf ("%s\n",tok);
                strcpy(key[j],tok);
                j++;
            }
            
            // fprintf(fo,"%d\t%s\n",i,tok);
            tok = strtok(NULL," ");
            i++;
        }
    }
    fclose(fp);
    int l,q;
    for(l=0;l<j;l++)
    {
        for(q=l+1;q<j;q++)
        {
            if(strcmp(key[l],key[q])==0)
                printf("duplicate found: %s\n",key[q]);
        }
       // printf("%s\t",key[j]);
    }
}