#pragma once
#include<iostream>
#include"clsPerson.h"
#include<string>
#include<vector>
#include<fstream>
#include<clsString.h>
#include"clsUtil.h"
using namespace std;

class clsUser : public clsPerson
{
	enum enMode {eEmptyMode=0,eUpdateMode=1,eAddNewMode=2};
	enMode _Mode;
	string _UserName;
	string _Password;
	string _Time;
	int _Permissions;
	bool _MarkForDelete=false;
struct stLoginRegisterRecord;
	static clsUser _ConvertLineToUserObject(string Line,string Seperator="#//#")
	{
		vector <string> vUserData = clsString::Split(Line, Seperator);
		return clsUser(enMode::eUpdateMode, vUserData[0], vUserData[1], vUserData[2],
			vUserData[3], vUserData[4],clsUtil::DecryptText( vUserData[5]), stoi(vUserData[6]));
	}
	static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line, string Seperator = "#//#")
	{
		vector <string> LoginRegisterDataLine = clsString::Split(Line, Seperator);
		stLoginRegisterRecord LoginRegisterRecord;
		LoginRegisterRecord.DataTime = LoginRegisterDataLine[0];
		LoginRegisterRecord.Username = LoginRegisterDataLine[1];
		LoginRegisterRecord.Password =clsUtil::DecryptText( LoginRegisterDataLine[2]);
		LoginRegisterRecord.Permissions = stoi(LoginRegisterDataLine[3]);
		return LoginRegisterRecord;
	}
	 string _PrepareLoginRecord(string Seperator = "#//#")
	{
		string LoginRecord = "";
		LoginRecord += clsDate::GetSystemDateTimeSring()+Seperator;
		LoginRecord +=  Username + Seperator;
		LoginRecord += clsUtil::EncryptText(Password) + Seperator;
		LoginRecord += to_string(Permissions);
		return LoginRecord;
	}
	static string _ConvertUserObjectToLine(clsUser User,string Seperator="#//#")
	{
		string UserData = "";
		UserData += User.FirstName + Seperator;
		UserData += User.LastName + Seperator;
		UserData += User.Email + Seperator;
		UserData += User.Phone + Seperator;
		UserData += User.Username + Seperator;
		UserData +=clsUtil::EncryptText( User.Password)+ Seperator;
		UserData += to_string(User.Permissions);
		return UserData;
	}
	static vector <clsUser> _LoadUsersDataFromFile()
	{
		vector <clsUser> vUsers;
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				vUsers.push_back(User);
			}
			MyFile.close();
		}
		return vUsers;
	}

	static void _SaveDataToFile(vector <clsUser> vUsers)
	{
		fstream MyFile;
		string DataLine;
		MyFile.open("Users.txt", ios::out);
		if (MyFile.is_open())
		{
			for (clsUser& U : vUsers)
			{
				if (U.MarkForDelete() == false)
				{
					DataLine = _ConvertUserObjectToLine(U);
					MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}
	}
	 void _Update()
	{
		vector <clsUser> vUsers = _LoadUsersDataFromFile();
		for (clsUser& U : vUsers)
		{
			if (U.Username == Username)
			{
				U = *this;
				break;
			}
		}
		_SaveDataToFile(vUsers);

	}
	 void _AddNew()
	 {
		 _AddDataLineToFile(_ConvertUserObjectToLine(*this));
	 }
	 void _AddDataLineToFile(string stDataLine)
	 {
		 fstream MyFile;
		 MyFile.open("Users.txt", ios::out | ios::app);
		 if (MyFile.is_open())
		 {
			 MyFile << stDataLine << endl;
			 MyFile.close();
		 }

	 }
	static clsUser _GetEmptyUserObject()
	{
		return	clsUser(enMode::eEmptyMode, "", "", "", "", "", "", 0);
	}
public:
	enum enPermissions { eAll=-1,pListClients=1,pAddNewClient=2,pDeleteClient=4,pUpdateClients=8,
	pFindClient=16,pTransactions=32,pManageUsers=64,pLogRegisterScreen=128};
	clsUser(enMode Mode, string FirstName, string LastName, string Email, string phone, string UserName,
		string Password, int Permissions) :clsPerson(FirstName, LastName, Email, phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}
	struct stLoginRegisterRecord
	{
		string DataTime;
		string Username;
		string Password;
		int Permissions;
	};
 bool IsEmpty()
	{
		return (_Mode == enMode::eEmptyMode);
	}
	bool MarkForDelete()
	{
		return _MarkForDelete;
	}
	string Time()
	{
		return _Time;
	}
	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}
	string GetUserName()
	{
		return _UserName;
	}
	_declspec(property(get = GetUserName, put = SetUserName)) string Username;
	void SetPassword(string Password)
	{
		_Password = Password;
	}
	string GetPassword()
	{
		return _Password;
	}
	_declspec(property(get = GetPassword, put = SetPassword)) string Password;
	void SetPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}
	int GetPermission()
	{
		return _Permissions;
	}
	_declspec(property(get = GetPermission, put = SetPermissions)) int Permissions;
	static clsUser Find(string UserName)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				if (User.Username == UserName)
				{
					MyFile.close();
					return User;
				}
			}
		}
		return _GetEmptyUserObject();
	}
	static clsUser Find(string UserName,string Password)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				if (User.Username == UserName&&User.Password==Password)
				{
					MyFile.close();
					return User;
				}
			}
		}
		return _GetEmptyUserObject();
	}
	static bool ISUserExist(string UserName)
	{
		clsUser User = clsUser::Find(UserName);
		return (!User.IsEmpty());
	}
	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };
	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::eEmptyMode:
		{
			if (IsEmpty())
				return enSaveResults::svFaildEmptyObject;
			break;
		}

		case enMode::eUpdateMode:
			_Update();
			return enSaveResults::svSucceeded;
			break;

		case enMode::eAddNewMode:
			if (clsUser::ISUserExist(_UserName))
			{
				return enSaveResults::svFaildUserExists;
				
			}
			else
			{
			   _AddNew();
			   _Mode = enMode::eUpdateMode;
				return enSaveResults::svSucceeded;
			}
			break;
		}

	}
	bool Delete()
	{
		vector <clsUser> vUsers = _LoadUsersDataFromFile();
		for (clsUser& U : vUsers)
		{
			if (U.Username == _UserName)
			{
				U._MarkForDelete = true;
				break;
			}
		}
		_SaveDataToFile(vUsers);
		*this = _GetEmptyUserObject();
		return true;
	}
	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(enMode::eAddNewMode, "", "", "", "", UserName, "", 0);
	}
	static vector <clsUser> GetUsersList()
	{
		return _LoadUsersDataFromFile();
	}
	
	bool CheckAccessPermission(enPermissions Permissions)
	{
		if (this->Permissions == enPermissions::eAll)
			return true;
		if ((this->Permissions & Permissions) == Permissions)
			return true;
		else
			false;

	}
	 void RegisterLogin()
	{
		fstream MyFile;
		string stDataLine = _PrepareLoginRecord();
		MyFile.open("LoginRegister.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << stDataLine<< endl;
			MyFile.close();
		}

	}
	 static vector <stLoginRegisterRecord> GetLoginRegisterList()
	 {
		 vector <stLoginRegisterRecord> vLoginRegisterRecord;
		 fstream MyFile;
		 MyFile.open("LoginRegister.txt", ios::in);
		 if (MyFile.is_open())
		 {
			 string Line;
			 stLoginRegisterRecord LoginRegisterRecord;
			 while (getline(MyFile, Line))
			 {
				 LoginRegisterRecord = _ConvertLoginRegisterLineToRecord(Line);
				 vLoginRegisterRecord.push_back(LoginRegisterRecord);
			 }
			 MyFile.close();
		 }
		 return vLoginRegisterRecord;
	 }
};

