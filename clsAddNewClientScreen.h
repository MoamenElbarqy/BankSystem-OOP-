#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "Global.h"

class clsAddNewClient : private clsScreen
{
private:
	clsBankClient newClient;
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
		cout << "\nPin Code       : " << MyClient.GetPinCode();
		cout << "\nBalance        : " << MyClient.GetBalance();
		cout << "\n___________________\n";

	}
public:
	static void AddNewClient()
	{
		if (!hasAccess(clsUser::enUsersPermissions::pAddNewClient)) return; // Acceess Check

		DrawScreenHeader("\t Add New Client Screen");

		cout << "Enter New Client Account Number :";
		string AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::isClientExisted(AccountNumber))
		{
			cout << "This Account Already Existed,Enter a new one :";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient newClient = clsBankClient::GetAddNewModeClient(AccountNumber);

		_ReadClientInfo(newClient);

		if (clsUtil::ContinueOperation())
		{
			if (newClient.Save())
			{
				cout << "\n===============================\n";
				cout << " Account Added Successfully :-)\n";
				cout << "===============================\n";
				_Print(newClient);
			}
			else
			{
				cout << "\n===============================\n";
				cout << " We Can't Save Empty Client :-(\n";
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


