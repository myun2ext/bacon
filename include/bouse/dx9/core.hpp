#ifndef __github_com_myun2__bouse__dx9__core_HPP__
#define __github_com_myun2__bouse__dx9__core_HPP__

#include <d3d9.h>
#pragma comment(lib, "d3d9.lib")

namespace myun2
{
	namespace bouse
	{
		namespace dx9
		{
			struct core {
				IDirect3D9* ptr;
				core() { ptr = ::Direct3DCreate9(D3D_SDK_VERSION); }
				virtual~ core(){ ptr->Release(); }
				IDirect3D9* get () { return ptr; }
			};
		}
	}
}


#endif//__github_com_myun2__bouse__dx9__core_HPP__
