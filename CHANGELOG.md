
# CHANGELOG - X64DOS

> **Cumplimiento:** ISO/IEC 12207, 25010, 15504, 27001, 9001.  
> **Documento versionado y auditado.**  
> **Revisión:** 2026-05-14, **Responsable:** Equipo X64DOS

> **Versionado:** xx.yy.zz — yy es el número de sprint, zz el número de issue asociado. Consulta las reglas completas en [VERSIONING.md](VERSIONING.md)


Todas las modificaciones mayores y menores en este proyecto serán documentadas aquí, siguiendo el estándar Keep a Changelog.

## [Unreleased]

- Cambios pendientes de merge o próximos a release.

## [v1.0.0] - 2026-05-14

### Añadido

- Arquitectura industrial inicial y política multiusuario.
- Logger y logs audit trail seguro multiusuario.
- Makefile con target QEMU run y batchs de prueba industrial.
- Esquemas industriales para scripts/config/Makefile.
- Documentación completa sprints/issues (sistema CMMI/ISO/IEC).
- Policies de segregación root/usuario, compliance login y scripting Lua seguro.

### Corregido

- Permisos y acceso multiusuario a logs (
issue-001).

### Cambiado

- Ajustes integración bridge Lua-C, review batch y templates.

## [v0.1.0] - 2026-05-01

### Añadido

- Arranque inicial, plantilla doc y scripts básicos.
