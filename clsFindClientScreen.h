#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
using namespace std;
class clsFindClientScreen :protected clsScreen
{
private:
	static void _Print(clsBankClient Client)
	{
		cout << "\n\nClient Card :";
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
	static void ShowFindClientScreen()
	{
		if (!CheckAccessRigt(clsUser::enPermissions::pFindClient))
		{
			return;
		}
		_DrawScreenHeader("\tFind Client Screen :-)");
		cout << "\tPlease enter Account Number ? ";
		string AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\n Account Number is not found :-(, enter another one?";
			 AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		if (!Client.IsEmpty())
		{
			cout << "\nClient found :-)";
		}
		else
		{
			cout << "\nClient is not found :-(";
		}
		_Print(Client);
	}
};

