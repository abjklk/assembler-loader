#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    if ((fp = fopen("program.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        exit(1);         
    }
							                 // reads text until newline 
 	char line[1000];

	while ((fscanf(fp, "%[^\n]%*c", line)) != EOF )
	{
		//  fgetc(stream); 
		printf("%s\n",line);
	}
							                                 
    return 0;
}
