#ifndef HELPER_H
#define HELPER_H

#include <ctime>
#include <string>
#include <sstream> //used to convert Strings

namespace Helper{
    template <class T>
    std::string ToString (const T &)

    struct DateTime{ //structs are users defined type, they are pretty much like classes;
                        //classes are just structs iwth functions
                            //structs by default are public
    DateTime()[
        time_t ms;  //time_t is a type for system time
        time (&ms); //time is a function from ctime included in header which returns system time

        struct tm *info = localtime(&ms) ;  //pointers to a struct tm;

        D = info->tm_mday;
        m = info->tm_mon +1;
        y =1900 +info -> tm_year ; // unix pc start counting from 1900
        M = info ->tm_min;
        H = info-> tm_hour;
        S = info->tm_sec;
    ]

    };

#endif // HELPER_H
class {

};
