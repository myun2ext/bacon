#ifndef __github_com_myun2__bouse__dx9__device_HPP__
#define __github_com_myun2__bouse__dx9__device_HPP__

namespace myun2
{
	namespace bouse
	{
		namespace dx9
		{
			class device
			{
			protected:
				::IDirect3DDevice9* ptr;
			public:
				device(HWND hWnd, UINT height, UINT width, const driver_params &params) {
					start(params);
				}
				virtual~ driver_dx9(){ release(); }

				void start(HWND hWnd, UINT height, UINT width, const driver_params &params, BOOL is_fullscreen = false)
				{
					D3DPRESENT_PARAMETERS d3dParams = {
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

					if( FAILED( get_dx9()->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dParams, &ptr ) ) )
					if( FAILED( get_dx9()->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dParams, &ptr ) ) )
					if( FAILED( get_dx9()->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dParams, &ptr ) ) )
					if( FAILED( get_dx9()->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dParams, &ptr ) ) )
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
