#pragma once
#include<iostream>
#include<vector>
#include"clsScreen.h"
#include"clsUser.h"
#include<iomanip>

class clsLoginRegisterScreen :protected clsScreen
{
private:
	static void _PrintLoginRecordLine(clsUser::stLoginRegisterRecord LoginRegisterRecord)
	{
		cout << setw(8) << left << "" << "| " << left << setw(40) << LoginRegisterRecord.DataTime;
		cout << "| " << left << setw(15) << LoginRegisterRecord.Username;
		cout << "| " << left << setw(12) << LoginRegisterRecord.Password;
		cout << "| " << left << setw(12) << LoginRegisterRecord.Permissions;
	}
public:
	static void ShowLoginRegisterList()
	{
		if (!CheckAccessRigt(clsUser::enPermissions::pLogRegisterScreen))
		{
			return;
        }
	vector	<clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterList();
		string Title = "\tLogin Register List Screen :-) ";
		string SubTitle = "\t(" + to_string(vLoginRegisterRecord.size()) + ") Record(s)";
		clsScreen::_DrawScreenHeader(Title, SubTitle);
		cout << left << setw(8) << "\n\t____________________________________________________________";
		cout << "________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(40) << "Date Time";
		cout << "| " << left << setw(15) << "Username";
		cout << "| " << left << setw(12) << "Pasword";
		cout << "| " << left << setw(12) << "Permissions";
		cout << left << setw(8) << "\n\t____________________________________________________________";
		cout << "________________________________\n" << endl;
		if (vLoginRegisterRecord.size() == 0)
		{
			cout << "\t\t\t\tNo Records in the system!";
		}
		else
		{
			for (clsUser::stLoginRegisterRecord& Record : vLoginRegisterRecord)
			{
				_PrintLoginRecordLine(Record);
				cout << endl;
			}
		}
		cout << left << setw(8) << "\n\t____________________________________________________________";
		cout << "________________________________\n" << endl;
	}
};

