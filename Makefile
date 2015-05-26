export CGO_ENABLED=1
export GOARCH=386
export WDIR=${PWD}

all: linux windows

linux:
	GOOS=linux CGO_CFLAGS="-I${WDIR}/include" CGO_LDFLAGS="-L${WDIR}/lib -Wl,-rpath=${WDIR}/lib -lhcnetsdk" go build -o build/Linux/hikka src/hikka.go
	cp lib/libhcnetsdk.so build/Linux/
	cp dist/hosts build/Linux
	cp dist/logins build/Linux
	cp dist/passwords build/Linux

windows:
	CGO_CFLAGS="-I${WDIR}/include" CGO_LDFLAGS="-L${WDIR}/lib -Wl,--large-address-aware,--enable-stdcall-fixup,-rpath=${WDIR}/lib -lhcnetsdk" GOOS=windows CC=i686-w64-mingw32-gcc CXX=i686-w64-mingw32-g++ go build -o build/Windows/hikka.exe src/hikka.go
	cp lib/libhcnetsdk.dll build/Windows/hcnetsdk.dll
	cp lib/HPR.dll build/Windows/HPR.dll
	cp dist/hosts build/Windows/hosts
	cp dist/logins build/Windows/logins
	cp dist/passwords build/Windows/passwords

clean:
	rm -r build/
