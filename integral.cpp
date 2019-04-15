#include "pch.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <cctype>
#include <iterator>
#include <math.h>

using namespace std;

double func(string input)
{
	string sp; //tar bort spaces om det finns (error handeling)
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] != ' ')
		{
			sp += input[i];
		}
	}

	string tok = ""; // Paranteser prioriterat först
	for (int i = 0; i < sp.length(); i++)
	{
		if (sp[i] == '(')
		{
			int it = 1;
			string tk;
			i++;
			while (true)
			{
				if (sp[i] == '(')
				{
					it++;
				}
				else if (sp[i] == ')')
				{
					it--;
					if (it == 0)
					{
						i++;
						break;
					}
				}
				tk += sp[i];
				i++;
			}
			tok += to_string(func(tk));
		}
		tok += sp[i];
	}

	//igenkänner olika matematiska operatorer
	for (int i = 0; i < tok.length(); i++)
	{
		if (tok[i] == '+')
		{
			return func(tok.substr(0, i)) + func(tok.substr(i + 1, tok.length() - i - 1)); // adderar första siffran / siffrorna med andra siffran / siffrorna
		}
		else if (tok[i] == '-')
		{
			return func(tok.substr(0, i)) - func(tok.substr(i + 1, tok.length() - i - 1)); // subtraherar
		}
	}

	for (int i = 0; i < tok.length(); i++)
	{
		if (tok[i] == '*')
		{
			return func(tok.substr(0, i)) * func(tok.substr(i + 1, tok.length() - i - 1)); //multiplicerar
		}
		else if (tok[i] == '/')
		{
			return func(tok.substr(0, i)) / func(tok.substr(i + 1, tok.length() - i - 1)); // dividerar
		}
		else if (tok[i] == '^') {
			return pow(func(tok.substr(0, i)), func(tok.substr(i + 1, tok.length() - i - 1))); // använder pow(x,y) för att "upphöja" x med y.
		}
	}
	return stod(tok.c_str()); // returnerar den uträknade funktionen som en double variabel (konverterar från en string till double)
}

int main()
{
	double n; // antal rektanglar
	//double nFunc;
	double a, b; //intervallet
	//string func;
	string input; //din funktion som input

	cout << "enter a function to integrate(example: 4x*5^2): ";
	//cin >> func;
	cin >> input;
	//nFunc = stod(func);
	cout << "enter the interval from a to b, a must be smaller than b" << endl;
	cout << "enter a: ";
	cin >> a;
	cout << "enter b: ";
	cin >> b;

	if (a > b) { // error handeling
		cout << "error! _r_e_a_d_Instructions" << endl;
		system("pause");
	}
	else {
		cout << "enter how many rectangles: " << endl;
		cin >> n;
		double base = (b - a) / n;
		double g = 0;
		for (double j = 0; j < n; j++)
		{
			g += func(input) * (a + base * j) * base;
		}
		cout << endl;
		cout << "answer: " << g << endl;
		system("pause");
	}
}