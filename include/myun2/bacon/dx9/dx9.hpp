#ifndef __github_com_myun2__bacon__dx9__dx9_HPP__
#define __github_com_myun2__bacon__dx9__dx9_HPP__

#include <d3d9.h>
#pragma comment(lib, "d3d9.lib")

namespace myun2
{
	namespace bacon
	{
		class dx9
		{
		protected:
			IDirect3D9* d3d;
		public:
			dx9(){ start(); }
			virtual~ dx9(){ end(); }
			void start() {
				d3d = ::Direct3DCreate9(D3D_SDK_VERSION);
			}
			void end() {
				if ( d3d != NULL ) {
					d3d->Release();
					d3d = NULL;
				}
			}
			operator IDirect3D9*() { return d3d; }
			IDirect3D9* operator ->() { return d3d; }
			IDirect3D9* get_direct3d() { return d3d; }
		};

		dx9& get_dx9() {
			static dx9 dx;
			return dx;
		}
		IDirect3D9* get_d3d9() {
			return get_dx9().get_direct3d();
		}
	}
}


#endif//__github_com_myun2__bacon__dx9__dx9_HPP__
