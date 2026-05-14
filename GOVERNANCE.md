# GOVERNANCE - X64DOS
> **Cumplimiento:** ISO/IEC 12207, 25010, 15504, 27001, 9001.  
> **Documento versionado y auditado.**  
> **Revisión:** 2026-05-14, **Responsable:** Equipo X64DOS


Este documento establece las reglas de gobernanza, toma de decisiones y estructura de autoridad en el proyecto X64DOS.

## Toma de decisiones

- Las decisiones técnicas y de proceso se toman por consenso del comité de responsables de sprint (ver OWNER_REGISTER.md).
- Cualquier cambio a políticas críticas, seguridad, compliance o auditoría debe ser aprobado por el responsable de compliance y QA.
- Issues, bugs y features críticos requieren revisión cruzada QA y dev.

## Roles (mínimo por sprint)

- Dueño de sprint: Dicta rumbo y prioridades, funge de árbitro final
- QA: Verifica resultados/pruebas, puede vetar merge
- Compliance: Vigila políticas regulatorias, logs, segregación, etc.

## Rotación y meritocracia

- Los roles rotan por sprint/ciclo, ver OWNER_REGISTER.md para bitácora
- Cualquier miembro puede proponer mejoras vía sprint retrospective/issue

## Aprobaciones

- Pull requests, cambios de plantilla, scripts de auditoría y logs requieren:
  - [ ] Revisión QA
  - [ ] Revisión Compliance

## Resolución de conflictos

- Si no hay consenso, decide el Dueño de Sprint; si afecta compliance, prima QA/Compliance

**La documentación y logs de decisiones deben archivarse junto con el sprint correspondiente para trazabilidad y auditoría externa.**
