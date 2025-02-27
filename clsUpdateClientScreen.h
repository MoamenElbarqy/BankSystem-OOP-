#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "Global.h"

class clsUpdateClientScreen : private clsScreen
{
private:
	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "Enter First Name : ";
		Client.SetFirstName(clsInputValidate::ReadString());


		cout << "Enter Last Name : ";
		Client.SetLastName(clsInputValidate::ReadString());


		cout << "Enter Email : ";
		Client.SetEmail(clsInputValidate::ReadString());


		cout << "Enter Phone : ";
		Client.SetPhoneNumber(clsInputValidate::ReadString());


		cout << "Enter Pin Code : ";
		Client.SetPinCode(clsInputValidate::ReadString());


		cout << "Enter your Balance : ";
		Client.SetBalance(clsInputValidate::ReadFloatNumber());


	}
	static void _Print(clsBankClient MyClient)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName      : " << MyClient.GetFirstName();
		cout << "\nLastName       : " << MyClient.GetLastName();
		cout << "\nFull Name      : " << MyClient.GetFirstName() + " " + MyClient.GetLastName();
		cout << "\nEmail          : " << MyClient.GetEmail();
		cout << "\nPhone          : " << MyClient.GetPhoneNumber();
		cout << "\nAccount Number : " << MyClient.GetAccNumber();
		cout << "\nPassword       : " << MyClient.GetPinCode();
		cout << "\nBalance        : " << MyClient.GetBalance();
		cout << "\n___________________\n";

	}

public:
	static void UpdateClient()
	{
		// This Will Show Access Denied Screen Internaly If The user Dosen't Have Permission To Do This 
		if (!hasAccess(clsUser::enUsersPermissions::pUpdateClient)) return;

		DrawScreenHeader("\tUpdate Client Info Screen");
		string AccountNumber = "";
		cout << "Please Enter Account Number : ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::isClientExisted(AccountNumber))
		{
			cout << "Account Number is not Found , Enter a valid one : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_Print(Client);
		cout << "\nUpdate Info:\n";
		cout << "---------------\n";
		_ReadClientInfo(Client);
		if (clsUtil::ContinueOperation())
		{
			if (Client.Save())
			{
				cout << "\n===============================\n";
				cout << " Account Updated Successfully :-)\n";
				cout << "===============================\n";
				_Print(Client);
			}
			else
			{
				cout << "\n==================================================\n";
				cout << "Error Account Wasn't Saved Because It's Empty :-(\n";
				cout << "==================================================\n";
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

