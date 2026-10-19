#pragma once
#include<iostream>
#include"clsUser.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
class clsFindUserScreen :protected clsScreen
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
	static void ShowFindUserScreen()
	{
		_DrawScreenHeader("\tFind User Screen :-)");
		cout << "\tPlease enter User Name ? ";
		string UserName = clsInputValidate::ReadString();
		while (!clsUser::ISUserExist(UserName))
		{
			cout << "\n UserName is not found :-(, enter another one?";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User = clsUser::Find(UserName);
		if (!User.IsEmpty())
		{
			cout << "\nUser found :-)";
		}
		else
		{
			cout << "\nClient is not found :-(";
		}
		_PrintUser(User);
	}
};

