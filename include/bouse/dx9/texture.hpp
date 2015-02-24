#ifndef __github_com_myun2__bouse__dx9__texture_HPP__
#define __github_com_myun2__bouse__dx9__texture_HPP__

namespace myun2
{
	namespace bouse
	{
		namespace dx9
		{
			class texture
			{
			protected:
				typedef _DevPtr* IDirect3DDevice9;
				::IDirect3DTexture9* ptr;
			public:
				texture(_DevPtr dev, const char* filename) : ptr(0) { load_from_file(dev, filename); }
				virtual~ driver_dx9(){ release(); }

				bool load_from_file(_DevPtr dev, const char* filename)
				{
					return ::D3DXCreateTextureFromFile(dev, filename, &ptr);
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

#endif//__github_com_myun2__bouse__dx9__texture_HPP__
