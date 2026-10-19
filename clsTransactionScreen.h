#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include<iomanip>
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalancesScreen.h"
#include"clsTransferScreen.h"
#include"clsTransferLogScreen.h"
using namespace std;
class clsTransactionScreen : protected clsScreen
{
private:
	enum _enTransactionsMenueOptions
	{
		eDeposit=1,eWithdraw=2,eShowTotalBalance=3,eTransfer=4,eTranferLog=5,eShowMainMenue=6
	};
	static short _ReadTransactionsMenueOptions()
	{
		cout << setw(37) << left << "" << "Choose what do you want?[1 to 6]?";
		short Choice;
		Choice = clsInputValidate::ReadIntNumberBetween(1, 6, "Enter Number between 1 to 6 ?");
		return Choice;
	}
	static void _ShowDepositScreen()
	{
		//cout << "\nDeposit Screen will be here....\n";
		clsDepositScreen::ShowDepositScreen();
	}
	static void _ShowWithDrawScreen()
	{
		//cout << "\nWitdraw Screen will be here....\n";
		clsWithdrawScreen::ShowWithdrawScreen();
	}
	static void _ShowTotalBalanceScreen()
	{
		//cout << "\nTotal Balances Screen will be here....\n";
		clsTotalBalancesScreen::ShowTotalBalances();
	}
	static void _ShowTransferScreen()
	{
		clsTransferScreen::ShowTransferScreen();
	}
	static void _ShowTransferLogScreen()
	{
		clsTransferLogScreen::ShowTransferLogScreen();
	}
	static void _GoToBackTransacionsMenue()
	{
		cout << "\n\nPlease entet any key to go back to Transactions Menue";
		system("pause>0");
		ShowTransactionsMenue();

	}
	static void _PerformTransactionMenueOption(_enTransactionsMenueOptions TransactionsMenueOptions)
	{
		switch (TransactionsMenueOptions)
		{
		case _enTransactionsMenueOptions::eDeposit:
			system("cls");
			_ShowDepositScreen();
			_GoToBackTransacionsMenue();
			break;

			case _enTransactionsMenueOptions::eWithdraw:
				system("cls");
				_ShowWithDrawScreen();
				_GoToBackTransacionsMenue();
				break;

			case _enTransactionsMenueOptions::eShowTotalBalance:
				system("cls");
				_ShowTotalBalanceScreen();
				_GoToBackTransacionsMenue();
				break;
				
			case _enTransactionsMenueOptions::eTransfer:
				system("cls");
				_ShowTransferScreen();
				_GoToBackTransacionsMenue();
				break;
				 
			case _enTransactionsMenueOptions::eTranferLog:
				system("cls");
				_ShowTransferLogScreen();
				_GoToBackTransacionsMenue();
				break;

			case _enTransactionsMenueOptions::eShowMainMenue:
				//do nothing here the main screen will handle it :-)
				break;
		}
	}
public:
	static void ShowTransactionsMenue()
	{
		if (!CheckAccessRigt(clsUser::enPermissions::pTransactions))
		{
			return;
		}
		system("cls");
		_DrawScreenHeader("\tTransactions Screen :-)");
		cout << setw(37) << left << "" << "========================================================\n";
		cout << setw(37) << left << "" << "\t\t\tTransactins Menue\n";
		cout << setw(37) << left << "" << "========================================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] TransferLog.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "========================================================\n";
		_PerformTransactionMenueOption(_enTransactionsMenueOptions(_ReadTransactionsMenueOptions()));
	}
};

