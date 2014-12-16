#ifndef __github_com_myun2__bacon__app_base_HPP__
#define __github_com_myun2__bacon__app_base_HPP__

#include "myun2/bacon/window.hpp"
#include "myun2/bacon/driver_params.hpp"

namespace myun2
{
	namespace bacon
	{
		template <typename _Driver>
		class app_base
		{
		public:
			app_base(const char* app_title, unsigned int height, unsigned int width, bool is_fullscreen=false)
			{
				window_class wc("Bacon Window Class", window_proc<window_proc_base>);
				wc.register_class();
				window w(wc, app_title, height, width);

				_Driver drv(driver_params(driver_window_params(w, height, width, is_fullscreen)));
				message_loop lp;
				lp.run();
			}
		};
	}
}

#endif//__github_com_myun2__bacon__app_base_HPP__
