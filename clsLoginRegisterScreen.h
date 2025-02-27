#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
class clsLoginRegisterScreen : private clsScreen
{
private:
	struct stLoginData
	{
		string date = "";
		string time = "";
		string user_name = "";
		string password = "";
		int permissions = 0;
	};

	static vector<stLoginData> _LoadLoginRegisterFile()
	{
		vector<stLoginData> vLoginData;
		vector<string> RecordData;
		stLoginData CurrentData;
		fstream MyFile;
		string line;

		MyFile.open("LoginRegister.txt", ios::in);
		if (MyFile.is_open())
		{
			while (getline(MyFile, line))
			{
				RecordData = clsUtil::SplitRecord(line);
				CurrentData.date = RecordData[0];
				CurrentData.time = RecordData[1];
				CurrentData.user_name = RecordData[2];
				CurrentData.password = RecordData[3];
				CurrentData.permissions = stoi(RecordData[4]);
				vLoginData.push_back(CurrentData);
			}
			MyFile.close();
		}
		return vLoginData;
	}
	static void _PrintLoginRegisterData(vector<stLoginData> vLoginRegisterData)
	{
		cout << "\t-----------------------------------------------------------------------------------------------------\n";
		cout << "\t|       Date       |      Time       |      UserName      |   Password (Encrepted)     |  Permissions \n";
		cout << "\t-----------------------------------------------------------------------------------------------------\n";


		for (stLoginData CurrentData : vLoginRegisterData)
		{
			cout << "\t|" << setw(18) << left << CurrentData.date;
			cout << "|" << setw(17) << left << CurrentData.time;
			cout << "|" << setw(20) << left << CurrentData.user_name;
			cout << "|" << setw(28) << left << CurrentData.password;
			cout << "|" << setw(15) << left << CurrentData.permissions;
			cout << endl;
		}
		cout << "\t--------------------------------------------------------------------------------------------\n";

	}
public:
	static void ShowLoginRegisterScreen()
	{
		if (!hasAccess(clsUser::enUsersPermissions::pAddNewClient)) return; // This Will Show Access Denied Screen Internaly
		vector<stLoginData> vLoginRegisterData = _LoadLoginRegisterFile();
		string subTitle = "(" + to_string(vLoginRegisterData.size()) + ")" + " Time(s)";

		DrawScreenHeader("\tLogin Register Screen", subTitle);
		_PrintLoginRegisterData(vLoginRegisterData);
	}
};

