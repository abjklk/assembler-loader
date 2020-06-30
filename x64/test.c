#include <stdio.h>
#include <string.h>
#include <math.h>

long long int stringthex(char z[])
{
    z=strrev(z);
    int k=0;
    long long int hex=0;
    while(z[k]!='\0')
    {
        if(z[k]=='A'||z[k]=='B'||z[k]=='C'||z[k]=='D'||z[k]=='E'||z[k]=='F')
            hex+=(int)(z[k]-55)*(pow(16,k));
        else if(z[k]=='a'||z[k]=='b'||z[k]=='c'||z[k]=='d'|z[k]=='e'||z[k]=='f') 
              hex+=(int)(z[k]-87)*(pow(16,k));
        else
            hex+=(int)(z[k]-48)*(pow(16,k));
        k++;
    }
    z=strrev(z);
    return hex;
}

int main()
{
    FILE *fp1,*fp2;
	char *tok;
    char arr[100][2][20];
    int i=0;
    int j=0;
	char inbuf[200];
    int q=0;
	int ct=0;
    fp1=fopen("list.txt","r");
    while ((fscanf(fp1, "%[^\n]%*c", inbuf)) != EOF )
	{
		// printf("%s\n",inbuf);
        tok = strtok(inbuf," ");
        i=0;
        while (tok!= NULL)
        {
            // printf("words: %s\n",tok);
            strcpy(arr[ct][i],tok);
            i++;
            tok = strtok(NULL," ");
        }
        ct++;
    }
    fclose(fp1);
    for(i=0;i<ct;i++)
        printf("%s\n",arr[i][0]);
    char x[20] = "ABCDEF12345678";
    long long int d = stringthex(x);
    printf("%x",d);


}