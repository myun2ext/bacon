#ifndef __github_com_myun2__bacon__app_base_HPP__
#define __github_com_myun2__bacon__app_base_HPP__

#include "myun2/bacon/window.hpp"
#include "myun2/bacon/app/message_loop.hpp"

namespace myun2
{
	namespace bacon
	{
		template <typename _Driver>
		class app_base :
			public app::message_loop
		{
		private:
			window wnd;
			_Driver drv;
			void on_frame()
			{
				//drv.clear(D3DCOLOR_XRGB(0,0,255));
				drv.begin_scene();
				drv.end_scene();
				drv.present();
				Sleep(100);
			}
			static window_class wndclass() {
				window_class wc("Bacon Window Class", window_proc<window_proc_base>);
				wc.register_class();
				return wc;
			}
		public:
			app_base(const char* app_title, unsigned int height, unsigned int width, bool is_fullscreen=false)
				: wnd(wndclass(), app_title, height, width),
				  drv(driver_params(driver_window_params(wnd, height, width, is_fullscreen)))
			{
				run_message_loop();
			}
		};
	}
}

#endif//__github_com_myun2__bacon__app_base_HPP__
