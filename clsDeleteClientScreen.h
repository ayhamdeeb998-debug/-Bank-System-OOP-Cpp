#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
using namespace std;
class clsDeleteClientScreen : protected clsScreen
{
private:
static void _Print(clsBankClient Client)
	{
		cout << "\nClient Card :";
		cout << "\n________________________";
		cout << "\nFirst Name    : " << Client.FirstName;
		cout << "\nLast Name     : " << Client.LastName;
		cout << "\nFull Name     : " << Client.FullName();
		cout << "\nEmail         : " << Client.Email;
		cout << "\nPhone         : " << Client.Phone;
		cout << "\nAcc.Number    : " << Client.AccountNumber();
		cout << "\nPassword      : " << Client.PinCode;
		cout << "\nBalance       : " << Client.AccountBalance;
		cout << "\n________________________\n";
	}
public:
static void ShowDeleteClientScreen()
{
	if (!CheckAccessRigt(clsUser::enPermissions::pDeleteClient))
	{
		return;
	}
	_DrawScreenHeader("\tDelete Client Screen");
	string AccountNumber;
	cout << "\nPlease enter Account Number ?\n";
	AccountNumber = clsInputValidate::ReadString();
	while (!clsBankClient::IsClientExist(AccountNumber))
	{
		cout << "\nAccount number is not found, please choose another one : ";
		AccountNumber = clsInputValidate::ReadString();
	}
	clsBankClient Client1 = clsBankClient::Find(AccountNumber);
	_Print(Client1);
	char Answer = 'n';
	cout << "\nAre you sure you want to delete this client y/n?";
	cin >> Answer;
	if (Answer == 'y' || Answer == 'Y')
	{
		if (Client1.Delete())
		{
			cout << "\nCLient Deleted Successfully :-)\n";
			_Print(Client1);
		}
		else
		{
			cout << "\nError Client was not deleted\n";
		}
	}
}

};

