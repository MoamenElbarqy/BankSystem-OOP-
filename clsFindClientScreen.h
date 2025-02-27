#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "Global.h"

class clsFindClientScreen : private clsScreen
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
	static void FindClientScreen()
	{
		if (!hasAccess(clsUser::enUsersPermissions::pFindClient)) return; // This Will Show Access Denied Screen Internaly

		DrawScreenHeader("\tFind Client Screen");
		cout << "Please Enter Client Account Number : ";
		string acc_number = clsInputValidate::ReadString();
		if (!clsBankClient::isClientExisted(acc_number))
		{
			cout << "\n===============================\n";
			cout << " Account Number is not found :-(\n";
			cout << "===============================\n";
		}
		else
		{
			clsBankClient MyClient = clsBankClient::Find(acc_number);
			_Print(MyClient);
		}
	}
};

