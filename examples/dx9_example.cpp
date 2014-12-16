#include "myun2/bacon/dx9.hpp"
#include "myun2/bacon/app_base.hpp"
#include <stdio.h>

using namespace myun2::bacon;

class example_app : public app_base<driver_dx9>
{
private:
	typedef app_base<driver_dx9> base;
public:
	example_app() : base("Bacon", 640, 480) {}
};

int main()
{
	try {
		example_app a;
	}
	catch(::std::exception &e)
	{
		printf("%s", e.what());
	}
}
