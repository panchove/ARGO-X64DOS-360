# Makefile industrial ARM64 para X64DOS
TARGET = x64dos.kernel
CC = aarch64-linux-gnu-gcc
CFLAGS = -Wall -O2 -std=c99
LUAFLAGS = -llua5.4

SRC := $(wildcard kernel/*.c tools/*.c drivers/fuentes/*.c)
OBJ := $(SRC:.c=.o)

all: $(TARGET) drivers/exampledev.sys drivers/exampledev_test tools/bridge_int21_64.so tools/bridge_int21_64_test

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LUAFLAGS)

drivers/exampledev.sys: drivers/exampledev.c
	$(CC) $(CFLAGS) -c -o drivers/exampledev.sys drivers/exampledev.c

drivers/exampledev_test: drivers/exampledev.c
	$(CC) $(CFLAGS) -static -DUNIT_TEST -o drivers/exampledev_test drivers/exampledev.c

tools/bridge_int21_64.so: tools/bridge_int21_64.c
	$(CC) $(CFLAGS) -fPIC -shared -o tools/bridge_int21_64.so tools/bridge_int21_64.c

tools/bridge_int21_64_test: tools/bridge_int21_64.c
	$(CC) $(CFLAGS) -static -DUNIT_TEST -o tools/bridge_int21_64_test tools/bridge_int21_64.c

test: drivers/exampledev_test tools/bridge_int21_64_test
	@echo '==> QA drivers/exampledev_test'
	qemu-aarch64 drivers/exampledev_test
	@echo
	@echo '==> QA tools/bridge_int21_64_test'
	qemu-aarch64 tools/bridge_int21_64_test
	@echo '\n==> Todos los tests ejecutados. Verifica evidencia en logs/'

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
