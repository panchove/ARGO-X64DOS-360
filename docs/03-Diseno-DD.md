# Documento de Diseño (DD)
>
> **Cumplimiento:** ISO/IEC 12207, 25010, 15504, 27001, 9001.  
> **Documento versionado y auditado.**  
> **Revisión:** 2026-05-14, **Responsable:** Equipo X64DOS

## 1. Introducción

Enuncia las principales decisiones de bajo nivel requeridas para implementar X64DOS.

## 2. Estructura del Código

- boot.S: inicialización desde QEMU/hardware, setting stack y saltos al kernel.
- kernel/: rutinas principales en C.
- drivers/: UART, timer, disco.
- fs/: Implementaciones de sistemas de archivos.
- bin/: comandos y utilidades.

## 3. Estructuras clave

- task_t: proceso, contexto ARM64, scheduling, señalización.
- file_t, vfs_node_t: abstracciones filesystem genérico.

## 4. Algoritmos Principales

- Schedulder round-robin con quantum configurable.
- Syscall dispatching seguro y tabulado.
- Context switch ARM64 (assembly), salvando/restaurando registros.
- Loader de ejecutables: parse header X64 y mapea regiones de memoria aisladas.

## 5. Diagramas de Flujo

- Boot -> kernel -> multitarea -> shell.
- Llamada API INT21-64 -> syscall_handler -> núcleo (dispatcher).

## 6. Convenciones

- Estilo C99 estricto.
- Código ARM64 ensamblador para partes críticas.
- 100% sin dependencias de librerías externas.
