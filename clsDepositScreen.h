#pragma once
#include"clsBankClient.h"
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
class clsDepositScreen : protected clsScreen
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
	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "\nPlease enter Account Number?";
		AccountNumber = clsInputValidate::ReadString();
		return AccountNumber;
	}
public:
	static void ShowDepositScreen()
	{
		_DrawScreenHeader("\tDeposit Screen :-)");
		string AccountNumber = _ReadAccountNumber();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with [" << AccountNumber << "] does not exist.\n ";
			AccountNumber = _ReadAccountNumber();
		}
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_Print(Client1);
		double Amount = 0;
		cout << "\nPlease enter deposit amount?";
		Amount = clsInputValidate::ReadDbNumber();
		cout << "\nAre you sure you want to perform this transaction?";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Client1.Deposit(Amount);
			cout << "\nAmount Deposited Successfully :-) \n";
			cout << "\nNew Balance is : " << Client1.AccountBalance;
		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}
	}
};

