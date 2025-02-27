#pragma once
#include <iostream>
#include <vector>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "Global.h"

class clsUsersListScreen :private clsScreen
{
public:
	static void ShowUsersListScreen()
	{
		vector<clsUser> vMyUsers = clsUser::LoadDataUsersFromFile();
		string subTitle = "  (" + to_string(vMyUsers.size()) + ")" + " clinet(s)";
		if (vMyUsers.size() == 0) subTitle = "No Users Available";
		DrawScreenHeader("\nUsers List Screen ", subTitle);

		cout << "\t--------------------------------------------------------------------------------------------------\n";
		cout << "\t|    UserName     |    Full Name         |     Phone      |       Email           |  Permissions  \n";
		cout << "\t--------------------------------------------------------------------------------------------------\n";
		for (clsUser CurrentUser : vMyUsers)
		{
			cout << "\t|" << setw(17) << left << CurrentUser.GetUserName();
			cout << "|" << setw(22) << left << CurrentUser.GetFirstName() + " " + CurrentUser.GetLastName();
			cout << "|" << setw(16) << left << CurrentUser.GetPhoneNumber();
			cout << "|" << setw(23) << left << CurrentUser.GetEmail();
			cout << "|" << setw(14) << left << CurrentUser.GetPermissions();
			cout << endl;
		}
		cout << "\t--------------------------------------------------------------------------------------------------\n";
	}
};

