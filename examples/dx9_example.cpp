#include "myun2/bacon/dx9.hpp"
#include "myun2/bacon/app_base.hpp"

using namespace myun2::bacon;

class example_app : public app_base<driver_dx9>
{
private:
	typedef app_base<driver_dx9> base;
public:
	example_app() : base("Bacon", 640, 480) {}
};


int WINAPI WinMain(
	HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	try {
		example_app a;
	}
	catch(::std::exception &e)
	{
		MessageBox(NULL, e.what(), "Error", 0);
	}
	return 0;
}
