# Especificación de Pruebas (STD)
>
> **Cumplimiento:** ISO/IEC 12207, 25010, 15504, 27001, 9001.  
> **Documento versionado y auditado.**  
> **Revisión:** 2026-05-14, **Responsable:** Equipo X64DOS

## 1. Introducción

Se describen los principales casos y planes de prueba para X64DOS.

## 2. Tipos de Prueba

- **Pruebas unitarias** del núcleo, librerías, scripts y drivers: cada función/módulo se valida de forma aislada, automatizada y con evidencia de resultado. Obligatorias en todo código fuente nuevo y en refactors críticos. Resultado: OK/FAIL, logs automatizados, errores con traza.
- **Pruebas de implementación/integración**: verifican interacción entre módulos, APIs o capas (ej: kernel+drivers+VFS; shell+INT21-64; batch-SYS). Se ejecutan en entornos de staging/QEMU por responsables de QA y desarrollo. Requieren checklist, logs de ejecución, y evidencia de funcionamiento transversal.
- Pruebas de regresión y stress: garantizan que cambios no rompen funcionalidades previas; incluyen escenarios automáticos y uso intensivo.

### 2.1 Definición y Política

#### Pruebas unitarias
- Objetivo: Validar funciones/síntesis mínima de una pieza de código aislada (C/híbrido/Lua/batch)
- Criterios: Salida esperada, casos límite, errores controlados
- Ejemplo: test de sum(), batch de inicialización, driver de disco .SYS simulando I/O
- Formato esperado: script `test_<modulo>.sh`, LuaTest, C test-main, batch `test.bat`, salida estandarizada LOG/OK/FAIL
- Evidencia: Log por cada prueba, resultado visible/archivado, debe poder ejecutarse automáticamente
- Ejemplo tabla:

| Prueba                  | Módulo         | Entrada      | Esperado    | Resultado | Evidencia          |
|-------------------------|----------------|--------------|-------------|-----------|--------------------|
| Suma simple int         | math.c         | 2+2          | 4           | OK        | logs/test_math.out |
| Login exitoso           | login.lua      | user/pwd     | Login Ok    | OK        | logs/test_login.out|

#### Pruebas de implementación/integración
- Objetivo: Validar funcionamiento conjunto de módulos, flujo real usuario/SO
- Criterios: Interacción, paso de datos, errores entre componentes
- Ejemplo: login+shell+batch; driver + VFS + script; pipeline batch
- Formato esperado: test-runner, batch encadenado, script QA, prueba manual guiada + check
- Evidencia: logs QEMU/simulación, screenshots, archivos generados
- Ejemplo tabla:

| Prueba                       | Componentes              | Flujo               | Esperado           | Evidencia                |
|------------------------------|--------------------------|---------------------|--------------------|--------------------------|
| Login + Shell + Batch        | login, shell, batch.bat  | Sesión completa     | batch output OK    | bashlog, screen, output  |
| Driver .SYS + VFS + boot     | dskdrv.sys, vfs, kernel  | Boot + mount + ls   | listado real       | qemu-log, disk.img       |

## 3. Pruebas Relevantes

### 3.1 Boot y consola

- X Cargar kernel en QEMU y recibir prompt vía UART

### 3.2 API INT21-64

- X Llamada SYS_PRINT imprime en consola
- X Llamada SYS_EXIT termina proceso

### 3.3 Multitarea

- X fork() y ps listan procesos concurrentes

### 3.4 VFS y discos

- X Montar unidad, listar archivos, copiar, borrar
- X Error accesos ilegales/sin permisos

### 3.5 Scripts batch y comandos

- X Ejecución batch, pipes, redirecciones

### 3.6 Robustez

- X Manejo de memoria insuficiente/corrupción
- X Interrupciones y recuperación frente a errores

## 4. Herramientas

- QEMU (consola UART y virtual disk)
- Scripts de prueba automática (planificado)
