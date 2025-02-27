#pragma once
#include "clsScreen.h"
#include "Global.h"

class clsFindUsersScreen : private clsScreen
{
private:
	static void _Print(clsUser MyUser)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << MyUser.GetFirstName();
		cout << "\nLastName    : " << MyUser.GetLastName();
		cout << "\nFull Name   : " << MyUser.GetFirstName() + " " + MyUser.GetLastName();
		cout << "\nEmail       : " << MyUser.GetEmail();
		cout << "\nPhone       : " << MyUser.GetPhoneNumber();
		cout << "\nUsername    : " << MyUser.GetUserName();
		cout << "\nPermissions  : " << MyUser.GetPermissions();
		cout << "\n___________________\n";
	}
public:
	static void FindUserScreen()
	{
		DrawScreenHeader("\tFind Users Screen");
		cout << "Please Enter UserName : ";
		string UserName = clsInputValidate::ReadString();
		if (!clsUser::isUserExisted(UserName))
		{
			cout << "\n===============================\n";
			cout << " User Is't Found :-(\n";
			cout << "===============================\n";			
		}
		else
		{
			clsUser MyUser = clsUser::Find(UserName);
			_Print(MyUser);
		}
	}
};

