#ifndef __github_com_myun2__bacon__dx9__driver_HPP__
#define __github_com_myun2__bacon__dx9__driver_HPP__

namespace myun2
{
	namespace bacon
	{
		class driver_dx9
		{
		protected:
			IDirect3DDevice9* inner;
		public:
			driver_dx9(const driver_params &params) {
				start(params);
			}
			virtual~ driver_dx9(){ release(); }

			void start(const driver_params &params)
			{
				HWND hWnd = params.wndparams.hWnd;

				D3DPRESENT_PARAMETERS d3dParams = {
					params.wndparams.width,
					params.wndparams.height,
					D3DFMT_UNKNOWN,
					0,
					D3DMULTISAMPLE_NONE,
					0,
					D3DSWAPEFFECT_DISCARD,
					NULL,
					(params.wndparams.is_fullscreen ? FALSE : TRUE ),
					TRUE,
					D3DFMT_D24S8,
					0,
					0
				};

				if( FAILED( get_dx9()->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dParams, &inner ) ) )
				if( FAILED( get_dx9()->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dParams, &inner ) ) )
				if( FAILED( get_dx9()->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dParams, &inner ) ) )
				if( FAILED( get_dx9()->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dParams, &inner ) ) )
				{
					//	release
				}
			}
			void release() {
				if ( inner != NULL ) {
					inner->Release();
					inner = NULL;
				}
			}
			void begin_scene() { inner->BeginScene(); }
			void end_scene() { inner->EndScene(); }
			void present() { inner->Present( NULL, NULL, NULL, NULL ); }
		};
	}
}

#endif//__github_com_myun2__bacon__dx9__driver_HPP__
