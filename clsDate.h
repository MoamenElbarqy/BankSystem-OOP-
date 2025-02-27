#pragma once
#include <ctime>
#include <string>
using namespace std;
class clsDate
{
public:
	static string current_date_in_days_months_years()
	{
		time_t t = time(nullptr); // Current Time
		tm now;
		localtime_s(&now, &t); // Changing Time To Structure Contains Day, Month, Year
		string Date =  to_string(now.tm_mday) + "/" + to_string((now.tm_mon + 1)) + "/" + to_string(now.tm_year + 1900) ;
		return Date;
	}
	static string current_time()
	{
		time_t t = time(nullptr); 
		tm now;
		localtime_s(&now, &t); 
		string Time = to_string(now.tm_hour) + ":" + to_string(now.tm_min) + ":" + to_string(now.tm_sec);
		return Time;
	}
};

