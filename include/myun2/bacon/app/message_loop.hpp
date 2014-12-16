#ifndef __github_com_myun2__bacon__app__message_loop_HPP__
#define __github_com_myun2__bacon__app__message_loop_HPP__

#include <windows.h>

namespace myun2
{
	namespace bacon
	{
		namespace app
		{
			class message_loop
			{
			protected:
				virtual void on_frame() =0;
			public:
				void run_message_loop()
				{
					MSG msg;
					do {
						if ( PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) )
							::DispatchMessage( &msg );
						else
							on_frame();
					} while( msg.message != WM_QUIT );
				}
			};
		}
	}
}

#endif//__github_com_myun2__bacon__app__message_loop_HPP__
