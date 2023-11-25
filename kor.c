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
#define ido_szavazas 5

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
	int szavazat;
	int kapott_szavazat;

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

void pr_szabalyok(){
	system("cls");
	printf(MAGENTA_TEXT"Csak 1 nyertes lehet.\n");
	printf("A szavazas utolso fordulojaban ha 2 jatekos maradt eletben akkor kozottuk veletlenszeruen sorsoljuk ki a nyertest.\n");
	printf("Aki nem szavaz idoben az kiesett.\n");
	printf("Akikre ugyanannyi szavazat esik egy korben azok mind kiesnek.\n");
	printf(RESET_TEXT);
}
void pr_nyertes(jatekosok *jatekos, int jatekos_szam){
	for (int i = 0; i < jatekos_szam; i++)
	{
		if (jatekos[i].el == 1)
		{
			printf(YELLOW_TEXT"A nyertesunk %s\n", jatekos[i].nev); printf(RESET_TEXT);
			printf(MAGENTA_TEXT"Gratulalunk a gyozelemhez, sikerult bebizonyitanod hogy te vagy a legertekesebb a tarsadalom szamara."); printf(RESET_TEXT);
		}
		
	}
	
}
void pr_mindenki_kiesett(){
	printf(RED_TEXT"Mindenkit kiszavaztatok, így nincs nyertesünk csak sok, sok vesztesünk."); printf(RESET_TEXT);
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

int sc_eles_jatszma(){
	int eles_jatszma = -1;
	printf(YELLOW_TEXT"Gyakorolni szeretnel vagy elesben jatszani?\n");
	printf(GREEN_TEXT"Gyakorolni 0 ");
	printf(CYAN_TEXT"Elesben 1\n");printf(RESET_TEXT);
	while (eles_jatszma < 0 || eles_jatszma > 1)
	{
		scanf("%d", &eles_jatszma);
	}
	return eles_jatszma;
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
		jatekos[i].szavazat = -1;
		jatekos[i].kapott_szavazat = 0; 
	}
}

int valaszto(){
	int i = -1;
	printf(YELLOW_TEXT"Kerlek valassz a lehetosegek kozul.\n");
	printf(RED_TEXT"Kilepes: 0 ");
	printf(CYAN_TEXT"Kiiratas 1 ");
	printf(GREEN_TEXT"Szavazas: 2 ");
	printf(CYAN_TEXT"Szabalyok: 3\n");
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
int szavazas_szamlalo(jatekosok *jatekos, int jatekos_szam,int db_jatekosok_elok){
	for (int i = 0; i < jatekos_szam; i++)
	{
		if (jatekos[i].el == 1)
		{
			if (jatekos[i].szavazat == i + 1)
			{
				jatekos[i].el = 0;
				printf(RED_TEXT"%s jatekos kiesett mert magara szavazott.\n", jatekos[i].nev); printf(RESET_TEXT);
			}
			else if (jatekos[i].szavazat > jatekos_szam || jatekos[i].szavazat < 1)
			{
				jatekos[i].el = 0;
				printf(RED_TEXT"%s jatekos kiesett mert ervenytelen szavazatot adott le.\n", jatekos[i].nev); printf(RESET_TEXT);
			}else{
				jatekos[jatekos[i].szavazat - 1].kapott_szavazat++;
			}
		}
		
	}
	int max_szavazat = 0; //komment, nincs kezelve az ha 2 játékos egyenlő mennyiségü szavazatot kap
	for(int i = 0; i < jatekos_szam;i++){
		if (jatekos[i].kapott_szavazat > max_szavazat)
		{
			max_szavazat = jatekos[i].kapott_szavazat;
		}
	}

	for(int i = 0; i < jatekos_szam;i++){
		if (jatekos[i].kapott_szavazat == max_szavazat && jatekos[i].el == 1)
		{
			printf(RED_TEXT"%-*s jatekost kiszavaztak.\n",max_char_hossz,jatekos[i].nev); printf(RESET_TEXT);
			jatekos[i].el = 0;
		}
		
	}

	db_jatekosok_elok = 0;
	for (int i = 0; i < jatekos_szam; i++)
	{
		if (jatekos[i].el == 1)
		{
			db_jatekosok_elok++;
		}
		 
	}
	for (int i = 0; i < jatekos_szam; i++)
	{
		jatekos[i].szavazat = -2;
	}
	
	return db_jatekosok_elok;
}

int sc_szavazas(jatekosok *jatekos, int jatekos_szam,int db_jatekosok_elok){
	system("cls");
	pr_jatekosok(jatekos, jatekos_szam);
	printf(YELLOW_TEXT"Szavazas kezdete.\n");
	printf(RED_TEXT"Csak %d mp-etek lessz szavazni. (aki nem szavaz az idon bellul az meghal)\n", ido_szavazas);
	printf(RESET_TEXT);
	for (int i = 0; i < jatekos_szam; i++)
	{
		if (jatekos[i].el == 1)
		{
		printf(CYAN_TEXT"%-*s ", max_char_hossz, jatekos[i].nev);
		scanf("%d", &jatekos[i].szavazat);
		if (jatekos[jatekos[i].szavazat - 1].el != 1) //ha halottra szavaz akkor kiesik
		{
			jatekos[i].szavazat = 0;
		}
		
		}
		else{}
	}
	db_jatekosok_elok = szavazas_szamlalo(jatekos,jatekos_szam,db_jatekosok_elok);
	return db_jatekosok_elok;
}
int ujrainditas(jatekosok *jatekos, int jatekos_szam, int db_jatekosok_elok){
	generalas(jatekos,jatekos_szam);
	db_jatekosok_elok = jatekos_szam;
	return db_jatekosok_elok;
}

int sc_ujrainditas(jatekosok *jatekos,int jatekos_szam, int db_jatekosok_elok){
	int input = 0;
	printf(CYAN_TEXT"\nSzeretnetek ujrakezdeni a jatekot?\n");
	printf(GREEN_TEXT"Igen 1 ");
	printf(MAGENTA_TEXT"Nem 2\n");
	printf(RESET_TEXT);
	while (input < 1 || input > 2)
	{
		scanf("%d", &input);
	}
	if(input == 1){
		db_jatekosok_elok = ujrainditas(jatekos,jatekos_szam,db_jatekosok_elok);
		return db_jatekosok_elok;
	}
	else if(input == 2){
		kilepes();
		return 0;
	}
}

int nyertes_sorsolas(jatekosok *jatekos,int jatekos_szam, int db_emberek_elok){
	int jatekosok_eloek_index[2];
	int n = 0;
	for (int i = 0; i <jatekos_szam; i++)
	{
		if(jatekos[i].el == 1){
			jatekosok_eloek_index[n] = i;
			n++;
		}
	}
	//kisorsolja ki esik ki
	int sorsolas = rand() % 2;
	jatekos[jatekosok_eloek_index[sorsolas]].el = 0;
	db_emberek_elok--;
	return db_emberek_elok;
}



int main()
{
	jatekosok *jatekos = (jatekosok *)malloc(max_jatekoszam * sizeof(jatekosok)); //jatekos[4].nev
	pr_start();
	int jatekos_szam = sc_jatekosszam();
	sc_nevek(jatekos, jatekos_szam);
	int db_jatekosok_elok = jatekos_szam;
	int jatekban = 1;
	int eles_jatszma = 0;
	eles_jatszma = sc_eles_jatszma();
	int input;
	if (eles_jatszma == 1)
	{
		input = 2;
	}else if(eles_jatszma == 0){
	input = valaszto();
	}
	
	while (jatekban == 1)
	{
		generalas(jatekos, jatekos_szam);
		while (eles_jatszma == 1)
		{
				while (db_jatekosok_elok > 2)
			{
				if (input == 2)
				{
					db_jatekosok_elok = sc_szavazas(jatekos, jatekos_szam,db_jatekosok_elok);
					if (db_jatekosok_elok < 3)
					{
						break;
					}
				}
			}
			if(db_jatekosok_elok == 2)
			{
				db_jatekosok_elok = nyertes_sorsolas(jatekos, jatekos_szam, db_jatekosok_elok);
			}
			while (db_jatekosok_elok == 1)
			{
				pr_nyertes(jatekos, jatekos_szam);
				db_jatekosok_elok = sc_ujrainditas(jatekos,jatekos_szam, db_jatekosok_elok);
				break;
			}
			if (db_jatekosok_elok == 0)
			{
				pr_mindenki_kiesett();
				db_jatekosok_elok = sc_ujrainditas(jatekos,jatekos_szam, db_jatekosok_elok);
				break;
			}
		}
		
		while (db_jatekosok_elok > 2)
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
				db_jatekosok_elok = sc_szavazas(jatekos, jatekos_szam,db_jatekosok_elok);
				if (db_jatekosok_elok < 3)
				{
					break;
				}
				input = valaszto();
			}
			if (input == 3){
				pr_szabalyok();
				input = valaszto();
			}
		}
		if(db_jatekosok_elok == 2)
		{
			db_jatekosok_elok = nyertes_sorsolas(jatekos, jatekos_szam, db_jatekosok_elok);
		}
		while (db_jatekosok_elok == 1)
		{
			pr_nyertes(jatekos, jatekos_szam);
			db_jatekosok_elok = sc_ujrainditas(jatekos,jatekos_szam, db_jatekosok_elok);
			break;
		}
		if (db_jatekosok_elok == 0)
		{
			pr_mindenki_kiesett();
			db_jatekosok_elok = sc_ujrainditas(jatekos,jatekos_szam, db_jatekosok_elok);
			break;
		}
	}
}