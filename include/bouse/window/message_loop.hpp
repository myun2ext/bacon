#ifndef __github_com_myun2__bouse__message_loop_HPP__
#define __github_com_myun2__bouse__message_loop_HPP__

#include <windows.h>

namespace myun2
{
	namespace bouse
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

#endif//__github_com_myun2__bouse__message_loop_HPP__
