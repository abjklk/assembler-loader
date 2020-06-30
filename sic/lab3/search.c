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
    fo=fopen("search.txt","w");
    char str[10];
    int i;
    for(i=0;i<7;i++)
    {
        printf("Enter search keyword: ");
        scanf("%s",str);
        while ((fscanf(fp, "%[^\n]%*c", inbuf)) != EOF )
        {
            
            //  fgetc(stream); 
            //printf("%s\n",inbuf);
        // fprintf(fo,"%x %s\n",i,inbuf);
            tok = strtok(inbuf," ");
            int i=1;
            
            while (tok!= NULL)
            {
                if(i==2 && strcmp(str,tok)==0)
                {
                    fprintf (fo,"%s\n",tok);
                    printf("Keyword Found!\n");
                // fprintf(fo,"%s\n",tok);
                }
                
                // fprintf(fo,"%d\t%s\n",i,tok);
                tok = strtok(NULL," ");
                i++;
            }
        }
        rewind(fp);
    }
    fclose(fo);
    fclose(fp);

}