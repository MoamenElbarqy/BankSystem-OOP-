#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Global.h"

using namespace std;
class clsPerson
{
private:
	string _FirstName;
	string _LastName;
	string _Email;
	string _PhoneNumber;

public:
	// Costractors
	clsPerson()
	{

	}
	clsPerson(string firstname, string lastname, string email, string phone)
	{
		_FirstName = firstname;
		_LastName = lastname;
		_Email = email;
		_PhoneNumber = phone;
	}
	// Setters
	void SetFirstName(string str) { _FirstName = str; }
	void SetLastName(string str) { _LastName = str; }
	void SetEmail(string str) { _Email = str; }
	void SetPhoneNumber(string str) { _PhoneNumber = str; }
	// getters
	string GetFirstName() { return _FirstName; }
	string GetLastName() { return _LastName; }
	string GetEmail() { return _Email; }
	string GetPhoneNumber() { return _PhoneNumber; }

};

