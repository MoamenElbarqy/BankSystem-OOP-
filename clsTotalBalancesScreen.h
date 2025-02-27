#pragma once
#include <vector>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "Global.h"

class clsTotalBalacnesScreen : private clsScreen
{
private:
public:
	static void TotalBalances()
	{
		vector<clsBankClient> vMyClients = clsBankClient::LoadDataClientsFromFile();

		string subTitle = "   (" + to_string(vMyClients.size()) + ")" + " clinet(s)";
		DrawScreenHeader("\tTotal Balances Screen", subTitle);

		cout << "\t\t\t\t========================================\n";
		cout << "\t\t\t\t\t" << "Total Balances is : $" << clsBankClient::CountTotalBalances(vMyClients) << endl;
		cout << "\t\t\t\t========================================\n";


		cout << "\t--------------------------------------------------------------------------------------------\n";
		cout << "\t|          Account Number             |            Client Name           |      Balance     \n";
		cout << "\t--------------------------------------------------------------------------------------------\n";
		if (vMyClients.size() == 0)
		{
			cout << "\t\tNo Clients Available\n";
		}
		else
		{
			for (clsBankClient CurrentClient : vMyClients)
			{
				cout << "\t|" << setw(37) << left << CurrentClient.GetAccNumber();
				cout << "|" << setw(19 + 15) << left << CurrentClient.GetFirstName() + " " + CurrentClient.GetLastName();
				cout << "|" << setw(17) << left << CurrentClient.GetBalance();
				cout << endl;
			}

		}
		cout << "\t--------------------------------------------------------------------------------------------\n";
	}
};