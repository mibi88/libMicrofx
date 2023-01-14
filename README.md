# libMicrofx

Make very small add-ins.

With this library you can easly make very small add-ins, but they are not as fast as add-ins made using gint, so you should use gint to write more complex add-ins. This library only provides support of the fx98xx series of CASIO monochrome calculators that support add-ins.

## Getting started

An example add-in is in template. Start your project with this folder. Requires sh-elf-* of the fxsdk.

The library is in microfx_src. If the library was updated, update you project by replacing lib with a new version compiled by typing `make` in microfx_src.

You can read the header files in lib/include/microfx to see the available functions.