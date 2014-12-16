#include "myun2/bacon/window.hpp"
#include <stdio.h>

using namespace myun2::bacon;

int main()
{
	try {
		window_class wc("Example Window Class", window_proc<window_proc_base>);
		wc.register_class();
		window win(wc, "Title", 640, 480);
		Sleep(3000);
	}
	catch(::std::exception &e)
	{
		printf("%s", e.what());
	}
}
