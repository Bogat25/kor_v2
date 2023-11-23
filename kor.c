#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


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

void pr_start(){
	printf("Jatek tortenete. Bevezeto.\n");
}
int sc_jatekosszam(){
	int a;
	scanf("%d", &a);
	return a;
}
int main()
{
	pr_start();
	int jatekos_szam = sc_jatekosszam();
	printf("%d",jatekos_szam);

	return 0;
	//egyáltalán nincs még befejezve
	//hiányoznak: dinamikus tömbök, indexelhető struktura a statoknak

	//Generálás
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
		"Artatlan","Artatlan","Artatlan","Artatlan","Artatlan","Artatlan"
		,"2 embert olt","Gyereket olt","Terrorista","Drogdiller","Haborus hos"
	};

}