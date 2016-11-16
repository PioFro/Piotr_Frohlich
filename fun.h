#pragma once
#include <string>
#include "button.h"
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

void firstbutton(button klawisz, string &slowostart, string &slowoend, string file_path)// pierwsze s³owo ok, tylko musz¹ byæ przynajmniej raz u¿yte wszystkie litery alfabetu!!!
{
	fstream plik;
	string poprz;
	plik.open(file_path, std::ios::out | std::ios::in);
	int i = 1, j = 0;
	while (!plik.eof())
	{
		plik >> slowostart;
		if (slowostart[0] == klawisz.tab[0]) break;
	}
	while (!plik.eof())
	{
		plik >> slowoend;
		j = 0;
		for (int i = 1; i < klawisz.len; i++)
		{
			if (slowoend[0] == klawisz.tab[i]) {
				poprz = slowoend;
				j++;  break;
			}
		}
		if (j == 0) slowoend = poprz;
	}
	return;
}

void to_tab(button klawisz, int miejsce, int &len, string slowa[], string poczatek, string koniec, string file_path)
{
	fstream plik;
	string slowo;
	unsigned int j = 0;
	plik.open(file_path, std::ios::out | std::ios::in);

	while (slowo != poczatek)
	{							//znajdywanie pocz¹tku podanego przez funkcje firstbutton();
		plik >> slowo;

	}
	while (slowo != koniec)
	{
		for (int i = 0; i < klawisz.len; i++)
		{
			if (slowo[miejsce] == klawisz.tab[i]) { slowa[j] = slowo; j++; break; }	//przenoszenie do tablicy stringow
		}
		plik >> slowo;
		if (slowo == koniec) { slowa[j] = slowo; j++; break; }

	}
	plik.close();
	len = j;
	return;
}

void in_tab(button klawisz, int miejsce, string slowa[], int &len)
{
	string slowo;
	int len_returned = 0, k = 0;
	for (int i = 0; i < len; i++)
	{
		slowo = slowa[i];

		for (int j = 0; j < klawisz.len; j++)
		{
			if (slowo[miejsce] == klawisz.tab[j])
			{
				slowa[len_returned] = slowa[k];
				len_returned++;
				break;
			}	//zawê¿anie opcji w tablicy stringów
		}
		k++;
	}
	len = len_returned;// przekazanie do programu wiadomoœci o iloœci poprawnych do tej pory s³ów
}

void finished_with_1(string slowa[], int &tab_len, int len)
{
	int j = 0;
	for (int i = 0; i < tab_len; i++)
	{
		if (slowa[i].length() == len)
		{
			slowa[j] = slowa[i];
			j++;
		}
	}
	tab_len = j;
}

void show_options(string tab[], int len, int &chosen_option)
{
	if (chosen_option < 0) chosen_option = 0;
	if (len > 25)
		len = 25;
	cout << '<';
	for (int i = 0; i < len; i++)
	{
		if (i == chosen_option)cout << "* ";
		cout << tab[i] << " | ";

	}
	cout << '>' << endl;

}
void show()// pokazuje klawisze, pomoc przy wprowadzaniu
{
	cout << "[ 1 FIN ] [ 2 ABC ] [ 3 DEF ]" << endl << "[ 4 GHI ] [ 5 JKL ] [ 6 MNO ]" << endl << "[ 7PQRS ] [ 8 TUV ] [ 9WXYZ ]" << endl;
}
void show2(int tab[])//pokazuje dotychczas wcisniete klawisze
{
	for (int i = 0; tab[i] != 0; i++)
		cout << tab[i];
}
void zero_tab(int tab[])
{
	for (int i = 0; i < 20; i++)
	{
		tab[i] = 0;
	}
}
void decide(int &i, button k[], int slowo[], string &poczatek, string &koniec, char &b, int &lenght_of_tab, string slowa[], int opt, string file_path)
{
	if (i == 0 && b != '1')
	{
		firstbutton(k[slowo[i] - 2], poczatek, koniec, file_path);
		system("cls");
		show();
		cout << '<' << poczatek << " | " << koniec << '>' << endl;
		show2(slowo);

	}
	else
	{
		if (i == 1 && b != '1')
		{
			to_tab(k[slowo[i] - 2], i, lenght_of_tab, slowa, poczatek, koniec, file_path);
			system("cls");
			show();
			show_options(slowa, lenght_of_tab, opt);
			show2(slowo);
		}
		else if (b != '1')
		{
			in_tab(k[slowo[i] - 2], i, slowa, lenght_of_tab);
			system("cls");
			show();
			show_options(slowa, lenght_of_tab, opt);
			show2(slowo);

		}

	}
}
bool check_input(char b)
{
	if (b > '1'&&b <= '9') return true;
	else return false;

}
void show_instructions()
{
	cout << "Welcome to T9 dictionary." << endl << "Instruction:  type numbers from 2 to 9 to chose letters wirtten on them, choose 1 to decide on the lenght of the typed word ( the amount of the pressed earlier buttons )." << endl;
	cout << "The app will show You some options: currently chosen option will be marked with the symbol: * . To change currently chosen option press [,] to move left and [.] to move right. To accept chosen word press enter." << endl;
	cout << "To carry on typing just carry on typing. Every different button apart from prev. mentioned will be ignored.";
}