#include "myun2/bacon/window.hpp"

using namespace myun2::bacon;

int main()
{
	window_class wc;
	wc.register_class();
	window win(wc, "Title", 230, 120);
	Sleep(1000);
}
