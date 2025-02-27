#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
class clsCurrencyCalculator :
	private clsScreen
{
public:
	static void ShowCurrencyCalculatorScreen()
	{
		string Currency1 = "";
		string Currency2 = "";
		DrawScreenHeader("\tCurrency Calculator Screen");

		cout << "Enter Currency1 Code : ";
		Currency1 = clsInputValidate::ReadString();
		while (!clsCurrency::isCurrencyExsisted(Currency1))
		{
			cout << "Invalid Currency, Enter a Valid one : ";
			Currency1 = clsInputValidate::ReadString();
		}
		clsCurrency first_currency = clsCurrency::FindByCode(Currency1);
		cout << "Enter Currency2 Code : ";
		Currency2 = clsInputValidate::ReadString();

		while (!clsCurrency::isCurrencyExsisted(Currency2))
		{
			cout << "Invalid Currency, Enter a Valid one : ";
			Currency2 = clsInputValidate::ReadString();
		}
		clsCurrency second_currency = clsCurrency::FindByCode(Currency2);
		cout << "Please Enter Amount Of ExChange : ";
		float amount = clsInputValidate::ReadFloatNumber();
		while (amount < 0)
		{
			cout << "You Can't Change Negative Number, Please Enter a Positive one : ";
			amount = clsInputValidate::ReadFloatNumber();
		}
		float MoneyAfterExchange = amount / first_currency.GetRate() * second_currency.GetRate();
		// formatin the output to be like -> 1 Usd = 50 EGP
		cout << amount << " " << first_currency.GetCode() << " = " << MoneyAfterExchange << " " << second_currency.GetCurrencyName();
	}

};

