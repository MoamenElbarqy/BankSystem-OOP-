#pragma once
#include <iostream>
#include "clsUtil.h"
#include "clsCurrency.h"
#include "clsScreen.h"
class clsFindCurrencuey :public clsScreen
{
private:
	static void Print(clsCurrency MyCurrency)
	{
		cout << "\nCurrency Data:";
		cout << "\n___________________";
		cout << "\nCountry       : " << MyCurrency.GetCountryName();
		cout << "\nCode          : " << MyCurrency.GetCode();
		cout << "\nCurrency Name : " << MyCurrency.GetCurrencyName();
		cout << "\nRate          : " << MyCurrency.GetRate();
		cout << "\n___________________\n";

	}
public:
	static void ShowFindCurrencueyScreen()
	{
		clsCurrency MyCuurency;
		DrawScreenHeader("\tFind Currencuey Screen");

		cout << "Find By Country Code [1] or Country Name [2] : ";
		short UserChoice = clsInputValidate::ReadNumberBetween(1, 2);
		switch (UserChoice)
		{
		case 1:
		{
			cout << "Please Enter Country Code : ";
			string CountryCode = clsInputValidate::ReadString();

			CountryCode = clsUtil::UpperAll(CountryCode);

			MyCuurency = clsCurrency::FindByCode(CountryCode);

			if (MyCuurency.isEmpty())
			{
				cout << "\n===============================\n";
				cout << " Currency is Not Found :-(\n";
				cout << "===============================\n";
			}
			else
			{
				Print(MyCuurency);
			}
			break;

		}

		case 2:

		{
			cout << "Please Enter Country Name : ";
			string CountryName = clsInputValidate::ReadString();

			CountryName = clsUtil::UpperAll(CountryName);

			MyCuurency = clsCurrency::FindByName(CountryName);

			if (MyCuurency.isEmpty())
			{
				cout << "\n===============================\n";
				cout << " Currency is Not Found :-(\n";
				cout << "===============================\n";
			}
			else
			{
				Print(MyCuurency);
			}
			break;

		}

		}


	}
};

