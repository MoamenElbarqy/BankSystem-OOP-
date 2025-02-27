#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "Global.h"
class clsTransferScreen : private clsScreen
{
private:
	static void _Print(clsBankClient MyClient)
	{
		cout << "\nClient Card:";
		cout << "\n----------------------------";
		cout << "\nFull Name   : " << MyClient.GetFirstName() + " " + MyClient.GetLastName();
		cout << "\nAccount Number : " << MyClient.GetAccNumber();
		cout << "\nBalance     : " << MyClient.GetBalance();
		cout << "\n----------------------------\n";

	}
	static string _ConvertDataTransferToRecord(clsBankClient TransferFrom, clsBankClient TransferTo, float Amount, string seprator = "#//#")
	{
		string record = "";
		record += clsDate::current_date_in_days_months_years() + seprator;
		record += clsDate::current_time() + seprator;
		record += TransferFrom.GetAccNumber() + seprator;
		record += TransferTo.GetAccNumber() + seprator;
		record += to_string(Amount) + seprator;
		record += to_string(TransferFrom.GetBalance()) + seprator;
		record += to_string(TransferTo.GetBalance()) + seprator;
		record += SystemUser.GetUserName();
		return record;
	}
	static void _SaveTransferingOperation(clsBankClient TransferFrom, clsBankClient TransferTo, float Amount, string seprator = "#//#")
	{
		fstream MyFile;

		MyFile.open("TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << _ConvertDataTransferToRecord(TransferFrom, TransferTo, Amount) << endl;
			MyFile.close();
		}
	}
public:
	static void ShowTransferScreen()
	{
		DrawScreenHeader("\tTransfer Screen");

		cout << "PLease Enter Account Number To Transfer From : ";
		string FirstClientAccNumber = clsInputValidate::ReadString();

		while (!clsBankClient::isClientExisted(FirstClientAccNumber))
		{
			cout << "Client Isn't Found Please Enter a Valid Client : ";
			FirstClientAccNumber = clsInputValidate::ReadString();
		}
		clsBankClient FirstClient = clsBankClient::Find(FirstClientAccNumber);
		_Print(FirstClient);

		cout << "PLease Enter Account Number To Transfer To : ";
		string SecondClientAccNumber = clsInputValidate::ReadString();

		while (!clsBankClient::isClientExisted(SecondClientAccNumber) || FirstClientAccNumber == SecondClientAccNumber)
		{
			if (FirstClientAccNumber == SecondClientAccNumber)
			{
				cout << "You Can't Transfer To The Same Account, Please Enter another Account : ";
				SecondClientAccNumber = clsInputValidate::ReadString();
				continue;
			}
			else
			{
				cout << "Client Isn't Found Please Enter a Valid Client : ";
				SecondClientAccNumber = clsInputValidate::ReadString();
			}
		}
		clsBankClient SecondClient = clsBankClient::Find(SecondClientAccNumber);
		_Print(SecondClient);

		float TransferAmount = 0;
		cout << "Enter Transfer Amount : ";
		TransferAmount = clsInputValidate::ReadFloatNumber();

		while (TransferAmount > FirstClient.GetBalance())
		{
			cout << "Amount Exceeds Available Balance, Enter another Amount : ";
			TransferAmount = clsInputValidate::ReadFloatNumber();
		}

		if (clsUtil::ContinueOperation())
		{
			FirstClient.WithDraw(TransferAmount);
			SecondClient.Deposit(TransferAmount);

			cout << "\n===============================\n";
			cout << " Transfer Done Successfully :-)\n";
			cout << "===============================\n";

			_Print(FirstClient); cout << "\n";
			_Print(SecondClient); cout << "\n";

			_SaveTransferingOperation(FirstClient, SecondClient, TransferAmount); // Saving Transfer Data in File
		}
		else
		{
			cout << "\n===============================\n";
			cout << " Operation Denied :-(\n";
			cout << "===============================\n";
		}
	}

};