#include "myun2/bacon/window.hpp"
#include "myun2/bacon/driver_params.hpp"
#include "myun2/bacon/dx9.hpp"
#include <stdio.h>

using namespace myun2::bacon;

int main()
{
	try {
		window_class wc("Example Window Class", window_proc<window_proc_base>);
		wc.register_class();
		window w(wc, "Title", 640, 480);

		driver_dx9 drv(driver_params(driver_window_params(w, 640, 480)));
		message_loop lp;
		lp.run();
	}
	catch(::std::exception &e)
	{
		printf("%s", e.what());
	}
}
