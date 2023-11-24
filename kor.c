#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>


#define BLACK_TEXT "\033[30m"
#define RED_TEXT "\033[31m"
#define GREEN_TEXT "\033[32m"
#define YELLOW_TEXT "\033[33m"
#define BLUE_TEXT "\033[34m"
#define MAGENTA_TEXT "\033[35m"
#define CYAN_TEXT "\033[36m"
#define WHITE_TEXT "\033[37m"
#define RESET_TEXT "\033[0m"

#define max_jatekoszam 8
#define max_char_hossz 17

#define max_char_hossz_foglalkozas 12
#define max_char_hossz_eloelet 15
#define max_char_hossz_csaladi_allapot 13
#define max_char_hossz_politikai_beallitottsag 14

#define db_foglalkozas 20
#define db_csaladi_allapot 6
#define db_politikai_beallitottsag 10
#define db_eloelet 11

#define ido_kilepes 5

typedef struct {
    int id;
	char nev[max_char_hossz];
	int kor;
    char foglalkozas[max_char_hossz_foglalkozas];
	char csaladi_allapot[max_char_hossz_csaladi_allapot];
	char eloelet[max_char_hossz_eloelet];
	char politika[max_char_hossz_politikai_beallitottsag];
	int kinezet;
	int el;

} jatekosok;

void pr_start(){
	printf("Jatek tortenete. Bevezeto.\n");
}

void pr_jatekosok(jatekosok *jatekos, int jatekos_szam){
	for (int i = 0; i < jatekos_szam; i++)
	{
	if (jatekos[i].el == 1)
	{
		printf(BLUE_TEXT);
	} else if(jatekos[i].el == 0){
		printf(RED_TEXT);
	}
	printf("ID %d ", jatekos[i].id);
	printf("Nev %s ", jatekos[i].nev);
	printf("Kor %-2d ", jatekos[i].kor);
	printf("Foglalkozas %-*s ",max_char_hossz_foglalkozas, jatekos[i].foglalkozas);
	printf("Csaladi allapot: %-*s ", max_char_hossz_csaladi_allapot, jatekos[i].csaladi_allapot);
	printf("Eloelet %-*s ", max_char_hossz_eloelet, jatekos[i].eloelet);
	printf("Politika %-*s",max_char_hossz_politikai_beallitottsag, jatekos[i].politika);
	printf("Kinezet %d\n", jatekos[i].kinezet);
	printf(RESET_TEXT);
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

void sc_nevek(jatekosok *jatekos,int jatekos_szam){
	printf(YELLOW_TEXT"Kerem a jatekosnevekket.\n");
	printf(BLUE_TEXT);
	for (int i = 0; i < jatekos_szam; i++)
	{
		printf("%d. jatekos: ", i + 1);
		scanf("%s", jatekos[i].nev);
	}
	system("cls");
	
}

void generalas(jatekosok *jatekos, int jatekos_szam){

	const char foglalkozasok[][max_char_hossz_foglalkozas] = {
		"Programozo", "Mernok", "Orvos", "Apolo", "Autoszerelo",
		"Pekek", "Ugyved", "Tanar", "Epitesz", "Grafikus",
		"Pincer", "Komuves", "Konyvelo", "Fogorvos", "Kertesz",
		"Festo", "Muvesz", "Szobafesto", "Asztalos", "Szakacs"
	};
	const char csaladi_allapotok[][max_char_hossz_csaladi_allapot] = {
	"Hazas", "Elvalt", "Ozvegy",
	"Egyedulallo", "Kapcsolatban", "Gyerektelen",
	};
	const char politikai_beallitottsagok[][max_char_hossz_politikai_beallitottsag] = {
		"Anarchista", "Nacionalista", "Totalitarista", "Szeparatista", "Szupremacista",
		"Forradalmar", "Autokrata", "Radikalis", "Szelsojobb", "Szelsobal"
	};
	const char eloeletek[][max_char_hossz_eloelet] = {
		"Ismeretlen","Ismeretlen","Ismeretlen","Ismeretlen","Ismeretlen","Ismeretlen"
		,"2 embert olt","Gyereket olt","Terrorista","Drogdiller","Haborus hos"
	};

	srand((unsigned int)time(NULL));

	for (int i = 0; i < jatekos_szam; i++)
	{
		jatekos[i].id = i + 1;
		jatekos[i].kor = rand() % 100 + 1;
		strcpy(jatekos[i].foglalkozas, foglalkozasok[rand() % db_foglalkozas]);
		strcpy(jatekos[i].csaladi_allapot, csaladi_allapotok[rand() % db_csaladi_allapot]);
		strcpy(jatekos[i].eloelet, eloeletek[rand() % db_eloelet]);
		strcpy(jatekos[i].politika, politikai_beallitottsagok[rand() % db_politikai_beallitottsag]);
		jatekos[i].kinezet = rand() % 10 + 1;
		jatekos[i].el = 1;
	}
}

int valaszto(){
	int i = -1;
	printf(YELLOW_TEXT"Kerlek valassz a lehetosegek kozul.\n");
	printf(RED_TEXT"Kilepes: 0 ");
	printf(CYAN_TEXT"Kiiratas 1 ");
	printf(GREEN_TEXT"Szavazas: 2\n");
	printf(RESET_TEXT);
	while (i < 0 || i > 3)
	{
		scanf("%d", &i);
	}
	return i;
}

void kilepes(){
	printf(YELLOW_TEXT"Koszonom hogy a jatekommal jatszottal.\n");
	printf(YELLOW_TEXT"Keszito: ");
	printf(CYAN_TEXT"Nagy Csanad\n");
	printf(RESET_TEXT);
	printf(" \n");
	for (int i = 0; i < ido_kilepes; i++)
	{
				printf("A kilepesig ennyi ido van vissza: %d\n", ido_kilepes - i);
		printf("\x1b[1F");		
		Sleep(1000);
	}
	printf("\x1b[2K");//nullazza az adott sor karaktereit
	printf(RED_TEXT"Kilepett");
	printf(RESET_TEXT);
}
int szavazas(jatekosok *jatekos, int jatekos_szam,int db_jatekosok_elok){
	system("cls");
	pr_jatekosok(jatekos, jatekos_szam);
	


	return db_jatekosok_elok;
}

int main()
{
	jatekosok *jatekos = (jatekosok *)malloc(max_jatekoszam * sizeof(jatekosok)); //jatekos[4].nev
	pr_start();
	int jatekos_szam = sc_jatekosszam();
	sc_nevek(jatekos, jatekos_szam);
	generalas(jatekos, jatekos_szam);
	int db_jatekosok_elok = jatekos_szam;
	int input = valaszto();
	while (db_jatekosok_elok > 1)
	{
		if (input == 0)
		{
			kilepes();
			return 0;
		}
		if (input == 1)
		{
			system("cls");
			pr_jatekosok(jatekos, jatekos_szam);
			input = valaszto();
		}
		if (input == 2)
		{
			db_jatekosok_elok = szavazas(jatekos, jatekos_szam,db_jatekosok_elok);
			if (db_jatekosok_elok < 3)
			{
				break;
			}
			input = valaszto();
			
			
		}
		
	}
	
	pr_jatekosok(jatekos, jatekos_szam);

	return 0;
}