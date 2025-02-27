#include "clsLoginScreen.h"
#include "Global.h"
#
int main()
{
	do
	{
		clsLoginScreen::ShowLoginScreen();
		if (LockTheSystem)// The System Will Lock If You Fail 3 Times In Login
		{
			cout << "The System Has Been Locked :-(";
			return 0;
		} 
	} while (clsUtil::ContinueOperation("\nDo You Wany To Login Again (y / n) : "));
	return 0;

}