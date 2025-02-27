#pragma once
#include <iostream>
#include <algorithm>
#include "clsPerson.h"
#include "Global.h"

class clsBankClient : public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };

	string _AccountNumber;
	string _PinCode;
	float _Balance;
	enMode _Mode;

	
	static clsBankClient _ConvertRecordToObject(string line)
	{
		clsBankClient Client;
		vector<string> ClientData = clsUtil::SplitRecord(line);


		return clsBankClient(enMode::UpdateMode, ClientData[0], ClientData[1], ClientData[2],
			ClientData[3], ClientData[4], ClientData[5], stof(ClientData[6]));
	}
	static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{
		string stClientRecord = "";
		stClientRecord += Client.GetFirstName() + Seperator;
		stClientRecord += Client.GetLastName() + Seperator;
		stClientRecord += Client.GetEmail() + Seperator;
		stClientRecord += Client.GetPhoneNumber() + Seperator;
		stClientRecord += Client.GetAccNumber() + Seperator;
		stClientRecord += Client.GetPinCode() + Seperator;
		stClientRecord += to_string(Client.GetBalance());

		return stClientRecord;

	}
	void _SaveClientsDataToFile(vector<clsBankClient>& MyClients)
	{
		fstream MyFile;
		MyFile.open("DataClients.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsBankClient& C : MyClients)
			{
				DataLine = _ConverClientObjectToLine(C);
				MyFile << DataLine << endl;

			}
			MyFile.close();

		}
	}

	void _Update()
	{
		vector<clsBankClient> MyClients = LoadDataClientsFromFile();

		for (clsBankClient& C : MyClients)
		{
			if (C.GetAccNumber() == GetAccNumber())
			{
				C = *this;
				break;
			}
		}
		_SaveClientsDataToFile(MyClients);

	}

	void _AddNewClientToTheFile()
	{
		string line = _ConverClientObjectToLine(*this);
		fstream MyFile;

		MyFile.open("DataClients.txt", ios::app | ios::out);

		if (MyFile.is_open())
		{
			MyFile << line << endl;
			MyFile.close();
		}
	}
protected:

public:
	clsBankClient() :clsPerson("", "", "", "")
	{
		_Mode = enMode::EmptyMode;
		_AccountNumber = "";
		_PinCode = "";
		_Balance = 0;

	}
	clsBankClient(enMode mode, string firstname, string lastname, string email,
		string phone_number, string acc_number, string pin_code, float acc_balacne)

		:clsPerson(firstname, lastname, email, phone_number)
	{
		_Mode = mode;
		_AccountNumber = acc_number;
		_PinCode = pin_code;
		_Balance = acc_balacne;
	}
	static vector<clsBankClient> LoadDataClientsFromFile()
	{
		vector<clsBankClient> MyClients;

		fstream MyFile;

		MyFile.open("DataClients.txt", ios::in);

		if (MyFile.is_open())
		{
			string line;

			while (getline(MyFile, line))
			{
				clsBankClient Client = _ConvertRecordToObject(line);
				MyClients.push_back(Client);
			}
			MyFile.close();
		}
		return MyClients;
	}
	static double CountTotalBalances(vector<clsBankClient>& MyClients)
	{
		double total = 0;
		for (clsBankClient& CurrentClient : MyClients)
		{
			total += CurrentClient.GetBalance();
		}
		return total;
	}
	bool isEmpty() { return _Mode == enMode::EmptyMode; }

	// Setters

	void SetPinCode(string pin) { _PinCode = pin; }
	void SetBalance(float Balance) { _Balance = Balance; }

	// Getters
	float GetBalance() { return _Balance; }
	string GetAccNumber() { return _AccountNumber; }
	string GetPinCode() { return _PinCode; }

	static clsBankClient Find(string acc_number)
	{
		vector<string> ClientData;

		fstream MyFile;
		MyFile.open("DataClients.txt", ios::in);

		if (MyFile.is_open())
		{
			string line;
			while (getline(MyFile, line))
			{
				ClientData = clsUtil::SplitRecord(line);
				if (ClientData[4] == acc_number)
				{
					MyFile.close();
					return clsBankClient(enMode::UpdateMode, ClientData[0], ClientData[1], ClientData[2],
						ClientData[3], ClientData[4], ClientData[5], stof(ClientData[6]));
				}
			}
		}
		MyFile.close();

		return clsBankClient(); // if we reached here we did't find the client and returning empty client
	}
	static clsBankClient Find(string acc_number, string PinCode)
	{
		vector<string> ClientData;

		fstream MyFile;
		MyFile.open("DataClients.txt", ios::in);

		if (MyFile.is_open())
		{
			string line;
			while (getline(MyFile, line))
			{
				ClientData = clsUtil::SplitRecord(line);
				if (ClientData[4] == acc_number && PinCode == ClientData[5])
					return clsBankClient(enMode::UpdateMode, ClientData[0], ClientData[1], ClientData[2], ClientData[3], ClientData[4], ClientData[5], stof(ClientData[6]));
			}
			MyFile.close();
		}

		return clsBankClient();
	}

	static bool isClientExisted(string AccNumber)
	{
		clsBankClient Client = clsBankClient::Find(AccNumber);
		return (!Client.isEmpty());
	}

	bool Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
			return false;

		case enMode::UpdateMode:
			_Update();
			return true;

		case enMode::AddNewMode:
			_AddNewClientToTheFile();
			_Mode = enMode::UpdateMode; // Changing The Client Mode After Becoming Exsisted In The File
			return true;

		}
		return false; // Defualt Value for UnKnown Behaviours
	}

	static clsBankClient GetEmptyClient(string AccountNumber)
	{
		return	clsBankClient(enMode::EmptyMode, "", "", "", "", AccountNumber, "", 0);
	}
	bool Delete()
	{
		vector<clsBankClient> vMyClients = LoadDataClientsFromFile();
		vector<clsBankClient>::iterator it;

		for (it = vMyClients.begin(); it != vMyClients.end(); ++it)
		{
			if (it->GetAccNumber() == this->GetAccNumber())
			{
				vMyClients.erase(it);
				break;
			}
		}
		_SaveClientsDataToFile(vMyClients);

		*this = clsBankClient(); // Making The Current Object Empty From Its Data After Deleting Him From The File 
		return true;
	}
	static clsBankClient GetAddNewModeClient(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}
	void Deposit(float val)
	{
		_Balance += val;
		Save();
	}
	void WithDraw(float val)
	{
		_Balance -= val;
		Save();
	}
};
