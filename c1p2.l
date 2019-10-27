%{
	int isfound(char *x);
	char buffer[200][100];
	int z=0;
%}

%%
[+-/=*%] {if(isfound(yytext)){
			printf("%s is an Operator \n",yytext);	}
		 }
[{};,()"] {if(isfound(yytext)){
			printf("%s is a Seperator \n",yytext);}
			}
auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while {
if(isfound(yytext)){
		printf("%s is a keyword \n",yytext);}
	}		 
([a-zA-Z][0-9])+|[a-zA-Z]* {
if(isfound(yytext)){
	printf("%s is an Identifier \n",yytext);}
}	
[0-9]+ {
if(isfound(yytext)){
printf("%s is a number \n",yytext);}
}
[\n\t ] {}
%%

int yywrap()
{return 1;}

int isfound(char x[])
{
	int i,flag=1;
	for(i=0;i<z;i++)
	{
		if(strcmp(x,buffer[i])==0)
			flag=0;}
		if(flag==1){
			strcpy(buffer[z],x);z++;}
			return flag;
}
int main()
{
	char found[100];
	FILE *fptr;
	fptr=fopen("input.txt","r");
	yyin=fptr;
	
	yylex();
	fclose(fptr);
	return 0;
}	
	


