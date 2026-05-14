# Issue #001
> **Cumplimiento:** ISO/IEC 12207, 25010, 15504, 27001, 9001.  
> **Documento versionado y auditado.**  
> **Revisión:** 2026-05-14, **Responsable:** Equipo X64DOS


- **Título:** Error de permisos en log de auditoría (root)
- **Fecha:** 2026-05-02
- **Reportado por:** Juan Pérez
- **Sprint relacionado:** sprint-01

## Descripción

Cuando un usuario root genera eventos de auditoría, algunas entradas quedan con permisos de escritura universal. Esto viola la política de compliance.

## Pasos para reproducir

1. Loguear como root
2. Ejecutar algún script que invoque el logger
3. Verificar permisos de /fs/example_audit.log

## Resultado esperado

El archivo debe estar siempre con permisos `-rw-r-----` y propietario root:root

## Evidencia/Logs/Adjuntos

- [x] Log relevante: se adjunta para revisión
- [ ] Captura pendiente

## Prioridad

- Alta

## Estado actual

- Pendiente

## Responsable asignado

- Pablo Ruiz
