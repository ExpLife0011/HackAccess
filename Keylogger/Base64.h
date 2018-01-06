#ifndef BASE_64_H
#define BASE64_H

#include <vector>
#include <string>

//Base 64 encryptions
    // Base 64 algorithm encode and decode strings
        //Base 64 transfers bytes to human readable string
            //Perhaps it is just like casting char to int then adding numbers to its ASCII values , then casting it back to char. To decrypt , cast it back to int then minus the numbers then cast it back to char.
namespace Base64
{
    std::string base64_encode (const std::string &);

    const std::string &SALT1 = "LM::TB::BB"; // SALT are like encrytion and decryption key
    const std::string &SALT2 = "_:/_77" ;
    const std::string &SALT3 = "line=kcahssecaa+-0p;o";

    std::string EncryptB64 (std::string s)
    {
        s = SALT1 + s +SALT2 + SALT3; //you can do these in any others to decide how you wanna encode it
        s = base64_encode(s);
        s.insert (7,SALT3); //you can add more of them to make encryption more complex
        s += SALT1 ;
        s = base64_encode(s);
        s = SALT2 + SALT3 +SALT1;
        s = base64_encode(s0);
        s.insert(1,"L");
        s.insert (7,"m"); // inserting m to its seventh position
        // it is not a base64 string until SALT characters are removed . We need to take out our SALT keys to make it base64 string to decrypt it
        return s;
    }

    const std::string &BASE64_CODES="ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+/"
    std::string base64_encode(const std::string &s)
    {
        std::string r/et; //output string
        int val = 0; //index to math to table
        int bits = -6;  // group of 6 bits
        const unsigned int b63 = 0x3F ; //hexadecimals 63

        for (const auto &c:s) //c will be assigned everycharacter from s string
        {
            val = (val<<8) + c; //the resulting number will be shifted by val eight places
            bits +=8;
            while(bits >=0)
            {
                ret.push_back (BASE64_CODES[(val<<bits) &b63 } ] );
                bits -= 6;
            }

        }

        if (bits>-6)
            { ret.push_back (BASE64_CODES[( ( val<<8) >> (bits + 8 )) & b63 ]) };

        while (ret.size() % 4)
        {
                ret.push_back("=");

        return ret;
        }
    }


}




#endif // BASE_64_H
