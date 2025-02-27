#pragma once
#include <iomanip>
#include "clsBankClient.h"
#include "Global.h"

class clsShowClientListScreen : private clsScreen
{
public:
	static void ShowClientsListScreen()
	{
		if (!hasAccess(clsUser::enUsersPermissions::pListClients)) return; // This Will Show Access Denied Screen Internaly

		vector<clsBankClient> vMyClients = clsBankClient::LoadDataClientsFromFile();
		string subTitle = "(" + to_string(vMyClients.size()) + ")" + " clinet(s)";
		if (vMyClients.size() == 0) subTitle = "No Clients Available";
		DrawScreenHeader("\tClients List Screen ", subTitle);

		cout << "\t---------------------------------------------------------------------------------------------------------\n";
		cout << "\t|Account Number   | Pin Code  |  Client Name      | Phone          |       Email                | Balance \n";
		cout << "\t---------------------------------------------------------------------------------------------------------\n";
		for (clsBankClient CurrentClient : vMyClients)
		{
			cout << "\t|" << setw(17) << left << CurrentClient.GetAccNumber();
			cout << "|" << setw(11) << left << CurrentClient.GetPinCode();
			cout << "|" << setw(19) << left << CurrentClient.GetFirstName() + " " + CurrentClient.GetLastName();
			cout << "|" << setw(16) << left << CurrentClient.GetPhoneNumber();
			cout << "|" << setw(28) << left << CurrentClient.GetEmail();
			cout << "|" << setw(7) << left << CurrentClient.GetBalance();
			cout << endl;
		}
		cout << "\t---------------------------------------------------------------------------------------------------------\n";
	}
};

