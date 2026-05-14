# Reglas de Negocio - X64DOS (v1.0.0)
>
> **Cumplimiento:** ISO/IEC 12207, 25010, 15504, 27001, 9001.  
> **Documento versionado y auditado.**  
> **Revisión:** 2026-05-14, **Responsable:** Equipo X64DOS

Este documento reúne las reglas de negocio que rigen el desarrollo, operación y auditoría del sistema X64DOS y todos sus sprints/issues.

## 1. Cumplimiento y operación

- Todo acceso a la plataforma requiere autenticación industrial multiusuario.
- Está prohibida la modificación o bypass de logs de auditoría por cualquier usuario que no sea root.
- El sistema debe garantizar segregación de workspaces: ningún usuario puede acceder, ver ni modificar datos de otro usuario.
- Todos los drivers deben tener extensión .SYS, sólo pueden cargarse drivers auditados y con check de hash.
- El workspace root solo es accesible por el usuario root; C:/, /, y /Users/root tienen permisos exclusivos.

## 2. Seguridad & compliance

- El login debe exigir password con mínimo 10 caracteres y validación exhaustiva antes de cualquier operación.
- Todos los batch/scripts configurables por usuarios deben ser auditables.
- El log de auditoría `/fs/example_audit.log` requiere rotación y solo root puede manipularlo.
- Cualquier cambio en scripts o plantillas de procesos QA debe estar aprobado y documentado según GOVERNANCE.md.

## 3. QA, pruebas y despliegue

- El despliegue debe ejecutarse bajo ambiente controlado, sin interacción manual directa en entornos productivos.
- Todos los cambios deben validarse y firmarse digitalmente por responsable QA o compliance.
- QA debe validar el correcto funcionamiento de segregación, logs y compliance de todos los scripts batch/Lua previos a cada release.

## 4. Documentación obligatoria

- Toda funcionalidad crítica debe tener documentación asociada, checklist de validación y entrada en el changelog.
- Cualquier proceso industrial “core” modificado requiere nueva entrada de versión/documento.

## Referencias cruzadas

- Ver [01-Requisitos-SRN.md](01-Requisitos-SRN.md) para requisitos funcionales y no funcionales.
- Políticas de ownership y gobernanza: [GOVERNANCE.md](../GOVERNANCE.md)
- Política de versionado: [VERSIONING.md](../VERSIONING.md)
- Proceso de compliance y cierre: [docs/sprints/CHECKLIST-CIERRE.md](sprints/CHECKLIST-CIERRE.md)
