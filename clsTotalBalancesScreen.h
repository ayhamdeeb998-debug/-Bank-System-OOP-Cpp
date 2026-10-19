#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsUtil.h"
#include"clsBankClient.h"
class clsTotalBalancesScreen : protected clsScreen
{
private:
static void  _PrintClientRecordBalanceLine(clsBankClient Client)
	{
		cout <<setw(25)<<left<<"" << "| " << left << setw(15) << Client.AccountNumber();
		cout << "| " << left << setw(40) << Client.FullName();
		cout << "| " << left << setw(12) << Client.AccountBalance;
	}
public:
static void ShowTotalBalances()
	{
		vector <clsBankClient> vClients = clsBankClient::GetClientsList();
		string Title = "\tBalances List Screen :-)";
		string SubTitle = "\t(" + to_string(vClients.size()) + ") Client(s)";
		_DrawScreenHeader(Title, SubTitle);
		cout <<setw(25)<<left<<""<< "\n\t\t____________________________________________________________";
		cout << "________________________________\n" << endl;
		cout <<setw(25)<<left<<"" << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout <<setw(25)<<left<<""<< "\t\t____________________________________________________________";
		cout << "________________________________\n" << endl;
		double TotalBalances = clsBankClient::GetTotalBalances();
		if (vClients.size() == 0)
		{
			cout << "\t\t\t\tNo Clients Available in the system!";
		}
		else
		{
			for (clsBankClient& C : vClients)
			{
				_PrintClientRecordBalanceLine(C);
				cout << endl;
			}
		}
		cout <<setw(25)<<left<<""<< "\n\t\t____________________________________________________________";
		cout << "________________________________\n" << endl;
		cout <<setw(8)<<left<<"" << "\t\t\t\t\t   Total Balances = " << TotalBalances << endl;
		cout <<setw(8)<<left<<""<< "\t\t\t\t\t   (" << clsUtil::NumberToWords(TotalBalances) << ")";
	}
};

