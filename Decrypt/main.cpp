#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string DecryptB64();

int main( int argc , char *argv[])
{
    if (argc !=3) // number of arguements on command
        return cout << "Program needs TWO arguement , input and output!"   <<endl ,2;
    string in (argv[1]) , out (argv[2]); // arguement parameter 1
    ifstream fi (in);
    if (!fi)
        return cout<< "Cannot read input file'" << in <<"'" <<endl ,3 ; //return 3 after print
    string data ;
    fi >> data ; // input into data
    if (!fi) // if input is still empty
        return cout << "Input file" << in <<"' corrupted!" <<endl, 4;
    data = DecryptBase64 (data);



    return 0;
}


string DecryptB64 (std::string s)
    {
        s = s.erase (7, 1);
        s = s.erase (1, 1);
        s = base64_decode (s);
        s = s.substr (SALT2.length() + SALT3.length());
        s = s.substr (0, s.length() - SALT1.length());
        s = base64_decode (s);
        s = s.substr (0, s.length() - SALT1.length());
        s = s.erase (7, SALT3.length());
        s = base64_decode (s);
        s = s.substr (SALT1.length());
        s = s.substr (0, s.length() - SALT2.length() - SALT3.length());
        return s;
    }
