#pragma once
#include <iomanip>
#include "clsScreen.h"
#include "clsUsersListScreen.h"
#include "clsAddNewUsersScreen.h"
#include "clsDeleteUsersScreen.h"
#include "clsUpdateUsersScreen.h"
#include "clsFindUsersScreen.h"
#include "clsInputValidate.h"
#include "Global.h"

class clsMangeUsersScreen : private clsScreen
{
private:
	enum enMangeUsersMenueOptions
	{
		enShowUsersList = 1,
		enAddNewUser = 2,
		enDeleteUser = 3,
		enUpdateUser = 4,
		enFindUser = 5,
		enMainMenue = 8
	};
	static void _BackToMangeUsersScreen()
	{
		cout << setw(37) << left << "" << "\n\t\t\t\tPress any key to go back to Mange Users Menue...\n";
		system("pause>0");
		ShowMangeUsersScreen();
	}
	static void _ShowUsersListScreen()
	{
		clsUsersListScreen::ShowUsersListScreen();
	}
	static void _ShowAddNewUsersScreen()
	{
		clsAddNewUsersScreen::AddNewUser();
	}
	static void _ShowDeleteUsersScreen()
	{
		clsDeleteUsersScreen::DeleteUser();
	}
	static void _ShowUpdateUsersScreen()
	{
		clsUpdateUsersScreen::UpdateUser();
	}
	static void _ShowFindUsersScreen()
	{
		clsFindUsersScreen::FindUserScreen();
	}
	static void _PerfromMangeUsersOptions(enMangeUsersMenueOptions Choice)
	{
		switch (Choice)
		{
		case clsMangeUsersScreen::enShowUsersList:
		{
			system("cls");
			_ShowUsersListScreen();
			_BackToMangeUsersScreen();
			break;
		}
		case clsMangeUsersScreen::enAddNewUser:
		{
			system("cls");
			_ShowAddNewUsersScreen();
			_BackToMangeUsersScreen();
			break;
		}
		case clsMangeUsersScreen::enDeleteUser:
		{
			system("cls");
			_ShowDeleteUsersScreen();
			_BackToMangeUsersScreen();
			break;
		}
		case clsMangeUsersScreen::enUpdateUser:
		{
			system("cls");
			_ShowUpdateUsersScreen();
			_BackToMangeUsersScreen();
			break;
		}
		case clsMangeUsersScreen::enFindUser:
		{
			system("cls");
			_ShowFindUsersScreen();
			_BackToMangeUsersScreen();
			break;
		}
		}
	}
public:
	static void ShowMangeUsersScreen()
	{
		if (!hasAccess(clsUser::enUsersPermissions::pMangeUsers)) return; // This Will Show Access Denied Screen Internaly

		system("cls");
		DrawScreenHeader("\t\tMange Users Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMange Users\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show User List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "Choose What Do you Want to Do :";

		_PerfromMangeUsersOptions((enMangeUsersMenueOptions)clsInputValidate::ReadNumberBetween(1, 6));
	}

};

