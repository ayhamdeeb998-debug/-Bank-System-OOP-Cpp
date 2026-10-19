#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include<iomanip>
#include"clsCurrenciesListScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyScreen.h"
#include"clsCurrencyCalculatorScreen.h"
class clsCurrencyExhangeMainScreen :clsScreen
{
private:
	enum enCurrencMainMenueOptions{eListCurrencies=1,eFindCurrency=2,eUpdateRate=3,
	eCurrencyCalculator=4,eMainMenue=5};
	static short _ReadCurrencyMainMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do?[1 to 5]?";
		short Choice = clsInputValidate::ReadIntNumberBetween(1, 5, "Enter Number between 1 to 5 ?");
		return Choice;
	}
	static void _GoBackToCurrencyMainMenue()
	{
		cout << setw(37) << left << "" << "\n\nPress any key to go back to Currency Exchange Menue...\n";
		system("pause>0");
		ShowCurrencyMainMenue();
	}
	static void _ShowListCurrenciesScreen()
	{
		//cout << "\nList Currencies Screen will be here :-)";
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}
	static void _ShowFindCurrencyScreen()
	{
		//cout << "\nFind Currency Screen will be here :-)";
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}
	static void _ShowUpdateRateScreen()
	{
	//	cout << "\nUpdate Currency Screen will be here :-)";
		clsUpdateCurrencyScreen::_ShowUpdateCurrencyScreen();
	}
	static void _ShowCurrencyCalculatorScreen()
	{
		//cout << "\ Currency Calculator Screen will be here :-)";
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}
	static void _PerfromCurrencyMainMenueOption(enCurrencMainMenueOptions CurrencyMainMenueOption)
	{
		switch (CurrencyMainMenueOption)
		{
		case enCurrencMainMenueOptions::eListCurrencies:
			system("cls");
			_ShowListCurrenciesScreen();
			_GoBackToCurrencyMainMenue();
			break;

		case enCurrencMainMenueOptions::eFindCurrency:
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyMainMenue();
			break;

		case enCurrencMainMenueOptions::eUpdateRate:
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToCurrencyMainMenue();
			break;

		case enCurrencMainMenueOptions::eCurrencyCalculator:
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyMainMenue();
			break;

		case enCurrencMainMenueOptions::eMainMenue:
		
			break;

		}

	}

public:
	static void ShowCurrencyMainMenue()
	{
		system("cls");
		clsScreen::_DrawScreenHeader("\tCurrency Exchange Main Screen :-)");
		cout << setw(37) << left << "" << "========================================================\n";
		cout << setw(37) << left << "" << "\t\t\tCurrency Exchange Menue\n";
		cout << setw(37) << left << "" << "========================================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "========================================================\n";
		_PerfromCurrencyMainMenueOption((enCurrencMainMenueOptions)_ReadCurrencyMainMenueOption());
	}

};

