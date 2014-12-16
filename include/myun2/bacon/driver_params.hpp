#ifndef __github_com_myun2__bacon__driver_params_HPP__
#define __github_com_myun2__bacon__driver_params_HPP__

namespace myun2
{
	namespace bacon
	{
		struct driver_window_params
		{
			HWND hWnd;
			unsigned int height;
			unsigned int width;
			bool is_fullscreen;

			driver_window_params(HWND _hWnd, unsigned int _height, unsigned int _width, bool _is_fullscreen=false) :
				hWnd(_hWnd), height(_height), width(_width), is_fullscreen(_is_fullscreen) {}
		};

		struct driver_params
		{
			driver_window_params wndparams;
			unsigned int adapter_no;

			driver_params(const driver_window_params& _wndparams) :
				wndparams(_wndparams) {}
		};
	}
}


#endif//__github_com_myun2__bacon__driver_params_HPP__
