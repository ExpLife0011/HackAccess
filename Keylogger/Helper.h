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
    DateTime(){
        time_t ms;  //time_t is a type for system time
        time (&ms); //time is a function from ctime included in header which returns system time

        struct tm *info = localtime(&ms) ;  //pointers to a struct tm;

        D = info->tm_mday;
        m = info->tm_mon +1;
        y =1900 +info -> tm_year ; // unix pc start counting from 1900
        M = info ->tm_min;
        H = info-> tm_hour;
        S = info->tm_sec;
    }
    DateTime(int D, int m , int y, int M,int H, int S   ) : D(D), m(m), y(y),M(M),H(H), S(S) {}
    DateTime (int D, int m , int y): D(D), m(m), y(y),M(0),H(0), S(0 {}

    DateTime Now() const{ return DateTime(); }
    int D,  m ,  y,  M, H,  S;

    std::String GetDateString() const{
    return std:string(D <10 ? "0": "") + ToString(D) +   //condition ? result_if_true : result_if_false
            std:string(m<10 ? ".0" : ".") ToString(m) + "." + ToString(y);
            }  //DD.mm.YYYY
    std::string GetTimeString (const std::string &sep = ":") const
    {
        return std:string(H<10? "0":"" ) + ToString(H)+sep+
                std:string (M<10 ? "0" ; "" ) + ToString(M)+sep +
   0             std:string (S<10 ? sep:"") + ToString(S);
    }
        std:string GetDateTimeString (const std:string &sep =":" )const
        {
            return GetDateString() + " " + GetTimeString (sep);
        }

    };

 template <class T>

 std::string ToString (const T &e)
 {
    std::ostringstream s;
    s << e;
    return s.str;
 }

 void WriteAppLog (const std::string &s)
 {
    std::ofstream file("AppLog.txt" , std::ios::app); //app stands for append.
    file<<"{"<<Helper::DateTime.GetDateTimeString() <<"}"<<
    "\n" <<s <<std::endl << "\n";
    file.close();
 }

 }
#endif // HELPER_H

