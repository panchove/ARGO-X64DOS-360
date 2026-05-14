# Guía de Instalación y Entorno (SID)
>
> **Cumplimiento:** ISO/IEC 12207, 25010, 15504, 27001, 9001.  
> **Documento versionado y auditado.**  
> **Revisión:** 2026-05-14, **Responsable:** Equipo X64DOS

## 1. Requisitos

- Ubuntu/Debian
- QEMU
- Toolchain cruzado: aarch64-none-elf-gcc/binutils
- make, gdb-multiarch

## 2. Instalación

```bash
sudo apt update
sudo apt install gcc-aarch64-linux-gnu binutils-aarch64-linux-gnu \
qemu-system-arm gdb-multiarch make
```

## 3. Compilación kernel

```bash
make
```

Genera `x64dos.elf` al finalizar.

## 4. Ejecución en QEMU

```bash
qemu-system-aarch64 -M virt -cpu cortex-a53 -m 2G -nographic -kernel x64dos.elf
```

## 5. Debugging con GDB

Abra dos terminales:
En 1:

```bash
qemu-system-aarch64 -M virt -cpu cortex-a53 -m 2G -nographic -kernel x64dos.elf -s -S
```

En 2:

```bash
aarch64-none-elf-gdb x64dos.elf
target remote localhost:1234
```

## 6. Limpieza

```bash
make clean
```
