# Requisitos de Software (SRN) - X64DOS v1.0.0
>
> **Cumplimiento:** ISO/IEC 12207, 25010, 15504, 27001, 9001.  
> **Documento versionado y auditado.**  
> **Revisión:** 2026-05-14, **Responsable:** Equipo X64DOS
> Para reglas de negocio obligatorias, consulte [REGLAS-DE-NEGOCIO.md](REGLAS-DE-NEGOCIO.md).

## Resumen

Documento de requisitos funcionales y no funcionales para desarrollo, validación y auditoría de X64DOS.

## Funcionales

- El sistema debe:
  - Soportar scripting Lua seguro y bridge industrial C/Lua
  - Restringir rutas (case-insensitive), sólo .SYS los drivers
  - Segregar workspaces; login y password obligatorios
  - Plugins/scripts sólo ejecutables en workspace usuario
  - Documentar todo con compliance ISO/IEC

## No funcionales

- Seguridad nuclear en logs y segregación de usuarios.
- Documentación de cambios y procesos bajo política de versionado.

## Ejemplos de configuraciones

- config.ini y .env.example

---
*Revisar este documento y REGLAS-DE-NEGOCIO.md antes de iniciar cada sprint/release.*
