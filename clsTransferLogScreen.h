#pragma once
#include<iostream>
#include<vector>
#include"clsScreen.h"
#include"clsBankClient.h"
#include<iomanip>
class clsTransferLogScreen :protected clsScreen
{
private:
	static void _PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord TransferLogRecord)
	{
		cout << setw(8) << left << "" << "| " << left << setw(23) << TransferLogRecord.Date;
		cout << "| " << left << setw(8) << TransferLogRecord.SourceAccountNumber;
		cout << "| " << left << setw(8) << TransferLogRecord.DestinationAccountNumber;
		cout << "| " << left << setw(8) << TransferLogRecord.Amount;
		cout << "| " << left << setw(10) << TransferLogRecord.SourceBalanceAfter;
		cout << "| " << left << setw(10) << TransferLogRecord.DestinationBalanceAfter;
		cout << "| " << left << setw(8) << TransferLogRecord.Username;
			}
public:
	static void ShowTransferLogScreen()
	{
		
		vector	<clsBankClient::stTransferLogRecord> vTransferRegisterRecord = clsBankClient::GetTansferLogList();
		string Title = "\tTransfer Register List Screen :-) ";
		string SubTitle = "\t(" + to_string(vTransferRegisterRecord.size()) + ") Record(s)";
		clsScreen::_DrawScreenHeader(Title, SubTitle);
		cout << left << setw(8) << "\n\t____________________________________________________________";
		cout << "________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(23) << "Date Time";
		cout << "| " << left << setw(8) << "s.Acct";
		cout << "| " << left << setw(8) << "d.Acct";
		cout << "| " << left << setw(8) << "Amount";
		cout << "| " << left << setw(10) << "s.Balsnce";
		cout << "| " << left << setw(10) << "d.Balsnce";
		cout << "| " << left << setw(8) << "User";
		cout << left << setw(8) << "\n\t____________________________________________________________";
		cout << "________________________________________\n" << endl;
		if (vTransferRegisterRecord.size() == 0)
		{
			cout << "\t\t\t\tNo Records in the system!";
		}
		else
		{
			for (clsBankClient::stTransferLogRecord&Record : vTransferRegisterRecord)
			{
				_PrintTransferLogRecordLine(Record);
				cout << endl;
			}
		}
		cout << left << setw(8) << "\n\t____________________________________________________________";
		cout << "________________________________________\n" << endl;
	}


};

