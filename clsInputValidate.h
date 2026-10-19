#pragma once
#include<iostream>
#include "clsDate.h"
#include<string>
using namespace std;
class clsInputValidate
{
	public:
		static bool IsNumberBetween(short Number, short From, short To)
		{
			return (Number >= From && Number <= To);
		}
		static bool IsNumberBetween(int Number, int From, int To)
		{
			return (Number >= From && Number <= To);
		}
		static bool IsNumberBetween(float Number, float From, float To)
		{
			return (Number >= From && Number <= To);
		}
		static bool IsNumberBetween(double Number, double From, double To)
		{
			return (Number >= From && Number <= To);
		}
		static bool IsDateBetween(clsDate Date, clsDate DateFrom, clsDate DateTo)
		{
			if (clsDate::IsDate1AfterDate2(DateFrom, DateTo))
			{
				clsDate::SwapDates(DateFrom, DateTo);
			}
			if ((clsDate::IsDate1AfterDate2(Date, DateFrom) || clsDate::IsDate1EqualDate2(Date, DateFrom))
				&&
				(clsDate::IsDate1BeforeDate2(Date, DateTo) || clsDate::IsDate1EqualDate2(Date, DateTo)))
			{
				return true;
			}

		}
		static int ReadIntNumber(string ErrorMessage="Ivalid number,Enetr again\n")
		{
			int Number;
			cin >> Number;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << ErrorMessage ;
				cin >> Number;
			}
			return Number;
		}
		static short ReadShortNumber(string ErrorMessage = "Ivalid number,Enetr again\n")
		{
			short Number;
			cin >> Number;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << ErrorMessage;
				cin >> Number;
			}
			return Number;
		}
		static float ReadFloatNumber(string ErrorMessage = "Ivalid number,Enetr again\n")
		{
			float Number;
			cin >> Number;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << ErrorMessage;
				cin >> Number;
			}
			return Number;
		}
		static double ReadDbNumber(string ErrorMessage= "Ivalid number,Enetr again\n")
		{
			double Number;
			cin >> Number;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << ErrorMessage;
				cin >> Number;
			}
			return Number;
		}
		static int ReadIntNumberBetween(int From, int To, string ErrorMessage)
		{
			int Number;
			Number = ReadIntNumber();
			while (!IsNumberBetween(Number,From,To))
			{
				cout << ErrorMessage;
				Number = ReadIntNumber();
			}
			return Number;
		}
		static short ReadShortNumberBetween(short From, short To, string ErrorMessage)
		{
			short Number;
			Number = ReadShortNumber();
			while (!IsNumberBetween(Number, From, To))
			{
				cout << ErrorMessage;
				Number = ReadIntNumber();
			}
			return Number;
		}
		static double ReadDbNumberBetween(double From, double To, string ErrorMessage)
		{
			double Number;
			Number = ReadDbNumber();
			while (!IsNumberBetween(Number,From,To))
			{
				cout << ErrorMessage;
				Number = ReadDbNumber();
			}
			return Number;
		}
		static bool ISValideDate(clsDate Date)
		{
			return clsDate::IsValidDate(Date);
		}
		static string ReadString()
		{
			string S;
			getline(cin >> ws, S);
			return S;
		}
};

