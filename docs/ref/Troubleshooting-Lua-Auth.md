# Troubleshooting Lua/Bridge/Auth - X64DOS

> **Cumplimiento:** ISO/IEC 12207, 25010, 15504, 27001, 9001.  
> **Documento versionado y auditado.**  
> **Revisión:** 2026-05-14, **Responsable:** Equipo X64DOS


## Sintomatología frecuente

- "Sesión no válida": error en autenticación, revisar inicio sesión del usuario
- "No puede ejecutar script fuera de su home": Verifica ruta y script invocado desde su workspace
- Error en bridge: `secure_copy`, revisar integración C y permisos

## Pasos

1. Verifica que sec.is_authenticated() retorna true
2. Si error, revisa logs de auditoría (ver scripts/log_event.lua)
3. Revisar módulos bridge/require instalados y accesibles
4. Errores de path: todos los accesos y nombres son insensibles al case
5. Ante errores persistentes, revisar Makefile/compilación bridge

## Referencia

- Lib: lib/lua_bridge.c y scripts/log_event.lua
- Doc compliance: docs/ref/X64DOS-ARCHITECTURE.md, policy-usuarios.md
