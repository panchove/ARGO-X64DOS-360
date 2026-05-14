# Sprint 01 - Inicio Industrial X64DOS
> **Cumplimiento:** ISO/IEC 12207, 25010, 15504, 27001, 9001.  
> **Documento versionado y auditado.**  
> **Revisión:** 2026-05-14, **Responsable:** Equipo X64DOS


**Fechas:** 2026-05-01 a 2026-05-14
**Scrum Master:** Ana Martinez
**Equipo:** Juan Pérez, Pablo Ruiz, Carmen León

## Objetivos

- Arranque kernel ARM64 en QEMU
- Login industrial seguro multiusuario
- Auditoría básica actividad (log)

## Backlog/Tareas

| #  | Tarea                                | Responsable | Estado    |
|----|--------------------------------------|-------------|-----------|
| 1  | Arrancar kernel con QEMU             | Juan        | Completa  |
| 2  | Login/segregación workspaces         | Carmen      | Completa  |
| 3  | Logger de operaciones industrial     | Pablo       | Completa  |
| 4  | Documentar arquitectura inicial      | Ana         | Completa  |

## Issues abiertos relacionados

- [issue-001](issues/issue-001.md): Error permisos log/auditoría root

## Criterios de cierre

- Kernel prueba ARM64 levanta hasta shell básico
- Acceso sólo por login válido
- Auditoría operativa se registra en /fs/example_audit.log
- Documentación publicada y aprobada por compliance

---
