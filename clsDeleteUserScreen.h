#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"
class clsDeleteUserScreen : protected clsScreen
{
private:
	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card :";
		cout << "\n________________________";
		cout << "\nFirst Name    : " << User.FirstName;
		cout << "\nLast Name     : " << User.LastName;
		cout << "\nFull Name     : " << User.FullName();
		cout << "\nEmail         : " << User.Email;
		cout << "\nPhone         : " << User.Phone;
		cout << "\nUser Name     : " << User.Username;
		cout << "\nPassword      : " << User.Password;
		cout << "\nPermissions   : " << User.Permissions;
		cout << "\n________________________\n";
	}
public:
	static void ShowDeleteUserScreen()
	{
		_DrawScreenHeader("\tDelete User Screen :-)");
		string UserName;
		cout << "\nPlease enter User Name  ?\n";
		UserName = clsInputValidate::ReadString();
		while (!clsUser::ISUserExist(UserName))
		{
			cout << "\nUser Name is not found, please choose another one : ";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User1 = clsUser::Find(UserName);
		_PrintUser(User1);
		char Answer = 'n';
		cout << "\nAre you sure you want to delete this User y/n?";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			if (User1.Delete())
			{
				cout << "\nUser Deleted Successfully :-)\n";
				_PrintUser(User1);
			}
			else
			{
				cout << "\nError User was not deleted\n";
			}
		}
	}
};

