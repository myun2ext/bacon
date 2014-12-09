#ifndef __github_com_myun2__bacon__window_class_HPP__
#define __github_com_myun2__bacon__window_class_HPP__

#include <windows.h>

namespace myun2
{
	namespace bacon
	{
		class window_class
		{
		public:
			typedef ::WNDCLASSEX WindowClassType;
		protected:
			WindowClassType internal;
		public:
			window_class()
			{
				ZeroMemory(&internal, sizeof(internal));
				internal.cbSize = sizeof(internal);
			}

			operator WNDCLASSEX& () { return internal; }
			operator const WNDCLASSEX& () const { return internal; }
			operator WNDCLASSEX* () { return &internal; }
			operator const WNDCLASSEX* () const { return &internal; }

			void register_class() const { ::RegisterClassEx(&internal); }
			void unregister(HINSTANCE hInstance) const {
				::UnregisterClass(internal.lpszClassName, hInstance); }

			const char* get_class_name() const { return internal.lpszClassName; }
		};
	}
}

#endif//__github_com_myun2__bacon__window_class_HPP__
