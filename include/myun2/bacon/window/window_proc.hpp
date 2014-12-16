#ifndef __github_com_myun2__bacon__window_proc_HPP__
#define __github_com_myun2__bacon__window_proc_HPP__

#include <windows.h>

namespace myun2
{
	namespace bacon
	{
		class window_proc
		{
		public:
			LRESULT proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
			{
				switch (uMsg)
				{
					case WM_DESTROY: return on_destroy();
					default: break;
				}
				return ::DefWindowProc(hWnd, uMsg, wParam, lParam);
			}
		protected:
			LRESULT on_destroy() {
				::PostQuitMessage(0);
				return 0;
			}
		};
	}
}

#endif//__github_com_myun2__bacon__window_proc_HPP__
