QT += core
QT -= gui

CONFIG += c++11

TARGET = Proyecto
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    rep/rep.cpp \
    mkdisk/mkdisk.cpp \
    fdisk/fdisk.cpp \
    execute/execute.cpp \
    analizador/analizador.cpp \
    analizador/rmdisk.cpp \
    analizador/mount.cpp \
    analizador/unmount.cpp \
    analizador/mkfs.cpp \
    analizador/login.cpp \
    analizador/logout.cpp

HEADERS += \
    rep/rep.h \
    mkdisk/mkdisk.h \
    fdisk/fdisk.h \
    execute/execute.h \
    analizador/analizador.h \
    analizador/rmdisk.h \
    analizador/mount.h \
    analizador/unmount.h \
    analizador/mkfs.h \
    analizador/login.h \
    analizador/logout.h
