ASFLAGS64  = --64
ASFLAGS64 += -march=corei7

.PHONY: assemble

all: assemble
	@echo "No errors"

assemble:
	$(AS) rc4func.S ${ASFLAGS64} -o rc4func.o
