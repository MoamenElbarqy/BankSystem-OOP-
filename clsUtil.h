#pragma once
#include <string>
#include <cctype>
using namespace std;
class clsUtil
{
public:
	static string DecryptText(string Text, short EncryptionKey = 12 + 11) 
	{
		for (char& c : Text)
		{
			c -= EncryptionKey;
		}
		return Text;
	}
	static string EncryptText(string Text,short EncryptionKey = 12 + 11)
	{
		for (char& c : Text)
		{
			c += EncryptionKey;
		}
		return Text;
	}
	static bool ContinueOperation(string msg = "\nAre You Sure To Perform This Operation (y / n) : ")
	{
		char status = 'n';
		cout << msg;
		cin >> status;
		while (status != 'n' && status != 'N' && status != 'y' && status != 'Y')
		{
			cout << "Invalid Character, You Have Only Two Options [ Yes = Y , y ] &  [ No = N , n ] : ";
			cin >> status;
		}
		return status == 'y' || status == 'Y';
	}
	static vector<string> SplitRecord(string str, string delimiter = "#//#")
	{

		vector<string> result;
		string temp = "";
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] != delimiter[0])
			{
				temp += str[i];
			}
			else
			{
				result.push_back(temp);
				temp = "";
				i += int(delimiter.length()) - 1; // This Line Will Treat The Long Delimiter Like #//# not only the white space
			}
		}
		result.push_back(temp);
		return result;
	}
	static string UpperAll(string str)
	{
		for (char& c : str)
		{
			if (islower(c)) c = toupper(c);
		}
		return str;
	}
	
};

