export CGO_ENABLED=1
export WDIR=${PWD}

all: linux windows

linux:
	GOOS=linux CGO_CFLAGS="-I${WDIR}/include" CGO_LDFLAGS="-L${WDIR}/lib/Linux -Wl,-rpath=${WDIR}/lib/Linux -lhcnetsdk" go build -o build/Linux/hikka src/hikka.go
	cp lib/Linux/libhcnetsdk.so build/Linux/
	cp lib/Linux/libHCCore.so build/Linux/
	cp lib/Linux/libhpr.so build/Linux/
	cp -r lib/Linux/HCNetSDKCom/ build/Linux/
	cp dist/hosts build/Linux
	cp dist/logins build/Linux
	cp dist/passwords build/Linux

windows:
	CGO_CFLAGS="-I${WDIR}/include" CGO_LDFLAGS="-L${WDIR}/lib/Windows -Wl,--enable-stdcall-fixup,-rpath=${WDIR}/lib/Windows -lHCNetSDK" GOOS=windows CC=x86_64-w64-mingw32-gcc CXX=x86_64-w64-mingw32-g++ go build -o build/Windows/hikka.exe src/hikka.go
	cp lib/Windows/HCNetSDK.dll build/Windows/
	cp lib/Windows/HCCore.dll build/Windows/
	cp -r lib/Windows/HCNetSDKCom/ build/Windows/
	cp dist/hosts build/Windows/hosts
	cp dist/logins build/Windows/logins
	cp dist/passwords build/Windows/passwords

clean:
	rm -r build/
