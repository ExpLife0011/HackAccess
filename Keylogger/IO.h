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
 }













