#include <stdio.h>

#include <stdlib.h>

#include <string.h>

//functia afiseaza cuvintele asociate indiciilor din vecotrul nr
void modificare(char * s, char * del, char * out_del, int * nr, int n) {
  char sir[201], * p;
  //count numara cate cuvinte au fost citite
  int j, count = 0;
  //ne asiguram ca sir sa nu contina caractere
  sir[0] = '\0';
  //ne vom folosi de strtok pentru citirea cuvintelor de pe o lnie
  p = strtok(s, del);
  while (p != NULL) {
    count++;
    //vedem daca indicile cuvantului se regaseste in vector. Daca da, atunci il vom pune in sir
    for (j = 0; j < n; j++)
      if (count == nr[j]) {
          //in cazul in care nu are caractere copiem continul din p in sir
          // iar daca are, copiem in continuarea lui continului din p
        if (sir[0] == '\0') strcpy(sir, p);
        else strcat(sir, p);
        // la final punem delimitatorul out_del
        strcat(sir, out_del);
        //exista posibilitatea sa apara indici de aceeasi valoare, iesim din structura la prima gasire
        break;
      }
    p = strtok(NULL, del);
  }
  //trebuie sa stergem out_del-ul de la finalul sirului
  sir[strlen(sir) - strlen(out_del)] = '\0';
  printf("%s\n", sir);

}
//functie cu rolul de a citi del, out_del, vectorul nr care retine indicii coloanelor,
// n numarul de indici si m nr de siruri
void citire(char * del, char * out_del, int ** nr, int * n, int * m) {
  char * sir, in ;
  int i;
  //vom folosi vectorul sir pentru a retine sirurile care in final vor fi puse in matrice
  //il vom aloca dinamic:)
  sir = malloc(200 * sizeof(char));
  //facem mai intai citirea lui del 
  fgets(sir, 200, stdin);
  sir[strlen(sir) - 1] = '\0';
  //copiem continutul lui sir in del
  strcpy(del, sir);
  scanf("%d", n);
  * nr = (int * ) malloc(( * n) * sizeof(int));
  
  //in aceasta structura repetitiva vom citi indicii coloanelor cu care ne vom folosi la afisare
  for (i = 0; i < ( * n); i++) {
    scanf("%d", & ( * nr)[i]);
    //in caracterul in vom citi virgula
    scanf("%c", & in );
  }

  fgets(sir, 200, stdin);
  sir[strlen(sir) - 1] = '\0';
  strcpy(out_del, sir);
  scanf("%d", m);
  getchar();
  free(sir);
}
//in aceasta functie citim componentele matricei
void citirematrice(char ** * v, int m) {
  char * sir;
  sir = (char * ) malloc(200 * sizeof(char));
  int i;
  * v = (char ** ) malloc(m * sizeof(char * ));
  for (i = 0; i < m; i++) {
    fgets(sir, 200, stdin);
    sir[strlen(sir) - 1] = '\0';
    ( * v)[i] = (char * ) malloc((strlen(sir) + 1) * sizeof(char));
    strcpy(( * v)[i], sir);
  }
  free(sir);
}
//eliberam memoria din matrice
void eliberare(char ** v, int m) {
  int i;
  for (i = 0; i < m; i++)
    free(v[i]);
  free(v);

}

int main() {
  char del[10], out_del[10], ** v;
  int n, m, * nr, i;
  citire(del, out_del, & nr, & n, & m);
  citirematrice( & v, m);
  for (i = 0; i < m; i++)
    modificare(v[i], del, out_del, nr, n);
  eliberare(v, m);
  free(nr);

  return 0;
}
