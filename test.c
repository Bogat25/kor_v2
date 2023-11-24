#define _CRT_SECURE_NO_WARNINGS //itt tesztelem az új ismereteket
#include <stdio.h>
#include <stdlib.h>

#define max_jatekoszam 8
#define max_char_hossz 17

#define max_char_hossz_foglalkozas 12


typedef struct {
    int id;
	char nev[max_char_hossz];

	int kinezet;

} jatekosok;

void generalas(jatekosok *jatekos, int jatekos_szam){
	for (int i = 0; i < jatekos_szam; i++)
	{
		jatekos[i].id = i + 1;
	}
}

int sc_jatekosszam(){
	int a = 0;
    while (a < 3 || a > 8)
    {
	scanf("%d", &a);
    }
	return a;
}


int main()
{
    jatekosok *jatekos = (jatekosok *)malloc(max_jatekoszam * sizeof(jatekosok)); //jatekos[4].nev
	int jatekos_szam = sc_jatekosszam();
	generalas(jatekos, jatekos_szam);

    for (int i = 0; i < jatekos_szam; i++)
    {
    printf("%d", jatekos[i].id);
    }
    
	return 0;
}