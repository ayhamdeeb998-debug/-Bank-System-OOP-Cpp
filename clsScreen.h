#pragma once
#include<iostream>
#include"clsUser.h"
#include"Global.h"
#include"clsDate.h"
using namespace std;
class clsScreen
{
protected:
	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{

		cout << "\t\t\t\t\t_______________________________________";
		cout << "\n\n\t\t\t\t\t  " << Title;
		if (SubTitle != "")
		{
			cout << "\n\t\t\t\t\t" << SubTitle;
		}
		cout << "\n\t\t\t\t\t_______________________________________\n\n";
		cout << "\n\t\t\t\t\tUser : " << CurrentUser.Username << endl;
		cout << "\t\t\t\t\tDate : " << clsDate::DateToString(clsDate())<<"\n\n";
	}
	static bool CheckAccessRigt(clsUser::enPermissions Permission)
	{
		if (!CurrentUser.CheckAccessPermission(Permission))
		{
			cout << "\t\t\t\t\t_______________________________________";
			cout << "\n\n\t\t\t\t\tAccess Denied! Contact Your Admin";
			cout << "\n\t\t\t\t\t_______________________________________\n\n";
			return false;
		}
		else
		{
			return true;
		}
	}

};

