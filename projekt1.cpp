// Projekt_working.cpp : Defines the entry point for the console application.
//

// Try_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string>


#include "button.h"
#include "fun.h"

#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
	int slowo[20] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, lenght_of_tab = 0;
	string slowa[10000], poczatek, koniec, file_path;
	fstream slownik;
	button k[9];
	k[0].tab[0] = 'a'; k[0].id = 2;
	k[0].tab[1] = '¹'; k[0].id2 = '2';
	k[0].tab[2] = 'b'; k[0].len = 5;
	k[0].tab[3] = 'c';
	k[0].tab[4] = 'æ';
	k[1].tab[0] = 'd'; k[1].id = 3;
	k[1].tab[1] = 'e'; k[1].id2 = '3';
	k[1].tab[2] = 'ê'; k[1].len = 4;
	k[1].tab[3] = 'f';
	k[2].tab[0] = 'g'; k[2].id = 4;
	k[2].tab[1] = 'h'; k[2].id2 = '4';
	k[2].tab[2] = 'i'; k[2].len = 3;
	k[3].tab[0] = 'j'; k[3].id = 5;
	k[3].tab[1] = 'k'; k[3].id2 = '5';
	k[3].tab[2] = 'l'; k[3].len = 4;
	k[3].tab[3] = '³';
	k[4].tab[0] = 'm'; k[4].id = 6;
	k[4].tab[1] = 'n'; k[4].id2 = '6';
	k[4].tab[2] = 'ñ'; k[4].len = 5;
	k[4].tab[3] = 'o';
	k[4].tab[4] = 'ó';
	k[5].tab[0] = 'p'; k[5].id = 7;
	k[5].tab[1] = 'r'; k[5].id2 = '7';
	k[5].tab[2] = 's'; k[5].len = 4;
	k[5].tab[3] = 'œ'; k[6].len = 2;
	k[6].tab[0] = 't'; k[6].id = 8;
	k[6].tab[1] = 'u'; k[6].id2 = '8';
	k[7].tab[0] = 'w'; k[7].id = 9;
	k[7].tab[2] = 'z'; k[7].id2 = '9';
	k[7].tab[3] = 'Ÿ'; k[7].len = 5;
	k[7].tab[4] = '¿';
	k[7].tab[1] = 'y';
	
	do {
		cout << "\n\t Write file path: name_of_file.txt : containing the dictionary with wanted words:";
		cin >> file_path;
		slownik.open(file_path, ios::in | ios::out);
		if (!slownik.good())
		{
			system("cls");
			cout << "\n\t Path is wrong or some errors ocured. Try again!";
		}
	} while (!slownik.good());

	int i = 0, a, opt2 = 0;
	char b, fin = 'Y', opt = '0';
	show_instructions();
	system("PAUSE");
	system("cls");
	show();

	while (fin != 'n' || fin != 'N')
	{
		b = ' ';
		lenght_of_tab = 0;
		i = 0;
		a = 0;
		poczatek = "";
		koniec = "";
		zero_tab(slowo);


		do
		{
			b = _getch();
			switch (b)
			{
			case 13: break;
			case 44: {opt2 -= 1; system("cls"); show(); show_options(slowa, lenght_of_tab, opt2); show2(slowo); }
			case 46: { opt2 += 1;  system("cls"); show(); show_options(slowa, lenght_of_tab, opt2); show2(slowo); }
			}
			if (check_input(b))
			{
				slowo[i] = int(b - 48);
				cout << b;
				decide(i, k, slowo, poczatek, koniec, b, lenght_of_tab, slowa, opt2, file_path);
				i++;
			}
		} while (b != '1' && b != 13 && i<20);

		system("cls");
		if (b == 13) cout << slowa[opt2];
		if (b == '1' || i == 19)
		{
			finished_with_1(slowa, lenght_of_tab, i - 1);
			show_options(slowa, lenght_of_tab, opt2);
			cout << "Choose a word from 1. to" << lenght_of_tab << endl;
			cin >> a;
			system("cls");
			if (a >= 1 && a <= lenght_of_tab)
			{
				cout << "You've chosen: " << slowa[a - 1] << endl;
			}
			else cout << "<<<OUT OF THE REACH>>>>>";
		}
		cout <<endl<< "Continiue?" << endl << "         Y|N" << endl;
		cin >> fin;
		system("cls");
		show();
	}

	system("PAUSE");
	return 0;
}
