#include "myun2/bacon/window.hpp"
#include <stdio.h>

using namespace myun2::bacon;

int main()
{
	try {
		window_class wc;
		wc.register_class();
		window win(wc, "Title", 230, 120);
		Sleep(1000);
	}
	catch(::std::exception &e)
	{
		printf("%s", e.what());
	}
}
