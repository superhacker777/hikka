#hikka — IP camera bruteforcer based on Hikvision SDK.

---

## Building

I'm using a makefile, so you should be able to build it under Linux using this command:

    # make linux


You can also build it for Windows if you have a MinGW installed:

    # make windows

    
And you can make binaries for Linux and Windows by omiting a make target (it is useful for me as I distribute every build to people who don't know anything about compilers):

    # make


And now you have a `build` directory with compiled app.

---

## Usage

You can define some options:

* __-logins, -passwords__ — files where your logins and passwords are stored; it looks for «logins» and «passwords» by default;
* __-check__ — very useful, but still experimental option which allows to check a host before trying to log in (I did some reverse-engineering and I'm not really sure if everything is OK);
* __-shoots__ — a directory where pictures from cameras will be stored; it doesn't download pictures by default;
* __-threads__ — there's no multithreading until you define in how many threads you want to do a job;
* __-csv__ — write results to CSV file.


__Please note that it is hardcoded to read IPs from file called “hosts”!__

A typical cammand is:

    hikka -threads 200 -check -shoots pics/


Here you go, kid.

---

## TODO

1. Export result to JSON, iVMS-compatible CSV and m3u playlist.
2. Some features like checking PTZ- and microphone-enabled cameras.
3. Rewrite bruteforcing routine to make it possible to bruteforce a single camera in multiple threads (there's a one thread for every camera now).

---

## Bugs

There's some bugs in SDK library (memory leaks and cycling that can fuck up everything) and I can't do anything with it, but all in all it isn't that bad.

---

## Contributing

I'm a newbie in Go and this is my first Go program, so the code and some practices may be ugly. Please tell me if you'll find something that I did in wrong way.

Feel free to contribute, yeah.