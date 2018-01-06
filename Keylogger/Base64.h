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

}




#endif // BASE_64_H
