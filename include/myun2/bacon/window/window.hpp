#ifndef __github_com_myun2__bacon__window__window_HPP__
#define __github_com_myun2__bacon__window__window_HPP__

#include <windows.h>
#include "myun2/bacon/window/window_class.hpp"

namespace myun2
{
	namespace bacon
	{
		class window
		{
		private:
			HWND hWnd;
		public:
			window() : hWnd(NULL) {}
			window(const window_class& cls, const char* title, unsigned int width, unsigned int height,
				unsigned int x = CW_USEDEFAULT, unsigned int y = CW_USEDEFAULT, bool hidden=false)
			{
				start(cls, title, width, height, x, y, hidden);
			}
			start(const window_class& cls, const char* title, unsigned int width, unsigned int height,
				unsigned int x = CW_USEDEFAULT, unsigned int y = CW_USEDEFAULT, bool hidden=false)
			{
				hWnd = ::CreateWindowEx(
					WS_EX_APPWINDOW,
					cls.get_class_name(),
					title,
					WS_OVERLAPPEDWINDOW,
					x, y, width, height,
					NULL,
					NULL,
					NULL,
					NULL);

				if ( !hidden ) show();
			}

			void show() {
				ShowWindow(hWnd, SW_SHOWDEFAULT);
				UpdateWindow(hWnd);
			}

			HWND get_window_handle() const { return hWnd; }
		};
	}
}

#endif//__github_com_myun2__bacon__window__window_HPP__
