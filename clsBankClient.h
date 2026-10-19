#pragma once
#include<iostream>
#include"clsPerson.h"
#include"clsString.h"
#include<vector>
#include<fstream>
#include<string>
#include"clsDate.h"
#include"Global.h"
using namespace std;

class clsBankClient : public clsPerson
{
private:
	enum enMode {EmptyMode=0,UpdateMode=1,AddNewMode=2};
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkForDelete=false;
	struct stTransferLogRecord;
	static clsBankClient _ConvertLineToClientObject(string Line, string Seperator = "#//#")
	{
		vector <string> vClientData;
		vClientData = clsString::Split(Line, Seperator);
		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3],
			vClientData[4], vClientData[5], stod(vClientData[6]));
	}
	static stTransferLogRecord _ConvertTransferLogLineToRecord(string Line,string Seperator="#//#")
	{
		vector <string> TransferRegisterDataLine = clsString::Split(Line,Seperator);
		stTransferLogRecord TransferLogRecord;
		TransferLogRecord.Date = TransferRegisterDataLine[0];
		TransferLogRecord.SourceAccountNumber = TransferRegisterDataLine[1];
		TransferLogRecord.DestinationAccountNumber = TransferRegisterDataLine[2];
		TransferLogRecord.Amount = stod(TransferRegisterDataLine[3]);
		TransferLogRecord.SourceBalanceAfter = stod(TransferRegisterDataLine[4]);
		TransferLogRecord.DestinationBalanceAfter = stod(TransferRegisterDataLine[5]);
		TransferLogRecord.Username = TransferRegisterDataLine[6];
		return TransferLogRecord;
	}
	static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{
		string Line="";
		Line += Client.FirstName + Seperator;
		Line += Client.LastName + Seperator;
		Line += Client.Email + Seperator;
		Line += Client.Phone + Seperator;
		Line += Client.AccountNumber() + Seperator;
		Line += Client.PinCode + Seperator;
		Line += to_string(Client.AccountBalance);
		return Line;

	}
	static void _SaveClientsDataToFile(vector <clsBankClient> vClients)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);
		string DataLine;
	if(	MyFile.is_open())
		{
		for (clsBankClient& C : vClients)
		{
			if (C._MarkForDelete == false)
			{
				DataLine = _ConvertClientObjectToLine(C);
				MyFile << DataLine << endl;
			}
			}
		MyFile.close();
		}

	}
	static vector <clsBankClient> _LoadClientsDataFromFile()
	{
		fstream MyFile;
		vector <clsBankClient> vClients;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				vClients.push_back(Client);

			}
			MyFile.close();

			}
		return vClients;
	}
	 void  _Update()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();
		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}
		}
		_SaveClientsDataToFile(_vClients);

	}
	  string _PrepareTransferLogRecord(double Amount, clsBankClient DestinationClient,string Username, string Seperator="#//#")
	 {
		 string stDataLine = "";
		 stDataLine += clsDate::GetSystemDateTimeSring() + Seperator;
		 stDataLine += _AccountNumber + Seperator;
		 stDataLine += DestinationClient.AccountNumber() + Seperator;
		 stDataLine += to_string(Amount) + Seperator;
		 stDataLine += to_string(AccountBalance) + Seperator;
		 stDataLine += to_string(DestinationClient.AccountBalance) + Seperator;
		 stDataLine += Username;
		 return stDataLine;
	 }
	   void _RegisterTransferLog(double Amount, clsBankClient DestinationClient,string Username)
	 {
		 fstream MyFile;
		 
		 MyFile.open("TransferLog.txt", ios::out | ios::app);
		 if (MyFile.is_open())
		 {
			 string Line;
			 Line = _PrepareTransferLogRecord( Amount,DestinationClient,Username);
			 MyFile << Line << endl;
			 MyFile.close();
		 }
	 }
	 void _AddNew()
	 {
		 _AddNewDataLineToFile(_ConvertClientObjectToLine(*this));
	 }
	 void _AddNewDataLineToFile(string stDataLine)
	 {
		 fstream MyFile;
		 MyFile.open("Clients.txt", ios::out | ios::app);
		 if (MyFile.is_open())
		 {
			 MyFile << stDataLine << endl;
			 MyFile.close();
		 }
	 }
	static clsBankClient _GetEmpytyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
public:
	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone,
		string AccountNumber, string PinCode, float AccountBalance) :clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}
	struct stTransferLogRecord
	{
		string Date;
		string SourceAccountNumber;
		string DestinationAccountNumber;
		double Amount;
		double SourceBalanceAfter;
		double DestinationBalanceAfter;
		string Username;
	};
	bool IsEmpty()
	{
		return _Mode == enMode::EmptyMode;
	}
	string AccountNumber()
	{
		return _AccountNumber;
	}
	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	string GetPinCode()
	{
		return _PinCode;
	}
	_declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;
	void SetAccountBalaance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	_declspec(property(get = GetAccountBalance, put = SetAccountBalaance)) float AccountBalance;
	//void Print()
	//{
	//	cout << "\nClient Card :";
	//	cout << "\n________________________";
	//	cout << "\nFirst Name    : " << FirstName;
	//	cout << "\nLast Name     : " << LastName;
	//	cout << "\nFull Name     : " << FullName();
	//	cout << "\nEmail         : " << Email;
	//	cout << "\nPhone         : " << Phone;
	//	cout << "\nAcc.Number    : " << _AccountNumber;
	//	cout << "\nPassword      : " << PinCode;
	//	cout << "\nBalance       : " << AccountBalance;
	//	cout << "\n________________________\n";
	//}
	static clsBankClient Find(string AccountNumber)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}

		return _GetEmpytyClientObject();
	}
	static clsBankClient Find(string AccountNumber,string PinCode)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}

		return _GetEmpytyClientObject();
	}
	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Clinet1 = clsBankClient::Find(AccountNumber);
		return (!Clinet1.IsEmpty());
	}
	enum enSaveResults{svFailidEmptyObject=0,svSucceded=1,svFaliadAccountNumberExists=2};
	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			return enSaveResults::svFailidEmptyObject;
			break;
		}
		case enMode::UpdateMode:
		{

			_Update();
			return enSaveResults::svSucceded;
			break;
		}
		case enMode::AddNewMode:
			if (IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFaliadAccountNumberExists;
			}
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceded;
			}

		}


	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }
	bool Delete()
	{
		vector <clsBankClient> vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : vClients)
		{
			if (C.AccountNumber() == _AccountNumber)
			{
				C._MarkForDelete = true;
				break;
			}
		}
		_SaveClientsDataToFile(vClients);
		*this = _GetEmpytyClientObject();
		return true;
	}
	static vector <clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}
	static double GetTotalBalances()
	{
		vector <clsBankClient> vClients = GetClientsList();
		double TotalBalances = 0;
		for (clsBankClient& C : vClients)
		{
			TotalBalances += C.AccountBalance;
		}
		return TotalBalances;
	}
	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}
	bool Withdraw(double Amount)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}
		else
		{
			_AccountBalance -= Amount;
			Save();
			return true;
		}
	}
	bool Transfer(float Amount, clsBankClient& DestinationClient,string Username)
	{
		if (Amount > AccountBalance||_AccountNumber==DestinationClient._AccountNumber)
		{
			return false;
		}
		Withdraw(Amount);
		DestinationClient.Deposit(Amount);
		_RegisterTransferLog(Amount,DestinationClient,Username);
		return true;
	}
static	vector <stTransferLogRecord> GetTansferLogList()
	{
		vector <stTransferLogRecord> vTransferLogRecord;
		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			stTransferLogRecord TransferLogRecord;
			while (getline(MyFile, Line))
			{
				TransferLogRecord = _ConvertTransferLogLineToRecord(Line);
				vTransferLogRecord.push_back(TransferLogRecord);
			}
			MyFile.close();
		}
		return vTransferLogRecord;
	}
};

