#pragma once
#include<iostream>
#include"clsScreen.h"
#include<iomanip>
#include<string>
#include"clsBankClient.h"
using namespace std;
class clsClientListScreen:protected clsScreen
{
private:
static void _PrintClientRecordLine(clsBankClient Client)
	{
		cout <<setw(8)<<left<<"" << "| " << left << setw(15) << Client.AccountNumber();
		cout << "| " << left << setw(20) << Client.FullName();
		cout << "| " << left << setw(12) << Client.Phone;
		cout << "| " << left << setw(20) << Client.Email;
		cout << "| " << left << setw(10) << Client.PinCode;
		cout << "| " << left << setw(15) << Client.AccountBalance;
	}
public:
static void ShowClientList()
	{
	if (!CheckAccessRigt(clsUser::enPermissions::pListClients))
	{
		return;
	}
		vector <clsBankClient> vClients = clsBankClient::GetClientsList();
		string Title = "\tCLient List Screen";
		string SubTitle = "\t(" + to_string(vClients.size()) + ") Client(s)";
		clsScreen::_DrawScreenHeader(Title,SubTitle);
		cout << left<<setw(8)<<"\n\t____________________________________________________________";
		cout << "________________________________\n" << endl;
		cout <<setw(8)<<left<<"" << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(20) << "CLient Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance";
		cout << left << setw(8) << "\n\t____________________________________________________________";
		cout << "________________________________\n" << endl;
		if (vClients.size() == 0)
		{
			cout << "\t\t\t\tNo Clients Available in the system!";
		}
		else
		{
			for (clsBankClient& C : vClients)
			{
				_PrintClientRecordLine(C);
				cout << endl;
			}
		}
		cout << left << setw(8) << "\n\t____________________________________________________________";
		cout << "________________________________\n" << endl;
	}


};

