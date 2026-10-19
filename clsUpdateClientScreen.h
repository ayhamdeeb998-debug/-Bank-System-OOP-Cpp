#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
using namespace std;
class clsUpdateClientScreen :protected clsScreen
{
private:
static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "\nEnter First Name: ";
		Client.FirstName = clsInputValidate::ReadString();
		cout << "\nEnter Last Name: ";
		Client.LastName = clsInputValidate::ReadString();
		cout << "\nEnter Email: ";
		Client.Email = clsInputValidate::ReadString();
		cout << "\nEnter Phone: ";
		Client.Phone = clsInputValidate::ReadString();
		cout << "\nEnter PinCode: ";
		Client.PinCode = clsInputValidate::ReadString();
		cout << "\nEnter Account Balaance: ";
		Client.AccountBalance = clsInputValidate::ReadFloatNumber();

	}
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
static void ShowUpdatClientScreen()
{
	if (!CheckAccessRigt(clsUser::enPermissions::pUpdateClients))
	{
		return;
	}
	_DrawScreenHeader("\tUpdate CLient Screen");
	string AccountNumber;
	cout << "Please enter client account number ?";
	AccountNumber = clsInputValidate::ReadString();
	while (!clsBankClient::IsClientExist(AccountNumber))
	{
		cout << "Account Number is not found , please enter a new account number?";
		AccountNumber = clsInputValidate::ReadString();
	}
	clsBankClient Client1 = clsBankClient::Find(AccountNumber);
	_Print(Client1);
	cout << "\nAre you sure you want to update this client?Y/N?";
	char Answer;
	cin >> Answer;
	if (Answer == 'Y' || Answer == 'y')
	{
		cout << "\n\nUpdate Client Info :";
		cout << "\n__________________________\n";
		_ReadClientInfo(Client1);
		clsBankClient::enSaveResults SaveResult;
		SaveResult = Client1.Save();
		switch (SaveResult)
		{
		case clsBankClient::enSaveResults::svSucceded:
			cout << "\nAccount Update Successfuly :-)\n";
			_Print(Client1);
			break;
		case clsBankClient::enSaveResults::svFailidEmptyObject:
			cout << "\nError account was not saved because it's Empty";
			break;
		}
	}
} 

};

