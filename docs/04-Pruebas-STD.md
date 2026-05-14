# Especificación de Pruebas (STD)
>
> **Cumplimiento:** ISO/IEC 12207, 25010, 15504, 27001, 9001.  
> **Documento versionado y auditado.**  
> **Revisión:** 2026-05-14, **Responsable:** Equipo X64DOS

## 1. Introducción

Se describen los principales casos y planes de prueba para X64DOS.

## 2. Tipos de Prueba

- Pruebas unitarias del núcleo y drivers
- Pruebas de integración del shell, comandos, multitarea
- Pruebas de regresión y stress

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
