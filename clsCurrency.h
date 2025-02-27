#pragma once
#include <string>
using namespace std;


class clsCurrency
{
private:
	enum enCurrencyMode
	{
		UpdateMode = 1,
		EmptyMode = 2
	};
	enCurrencyMode _CurrencyMode;
	string _Country;
	string _Code;
	string _CurrencyName;
	float _Rate;

	static clsCurrency ConvertRecordToCurrencyObject(string line)
	{
		vector<string> CurrencyData = clsUtil::SplitRecord(line);
		return clsCurrency(enCurrencyMode::UpdateMode, CurrencyData[0], CurrencyData[1], CurrencyData[2], stof(CurrencyData[3]));
	}

public:
	clsCurrency()
	{
		_CurrencyMode = enCurrencyMode::EmptyMode;
		_Country = "";
		_Code = "";
		_CurrencyName = "";
		_Rate = 0;
	}
	clsCurrency(enCurrencyMode mode, string country, string code, string name, float rate)
	{
		_CurrencyMode = mode;
		_Country = country;
		_Code = code;
		_CurrencyName = name;
		_Rate = rate;

	}
	static clsCurrency GetEmptyCurrency()
	{
		return clsCurrency();
	}
	static string _ConvertCurrenyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
	{
		string record = "";
		record += Currency._Country + Seperator;
		record += Currency._Code + Seperator;
		record += Currency._CurrencyName + Seperator;
		record += to_string(Currency._Rate) ;

		return record;

	}

	void LoadCurrenciesToFile(vector<clsCurrency> vMyCurrencies)
	{
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{
			for (clsCurrency C : vMyCurrencies)
			{
				DataLine = _ConvertCurrenyObjectToLine(C);
				MyFile << DataLine << endl;
			}
			MyFile.close();
		}
	}
	void Save()
	{
		vector<clsCurrency> vMyCurrencies = LoadCurrenciesFromFile();
		for (clsCurrency& currenct_currency : vMyCurrencies)
		{
			if (this->GetCode() == currenct_currency.GetCode())
			{
				currenct_currency = *this;
				LoadCurrenciesToFile(vMyCurrencies);
				return;
			}
		}
	}
	void SetRate(float rate)
	{
		_Rate = rate;
		Save();
	}
	// getters
	string GetCountryName() { return _Country; }
	string GetCode() { return _Code; }
	string GetCurrencyName() { return _CurrencyName; }
	enCurrencyMode GetCurrencyMode() { return _CurrencyMode; }
	float GetRate() { return _Rate; }
	static vector<clsCurrency> LoadCurrenciesFromFile()
	{
		vector<clsCurrency> vMyCurrencies;

		fstream MyFile;

		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string line;

			while (getline(MyFile, line))
			{
				clsCurrency Currency = ConvertRecordToCurrencyObject(line);
				vMyCurrencies.push_back(Currency);
			}
			MyFile.close();
		}
		return vMyCurrencies;
	}
	
	bool isEmpty() { return  _CurrencyMode == enCurrencyMode::EmptyMode; }

	static clsCurrency FindByCode(string country_code)
	{
		country_code = clsUtil::UpperAll(country_code); // to make the code case insistive

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		string line;

		if (MyFile.is_open())
		{
			while (getline(MyFile, line))
			{
				clsCurrency CurrentCurrency = ConvertRecordToCurrencyObject(line);
				if (CurrentCurrency.GetCode() == country_code)
				{
					MyFile.close();
					return CurrentCurrency;
				}
			}
		}
		MyFile.close();
		return GetEmptyCurrency();
	}
	static clsCurrency FindByName(string country_name)
	{
		country_name = clsUtil::UpperAll(country_name); // to make the code case insistive

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		string line;

		if (MyFile.is_open())
		{
			while (getline(MyFile, line))
			{
				clsCurrency CurrentCurrency = ConvertRecordToCurrencyObject(line);
				if (clsUtil::UpperAll(CurrentCurrency.GetCountryName()) == country_name)
				{
					MyFile.close();
					return CurrentCurrency;
				}
			}
		}
		MyFile.close();
		return GetEmptyCurrency();
	}

	static bool isCurrencyExsisted(string CurrencyCode)
	{
		return  FindByCode(CurrencyCode).GetCurrencyMode() != EmptyMode;
	}
};

