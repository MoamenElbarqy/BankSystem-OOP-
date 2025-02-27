#pragma once
#include "clsScreen.h"
#include "Global.h"

class clsAddNewUsersScreen :private clsScreen
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
			cout << "\nDo You Want To Give Access To :-\n";

			if (clsUtil::ContinueOperation("\nShow List Clients Screen (y / n) : "))
				permissions |= clsUser::enUsersPermissions::pListClients;

			if (clsUtil::ContinueOperation("\nAdd New Client Screen (y / n) : "))
				permissions |= clsUser::enUsersPermissions::pAddNewClient;

			if (clsUtil::ContinueOperation("\nDelete Client Screen  (y / n) : "))
				permissions |= clsUser::enUsersPermissions::pDeleteClient;

			if (clsUtil::ContinueOperation("\nUpdate Client Screen  (y / n) : "))
				permissions |= clsUser::enUsersPermissions::pUpdateClient;

			if (clsUtil::ContinueOperation("\nFind Client Screen  (y / n) : "))
				permissions |= clsUser::enUsersPermissions::pFindClient;

			if (clsUtil::ContinueOperation("\nTransactions Screen (y / n) : "))
				permissions |= clsUser::enUsersPermissions::pTransactions;
			
			if (clsUtil::ContinueOperation("\nMange Users Screen (y / n) : "))
				permissions |= clsUser::enUsersPermissions::pMangeUsers;

			if (clsUtil::ContinueOperation("\nLogin Register Screen (y / n) : "))
				permissions |= clsUser::enUsersPermissions::pLoginRegister;

			if (clsUtil::ContinueOperation("\nCurrency Exchange Screen (y / n) : "))
				permissions |= clsUser::enUsersPermissions::pCurrencyExchange;


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
	static void AddNewUser()
	{
		DrawScreenHeader("\t Add New User Screen");
		cout << "Enter User Name : ";
		string UserName = clsInputValidate::ReadString();

		while (clsUser::isUserExisted(UserName))
		{
			cout << "This User Already Existed , Enter a new one :";
			UserName = clsInputValidate::ReadString();
		}
		clsUser newUser = clsUser::GetAddNewModeUser(UserName);

		_ReadUserInfo(newUser);

		if (clsUtil::ContinueOperation())
		{
			if (newUser.Save())
			{
				cout << "\n===============================\n";
				cout << " User Added Successfully :-)\n";
				cout << "===============================\n";
				_Print(newUser);
			}
			else
			{
				cout << "\n===============================\n";
				cout << " We Can't Save Empty User :-(\n";
				cout << "===============================\n";
			}
		}
		else
		{
			cout << "\n===============================\n";
			cout << " Operation Denied :-(\n";
			cout << "===============================\n";
		}
		
	}

};

