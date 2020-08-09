#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char s[201],*p,sir[201],sep[]=" ",sir1[201];
	int i,n,j=0;
	scanf("%d",&n);
	i=0;
	fgets(s,201,stdin);
	while(i<=n){
		fgets(s,201,stdin);
		s[strlen(s)-1]='\0';
		
		p=strtok(s,sep);
		sir1[0]='\0';
		while(p!=NULL){
			strcpy(sir,p);
			j=1;
			while(p[j]!='\0'){
			if(p[0]<48 || p[0]>57 || p[j]<48 || p[j]>57){
				sir[j]=(sir[j]+sir[0])%256;
			}
			j++;
			}
			if(sir1[0]!='\0') strcat(sir1,sir);
			else strcpy(sir1,sir);
			strcat(sir1," ");		
			p=strtok(NULL,sep);
		}
		printf("%s",sir1);	
		printf("\n");
		i++;
	}
	return 0;
}