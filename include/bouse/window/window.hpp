#ifndef __github_com_myun2__bouse__window__window_HPP__
#define __github_com_myun2__bouse__window__window_HPP__

#include <windows.h>
#include "bouse/window/window_class.hpp"
#include "bouse/window/window_proc.hpp"
#include "bouse/window/message_loop.hpp"

namespace myun2
{
	namespace bouse
	{
		class window
		{
		private:
			HWND hWnd;
			DWORD m_dwStyle;
			DWORD m_dwExStyle;
		public:
			window() : hWnd(NULL) { setup_standard_window_styles(); }
			window(const window_class& cls, const char* title, unsigned int width, unsigned int height,
				unsigned int x = CW_USEDEFAULT, unsigned int y = CW_USEDEFAULT, bool hidden=false)
			{
				setup_standard_window_styles();
				start(cls, title, width, height, x, y, hidden);
			}
			start(const window_class& cls, const char* title, unsigned int width, unsigned int height,
				unsigned int x = CW_USEDEFAULT, unsigned int y = CW_USEDEFAULT, bool hidden=false)
			{
				hWnd = ::CreateWindowEx(
					m_dwExStyle,
					cls.get_class_name(),
					title,
					m_dwStyle,
					x, y, width, height,
					NULL,
					NULL,
					NULL,
					NULL);

				if ( !hidden ) show();
			}

			void show() {
				ShowWindow(hWnd, SW_SHOWNORMAL);
				UpdateWindow(hWnd);
			}

			operator HWND() { return hWnd; }
			HWND get_window_handle() const { return hWnd; }
			void set_style(DWORD style) { m_dwStyle = style; }
			void set_ex_style(DWORD style) { m_dwExStyle = style; }
			void setup_standard_window_styles()
			{
				m_dwStyle = WS_OVERLAPPEDWINDOW;
				m_dwExStyle = WS_EX_APPWINDOW;
			}
		};
	}
}

#endif//__github_com_myun2__bouse__window__window_HPP__
