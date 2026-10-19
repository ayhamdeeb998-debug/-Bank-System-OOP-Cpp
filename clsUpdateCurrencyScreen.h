#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsUpdateCurrencyScreen :protected clsScreen
{
private:
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";

    }
    static float _ReadRate()
    {
        float NewRate;
        cout << "\nEnter New Rate : ";
        NewRate = clsInputValidate::ReadFloatNumber();
        return NewRate;
    }
public:
    static void _ShowUpdateCurrencyScreen()
    {
        _DrawScreenHeader("\tUpdate Currency Screen :-)");
        string Code;
        cout << "\nPlease enter Currency Code ? ";
        Code = clsInputValidate::ReadString();
        while (!clsCurrency::IsCurrencyExist(Code))
        {
            cout << "\nCurrency With code [" << Code << "] is not exist,Enter another code ? ";
            Code = clsInputValidate::ReadString();
        }
        clsCurrency Currency = clsCurrency::FindByCode(Code);
        _PrintCurrency(Currency);
        cout << "\n Are yoou sure you want to update the rate of the Currency ? Y/N ?";
        char Answer='n';
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            cout << "\n\nUpdate Currency Rate ";
            cout << "\n_______________________________\n";
            Currency.UpdateRate(_ReadRate());
            cout << "\nCurrency Rate Update Successfully :-)";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\nThe operation failed :-(";
        }
    }


};

