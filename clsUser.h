#pragma once
#include "clsPerson.h"
#include <iostream>
#include <algorithm>
#include "Global.h"
#include "clsDate.h"
#include "clsUtil.h"
class clsUser : public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };

	string _UserName;
	string _Password;
	int _Permissions;
	enMode _Mode;


	static clsUser _ConvertRecordToObject(string line)
	{
		// We Use It When We Want To Load Data From the File
		clsUser User;
		vector<string> UserData = clsUtil::SplitRecord(line);
		User.SetMode(enMode::UpdateMode);
		User.SetFirstName(UserData[0]);
		User.SetLastName(UserData[1]);
		User.SetEmail(UserData[2]);
		User.SetPhoneNumber(UserData[3]);
		User.SetUserName(UserData[4]);
		User.SetPassword(clsUtil::DecryptText(UserData[5]));
		User.SetPermissions(stoi(UserData[6]));

		return User;
	}
	static string _ConvertUserObjectToLine(clsUser User, string Seperator = "#//#")
	{
		string stUserRecord = "";
		stUserRecord += User.GetFirstName() + Seperator;
		stUserRecord += User.GetLastName() + Seperator;
		stUserRecord += User.GetEmail() + Seperator;
		stUserRecord += User.GetPhoneNumber() + Seperator;
		stUserRecord += User.GetUserName() + Seperator;
		stUserRecord += clsUtil::EncryptText(User.GetPassword()) + Seperator;
		stUserRecord += to_string(User.GetPermissions());

		return stUserRecord;

	}
	void _SaveUsersDataToFile(vector<clsUser>& vMyUsers)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{
			for (clsUser& C : vMyUsers)
			{
				DataLine = _ConvertUserObjectToLine(C);
				MyFile << DataLine << endl;
			}
			MyFile.close();
		}
	}
	void _Update()
	{
		vector<clsUser> vMyUsers = LoadDataUsersFromFile();

		for (clsUser& C : vMyUsers)
		{
			if (C.GetUserName() == GetUserName())
			{
				C = *this;
				break;
			}
		}
		_SaveUsersDataToFile(vMyUsers);

	}

	void _AddNewUserToTheFile()
	{
		string line = _ConvertUserObjectToLine(*this);
		fstream MyFile;

		MyFile.open("Users.txt", ios::app | ios::out);

		if (MyFile.is_open())
		{
			MyFile << line << endl;
			MyFile.close();
		}
	}


public:
	// (P) is abbreviation for permission
	enum enUsersPermissions
	{
		pAll = -1,
		pListClients = 1,
		pAddNewClient = 2,
		pDeleteClient = 4,
		pUpdateClient = 8,
		pFindClient = 16,
		pTransactions = 32,
		pMangeUsers = 64,
		pLoginRegister = 128,
		pCurrencyExchange = 256
	};

	// Empty User
	clsUser() :clsPerson("", "", "", "")
	{
		_Mode = enMode::EmptyMode;
		_Permissions = 0;
		_Password = "";

	}
	// User With data

	clsUser(enMode mode, string firstname, string lastname, string email,
		string phone_number, string UserName, string password, int permissions)
		:clsPerson(firstname, lastname, email, phone_number)
	{
		_Mode = mode;
		_Permissions = permissions;
		_Password = password;
		_UserName = UserName;
	}

	// Getters
	string GetPassword() { return _Password; }
	int GetPermissions() { return _Permissions; }
	string GetUserName() { return _UserName; }
	// Setters
	void SetPassword(string password) { _Password = password; }
	void SetPermissions(int permissions) { _Permissions = permissions; }
	void SetUserName(string username) { _UserName = username; }
	void SetMode(enMode UserMode) { _Mode = UserMode; }
	static vector<clsUser> LoadDataUsersFromFile()
	{
		vector<clsUser> vMyUsers;

		fstream MyFile;

		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string line;

			while (getline(MyFile, line))
			{
				clsUser User = _ConvertRecordToObject(line);
				vMyUsers.push_back(User);
			}
			MyFile.close();
		}
		return vMyUsers;
	}


	bool isEmpty() { return _Mode == enMode::EmptyMode; }

	static clsUser Find(string UserName)
	{
		vector<string> vUsersData;

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string line;
			while (getline(MyFile, line))
			{
				vUsersData = clsUtil::SplitRecord(line);
				if (vUsersData[4] == UserName)
				{
					MyFile.close();
					return clsUser(enMode::UpdateMode, vUsersData[0], vUsersData[1], vUsersData[2],
						vUsersData[3], vUsersData[4], vUsersData[5], stoi(vUsersData[6]));
				}
			}
		}

		MyFile.close();

		return clsUser(); // if we reached here we did't find the user and returning empty user
	}
	static clsUser Find(string Username, string Password)
	{
		vector<string> vUsersData;

		fstream MyFile;
		clsUser CurrentUser;
		string line;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			while (getline(MyFile, line))
			{
				vUsersData = clsUtil::SplitRecord(line);
				CurrentUser.SetUserName(vUsersData[4]);
				CurrentUser.SetPassword(clsUtil::DecryptText(vUsersData[5]));
				if (CurrentUser.GetUserName() == Username && Password == CurrentUser.GetPassword())
				{
					CurrentUser.SetMode(enMode::UpdateMode);
					CurrentUser.SetFirstName(vUsersData[0]);
					CurrentUser.SetLastName(vUsersData[1]);
					CurrentUser.SetEmail(vUsersData[2]);
					CurrentUser.SetPhoneNumber(vUsersData[3]);
					CurrentUser.SetPermissions(stoi(vUsersData[6]));
					MyFile.close();
					return CurrentUser;
				}
			}
			MyFile.close();
		}

		return clsUser();
	}

	static bool isUserExisted(string UserName)
	{
		clsUser User = clsUser::Find(UserName);
		return (!User.isEmpty());
	}

	bool Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			return false;

		}
		case enMode::UpdateMode:
		{
			_Update();
			return true;
		}
		case enMode::AddNewMode:
		{
			_AddNewUserToTheFile();
			_Mode = enMode::UpdateMode; // Changing The User Mode After Becoming Exsisted In The File
			return true;
		}

		}
		return false; // Defualt Value for UnKnown Behaviours
	}

	static clsUser GetEmptyUser(string UserName)
	{
		return	clsUser(enMode::EmptyMode, "", "", "", "", UserName, "", 0);
	}
	bool Delete()
	{
		vector<clsUser> vMyUsers = LoadDataUsersFromFile();
		vector<clsUser>::iterator it;

		for (it = vMyUsers.begin(); it != vMyUsers.end(); ++it)
		{
			if (it->GetUserName() == this->GetUserName())
			{
				vMyUsers.erase(it);
				break;
			}
		}
		_SaveUsersDataToFile(vMyUsers);
		*this = GetEmptyUser(_UserName); // Making The Current Object Empty From Its Data
		return true;
	}
	static clsUser GetAddNewModeUser(string UserName)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	string _ConvertLoginStatusToRecord(string separator = "#//#")
	{
		string record = "";
		record += clsDate::current_date_in_days_months_years() + separator;
		record += clsDate::current_time() + separator;
		record += _UserName + separator;
		record += clsUtil::EncryptText(_Password) + separator;
		record += to_string(_Permissions);
		return record;
	}

	void SaveLoginStatus()
	{
		fstream MyFile;

		MyFile.open("LoginRegister.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << _ConvertLoginStatusToRecord() << endl;
			MyFile.close();
		}
	}

};

