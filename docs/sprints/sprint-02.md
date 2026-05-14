# Sprint 02 - Hardening & QA
> **Cumplimiento:** ISO/IEC 12207, 25010, 15504, 27001, 9001.  
> **Documento versionado y auditado.**  
> **Revisión:** 2026-05-14, **Responsable:** Equipo X64DOS


**Fechas:** 2026-05-15 a 2026-05-28
**Scrum Master:** Pablo Ruiz
**Equipo:** Ana Martinez, Jose L., Daniela V.

## Objetivos

- Refactor de autenticación y segregación avanzada
- Hardening drivers (.SYS)
- QA sobre logs, políticas, auditoría multiusuario

## Backlog/Tareas

| #  | Tarea                                | Responsable | Estado    |
|----|--------------------------------------|-------------|-----------|
| 1  | Refactor autenticación avanzada      | Ana         | En prog.  |
| 2  | Limitar acceso drivers               | Daniela     | En prog.  |
| 3  | QA sobre logs/auditoría multiusuario | Jose L.     | Pendiente |
| 4  | Revisión compliance root/user        | Pablo       | Pendiente |

## Issues abiertos relacionados

- [issue-002](issues/issue-002.md): Falta de rotación en log de auditoría

## Criterios de cierre

- Tests QA sobre autenticación avanzados pasan 100% sin errores
- /fs/example_audit.log sólo modificable por root y rotado cada 30 días
- No existen drivers fuera de extensión .SYS
- Reporte compliance QA aprobado

## Checklist de cumplimiento

- [ ] Checklist de cierre completado ([CHECKLIST-CIERRE.md](CHECKLIST-CIERRE.md))
- [ ] Código fuente documentado
- [ ] QA pasado
- [ ] Issues resueltos

---
