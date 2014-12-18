dx10:
	g++ -O3 -I ./include ./examples/dx10_example.cpp -ld3d10 -Wl,--subsystem,windows
dx9:
	g++ -O3 -I ./include ./examples/dx9_example.cpp -ld3d9 -Wl,--subsystem,windows
window_test:
	g++ -O3 -I ./include ./examples/window_example.cpp -Wl,--subsystem,windows
