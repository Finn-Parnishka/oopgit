#include <conio.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <bitset>
#include <random>
#include <iomanip>

using namespace std;
int Enter_number()
{
	char size_mass[256];
	while (true)
	{
		cin.getline(size_mass, 256);
		int value = atoi(size_mass);
		if (value == 0 || size_mass == "" || value < 0)
			cout << "Вы не то ввели, повторите: ";
		else
			return value;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Enter size Massiv: ";
	int sizeMass = Enter_number();
	int* mass_One = new int[sizeMass];
	int* mass_Two = new int[sizeMass];

	srand(time(0));
	cout << "\nMassiv One: \n\n";
	for (int i = 0; i < sizeMass; i++)
	{
		mass_One[i] = rand() | (rand() << 15) | (rand() << 30);
		cout << bitset<32>(mass_One[i]) << dec << " = " << setw(12) << mass_One[i] << "\n\r";
	}

	for (int i = 0; i < sizeMass; i++)
	{
		int col_true = 0;
		int My_Masc = 0x0000001;
		for (int j = 0; j < 32; j++)
		{
			int prov = mass_One[i] & My_Masc;
			if (prov == My_Masc)
			{
				col_true++;
			}

			My_Masc = My_Masc << 1;
		}
		mass_Two[i] = col_true;
	}
	cout << "\nMassiv Two: ";
	for (int i = 0; i < sizeMass; i++)
	{
		cout << mass_Two[i] << " ";
	}
	delete[] mass_One;
	delete[] mass_Two;
	getchar();
	return 0;
}