#pragma once
#include "clsScreen.h"
class clsUpdateRate :private clsScreen
{
private:
	static void PrintCurrency(clsCurrency MyCurrency)
	{
		cout << "\nCurrency Card:";
		cout << "\n___________________";
		cout << "\nCountry       : " << MyCurrency.GetCountryName();
		cout << "\nCode          : " << MyCurrency.GetCode();
		cout << "\nCurrency Name : " << MyCurrency.GetCurrencyName();
		cout << "\nRate          : " << MyCurrency.GetRate();
		cout << "\n___________________\n";

	}
public:
	static void ShowUpdateRateScreen()
	{
		DrawScreenHeader("\tUpdate Rate Screen");

		cout << "Please Enter Currecy Code : ";
		string CurrencyCode = clsInputValidate::ReadString();

		CurrencyCode = clsUtil::UpperAll(CurrencyCode); // To Make It Case Insistive

		while (!clsCurrency::isCurrencyExsisted(CurrencyCode))
		{
			cout << "We Can't Find The Currency, Please Enter a Valid Currency : ";
			CurrencyCode = clsInputValidate::ReadString();
			CurrencyCode = clsUtil::UpperAll(CurrencyCode);
		}
		clsCurrency MyCurrency = clsCurrency::FindByCode(CurrencyCode);
		PrintCurrency(MyCurrency);

		cout << "Please Enter New Rate : ";
		float newRate = clsInputValidate::ReadFloatNumber();
		while (newRate <= 0)
		{
			cout << "The Rate of The Currency Can't be Negative Number, Enter a positive one : ";
			newRate = clsInputValidate::ReadFloatNumber();
		}
		if (clsUtil::ContinueOperation("Are You Sure Do You Want To Update Rate (y / n) : "))
		{
			MyCurrency.SetRate(newRate);
			PrintCurrency(MyCurrency);
		}
		else
		{
			cout << "\n===============================\n";
			cout << " Operation Denied :-(\n";
			cout << "===============================\n";
		}

	}
};


