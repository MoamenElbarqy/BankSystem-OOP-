#pragma once
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"
#include "Global.h"

class clsTransactionsScreen :  private clsScreen
{
private:
	static void _GoBackToTranactionsMenue()
	{

		cout << setw(37) << left << "" << "\n\t\t\t\tPress any key to go back to Main Menue...\n";
		system("pause>0");
		ShowTransactionsScreen();
	}
	static void _ShowDepositScreen()
	{
		clsDepositScreen::DepositClient();
	}
	static void _ShowWithdraw()
	{
		clsWithdrawScreen::WithdrawClient();
	}
	static void _ShowTotalBalances()
	{
		clsTotalBalacnesScreen::TotalBalances();
	}
	static void _ShowTransferScreen()
	{
		clsTransferScreen::ShowTransferScreen();
	}
	static void _ShowTransferLogScreen()
	{
		clsTransferLogScreen::ShowTransferLog();
	}
	enum enTransactions
	{
		enDeposit = 1,
		enWithdraw = 2,
		enTotalBalances = 3,
		enTransfer = 4,
		enTransferLog = 5,
		enMainMenu = 6
	};
	static void _PerfromTransactionsMenueOptions(enTransactions choice)
	{
		switch (choice)
		{
		case enTransactions::enDeposit:
			system("cls");
			_ShowDepositScreen();
			_GoBackToTranactionsMenue();
			break;
		case enTransactions::enWithdraw:
			system("cls");
			_ShowWithdraw();
			_GoBackToTranactionsMenue();
			break;
		case enTransactions::enTotalBalances:
			system("cls");
			_ShowTotalBalances();
			_GoBackToTranactionsMenue();
			break;
		case enTransactions::enTransfer:
			system("cls");
			_ShowTransferScreen();
			_GoBackToTranactionsMenue();
			break;
		case enTransactions::enTransferLog:
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTranactionsMenue();
			break;
		}
	}
	public:
		static void ShowTransactionsScreen()
		{
			if (!hasAccess(clsUser::enUsersPermissions::pTransactions)) return; // This Will Show Access Denied Screen Internaly

			system("cls");
			DrawScreenHeader("\tTransactions Screen");

			cout << setw(37) << left << "" << "===========================================\n";
			cout << setw(37) << left << "" << "\t\tTransactions Menue\n";
			cout << setw(37) << left << "" << "===========================================\n";
			cout << setw(37) << left << "" << "\t[1] Deposit.\n";
			cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
			cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
			cout << setw(37) << left << "" << "\t[4] Transfer.\n";
			cout << setw(37) << left << "" << "\t[5] Transfer Data.\n";
			cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
			cout << setw(37) << left << "" << "===========================================\n";
			cout << setw(37) << left << "" << "Choose What Do you Want to Do :";

			_PerfromTransactionsMenueOptions((enTransactions)clsInputValidate::ReadNumberBetween(1, 6));
		}
	};

