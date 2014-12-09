#ifndef __github_com_myun2__bacon__window_class_HPP__
#define __github_com_myun2__bacon__window_class_HPP__

#include <windows.h>
#include <exception>
#include <string>

namespace myun2
{
	namespace bacon
	{
		class window_class
		{
		public:
			typedef ::WNDCLASSEX WindowClassType;

			struct register_failed : ::std::exception
			{
			protected:
				const DWORD dwLastError;
				mutable ::std::string message;
			public:
				register_failed() : dwLastError(GetLastError()) {}
				virtual ~register_failed() throw() {}
				const char* what() const throw()
				{
					LPSTR localBuffer = NULL;
					size_t size = FormatMessageA(
						FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
						NULL, dwLastError, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&localBuffer, 0, NULL);

					message = ::std::string(localBuffer, size);
					LocalFree(localBuffer);
					return message.c_str();
				}
			};
		protected:
			WindowClassType internal;
			ATOM m_atom;
		public:
			void clear() {
				unregister(NULL);
				ZeroMemory(&internal, sizeof(internal));
				internal.cbSize = sizeof(internal);
			}

			window_class() : m_atom(0) { clear(); }
			window_class(const char* name) : m_atom(0) {
				internal.lpszClassName = name;
				clear();
			}

			operator WNDCLASSEX& () { return internal; }
			operator const WNDCLASSEX& () const { return internal; }
			operator WNDCLASSEX* () { return &internal; }
			operator const WNDCLASSEX* () const { return &internal; }

			void register_class() {
				m_atom = ::RegisterClassEx(&internal);
				if ( m_atom == 0 )
					throw register_failed();
			}
			void unregister(HINSTANCE hInstance) {
				if ( m_atom ) if ( ::UnregisterClass(internal.lpszClassName, hInstance) ) m_atom = 0;
			}

			const char* get_class_name() const { return internal.lpszClassName; }
		};
	}
}

#endif//__github_com_myun2__bacon__window_class_HPP__
