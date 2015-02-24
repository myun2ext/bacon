#ifndef __github_com_myun2__bacon__message_loop_HPP__
#define __github_com_myun2__bacon__message_loop_HPP__

#include <windows.h>

namespace myun2
{
	namespace bacon
	{
		class message_loop
		{
		public:
			void run()
			{
				MSG msg;
				while (GetMessage(&msg, NULL, 0, 0))
				{
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
			}
		};
	}
}

#endif//__github_com_myun2__bacon__message_loop_HPP__
