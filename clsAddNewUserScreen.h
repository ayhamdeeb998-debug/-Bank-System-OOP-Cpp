#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"
#include<iomanip>
class clsAddNewUserScreen :protected clsScreen
{
private:
	static void _ReadUserInfo(clsUser &User)
	{
		cout << "\nEnter First Name ? ";
		User.FirstName = clsInputValidate::ReadString();
		cout << "\nEnter Last Name ? ";
		User.LastName = clsInputValidate::ReadString();
		cout << "\nEnter Email ? ";
		User.Email = clsInputValidate::ReadString();
		cout << "\nEnter Phone ? ";
		User.Phone = clsInputValidate::ReadString();
		cout << "\nEnter Password ? ";
		User.Password = clsInputValidate::ReadString();
		User.Permissions = _ReadPermissionsToSet();
	
	}
	static int _ReadPermissionsToSet()
	{
		int Permissions = 0;
		char Answer = 'n';
		cout << "\nDo you want to give full access? y/n?";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			return -1;
		}
		cout << "\nDo you want to give  access to :\n";
		cout << "\nShow Client List? Y/N ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pListClients;
		}
		cout << "\nDo you want to give  access to :\n";
		cout << "\nAdd New Client ? Y/N ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pAddNewClient;
		}
		cout << "\nDo you want to give  access to :\n";
		cout << "\nDelete Client ? Y/N ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pDeleteClient;
		}
		cout << "\nDo you want to give  access to :\n";
		cout << "\nUpdate Client ? Y/N ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pUpdateClients;
		}
		cout << "\nDo you want to give  access to :\n";
		cout << "\nFind Client? Y/N ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pFindClient;
		}
		cout << "\nDo you want to give  access to :\n";
		cout << "\nTransactions? Y/N ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pTransactions;
		}
		cout << "\nDo you want to give  access to :\n";
		cout << "\nManage Users ? Y/N ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pManageUsers;
		}
		cout << "\nDo you want to give  access to :\n";
		cout << "\nLog Register Screen ? Y/N ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pLogRegisterScreen;
		}
		return Permissions;
	}
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
public :
	static void ShowAddNewUserScreen()
	{
		_DrawScreenHeader("\tAdd New User Screen :-)");
		string UserName;
		cout << "\nPlease enter User Name ? ";
		UserName = clsInputValidate::ReadString();
		while (clsUser::ISUserExist(UserName))
		{
			cout << "\nUser Name is already used, choose another one ? ";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User = clsUser::GetAddNewUserObject(UserName);
		_ReadUserInfo(User);
		clsUser::enSaveResults SaveResult;
		SaveResult = User.Save();
		switch (SaveResult)
		{
		case clsUser::enSaveResults::svSucceeded:
			cout << "\nUser Addeded Successfully :-)";
			_PrintUser(User);
			break;

		case clsUser::enSaveResults::svFaildEmptyObject:
			cout << "\nError User was not saved because it's Empty";
			break;
		case clsUser::enSaveResults::svFaildUserExists:
			cout << "\nError User wan no saved because UserName is User!\n";
			break;
		}
	}


};

