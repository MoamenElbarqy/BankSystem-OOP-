#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
class clsListCurrencies :private clsScreen
{
private:

public:
	static void ShowListCurrenciesScreen()
	{
		vector<clsCurrency> vCurrencies = clsCurrency::LoadCurrenciesFromFile();

		DrawScreenHeader("\t List Currencies Screen");
		string subTitle = "(" + to_string(vCurrencies.size()) + ")" + " clinet(s)";
		cout << "\t-------------------------------------------------------------------------------------\n";
		cout << "\t|        Country                |    Code     |     Name            | Rate by dollar\n";
		cout << "\t-------------------------------------------------------------------------------------\n";
		for (clsCurrency Currency : vCurrencies)
		{
			cout << "\t|" << setw(31) << left << Currency.GetCountryName();
			cout << "|" << setw(13) << left << Currency.GetCode();
			cout << "|" << setw(21) << left << Currency.GetCurrencyName();
			cout << "|" << setw(15) << left << Currency.GetRate();
			cout << endl;
		}
		cout << "\t---------------------------------------------------------------------------------------------------------\n";
    }
};

