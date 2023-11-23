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


int main()
{
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

float speed_gondolkodni = 0;
	while (speed_gondolkodni < 1 || speed_gondolkodni > 500)
	{
		printf(CYAN_TEXT"Mennyi idot szeretnetek gondolkodni?\n");
		printf(RESET_TEXT);
		scanf("%f", &speed_gondolkodni);
	}
	speed_gondolkodni++;

	float speed_szavazni = 0;
	while (speed_szavazni < 1 || speed_szavazni > 500)
	{
		printf(CYAN_TEXT"Milyen gyors legyen a szavazas? \n");
		printf(RESET_TEXT);
		scanf("%f", &speed_szavazni);
	}
	speed_szavazni++;
	system("cls");

	int jatekos_szam = 0;
	printf(YELLOW_TEXT"Udvozollek a kor nevu jatekban.\n");
	printf(RESET_TEXT);
	printf(BLUE_TEXT"v07\n");
	printf(RESET_TEXT);

	printf(MAGENTA_TEXT"A Fold az emberiseg tulnepesedese miatt szorult egy veszhelyzeti beavatkozasra.\nA vilag vezetoi osszegyultek es ugy dontottek,\nhogy csak egy kivalasztott csoport szamara biztosithato a tuleles, ezzel megmentve az emberiseget a kihalastol.\n");
	printf("Rajtatok all a felelosseg hogy eldontsetek melyikotok a leginkabb erdemes az eletre.\n");
	printf("\n");
	printf(RESET_TEXT);

	while (jatekos_szam < 3 || jatekos_szam > max_jatekoszam)
	{
		printf(CYAN_TEXT"Hanyan szeretnetek jatszani? 3-8 (fo)\n");
		printf(RESET_TEXT);
		scanf("%d", &jatekos_szam);
	}

	printf(CYAN_TEXT"Kerem a jatekos neveket (egyedieket):\n");
	printf(RESET_TEXT);
	char nevek[max_jatekoszam][max_char_hossz] = {0};
	for (int i = 0; i < jatekos_szam; i++)
	{
		scanf("%s", &nevek[i]);
	}
	system("cls");

	int
	srand((unsigned int)time(NULL));
	int jatekos_kor[max_jatekoszam];
	for (int i = 0; i < jatekos_szam; i++) {
		jatekos_kor[i] = rand() % 100 + 1;
	}
	char jatekos_foglalkozas[max_jatekoszam][max_char_hossz] = {};
	for (int i = 0; i < jatekos_szam; i++) {
		int random_index = (rand() % db_foglalkozas);
		strcpy(jatekos_foglalkozas[i], foglalkozasok[random_index]);
	}
	char jatekos_csaladi_allapot[max_jatekoszam][max_char_hossz] = {};
	for (int i = 0; i < jatekos_szam; i++) {
		int random_index = (rand() % db_csaladi_allapot);
		strcpy(jatekos_csaladi_allapot[i], csaladi_allapotok[random_index]);
	}
	int jatekos_kinezet[max_jatekoszam];
	for (int i = 0; i < jatekos_szam; i++) {
		jatekos_kinezet[i] = rand() % 10 + 1;
	}
	char jatekos_eloelet[max_jatekoszam][max_char_hossz_eloelet] = {};
	for (int i = 0; i < jatekos_szam; i++) {
		int random_index = (rand() % db_eloelet);
		strcpy(jatekos_eloelet[i], eloeletek[random_index]);
	}
	char jatekos_politikai_beallitottsag[max_jatekoszam][max_char_hossz] = {};
	for (int i = 0; i < jatekos_szam; i++) {
		int random_index = (rand() % db_politikai_beallitottsag);
		strcpy(jatekos_politikai_beallitottsag[i], politikai_beallitottsagok[random_index]);
	}


	//Generálás vége

	int kilepes = 0;
	int emberek_elok[max_jatekoszam] = { 0 };
	int emberek_szavazatok[max_jatekoszam] = { 0 };
	int jatekos_szavazat = 0;


	for (int i = 0; i < jatekos_szam; i++) { //elmenti a játékosokat
		emberek_elok[i] = 1;
	}
	int emberek_elok_index[max_jatekoszam] = { 0 };

	int db_emberek_elok = jatekos_szam;
	int db_emberek_elok_index = 0;
	int player_input = -2;

	int szavazat_szamlalo[max_jatekoszam] = { 0 }; //if 2-őhöz, a szavazáshoz
	int szavazat = 0;
	int szavazat_max = 0;


	int jatek_elkezdodott = 0;

	while (player_input < -1 || player_input > 10)
	{
		if (jatek_elkezdodott > 0)
		{
			player_input = 2;
		}
		while (player_input < -1 || player_input > 2) {
			printf(CYAN_TEXT"Kerlek valassz a lehetosegek kozul\n");
			printf(RESET_TEXT);
			printf(GREEN_TEXT"Jatekosok kiirasa: 1 ");
			printf(RESET_TEXT);
			printf(BLUE_TEXT"Szavazas: 2 ");
			printf(RESET_TEXT);
			printf(RED_TEXT"Kilepes: -1\n");
			printf(RESET_TEXT);
			scanf("%d", &player_input);
			jatek_elkezdodott++;
		}
		system("cls");
		if (player_input == 1) {
			for (int i = 0; i < jatekos_szam; i++) //kiiras
			{
				if (emberek_elok[i] == 1)
				{

					printf(BLUE_TEXT"ID: %d Nev: %-*s Kor: %-2d Foglalkozas: %-*s Csaladi allapot: %-*s Eloelet: %-*s Politika: %-*s Kinezet: %d\n" RESET_TEXT,
						i + 1, max_char_hossz, nevek[i], jatekos_kor[i],
						max_char_hossz_foglalkozas, jatekos_foglalkozas[i],
						max_char_hossz_csaladi_allapot, jatekos_csaladi_allapot[i],
						max_char_hossz_eloelet, jatekos_eloelet[i],
						max_char_hossz_politikai_beallitottsag, jatekos_politikai_beallitottsag[i],
						jatekos_kinezet[i]);
				}
				else if (emberek_elok[i] == 0)
				{

					printf(RED_TEXT"ID: %d Nev: %-*s Kor: %-2d Foglalkozas: %-*s Csaladi allapot: %-*s Eloelet: %-*s Politika: %-*s Kinezet: %d\n" RESET_TEXT,
						i + 1, max_char_hossz, nevek[i], jatekos_kor[i],
						max_char_hossz_foglalkozas, jatekos_foglalkozas[i],
						max_char_hossz_csaladi_allapot, jatekos_csaladi_allapot[i],
						max_char_hossz_eloelet, jatekos_eloelet[i],
						max_char_hossz_politikai_beallitottsag, jatekos_politikai_beallitottsag[i],
						jatekos_kinezet[i]);
				}
			}

			player_input = -2;
		}
		if (player_input == 2) {
			for (int i = 0; i < jatekos_szam; i++) //kiiras
			{
				if (emberek_elok[i] == 1)
				{

					printf(BLUE_TEXT"ID: %d Nev: %-*s Kor: %-2d Foglalkozas: %-*s Csaladi allapot: %-*s Eloelet: %-*s Politika: %-*s Kinezet: %d\n" RESET_TEXT,
						i + 1, max_char_hossz, nevek[i], jatekos_kor[i],
						max_char_hossz_foglalkozas, jatekos_foglalkozas[i],
						max_char_hossz_csaladi_allapot, jatekos_csaladi_allapot[i],
						max_char_hossz_eloelet, jatekos_eloelet[i],
						max_char_hossz_politikai_beallitottsag, jatekos_politikai_beallitottsag[i],
						jatekos_kinezet[i]);
				}
				else if (emberek_elok[i] == 0)
				{

					printf(RED_TEXT"ID: %d Nev: %-*s Kor: %-2d Foglalkozas: %-*s Csaladi allapot: %-*s Eloelet: %-*s Politika: %-*s Kinezet: %d\n" RESET_TEXT,
						i + 1, max_char_hossz, nevek[i], jatekos_kor[i],
						max_char_hossz_foglalkozas, jatekos_foglalkozas[i],
						max_char_hossz_csaladi_allapot, jatekos_csaladi_allapot[i],
						max_char_hossz_eloelet, jatekos_eloelet[i],
						max_char_hossz_politikai_beallitottsag, jatekos_politikai_beallitottsag[i],
						jatekos_kinezet[i]);
				}
			}
			int ido_1 = 0;								//várakozási idő
			clock_t eltelt_ido = 0;
			clock_t ido = time(NULL);
			ido = ido % 120 + 1;
			while (eltelt_ido < speed_gondolkodni)
			{
				ido_1 = eltelt_ido;
				eltelt_ido = (time(NULL) % 120 + 1) - ido;
				if (eltelt_ido > ido_1)
				{
					if (speed_gondolkodni - eltelt_ido + 1 != 0)
					{
						system("cls");
						for (int i = 0; i < jatekos_szam; i++) //kiiras
						{
							if (emberek_elok[i] == 1)
							{

								printf(BLUE_TEXT"ID: %d Nev: %-*s Kor: %-2d Foglalkozas: %-*s Csaladi allapot: %-*s Eloelet: %-*s Politika: %-*s Kinezet: %d\n" RESET_TEXT,
									i + 1, max_char_hossz, nevek[i], jatekos_kor[i],
									max_char_hossz_foglalkozas, jatekos_foglalkozas[i],
									max_char_hossz_csaladi_allapot, jatekos_csaladi_allapot[i],
									max_char_hossz_eloelet, jatekos_eloelet[i],
									max_char_hossz_politikai_beallitottsag, jatekos_politikai_beallitottsag[i],
									jatekos_kinezet[i]);
							}
							else if (emberek_elok[i] == 0)
							{

								printf(RED_TEXT"ID: %d Nev: %-*s Kor: %-2d Foglalkozas: %-*s Csaladi allapot: %-*s Eloelet: %-*s Politika: %-*s Kinezet: %d\n" RESET_TEXT,
									i + 1, max_char_hossz, nevek[i], jatekos_kor[i],
									max_char_hossz_foglalkozas, jatekos_foglalkozas[i],
									max_char_hossz_csaladi_allapot, jatekos_csaladi_allapot[i],
									max_char_hossz_eloelet, jatekos_eloelet[i],
									max_char_hossz_politikai_beallitottsag, jatekos_politikai_beallitottsag[i],
									jatekos_kinezet[i]);
							}
						}
						if (speed_gondolkodni - eltelt_ido != 0)
						{
							printf(CYAN_TEXT"A szavazas kezdeteig: %.0f", speed_gondolkodni - eltelt_ido);
							printf(RESET_TEXT);
						}
					}
					ido_1 = eltelt_ido;
				}
			}

			for (int i = 0; i < jatekos_szam; i++) //értékek nullázása
			{
				szavazat_szamlalo[i] = 0;
			}
			szavazat = -1;
			szavazat_max = 0;

			for (int i = 0; i < jatekos_szam; i++) //megtörténik a szavazás
			{
				if (emberek_elok[i] == 1) {
					while (emberek_elok[szavazat - 1] != 1)
					{
						ido = time(NULL);
						ido_1 = ido;
						printf(YELLOW_TEXT"\nA rendelkezesedre allo ido: %.0f", speed_szavazni); //befejezni
						printf(RESET_TEXT"\n");
						printf(GREEN_TEXT"\n%s", nevek[i]);
						printf(RESET_TEXT);
						printf(CYAN_TEXT" kire szavazol: ");
						printf(RESET_TEXT);
						while (speed_szavazni < ido_1 && emberek_elok[szavazat - 1] != 1)
						{
							ido_1 = time(NULL) - ido_1;
							scanf("%d", &szavazat);
						}
						if (emberek_elok[szavazat - 1] != 1)
						{
							printf("Szavazatod érvénytelen. ");
						}
						if (emberek_elok[szavazat - 1] == 1)
						{
							szavazat_szamlalo[szavazat - 1] = szavazat_szamlalo[szavazat - 1] + 1;
							szavazat = -1;
							break;
						}
						else
						{
							szavazat = -1;
						}
					}
				}
			}
			szavazat_max = 0;
			for (int i = 0; i < jatekos_szam; i++) //max szavazat kiválasztása
			{
				if (szavazat_max < szavazat_szamlalo[i])
				{
					szavazat_max = szavazat_szamlalo[i];

				}
			}

			for (int i = 0; i < jatekos_szam; i++)
			{
				if (szavazat_max == szavazat_szamlalo[i]) {
					printf(RED_TEXT"Kiesett: %s\n", nevek[i]);
					printf(RESET_TEXT);
					emberek_elok[i] = 0;
					db_emberek_elok--;

				}
			}

			if (db_emberek_elok == 1)
			{
				for (int i = 0; i < jatekos_szam; i++)
				{
					if (emberek_elok[i] == 1) {
						printf(CYAN_TEXT"\nA nyertes: %s\n", nevek[i]);
						printf(RESET_TEXT);
						printf(YELLOW_TEXT"Koszonom hogy a jatekommal jatszott. ");
						printf("Kilepeshez irjon be egy szamot");
						printf(RESET_TEXT);
						scanf("%d", &player_input);
						return 0;
					}
				}
			}
			if (db_emberek_elok < 1)
			{

				printf(RED_TEXT"\nMindeki meghallt, elbuktak\n");
				printf(RESET_TEXT);
				printf(YELLOW_TEXT"Koszonom hogy a jatekommal jatszott. ");
				printf("Kilepeshez irjon be egy szamot");
				printf(RESET_TEXT);
				scanf("%d", &player_input);
				return 0;
			}

			player_input = -2;
		}

		if (player_input == -1) {
			printf(YELLOW_TEXT"Koszonom hogy a termekemmel jatszottatok.");
			printf(RESET_TEXT);
			break;
		}

	}
	return 0;
}