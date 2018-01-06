
#include <iostream>
#include <windows.h>
#include "Helper.h"
#include "KeyConstants.h"
#include "Base64.h"

using namespace std;

int main()
{
	MSG Msg; //This is a message to be processed but it will never be processed

	while (GetMessage(&Msg, NULL, 0, 0) ) {
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}


	cout << "HEY THERE"; cout<<"work man";

    return 0;
}

