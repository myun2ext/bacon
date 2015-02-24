#ifndef __github_com_myun2__bouse__dx9__device_HPP__
#define __github_com_myun2__bouse__dx9__device_HPP__

namespace myun2
{
	namespace bouse
	{
		namespace dx9
		{
			struct device_params {};

			class device
			{
			protected:
				typedef IDirect3D9* _Root;
				::IDirect3DDevice9* ptr;
			public:
				device(_Root root, HWND hWnd, UINT height, UINT width, const device_params &params, BOOL is_fullscreen = false) {
					start(root, hWnd, height, width, params, is_fullscreen);
				}
				virtual~ device(){ release(); }

				void start(_Root root, HWND hWnd, UINT height, UINT width, const device_params &params, BOOL is_fullscreen = false)
				{
					D3DPRESENT_PARAMETERS d3d_params = {
						height,
						width,
						D3DFMT_UNKNOWN,
						0,
						D3DMULTISAMPLE_NONE,
						0,
						D3DSWAPEFFECT_DISCARD,
						NULL,
						is_fullscreen,
						TRUE,
						D3DFMT_D24S8,
						0,
						0
					};

					if( FAILED( root->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3d_params, &ptr ) ) )
					if( FAILED( root->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3d_params, &ptr ) ) )
					if( FAILED( root->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3d_params, &ptr ) ) )
					if( FAILED( root->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3d_params, &ptr ) ) )
					{
						//	release
					}
				}
				void release() {
					if ( ptr != NULL ) {
						ptr->Release();
						ptr = NULL;
					}
				}
			};
		}
	}
}

#endif//__github_com_myun2__bouse__dx9__device_HPP__
