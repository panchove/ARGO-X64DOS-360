# QEMU - Configuración Inicial
>
> **Cumplimiento:** ISO/IEC 12207, 25010, 15504, 27001, 9001.  
> **Documento versionado y auditado.**  
> **Revisión:** 2026-05-14, **Responsable:** Equipo X64DOS

## Propósito

Permite ejecutar el sistema operativo X64DOS en un entorno virtual ARM64 para pruebas y desarrollo, sin hardware físico, usando QEMU.

## Comando básico sugerido

```text
qemu-system-aarch64 -M virt -cpu cortex-a53 -m 2G -nographic -kernel kernel.elf
```

## Descripción de parámetros

- `qemu-system-aarch64`    Ejecutable QEMU para ARM64.
- `-M virt`                Usa la máquina virtual genérica ARM.
- `-cpu cortex-a53`        Simula un CPU ARMv8-A Cortex-A53.
- `-m 2G`                  Asigna 2GB de RAM a la VM.
- `-nographic`             Utiliza solo consola serial (UART), sin interfaz gráfica. Todo el I/O ocurre por terminal.
- `-kernel kernel.elf`     Carga la imagen ELF del kernel X64DOS directamente en memoria y comienza la ejecución.

## Flujo

1. Compila el kernel y asegúrate de que el binario `kernel.elf` esté disponible en el directorio de trabajo.
2. Ejecuta el comando anterior en tu terminal Linux.
3. La consola de QEMU presentará la salida y entrada estándar de X64DOS vía UART (modo texto).

## Consejos

- Puedes automatizar la ejecución en un script (`run-qemu.sh`) para agilizar pruebas.
- Para debug GDB, añade los flags `-s -S` (ver documentación en "Guía de Instalación y Entorno").

---
**Referencia:**

- Sección "Configuración de QEMU" en la documentación técnica.
