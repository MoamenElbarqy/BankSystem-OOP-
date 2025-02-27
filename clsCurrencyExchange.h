#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrencyCalculator.h"
#include "clsFindCurrencuey.h"
#include "clsUpdateRate.h"
#include "clsListCurrencies.h"
class clsCurrencyExchange :private clsScreen
{
private:
	enum enCurrencyExchange
	{
		ListCurrencies = 1,
		FindCurrencuey = 2,
		UpdateRate = 3,
		CurrencyCalculator = 4,
		MainScreen = 5
	};
	static void _BackToCurrencyExchangeScreen()
	{
		cout << setw(37) << left << "" << "\n\t\t\t\tPress any key to go back to Currency Exchange Menue...\n";
		system("pause>0");
		ShowCurrencyExchangeScreen();
	}
	static void _PerfromCurrencyExchangeOptions(enCurrencyExchange Choice)
	{
		switch (Choice)
		{
		case clsCurrencyExchange::ListCurrencies:
			system("cls");
			clsListCurrencies::ShowListCurrenciesScreen();
			_BackToCurrencyExchangeScreen();
			break;
		case clsCurrencyExchange::FindCurrencuey:
			system("cls");
			clsFindCurrencuey::ShowFindCurrencueyScreen();
			_BackToCurrencyExchangeScreen();
			break;
		case clsCurrencyExchange::UpdateRate:
			system("cls");
			clsUpdateRate::ShowUpdateRateScreen();
			_BackToCurrencyExchangeScreen();
			break;
		case clsCurrencyExchange::CurrencyCalculator:
			system("cls");
			clsCurrencyCalculator::ShowCurrencyCalculatorScreen();
			_BackToCurrencyExchangeScreen();
			break;
		}
	}
public:
	static void ShowCurrencyExchangeScreen()
	{
		system("cls");
		if (!hasAccess(clsUser::enUsersPermissions::pAddNewClient)) return; // Acceess Check
		DrawScreenHeader("Currency Exchange Main Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\tCurrency Exchange Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currencuey.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Screen.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "Choose What Do you Want to Do :";

		_PerfromCurrencyExchangeOptions((enCurrencyExchange)clsInputValidate::ReadNumberBetween(1, 5));
	}
	
};

