#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char del[10],out_del[10],*p,s[201],sir[201];
	int n,v[201],i,m,count,flag=1,aux,j;
	scanf("%s %d",del,&n);
	for(i=0;i<n;i++){
			scanf("%d",&v[i]);
			scanf("%c",s);
		}
	while(flag){
		flag=0;
		for(i=0;i<n-1;i++)
		if(v[i]>v[i+1]){
			aux=v[i];
			v[i]=v[i+1];
			v[i+1]=aux;
			flag=1;

		}

	}
		for(i=0;i<n;i++)
		printf("%d ",v[i]);
		scanf("%s %d",out_del,&m);
		fgets(s,201,stdin);
		printf("\n");
		printf("%s %s %d %d",del,out_del,n,m);
		printf("\n");
		i=0;
		while(i<=m)
		{
			fgets(s,201,stdin);
			s[strlen(s)-1]='\0';
			count=0;
			sir[0]='\0';
			p=strtok(s,del);
			while(p!=NULL){
				count++;
			for(j=0;j<n-1;j++)
				if(count==v[j]){
				if(sir[0]=='\0') strcpy(sir,p);
				else strcat(sir,p);
				strcat(sir,out_del);	
				}
			p=strtok(NULL,del);	
			
			}
			if(sir[strlen(sir)-1]=='-') sir[strlen(sir)-2]='\0';
			printf("%s\n",sir);
			i++;
		}
	return 0;
}