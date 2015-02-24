#ifndef __github_com_myun2__bouse__window_class_HPP__
#define __github_com_myun2__bouse__window_class_HPP__

#include <windows.h>

namespace myun2
{
	namespace bouse
	{
		class window_class
		{
		public:
			class register_failed {};
		protected:
			WNDCLASSEX wndcls;
			ATOM m_atom;
		public:
			void clear() {
				//unregister(NULL);
				ZeroMemory(&wndcls, sizeof(wndcls));
				wndcls.cbSize = sizeof(wndcls);
			}
			window_class(const char* name, WNDPROC wndproc) : m_atom(0) {
				clear();
				wndcls.lpszClassName = name;
				wndcls.lpfnWndProc = wndproc;
			}

			operator WNDCLASSEX& () { return wndcls; }
			operator const WNDCLASSEX& () const { return wndcls; }
			operator WNDCLASSEX* () { return &wndcls; }
			operator const WNDCLASSEX* () const { return &wndcls; }

			void register_class() {
				m_atom = ::RegisterClassEx(&wndcls);
				if ( m_atom == 0 )
					throw register_failed();
			}
			void unregister(HINSTANCE hInstance) {
				if ( m_atom ) if ( ::UnregisterClass(wndcls.lpszClassName, hInstance) ) m_atom = 0;
			}

			const char* get_class_name() const { return wndcls.lpszClassName; }
		};
	}
}

#endif//__github_com_myun2__bouse__window_class_HPP__
