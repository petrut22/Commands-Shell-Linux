#include <stdio.h>

#include <stdlib.h>

#include <string.h>

void modificare(char * s, int n) {
  char sir[201], * p, flag;
  int i;
  //vectorul sir e cu rolul de a afisa continutul criptat. Trebuie sa-l initializam cu 0
  sir[0] = '\0';
  //apelam functia strtok cu rolul de a cripta fiecare cuvant obtinut, respecand conditiile problemei 
  p = strtok(s, " ");
  while (p != NULL) {
      //retinem copia lui p in sir 
    strcpy(sir, p);
    flag = 1;
    // in urma pacurgerii lui p aflam daca string-ul este un numar sau nu, prin intermediul variabilei flag
    for (i = 1; p[i] != '\0'; i++) {
        //ne asiguram ca p[i] nu este '\n' pentru ca nu trebuie modificat sau sa influenteze conditia
      if (p[i] != '\n')
      //toate caracterele cu codul ASCII intre 48 si 57 sunt cifre de la 0 la 9. 
      //Daca un caracter din cuvant nu se afla in acest interval inseamna ca trebuie sa modificam cuvantul
        if (p[0] < 48 || p[0] > 57 || p[i] < 48 || p[i] > 57) {
          flag = 0;
          break;
        }

    }
    //daca flag=0 inseamna ca trebuie sa modificam cuvantul
    if (flag == 0)
      for (i = 1; p[i] != '\0'; i++) {
          // p[i] trebuie sa fie diferit de '\n' 
        if (p[i] != '\n')
          sir[i] = (sir[i] + sir[0]) % 256;

      }
    //La afisarea cuvantului trebuie sa ne asiguram ca nu este ultimul de pe linie(pentru ca nu vrem sa-i punem spatiu)
    if (sir[strlen(sir) - 1] != '\n') {
      if (sir[0] != '\n')
        printf("%s ", sir);
    } else printf("%s", sir);

    p = strtok(NULL, " ");
  }

}
//functie cu rolul de a citi o matrice 
void citirematrice(char ** * v, int n) {
  char * sir;
  //alocam dinamic vectorul sir cu rolul de a insera sirul de pe fiecare linie
  sir = (char * ) malloc(200 * sizeof(char));
  int i;
  //alocam dinamic matricea de string-uri
  * v = (char ** ) malloc(n * sizeof(char * ));
  for (i = 0; i < n; i++) {
      //citim la fiecare pas sirul de pe fiecare linie
    fgets(sir, 200, stdin);
    ( * v)[i] = (char * ) malloc((strlen(sir) + 1) * sizeof(char));
    //copiem continutul sirului in  matrice pe linia i
    strcpy(( * v)[i], sir);
  }
  free(sir);
}
//functie cu rolul de a elibera memoria utilizata
void eliberare(char ** v, int n) 
{
  int i;
  for(i = 0; i < n; i++)
    free(v[i]);
  free(v);
}
int main() {
  int n, i;
  char ** v;
  scanf("%d", & n);
  //folosim getchar() ca sa nu citim '\n'
   getchar();
  citirematrice( & v, n);
for(i = 0; i < n; i++)
    modificare(v[i], n);
    eliberare(v,n);
  return 0;
}
