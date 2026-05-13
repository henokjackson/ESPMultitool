.PHONY: clean all

C_STD_FLAGS:= -Wall -std=c23
C_PERF_OPT_FLAGS:= -march=native -flto -Ofast -funroll-loops -fno-exceptions -fno-rtti -fno-stack-protector
C_SIZE_OPT_FLAGS:=


all:

