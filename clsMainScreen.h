#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsShowClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsMangeUsersScreen.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyExchange.h"
#include "Global.h"

using namespace std;

class clsMainScreen : private clsScreen
{
private:
	enum enMainMenuChoices
	{
		enShowClientList = 1,
		enAddNewClient = 2,
		enDeleteClient = 3,
		enUpdateClientInfo = 4,
		enFindClient = 5,
		enTransactions = 6,
		enMangeUsers = 7,
		enLoginRegister = 8,
		enCurrencyExchange = 9,
		enLogout = 10
	};
	static  void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\t\t\t\tPress any key to go back to Main Menue...\n";
		system("pause>0");
		ShowMainMenueScreen();
	}
	static void _ShowAllClientsScreen()
	{
		clsShowClientListScreen::ShowClientsListScreen();
	}

	static void _ShowAddNewClientsScreen()
	{
		clsAddNewClient::AddNewClient();
	}

	static void _ShowDeleteClientScreen()
	{
		clsDeleteClientScreen::DeleteClient();
	}

	static void _ShowUpdateClientScreen()
	{
		clsUpdateClientScreen::UpdateClient();
	}

	static void _ShowFindClientScreen()
	{
		clsFindClientScreen::FindClientScreen();
	}

	static void _ShowTransactionsMenue()
	{
		clsTransactionsScreen::ShowTransactionsScreen();
	}

	static void _ShowManageUsersMenue()
	{
		clsMangeUsersScreen::ShowMangeUsersScreen();
	}
	static void _ShowLoginRegisterScreen()
	{
		clsLoginRegisterScreen::ShowLoginRegisterScreen();
	}
	static void _ShowShowCurrencyExchangeMenue()
	{
		clsCurrencyExchange::ShowCurrencyExchangeScreen();
	}
	static void _Logout()
	{
		SystemUser = clsUser::Find(""); // Make The System User Empty Until The User Loged In Again
	}
	static void _PerfromMainMenueOptions(enMainMenuChoices choice)
	{
		switch (choice)
		{
		case enMainMenuChoices::enShowClientList:
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenue();
			break;
		case enMainMenuChoices::enAddNewClient:
			system("cls");
			_ShowAddNewClientsScreen();
			_GoBackToMainMenue();
			break;
		case enMainMenuChoices::enDeleteClient:
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenue();
			break;
		case enMainMenuChoices::enUpdateClientInfo:
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenue();
			break;
		case enMainMenuChoices::enFindClient:
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenue();
			break;
		case enMainMenuChoices::enTransactions:
			system("cls");
			_ShowTransactionsMenue();
			_GoBackToMainMenue();
			break;
		case enMainMenuChoices::enMangeUsers:
			system("cls");
			_ShowManageUsersMenue();
			_GoBackToMainMenue();
			break;
		case enMainMenuChoices::enLoginRegister:
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenue();
			break;
		case enMainMenuChoices::enCurrencyExchange:
			system("cls");
			_ShowShowCurrencyExchangeMenue();
			_GoBackToMainMenue();
			break;
		case enMainMenuChoices::enLogout:
			system("cls");
			_Logout();
			break;
		}
	}
public:
	static void ShowMainMenueScreen()
	{
		system("cls");
		DrawScreenHeader("\t\tMain Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Login Register.\n";
		cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
		cout << setw(37) << left << "" << "\t[10] Logout.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "Choose What Do you Want to Do :";

		_PerfromMainMenueOptions((enMainMenuChoices)clsInputValidate::ReadNumberBetween(1, 10));
	}

};

