#pragma once
#include "clsScreen.h"
class clsTransferLogScreen : private clsScreen
{
private:
	struct stTransferData
	{
		string date = "";
		string time = "";
		string source_account = "";
		string destrnation_account = "";
		float transfer_amount = 0;
		float source_balance = 0;
		float destrnation_balance = 0;
		string user_name = "";
	};

	static stTransferData _ConvertVectorToTransferData(vector<string> vLineData)
	{
		stTransferData MyTransferData;

		MyTransferData.date = vLineData.at(0);
		MyTransferData.time = vLineData.at(1);
		MyTransferData.source_account = vLineData.at(2);
		MyTransferData.destrnation_account = vLineData.at(3);
		MyTransferData.transfer_amount = stof(vLineData.at(4));
		MyTransferData.source_balance = stof(vLineData.at(5));
		MyTransferData.destrnation_balance = stof(vLineData.at(6));
		MyTransferData.user_name = vLineData.at(7);
		return MyTransferData;
	}
	static vector<stTransferData> _LoadTransferDataFromFile()
	{
		vector<stTransferData> vMyTransferData;
		vector<string> vLineData;
		string line = "";

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);
		if (MyFile.is_open())
		{
			while (getline(MyFile, line))
			{
				vLineData = clsUtil::SplitRecord(line);
				stTransferData CurrentData = _ConvertVectorToTransferData(vLineData);
				vMyTransferData.push_back(CurrentData);
			}
			MyFile.close();
		}
		else
		{
			cout << "\n===============================\n";
			cout << " We Can't Open The File :-(\n";
			cout << "===============================\n";
		}
		return vMyTransferData;
	}
	static void _PrintTransferLogScreen()
	{

		cout << "\t-----------------------------------------------------------------------------------------------------\n";
		cout << "\t|    Date     |    Time    |   S.Acc  |   D.Acc  |   Amount    |  S.Balance  | D.Balance   | UserName\n";
		cout << "\t------------------------------------------------------------------------------------------------------\n";

		vector<stTransferData> vMyTransferData;

		vMyTransferData = _LoadTransferDataFromFile();
		for (stTransferData CurrentData : vMyTransferData)
		{
			cout << "\t|" << setw(13) << left << CurrentData.date;
			cout << "|" << setw(12) << left << CurrentData.time;
			cout << "|" << setw(10) << left << CurrentData.source_account;
			cout << "|" << setw(10) << left << CurrentData.destrnation_account;
			cout << "|" << setw(13) << left << CurrentData.transfer_amount;
			cout << "|" << setw(13) << left << CurrentData.source_balance;
			cout << "|" << setw(13) << left << CurrentData.destrnation_balance;
			cout << "|" << setw(9) << left << CurrentData.user_name;
			cout << endl;
		}
		cout << "\t-----------------------------------------------------------------------------------------------------\n";
	}
public:

	static void ShowTransferLog()
	{
		vector<stTransferData> vMyTransferData = _LoadTransferDataFromFile();
		string subTitle = "(" + to_string(vMyTransferData.size()) + ")" + " Operation(s)";

		DrawScreenHeader("\t Transfer Log", subTitle);
		_PrintTransferLogScreen();
	}
};

