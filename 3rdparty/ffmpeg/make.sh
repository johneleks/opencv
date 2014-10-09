#!/bin/sh
gcc -Wall -shared -o opencv_ffmpeg.dll -O2 -x c++ -I../include -I../include/ffmpeg_ -I../../modules/videoio/src ffopencv.c -L../lib -lavformat -lavcodec -lavdevice -lswscale -lavutil -lws2_32
gcc -m64 -Wall -shared -o opencv_ffmpeg_64.dll -O2 -x c++ -I../include -I../include/ffmpeg_ -I../../modules/videoio/src ffopencv.c -L../lib -lavformat64 -lavcodec64 -lavdevice64 -lswscale64 -lavutil64 -lws2_32
