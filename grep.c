#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void eliberare(char **v, int n) //functie cu rolul de a elibera memoria utilizata
{
    int i;
    for(i=0;i<n;i++)
		    free(v[i]); 
		    free(v);
        
}


void modificare(char ***v,char *s,char *s1,int n)
{
    char *p;
    int i;
    for(i=0;i<n;i++)
    {
    p=strtok((*v)[i]," \n");
    while(p!=NULL)
    {
      
        if(strcmp(s,p)==0) printf("%s",s1);
        else  printf("%s",p);

        p=strtok(NULL," \n"); 
        if(p!=NULL) printf(" ");
    }
    printf("\n");
    }


}
void citire(char ***v,char **s,char **s1, int *n)
{
    char *sir;
    int i;
    *s=(char *)malloc(31);
    *s1=(char *)malloc(50);
    sir=(char *)malloc(201);
    scanf("%s %d",*s,n);
    strcpy(sir,"\e[0;31m");
    strcat(sir,*s);
    strcat(sir,"\e[m");    
    strcpy(*s1,sir);
    fgets(sir,200,stdin);
    *v=(char **)malloc((*n)*sizeof(char*));
    for(i=0;i<*n;i++)
    {
        fgets(sir,200,stdin);
        (*v)[i]=malloc(strlen(sir)+1);
        strcpy((*v)[i],sir);
    }
    free(sir);
}

int main()
{
    char **vp,*s,*s1;
    int n;
    citire(&vp,&s,&s1,&n);
    modificare(&vp,s,s1,n);
    eliberare(vp,n);
    free(s);
    free(s1);
    return 0;
}
