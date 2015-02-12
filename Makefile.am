ACLOCAL_AMFLAGS = -I m4
SUBDIRS = libltdl src

win32:
	make
	mkdir -p win/win32
	cp ./src/.libs/exgauss.dll ./win/win32
	cp ./src/.libs/exgauss.dll.a ./win/win32
	cp ./src/.libs/exgauss.la ./win/win32

win64:
	make
	mkdir -p win/win64
	cp ./src/.libs/exgauss.dll ./win/win64
	cp ./src/.libs/exgauss.dll.a ./win/win64
	cp ./src/.libs/exgausexgauss.la ./win/win64
