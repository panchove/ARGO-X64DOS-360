
# Sprint 03 Issue 07

> **Orden en sprint: 7/8 (legacy)**
>
> **Cumplimiento:** ISO/IEC 12207, 25010, 15504, 27001, 9001.  
> **Documento versionado y auditado.**  
> **Revisión:** 2026-05-14, **Responsable:** Equipo X64DOS

- **Título:** Bug en pipeline de despliegue (Makefile/DEPLOYMENT)
- **Fecha:** 2026-05-30
- **Reportado por:** Pablo Ruiz
- **Sprint relacionado:** sprint-03

## Descripción

Al ejecutar `make run` post-despliegue, el sistema no monta correctamente los workspaces de usuarios (C:/Users/*) si se usa MultiFS.

## Pasos para reproducir

1. Ejecutar DEPLOYMENT como usuario root
2. Compilar kernel y ejecutar `make run`
3. Revisar consola del sistema: los usuarios no ven su home correcto.

## Resultado esperado

- Cada usuario debe ver C:/Users/<nombre> inmediato tras login

## Evidencia/Logs/Adjuntos

- [ ] Captura consola
- [ ] Log de montaje

## Prioridad

- Alta

## Estado actual

- Pendiente

## Responsable asignado

- Juan Pérez
