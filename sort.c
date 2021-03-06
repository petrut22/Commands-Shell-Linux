#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define NMAX 3
void bule(float ** v, int n, int * nr) //aplicam algoritmul de sortare bubble sort pe matricea v
{
  int flag = 1, aux, i;
  float * p;
  while (flag) {
    flag = 0;
    for (i = 0; i < n - 1; i++)
	//comparam mediile de pe fiecare linie si dupa interschimbam adresele lor
      if (v[i][0] < v[i + 1][0]) { 
        p = v[i];
        v[i] = v[i + 1];
        v[i + 1] = p;
        aux = nr[i];
        nr[i] = nr[i + 1];
        nr[i + 1] = aux;
        flag = 1;
      }

  }
}
//afisam matricea de note
void afisare(float ** v, int n, int * nr) 
{
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < nr[i]; j++)
      if (j == 0) printf("%-10.3f", v[i][j]);
      else if (j != nr[i] - 1) printf("%.0f ", v[i][j]);
    else printf("%.0f", v[i][j]);
    if (i != n) printf("\n");
  }

}
//functie cu rolul de a elibera memoria utilizata
void eliberare(float ** v, int n, int * nr) 
{
  int i;
  for (i = 0; i < n; i++)
    free(v[i]);
  free(v);
  free(nr);
}
//functie cu rolul de a citi matricea cu elemente si de a aloca dinamic
void alocarecitire(float ** * v, int n, int ** nr)
{
  int i, m, n_crt;
  float x, s;
  * v = (float ** ) malloc(n * sizeof(float * ));
  * nr = (int * ) malloc(n * sizeof(int));
  //vectorul nr e cu rolul de a retine cate elemente se afla pe o linie 
  if (v != NULL) {
    for (i = 0; i < n; i++) {
      s = 0;
      m = NMAX;
	  //n_crt numarul curent de elemente. Incepem de la 1 pentru ca pe pozitia 0 retinem media notelor
      n_crt = 1;
      ( * v)[i] = (float * ) malloc(n * sizeof(float));
      scanf("%f", & x);
	  //facem citirea pana la intalnirea valorii 0 (nu o punem in vector)
      while (x != 0) { 
        if (m == n_crt) {
          m = m + NMAX;
          ( * v)[i] = (float * ) realloc(( * v)[i], m * sizeof(float));
        }
        ( * v)[i][n_crt] = x;
        n_crt++;
        s += x;
        ( * nr)[i] = n_crt;
		//calculam media notelor
        ( * v)[i][0] = s / (float)(n_crt - 1); 
        scanf("%f", & x);
      }
    }
  }

}

int main() {
  float ** v;
  int * nr, n;
  //citim numarul de linii
  scanf("%d", & n);
  alocarecitire( & v, n, & nr);
  bule(v, n, nr);
  afisare(v, n, nr);
  eliberare(v, n, nr);
  return 0;
}
