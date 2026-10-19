#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include<iomanip>
using namespace std;
class clsUsersListScreen : protected clsScreen
{
private:
	static void _PrintUserRecordLine(clsUser User)
	{
		cout << setw(8) << left << "" << "| " << left << setw(12) << User.Username;
		cout << "| " << left << setw(25) << User.FullName();
		cout << "| " << left << setw(12) << User.Phone;
		cout << "| " << left << setw(20) << User.Email;
		cout << "| " << left << setw(10) << User.Password;
		cout << "| " << left << setw(12) << User.Permissions;
	}
public:
	static void ShowUserList()
	{
		vector <clsUser> vUsers =  clsUser::GetUsersList();
		string Title = "\tUser List Screen";
		string SubTitle = "\t(" + to_string(vUsers.size()) + ") User(s)";
		clsScreen::_DrawScreenHeader(Title, SubTitle);
		cout << left << setw(8) << "\n\t____________________________________________________________";
		cout << "______________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(12) << "User Name";
		cout << "| " << left << setw(25) << "Full Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(12) << "Permissions";
		cout << left << setw(8) << "\n\t____________________________________________________________";
		cout << "______________________________________\n" << endl;
		if (vUsers.size() == 0)
		{
			cout << "\t\t\t\tNo Users Available in the system!";
		}
		else
		{
			for (clsUser& U : vUsers)
			{
				_PrintUserRecordLine(U);
				cout << endl;
			}
		}
		cout << left << setw(8) << "\n\t____________________________________________________________";
		cout << "______________________________________\n" << endl;
	}



};

