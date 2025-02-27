#pragma once
#include "clsScreen.h"
#include "Global.h"

class clsUpdateUsersScreen : private clsScreen
{
private:

	static void _ReadUserInfo(clsUser& User)
	{
		cout << "Enter First Name : ";
		User.SetFirstName(clsInputValidate::ReadString());


		cout << "Enter Last Name : ";
		User.SetLastName(clsInputValidate::ReadString());


		cout << "Enter Email : ";
		User.SetEmail(clsInputValidate::ReadString());


		cout << "Enter Phone : ";
		User.SetPhoneNumber(clsInputValidate::ReadString());


		cout << "Enter Password : ";
		User.SetPassword(clsInputValidate::ReadString());


		if (clsUtil::ContinueOperation("\nDo You Want To Give Full Access (y / n): "))
		{
			User.SetPermissions(-1);
		}
		else
		{
			int permissions = 0;

			if (clsUtil::ContinueOperation("\nDo You Want To Give Access To Show List Clients Screen (y / n) : "))
				permissions += clsUser::enUsersPermissions::pListClients;
			if (clsUtil::ContinueOperation("\nDo You Want To Give Access To Add New Client Screen (y / n) : "))
				permissions += clsUser::enUsersPermissions::pAddNewClient;
			if (clsUtil::ContinueOperation("\nDo You Want To Give Access To Delete Client Screen  (y / n) : "))
				permissions += clsUser::enUsersPermissions::pDeleteClient;
			if (clsUtil::ContinueOperation("\nDo You Want To Give Access To Update Client Screen  (y / n) : "))
				permissions += clsUser::enUsersPermissions::pUpdateClient;
			if (clsUtil::ContinueOperation("\nDo You Want To Give Access To Find Client Screen  (y / n) : "))
				permissions += clsUser::enUsersPermissions::pFindClient;
			if (clsUtil::ContinueOperation("\nDo You Want To Give Access To Transactions Screen (y / n) : "))
				permissions += clsUser::enUsersPermissions::pTransactions;
			if (clsUtil::ContinueOperation("\nDo You Want To Give Access To Mange Users Screen (y / n) : "))
				permissions += clsUser::enUsersPermissions::pMangeUsers;

			User.SetPermissions(permissions);
		}

	}
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
	static void UpdateUser()
	{
		DrawScreenHeader("\tUpdate User Screen");
		string UserName = "";
		cout << "Please Enter Account Number : ";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::isUserExisted(UserName))
		{
			cout << "User is not Found , Enter a valid one : ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser Client = clsUser::Find(UserName);
		_Print(Client);
		cout << "\nUpdate Info:\n";
		cout << "---------------\n";
		_ReadUserInfo(Client);

		if (clsUtil::ContinueOperation())
		{
			if (Client.Save())
			{

				cout << "\n===============================\n";
				cout << " User Updated Successfully :-)\n";
				cout << "===============================\n";
				_Print(Client);
			}
			else
			{

				cout << "\n=======================================\n";
				cout << " User Was't Saved Because It's Empty :-(\n";
				cout << "=======================================\n";

			}
		}
		else
		{
			cout << "\n========================\n";
			cout << " Operation Denied :-(\n";
			cout << "========================\n";
		}


	}
};

