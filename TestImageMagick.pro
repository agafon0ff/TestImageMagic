TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += "/usr/local/include/ImageMagick-7/"

LIBS += /usr/local/lib/libMagick++-7.Q16HDRI.so
LIBS += /usr/local/lib/libMagickCore-7.Q16HDRI.so
LIBS += /usr/local/lib/libMagickWand-7.Q16HDRI.so

SOURCES += \
        main.cpp
