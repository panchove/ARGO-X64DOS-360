#!/bin/sh
# Script de arranque QEMU estandarizado (ver docs/08-QEMU-Configuracion-Inicial.md)
# Ajusta "x64dos.kernel" si generas un binario ELF distinto (ej: kernel.elf)
QEMU_BIN=qemu-system-aarch64
KERNEL=x64dos.kernel
RAM=2G
CPU=cortex-a53
MACH=virt

exec $QEMU_BIN -M $MACH -cpu $CPU -m $RAM -nographic -kernel $KERNEL "$@"
