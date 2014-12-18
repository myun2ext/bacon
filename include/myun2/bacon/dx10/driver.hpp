#ifndef __github_com_myun2__bacon__dx10__driver_HPP__
#define __github_com_myun2__bacon__dx10__driver_HPP__

#include <d3d10.h>

namespace myun2
{
	namespace bacon
	{
		class driver_dx10
		{
		protected:
		   ID3D10Device* inner;
		   IDXGISwapChain* swap_chain;
		public:
			driver_dx10(const driver_params &params)
				: inner(NULL), swap_chain(NULL)
			{
				start(params);
			}
			virtual~ driver_dx10(){ release(); }

			void start(const driver_params &params)
			{
				HWND hWnd = params.wndparams.hWnd;
				unsigned int width = params.wndparams.width;
				unsigned int height = params.wndparams.height;
				unsigned int frameRate = 0;

				DXGI_SWAP_CHAIN_DESC swapChainDesc = {
					{width, height, {frameRate, 1}, DXGI_FORMAT_R16G16B16A16_FLOAT, DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED, DXGI_MODE_SCALING_CENTERED},
					{1, 0}, DXGI_USAGE_RENDER_TARGET_OUTPUT, 1, hWnd, true, DXGI_SWAP_EFFECT_DISCARD, DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH
				};

				if( FAILED( D3D10CreateDeviceAndSwapChain( 0, D3D10_DRIVER_TYPE_HARDWARE, 0, 0, D3D10_SDK_VERSION, &swapChainDesc, &swap_chain, &inner ) ) ) {
					//	Failed
				}
			}
			void release() {
				if ( inner != NULL ) {
					inner->Release();
					inner = NULL;
				}
				if ( swap_chain != NULL ) {
					swap_chain->Release();
					swap_chain = NULL;
				}
			}
			void begin() { /* Empty */ }
			void present() { swap_chain->Present(0, 0); }
		};
	}
}

#endif//__github_com_myun2__bacon__dx10__driver_HPP__
