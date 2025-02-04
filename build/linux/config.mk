OS = $(shell name)
DEBUG ?= 0
SYSTEM ?= linux
LIBNAME=libAlgRC


OPTIMFLAG := -g

CROSS:=
RC_chipname:=x86
RC_platform:=x64
EXTRA_CFLAGS:=
EXTRA_LDFLAGS:=
BIN_DIR:=../../bin/$(SYSTEM)_$(RC_chipname)_$(RC_platform)_$(CROSS)gcc

CC := $(CROSS)gcc
CPP := $(CROSS)g++
AR := $(CROSS)ar
LD:= $(CROSS)ld
ASM:=nasm
