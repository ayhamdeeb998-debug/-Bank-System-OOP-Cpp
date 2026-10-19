#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include<iomanip>
#include"clsScreen.h"
using namespace std;

class clsAddNewClientScreen:protected clsScreen
{
private:
static	void _ReadClientInfo(clsBankClient& Client)
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
	static void ShowAddNewClientScreen()
	{
	if(	!CheckAccessRigt(clsUser::enPermissions::pAddNewClient))
		{
			return;
		}
		_DrawScreenHeader("\tAdd New Client Screen");
		string AccountNumber;
		cout << "\nPlease enter Account Number:  ";
		AccountNumber = clsInputValidate::ReadString();
		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number Is Already Used, Choose another one :-( ? ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
		_ReadClientInfo(NewClient);
		clsBankClient::enSaveResults SaveResult;
		SaveResult = NewClient.Save();
		switch (SaveResult)
		{
		case clsBankClient::enSaveResults::svSucceded:
			cout << "\nAccount Update Successfuly :-)\n";
			_Print(NewClient);
			break;
		case clsBankClient::enSaveResults::svFailidEmptyObject:
			cout << "\nError account was not saved because it's Empty :(-";
			break;
		case clsBankClient::enSaveResults::svFaliadAccountNumberExists:
			cout << "\nFailid,Account Number is  used :(-";
			break;
		}

	}
};

