#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int stringthex(char z[4])
{
    z=strrev(z);
    int k=0,hex=0;
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
	int lines[100];
    char arr[100][50][20];
    char sym[100][2][10];
    char opt[100][2][10];
    char reg[100][2][10];
    
    int i=0;
    int j=0;
	char inbuf[200];
    int q=0;
	int ct=0;
    int ct2=0;
    int ct3=0;
    int ct4=0;
	int locctr=0;
    int flag = 0;
    char objcode[30];

    //Pass 1 Begins
    printf("\n=============Intel x64 Assembler=============\n");
    printf("\n=============Pass 1==========================\n");
    //Reading from file to buffer
    fp1=fopen("input2.txt","r");
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
        lines[ct] = i;
        ct++;
    }
    fclose(fp1);

    fp1 = fopen("symtab.txt","w");
    // fp2 = fopen("list.txt","w");
	for(i=0;i<ct;i++)
	{
		if(strcmp(arr[i][0],"section")==0 && strcmp(arr[i][1],".data")==0){
			i++;
            printf("===============Data Section==========\n");
			while(strcmp(arr[i][0],"section")!=0){
				if(strcmp(arr[i][1],"db")==0){
					printf("%08x  %s %s %s\n",locctr,arr[i][0],arr[i][1],arr[i][2]);
                    fprintf(fp1,"%s %08x\n",arr[i][0],locctr);
					locctr += 1;
				}
				else if(strcmp(arr[i][1],"dw")==0){
					printf("%08x  %s %s %s\n",locctr,arr[i][0],arr[i][1],arr[i][2]);
                    fprintf(fp1,"%s %08x\n",arr[i][0],locctr);
					locctr += 2;
				}
				else if(strcmp(arr[i][1],"dd")==0){
					printf("%08x  %s %s %s\n",locctr,arr[i][0],arr[i][1],arr[i][2]);
                    fprintf(fp1,"%s %08x\n",arr[i][0],locctr);
					locctr += 4;
				}
				else if(strcmp(arr[i][1],"dq")==0){
					printf("%08x  %s %s %s\n",locctr,arr[i][0],arr[i][1],arr[i][2]);
                    fprintf(fp1,"%s %08x\n",arr[i][0],locctr);
					locctr += 8;
				}
				i++;
			}
		}
        if(strcmp(arr[i][0],"section")==0 && strcmp(arr[i][1],".text")==0){
            i+=2;
            printf("===============Text Section==========\n");
            if(strcmp(arr[i][0],"_start:")==0){
                i++;
                while(i<ct){
					printf("%08x  %s %s %s %s\n",locctr,arr[i][0],arr[i][1],arr[i][2],arr[i][3]);    
                    locctr+=7;  
                    i++;  
                }
            }
        }
	}

    printf("=========================\n\nProgram Length is %08x\n",locctr);
    fclose(fp1);

    //Pass 2 
    printf("\n========Pass 2 ============\n");

    fp1 = fopen("symtab.txt","r");
    while ((fscanf(fp1, "%[^\n]%*c", inbuf)) != EOF )
	{
		// printf("%s\n",inbuf);
        tok = strtok(inbuf," ");
        i=0;
        while (tok!= NULL)
        {
            // printf("words: %s\n",tok);
            strcpy(sym[ct2][i],tok);
            i++;
            tok = strtok(NULL," ");
        }
        ct2++;
    }
    fclose(fp1);

    fp1 = fopen("optab.txt","r");
    while ((fscanf(fp1, "%[^\n]%*c", inbuf)) != EOF )
	{
		// printf("%s\n",inbuf);
        tok = strtok(inbuf," ");
        i=0;
        while (tok!= NULL)
        {
            // printf("words: %s\n",tok);
            strcpy(opt[ct3][i],tok);
            i++;
            tok = strtok(NULL," ");
        }
        ct3++;
    }
    fclose(fp1);
    fp1 = fopen("regtab.txt","r");
    while ((fscanf(fp1, "%[^\n]%*c", inbuf)) != EOF )
	{
		// printf("%s\n",inbuf);
        tok = strtok(inbuf," ");
        i=0;
        while (tok!= NULL)
        {
            // printf("words: %s\n",tok);
            strcpy(reg[ct4][i],tok);
            i++;
            tok = strtok(NULL," ");
        }
        ct4++;
    }
    fclose(fp1);

    for(i=0;i<ct;i++){
        if(strcmp(arr[i][0],"section")==0 && strcmp(arr[i][1],".data")==0){
			i++;
            while(strcmp(arr[i][0],"section")!=0){
                printf("%s\t%s\t%s",arr[i][0],arr[i][1],arr[i][2]);
                
                if(strcmp(arr[i][1],"db")==0)
                    printf("\t%02X\n",atoi(arr[i][lines[i]-1]));
                else if(strcmp(arr[i][1],"dw")==0)
                    printf("\t%04X\n",atoi(arr[i][lines[i]-1]));
                else if(strcmp(arr[i][1],"dd")==0)
                    printf("\t%08X\n",atoi(arr[i][lines[i]-1]));
                else if(strcmp(arr[i][1],"dq")==0)
                    printf("\t%X\n",atoi(arr[i][lines[i]-1]));

                i++;
            }

        }
        if(strcmp(arr[i][0],"_start:")==0){
            i++;
            while(i<ct){
                printf("%s %s %s %s",arr[i][0],arr[i][1],arr[i][2],arr[i][3]);
                //search optab
                for(j=0;j<ct3;j++){
                    if(strcmp(arr[i][0],opt[j][0])==0){
                        // printf("%s",opt[j][1]);
                        strcpy(objcode,opt[j][1]);
                        break;
                    }
                }
                //check register
                if(strcmp(arr[i][1],"byte")==0 || strcmp(arr[i][1],"word")==0 || strcmp(arr[i][1],"dword")==0 || strcmp(arr[i][1],"qword")==0 ){   
                    flag = 1;        
                }
                //check register in regtab
                if(flag){
                    for(j=0;j<ct4;j++){
                        if(strcmp(arr[i][3],reg[j][0])==0){
                            if(reg[j][1][0]=='1'){
                                objcode[1]='c';
                                if(strcmp(arr[i][3],"r8")==0)
                                    strcpy(inbuf,"04");
                                else if(strcmp(arr[i][3],"r9")==0)
                                    strcpy(inbuf,"0c");
                                else if(strcmp(arr[i][3],"r10")==0)
                                   strcpy(inbuf,"14");
                                else if(strcmp(arr[i][3],"r11")==0)
                                    strcpy(inbuf,"1c");
                                else if(strcmp(arr[i][3],"r12")==0)
                                    strcpy(inbuf,"24");
                                else if(strcmp(arr[i][3],"r13")==0)
                                    strcpy(inbuf,"2c");
                                else if(strcmp(arr[i][3],"r14")==0)
                                    strcpy(inbuf,"34");
                                else if(strcmp(arr[i][3],"r15")==0)
                                    strcpy(inbuf,"3c");
                            }
                            else{
                                if(strcmp(arr[i][3],"rax")==0)
                                    strcpy(inbuf,"04");
                                else if(strcmp(arr[i][3],"rcx")==0)
                                    strcpy(inbuf,"0c");
                                else if(strcmp(arr[i][3],"rdx")==0)
                                   strcpy(inbuf,"14");
                                else if(strcmp(arr[i][3],"rbx")==0)
                                    strcpy(inbuf,"1c");
                                else if(strcmp(arr[i][3],"rsp")==0)
                                    strcpy(inbuf,"24");
                                else if(strcmp(arr[i][3],"rbp")==0)
                                    strcpy(inbuf,"2c");
                                else if(strcmp(arr[i][3],"rsi")==0)
                                    strcpy(inbuf,"34");
                                else if(strcmp(arr[i][3],"rdi")==0)
                                    strcpy(inbuf,"3c");
                            }
                            itoa(stringthex(objcode) & 0xFFFD,objcode,16);
                            strcat(objcode,inbuf);
                            break;
                        }
                    }
                    char t[20];
                    strcpy(t,arr[i][2]+1);
                    t[strlen(t)-1]=0;
                    t[strlen(t)-1]=0;
                    for(j=0;j<ct2;j++){
                        // printf("%s - %s\n",t,sym[j][0]);
                        if(strcmp(t,sym[j][0])==0){
                            char x[10][2];
                            for(q=1;q<strlen(sym[j][1]);q++){
                                if(q % 2 == 1){
                                    x[q][0]=sym[j][1][q-1];
                                    x[q][1]=sym[j][1][q];
                                    q++;
                                }
                            }
                            
                            strcat(objcode,x[7]);
                            strcat(objcode,x[5]);
                            strcat(objcode,x[3]);
                            strcat(objcode,x[1]);
                            break;

                        }
                    }
                
                flag = 0;
                }
                else
                {
                    arr[i][1][strlen(arr[i][1])-1]=0;
                    for(j=0;j<ct4;j++){
                        
                        if(strcmp(arr[i][1],reg[j][0])==0){
                            if(reg[j][1][0]=='1'){
                                objcode[1]='c';
                                if(strcmp(arr[i][3],"r8")==0)
                                    strcpy(inbuf,"04");
                                else if(strcmp(arr[i][3],"r9")==0)
                                    strcpy(inbuf,"0c");
                                else if(strcmp(arr[i][3],"r10")==0)
                                   strcpy(inbuf,"14");
                                else if(strcmp(arr[i][3],"r11")==0)
                                    strcpy(inbuf,"1c");
                                else if(strcmp(arr[i][3],"r12")==0)
                                    strcpy(inbuf,"24");
                                else if(strcmp(arr[i][3],"r13")==0)
                                    strcpy(inbuf,"2c");
                                else if(strcmp(arr[i][3],"r14")==0)
                                    strcpy(inbuf,"34");
                                else if(strcmp(arr[i][3],"r15")==0)
                                    strcpy(inbuf,"3c");
                            }
                            else{
                                
                                if(strcmp(arr[i][3],"rax")==0)
                                    strcpy(inbuf,"04");
                                else if(strcmp(arr[i][3],"rcx")==0)
                                    strcpy(inbuf,"0c");
                                else if(strcmp(arr[i][3],"rdx")==0)
                                   strcpy(inbuf,"14");
                                else if(strcmp(arr[i][3],"rbx")==0)
                                    strcpy(inbuf,"1c");
                                else if(strcmp(arr[i][3],"rsp")==0)
                                    strcpy(inbuf,"24");
                                else if(strcmp(arr[i][3],"rbp")==0)
                                    strcpy(inbuf,"2c");
                                else if(strcmp(arr[i][3],"rsi")==0)
                                    strcpy(inbuf,"34");
                                else if(strcmp(arr[i][3],"rdi")==0)
                                    strcpy(inbuf,"3c");
                            }
                            strcat(objcode,inbuf);
                            break;
                        }
                    }
                    char t[20];
                    strcpy(t,arr[i][3]+1);
                    t[strlen(t)-1]=0;
                    for(j=0;j<ct2;j++){
                        // printf("%s - %s\n",t,sym[j][0]);
                        if(strcmp(t,sym[j][0])==0){
                            char x[10][2];
                            for(q=1;q<strlen(sym[j][1]);q++){
                                if(q % 2 == 1){
                                    x[q][0]=sym[j][1][q-1];
                                    x[q][1]=sym[j][1][q];
                                    q++;
                                }
                            }   
                            strcat(objcode,x[7]);
                            strcat(objcode,x[5]);
                            strcat(objcode,x[3]);
                            strcat(objcode,x[1]);
                            break;
                        }
                    }
                }
                printf("\t%s\n",objcode);
                i++;
            }
        }
    }
}
