# Makefile industrial ARM64 para X64DOS
TARGET = x64dos.kernel
CC = aarch64-linux-gnu-gcc
CFLAGS = -Wall -O2 -std=c99
LUAFLAGS = -llua5.4

SRC := $(wildcard kernel/*.c tools/*.c drivers/fuentes/*.c)
OBJ := $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LUAFLAGS)

clean:
	rm -f $(OBJ) $(TARGET)

# --- Ejecución en emulador QEMU ARM64 ---
# Referencia:
#   - docs/08-QEMU-Configuracion-Inicial.md
#   - docs/06-Instalacion-SID.md
#
# Ajusta '$(TARGET)' a tu ELF real (kernel.elf, x64dos.elf...) si lo renombras
# Para debug con GDB: agrega -s -S al final del comando

run: $(TARGET)
	qemu-system-aarch64 -M virt -cpu cortex-a53 -m 2G -nographic -kernel $(TARGET)
