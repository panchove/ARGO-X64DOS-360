
# Sprint 02 Issue 07

> **Orden en sprint: 7/7 (legacy)**
>
> **Cumplimiento:** ISO/IEC 12207, 25010, 15504, 27001, 9001.  
> **Documento versionado y auditado.**  
> **Revisión:** 2026-05-14, **Responsable:** Equipo X64DOS

- **Título:** Falta de rotación en log de auditoría industrial
- **Fecha:** 2026-05-16
- **Reportado por:** Daniela V.
- **Sprint relacionado:** sprint-02

## Descripción

El archivo `/fs/example_audit.log` crece indefinidamente. No hay política ni mecanismo automático de rotación, lo que afecta cumplimiento y operatividad en auditoría industrial.

## Pasos para reproducir

1. Ejecutar muchos scripts que generen logs por 48h
2. Revisar tamaño y antigüedad de `/fs/example_audit.log`

## Resultado esperado

- El sistema debe rotar automáticamente el log (copiar y reemplazar por uno nuevo) al alcanzar 30 días o tamaño >100MB.
- Logs rotados deben tener permisos sólo root y quedar disponibles para auditoría.

## Evidencia/Logs/Adjuntos

- [ ] Script de prueba
- [ ] Listado logs generados

## Prioridad

- Media

## Estado actual

- Pendiente

## Responsable asignado

- Ana Martinez
