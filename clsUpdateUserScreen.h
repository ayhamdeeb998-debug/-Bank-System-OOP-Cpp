#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"
#include<iomanip>
class clsUpdateUserScreen :protected clsScreen
{
private:
	static void _ReadUserInfo(clsUser& User)
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
	public:
		static void ShowUpdatUserScreen()
		{
			_DrawScreenHeader("\tUpdate User Screen :-)");
			string UserName;
			cout << "Please enter client User Name ?";
			UserName = clsInputValidate::ReadString();
			while (!clsUser::ISUserExist(UserName))
			{
				cout << "User Name is not found , please enter a new User Name?";
				UserName = clsInputValidate::ReadString();
			}
			clsUser User1 = clsUser::Find(UserName);
			_PrintUser(User1);
			cout << "\nAre you sure you want to update this User?Y/N?";
			char Answer;
			cin >> Answer;
			if (Answer == 'Y' || Answer == 'y')
			{
				cout << "\n\nUpdate User Info :";
				cout << "\n__________________________\n";
				_ReadUserInfo(User1);
				clsUser::enSaveResults SaveResult;
				SaveResult = User1.Save();
				switch (SaveResult)
				{
				case clsUser::enSaveResults::svSucceeded:
					cout << "\nUser Update Successfuly :-)\n";
					_PrintUser(User1);
					break;
				case clsUser::enSaveResults::svFaildEmptyObject:
					cout << "\nError User  was not saved because it's Empty";
					break;
				}
			}
		}

};

