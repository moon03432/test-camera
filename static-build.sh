#!/bin/sh

g++ src/main.cpp -o main -pthread -I/usr/local/include/opencv -I/usr/local/include -I/usr/include/gtk-2.0 -I/usr/lib/aarch64-linux-gnu/gtk-2.0/include -I/usr/include/gio-unix-2.0/ -I/usr/include/cairo -I/usr/include/pango-1.0 -I/usr/include/harfbuzz -I/usr/include/pango-1.0 -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng12 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/libpng12 -I/usr/include/glib-2.0 -I/usr/lib/aarch64-linux-gnu/glib-2.0/include -L/usr/lib/aarch64-linux-gnu -L/usr/lib/gcc/aarch64-linux-gnu/5 -L/usr/local/share/OpenCV/3rdparty/lib -Wl,-Bstatic -lopencv_objdetect -lopencv_stitching -lopencv_videostab -lopencv_photo -lopencv_shape -lopencv_superres -lopencv_video -lopencv_dnn -lopencv_ml -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_imgproc -lopencv_flann -lopencv_core -ltegra_hal -Wl,-Bdynamic -lgcc_s -lz -ldl -ltiff -ljpeg -lwebp -lpng16 -ljasper -lgtk-x11-2.0 -lgdk-x11-2.0 -lpangocairo-1.0 -latk-1.0 -lcairo -lgdk_pixbuf-2.0 -lgio-2.0 -lpangoft2-1.0 -lpango-1.0 -lgobject-2.0 -lglib-2.0 -lfontconfig -lfreetype
