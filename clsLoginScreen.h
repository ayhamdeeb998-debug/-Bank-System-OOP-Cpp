#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"Global.h"
#include"clsMainScreen.h"
#include<iomanip>
#include"clsDate.h"
#include<fstream>
#include"clsUtil.h"
class clsLoginScreen : protected clsScreen
{
private:

	static  bool _Login()
	{
		bool LogainFalid = false;
		short FaildLoginCount = 0;
		string UserName, Password;
		do
		{
			
			if (LogainFalid)
			{
				FaildLoginCount++;
				cout << "\nInvalid Username/Password!\n";
				cout << "You have " <<3-FaildLoginCount   << " Trail(s) to Login\n\n";
			}
			if (FaildLoginCount == 3)
			{
				cout << "\n\nYou are after locked 3 faild trails:-(\n\n";
				return false;
			}
			cout << "Enter Username ? ";
			cin >> UserName;
			cout << "Enter Password ? ";
			cin >> Password;
			CurrentUser = clsUser::Find(UserName, Password);
			LogainFalid = CurrentUser.IsEmpty();
		} while (LogainFalid);
		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenue();
		}

public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\tLogin Screen :-)");
		return _Login();
	}


};

