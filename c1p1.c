#include<stdio.h>
#include<string.h>
#include<ctype.h>

char fbuf[40][100];
int y=0;
char fb[7];
int z=0;

int keyword(char x[]){
	int flag=0;
	char keywords[34][25]={"auto","break","case","char","const","continue","default",
							"do","double","else","enum","extern","float","for","goto",
							"if","int","long","register","return","short","signed",
							"sizeof","static","struct","switch","typedef","union",
							"unsigned","void","volatile","while"};

	for(int i=0;i<32;i++)
	{
		if(strcmp(keywords[i],x)==0)
		{
			flag=1;
		}

	}
	return flag;
}

int searchbuf(char x[]){
	int flag=0;
	for(int i=0;i<y;i++)
	{
		if(strcmp(fbuf[i],x)==0)
		{
			flag=1;
		}

	}
	return flag;
}
int searchop(char x)
{
	int flag=0;
	for(int i=0;i<z;i++)
	{
		if(fb[i]==x)
		{
			flag=1;
		}

	}
	return flag;
}
int main()
{
	FILE *fp;
	int j=0,l=0;
	fp=fopen("input.txt","r");
	char ch;
	char buffer[30],op[7]="+-/*%=";
	while((ch=fgetc(fp))!=EOF)
	{
		for(int i=0;i<7;i++)
		{
			if(op[i]==ch)
			{
				if(searchop(ch)==1)
					continue;
				else
				{
				
					fb[z++]=ch;
					printf("%c is an operator\n",ch);
				}
			}
		}
		if(isalnum(ch))
		{
			buffer[j++]=ch;
		}
		else if((ch==' '||ch=='\n')&&(j!=0))
		{
			buffer[j]='\0';
			j=0;
			
			//if(keyword(buffer)==0){
			//	printf("%s is not a keyowrd\n",buffer);l=1;}
			if(keyword(buffer)==1)
			{
				if(searchbuf(buffer)==1)
					continue;
				else
				{
				
					strcpy(fbuf[y++],buffer);
					printf("%s is a keyword\n",buffer);
				}
			}
			
			else
			{
				if(searchbuf(buffer)==1)
					continue;
				else
				{
				
					strcpy(fbuf[y++],buffer);
					printf("%s is an identifier\n",buffer);
				}
			}	
		}
			
		
	}
	fclose(fp);
	return 0;
}	
	



