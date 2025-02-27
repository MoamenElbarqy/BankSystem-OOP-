#pragma once
#include "clsScreen.h"
#include "Global.h"

class clsDeleteUsersScreen : private clsScreen
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
	static void DeleteUser()
	{
		DrawScreenHeader("\tDelete Users Screen");

		cout << "Please Enter UserName You Want To Delete :";
		string UserName = clsInputValidate::ReadString();

		while (!clsUser::isUserExisted(UserName))
		{
			cout << "User is not found , Enter Exsisted User :";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User = clsUser::Find(UserName);
		_Print(User);


		if (clsUtil::ContinueOperation())
		{
			if (User.Delete())
			{
				cout << "\n===============================\n";
				cout << " User Deleted Sucssefully :-)\n";
				cout << "===============================\n";
			}
			else
			{
				cout << "\n===============================\n";
				cout << " User Deleted Denied :-(\n";
				cout << "===============================\n";
			}
		}
	}
};

