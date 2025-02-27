#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "Global.h"

class clsDeleteClientScreen : private clsScreen
{
private:
	static void _Print(clsBankClient MyClient)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << MyClient.GetFirstName();
		cout << "\nLastName    : " << MyClient.GetLastName();
		cout << "\nFull Name   : " << MyClient.GetFirstName() + " " + MyClient.GetLastName();
		cout << "\nEmail       : " << MyClient.GetEmail();
		cout << "\nPhone       : " << MyClient.GetPhoneNumber();
		cout << "\nAccount Number : " << MyClient.GetAccNumber();
		cout << "\nPassword    : " << MyClient.GetPinCode();
		cout << "\nBalance     : " << MyClient.GetBalance();
		cout << "\n___________________\n";

	}

public:
	static void DeleteClient()
	{
		if (!hasAccess(clsUser::enUsersPermissions::pDeleteClient)) return; // This Will Show Access Denied Screen Internaly

		DrawScreenHeader("\tDelete Client Screen");

		cout << "Please Enter Account Number You Want To Delete :";
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::isClientExisted(AccountNumber))
		{
			cout << "Client is not found , Enter Exsisted Client :";
			 AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_Print(Client);


		if (clsUtil::ContinueOperation())
		{
			if (Client.Delete())
			{
				cout << "\n===============================\n";
				cout << " Client Deleted Successfully :-)\n";
				cout << "===============================\n";
			}			
		}
		else
		{
			cout << "\n===============================\n";
			cout << " Client Deleted Denied :-(\n";
			cout << "===============================\n";
		}
	}
};
