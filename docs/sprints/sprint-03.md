
# Sprint 03 - Inicio de Codificación y Desarrollo

> **Cumplimiento:** ISO/IEC 12207, 25010, 15504, 27001, 9001
> **Documento versionado y auditado.**
> **Revisión:** 2026-05-15, **Responsable:** Equipo X64DOS


**Fechas:** 2026-05-16 a 2026-05-30
**Scrum Master:** Por asignar
**Equipo:** Por asignar

## Objetivos
- Comenzar codificación real en módulos clave: automatización, scripting, integración drivers
- Implementar bridge Lua-INT21 y scripting batch
- Generar drivers .SYS demostrativos (MultiFS, logging, example)
- Crear y validar Makefile industrial con tests y targets de despliegue
- QA automatizado: test suites para scripts y drivers (Lua, batch)
- Definir y cumplir pruebas unitarias e implementación según estándar ([ver política de pruebas](../../04-Pruebas-STD.md))
- Documentación técnica de los módulos y APIs principales en /docs/ref/

## Backlog/Tareas

| #  | Tarea                               | Responsable   | Estado     | Issue/link                          |
|----|-------------------------------------|--------------|------------|-------------------------------------|
| 03-01 | Implementar esqueleto driver .SYS        | Por asignar  | PENDING    | [sprint-03-issue-01](issues/sprint-03-issue-01.md) |
| 03-02 | Bridge Lua ↔ INT21-64 (scripting)        | Por asignar  | PENDING    | [sprint-03-issue-02](issues/sprint-03-issue-02.md) |
| 03-03 | Batch industrial monitoreo ejemplo       | Por asignar  | PENDING    | [sprint-03-issue-03](issues/sprint-03-issue-03.md) |
| 03-04 | Makefile y CI tests integrados           | Por asignar  | PENDING    | [sprint-03-issue-04](issues/sprint-03-issue-04.md) |
| 03-05 | QA: test suite scripting y drivers       | Por asignar  | PENDING    | [sprint-03-issue-05](issues/sprint-03-issue-05.md) |
| 03-06 | Documentar APIs y módulos nuevos         | Por asignar  | PENDING    | [sprint-03-issue-06](issues/sprint-03-issue-06.md) |

> **Política de estados:** Solo se permiten 'PENDING', 'IN-PROGRESS' y 'DONE'.
> **Política de versiones:** El campo yy es el sprint y zz el número de issue asociado.

## Issues técnicos a abrir
- Uno por cada tarea de backlog, enlazados aquí y con evidencias mínimas de avance/código

## Issues adicionales legacy
- [sprint-03-issue-07](issues/sprint-03-issue-07.md): Bug en pipeline de despliegue (Makefile/DEPLOYMENT) _(7/8, legacy)_
- [sprint-03-issue-08](issues/sprint-03-issue-08.md): Requerimiento: batch de monitoreo periódico industrial _(8/8, legacy)_

## Checklist de inicio
- [ ] Responsables asignados
- [ ] Issues técnicos abiertos y enlazados
- [ ] Primer código/documento validado por QA
- [ ] Compliance declarado y versionado
- [ ] Pruebas unitarias e implementación verificadas ([ver criterio y ejemplos](../../04-Pruebas-STD.md))
