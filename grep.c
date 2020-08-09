 #include <stdio.h>

 #include <string.h>

 #include <stdlib.h>

// aflam numarul de aparitii ale cuvantului in sir pe care il vom modifica
 int aparitii(char * s, char * s1) {
   int i = 0, nr = 0;
   while (s[i] != 0) {
     if (strstr( & s[i], s1) == & s[i]) {
       nr++;
       i = i + strlen(s1) - 1;
     }
     i++;

   }
   return nr;
 }

 // in aceasta functie vom afisa noul sir obtinut prin inlocuirea aparitiilor lui s1 cu s2
 void cuvant(char * s, char * s1, char * s2) {
     //ne vom folosi de vectorul alocat dinamic sir in care vom retine sirul s modificat
   char * sir;
   //vom afla numarul de aparitii a lui s1 in s si daca exista in sir, va urma sa-l modificam
   int nr = aparitii(s, s1), i = 0, j = 0,flag=0,k;
   if (nr != 0) {
       sir = malloc((strlen(s) + 1 + nr * (10))*sizeof(char));
       while(s[i]!='\0')
       {
       flag=1;
       //parcurgem elementele sirului s1 si verificam daca acestea sunt egale cu cele ale lui s
       //ne vom folosi de un flag care sa ne arate daca sirul s1 exista in s
      for(k=0;s1[k]!='\0'&& flag==1;k++)
                if(s[i+k]!=s1[k]) flag=0;
                // daca acesta exista copiem la adresa lui sir[j] sirul s2
                if(flag==1) {
                    strcpy(&sir[j],s2);
                    i+=strlen(s1);
                    j+=strlen(s2);
                            }
                else sir[j++]=s[i++];
       }
       //ne asiguram sa punem terminatorul de sir
        sir[j] = '\0';
     printf("%s",sir);
     free(sir);
   }
   } 
 
 //in aceasta functie vom efectua citirea matricei de cuvinte, a cuvantului pe care il vom modifica s1
 // si a cuvantului cu care vom inlocui aparitiile primului s2
 void citire(char ** * v, char ** s1, char ** s2, int * n) {
    //vectorul sir e cu rolul de a ne ajuta sa facem citirea componentelor matricei, dar si a lui s2
   char * sir;
   int i;
   //alocam dinamic vectorii si citim vectorul s1 si n numarul de linii ale matricei
   * s1 = (char * ) malloc(31);
   * s2 = (char * ) malloc(50);
   sir = (char * ) malloc(201);
   fgets(( * s1), 200, stdin);
   ( * s1)[strlen(( * s1)) - 1] = '\0';
   scanf("%d", n);
   //construim s2 cu ajutorul lui s1, adaugand caracterele necasare pentru colorare
   strcpy(sir, "\e[0;31m");
   strcat(sir, * s1);
   strcat(sir, "\e[m");
   strcpy( * s2, sir);
   fgets(sir, 200, stdin);
   //in final facem alocam dinamic memorie pentru v si citim componentele vectorului 
   * v = (char ** ) malloc(( * n) * sizeof(char * ));
   for (i = 0; i < * n; i++) {
     fgets(sir, 200, stdin);
     ( * v)[i] = malloc(strlen(sir) + 1);
     strcpy(( * v)[i], sir);
   }
   free(sir);
 }

 //functie cu rolul de a elibera memoria utilizata
 void eliberare(char ** v, int n)
{
  int i;
  for (i = 0; i < n; i++)
    free(v[i]);
  free(v);
 
}

 int main() {
   char ** v, * s1, * s2;
   int n, i;
   citire( & v, & s1, & s2, & n);
   for (i = 0; i < n; i++)
     cuvant(v[i], s1, s2);
   //eliberam atat memoria matricei , cat si a cuvintelor 
   free(s1);
   free(s2);
    eliberare(v,n);
   return 0;
 }
