#pragma once
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsScreen.h"
#include "clsUser.h"
#include "Global.h"
class clsLoginScreen : private clsScreen
{
public:
	static void ShowLoginScreen()
	{
		system("cls");
		DrawScreenHeader("\tLogin Screen");

		short AvailableTrials = 3;
		bool LoginStatus = false;
		string UserName = "";
		string PassWord = "";

		while (!LoginStatus)
		{

			cout << "UserName : ";
			UserName = clsInputValidate::ReadString();

			cout << "Password : ";
			PassWord = clsInputValidate::ReadString();

			SystemUser = clsUser::Find(UserName, PassWord);

			if (!SystemUser.isEmpty())
				LoginStatus = true;
			else
			{
				if (!--AvailableTrials)
				{
					LockTheSystem = true;
					return;
				}
				else
				{
					cout << "\nInvalid UserName/Password, Enter a Valid User.\n";
					cout << "AvailableTrials : " << AvailableTrials << "\n\n";
				}			
			}
		}
		SystemUser.SaveLoginStatus();// Saved The Login Info  Date, Time, UserName And User Permissions in login Register File
		clsMainScreen::ShowMainMenueScreen();
	}
};

