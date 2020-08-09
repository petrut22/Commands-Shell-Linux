# Commands-Shell-Linux
This Project has implemented some important commands like grep cut 

Task 1
- Timp de implementare: 4 ore
- Problema are la baza modificarea unei matrici alocate dinamic cu ajutorul operatiilor pe siruri de caractere
- Am folosit o functie speciala pentru citirea matricei, a sirului ce trebuie modificat, dar si a unui sir obtinut pe baza primului, cu ajutorul caracterelor speciale adaugate care ii asigura culoare
- Pe langa functia de citire am folosit si o functie care sa numere de cate ori apare sirul ce trebuie schimbat pe fiecare linie in parte, a matricei
- La modificare, am declarat un vector care retine continutul unei linii, modificat. 
- Eliberarea memoriei s-a facut cu ajutorul unei functii fara tip

Task 2
- Timp de implementare: 10 ore
- Problema este modularizata in 5 functii( impreuna cu main-ul ) si foloseste functii din biblioteca stdlib.h si string.h.
- Citirea datelor s-a efectuat in 2 functii cu rol de a usura citirea codului. La prima functie, s-au citit delimitatorii in vectori alocati static, iar indicii, intr-un vector de int-uri. In a doua functie, s-au citit componentele matricei.
- Partea de modificare a fost asigurata de o functie fara tip care s-a bazat pe fragmentarea fiecarui sir din matrice cu ajutorul functiei strtok. De asemenea am folosit si functii cum ar fi strcat si strcpy pentru a usura construirea noului sir de afisat.
- La final am eliberat memoria utilizata pentru rezolvarea taskului.
- Au existat cateva probleme atat la fisiere ( checkerul imi arata ca nu merge programul pentru test-ul 7, in conditiile in care era corect), cat si la folosirea valgrindului: la un moment dat am avut 4 567 556 de erori, dar in final am rezolvat:)
.
Task 3
- Timp de implementare: 3 ore.
- Programul este structurat in 5 functii( impreuna cu main-ul ) si are rolul de a sorta o matrice in functie de primul element al fiecarei linii.
- In functia alocarematrice s-au citit componentele matricei, avand la baza alocare dinamica.Pentru fiecare linie s-a alocat atata memorie cat era necesar. S-au folosit functiile malloc si realloc pentru asigurarea alocarii.
- Citirea numerelor s-a facut pana la valoarea 0,nu a fost adaugata aceasta valoare( introducerea lor s-a facut de la pozitia 1, deoarece pe pozitiile de 0 s-au retinut mediile).
- Sortarea componentelor matricei s-a asigurat cu metoda de sortare bule.
- In final s-a afisat matricea si apoi s-a eliberat memoria. 

Task 4
- Timp de implementare: 3 ore.
- Programul este structurat in 4 functii( impreuna cu main-ul ) si are rolul de a codifica
anumite caractere ale unui text.
- In cazul acestei probleme, am folosit o matrice in care am retinut pe fiecare linie sirurile din fisier. Citirea acesteia s-a realizat in functia fara tip citirematrice. 
- In functia modificare, a fost analizata fiecare linie in parte si s-a folosit functia strtok pentru sectionarea ei in cuvinte.
- S-a analizat intr-o structura repetitiva daca cuvantul este un numar, iar daca conditia nu era satisfacuta, urma sa fie codificat in structura repetitiva urmatoare. Afisarea noilor siruri se face tot in cadrul acestei functii.
- In final s-a eliberat memoria.
- Problemele intampinate au fost in cadrul valgrindului care nu afisa erorile de pe liniile codului
- O alta problema a fost in unele fisiere care contineau spatii pe anumite linii, insa dupa ce s-a facut update la checker am reusit sa termin task-ul.
