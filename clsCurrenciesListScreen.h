#pragma once
#include<iostream>
#include<vector>
#include<iomanip>
#include"clsScreen.h"
#include"clsCurrency.h"
class clsCurrenciesListScreen :protected clsScreen
{
private:
	static void _PrintCurrencyRecordLine(clsCurrency Currency)
	{
		cout << setw(8) << left << "" << "| " << left << setw(30) << Currency.Country();
		cout << "| " << left << setw(8) << Currency.CurrencyCode();
		cout << "| " << left << setw(45) << Currency.CurrencyName();
		cout << "| " << left << setw(10) << Currency.Rate();
	}

public:
	static void ShowCurrenciesListScreen()
	{

		vector <clsCurrency > vCurruncies = clsCurrency::GetCurrenciesList();
		string Title = "\tCurrencies List Screen :-)";
		string SubTitle = "\t(" + to_string(vCurruncies.size()) + ") Currency";
		clsScreen::_DrawScreenHeader(Title, SubTitle);
		cout << left << setw(8) << "\n\t____________________________________________________________";
		cout << "__________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(8) << "Code";
		cout << "| " << left << setw(45) << "Name";
		cout << "| " << left << setw(10) << "Rate/(1$)";
		cout << left << setw(8) << "\n\t____________________________________________________________";
		cout << "__________________________________________\n" << endl;
		if (vCurruncies.size() == 0)
		{
			cout << "\t\t\t\tNo Currencies Available in the system!";
		}
		else
		{
			for (clsCurrency& C : vCurruncies)
			{
				_PrintCurrencyRecordLine(C);
				cout << endl;
			}
		}
		cout << left << setw(8) << "\n\t____________________________________________________________";
		cout << "__________________________________________\n" << endl;
	}

};

