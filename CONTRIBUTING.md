# Guía de Contribución - X64DOS
> **Cumplimiento:** ISO/IEC 12207, 25010, 15504, 27001, 9001.  
> **Documento versionado y auditado.**  
> **Revisión:** 2026-05-14, **Responsable:** Equipo X64DOS


**Versionado:** Todas las contribuciones deben respetar el esquema y reglas de [VERSIONING.md](VERSIONING.md).

¡Gracias por tu interés en contribuir a X64DOS! Por favor lee cuidadosamente estas reglas para asegurar la calidad y compliance industrial del proyecto.

## Requisitos previos

- Leer y entender docs/sprints/DOCUMENTOS.md
- Tener entorno de build ARM64, Lua 5.4+, QEMU configurado.

## Normas de colaboración

- Usa una rama por feature/fix: nombre `feature/<breve-descripcion>` o `fix/<issue-x>`
- Commits claros estilo Conventional Commits:
  - feat: para nuevas funciones
  - fix: para bugfixes
  - docs: para documentación (si impacta procesos, sprints, templates, incrementa versión por las reglas de [VERSIONING.md](VERSIONING.md))
  - chore: cambios menores o tooling
- Todo cambio debe ir documentado en CHANGELOG.md
- Issues deben crearse con el template (docs/sprints/issues/issue-template.md)
- Todo PR requiere revisión mínima de 1 QA y 1 responsable de compliance (ver GOVERNANCE.md)
- Correr y adjuntar pruebas automatizadas donde aplique
- Documentar decisiones técnicas relevantes en docs/sprints/DOCUMENTOS.md
- Las contribuciones que cambien procedimientos, templates, compliance artifacts o criterio de QA deben:
  - Indicar versión de documento/template en header/pie de página
  - Explicitar motivación y alcance en el Pull Request
  - Incluir referencia al update (versión, fecha, responsable)

## Pruebas y compliance

- Los cambios deben pasar `make`, `make run` (QEMU), scripts de batch/Lua y QA batch en entorno aislado.
- Validar logs audit trail: ningún error, permisos correctos, segregación root/usuario vigente.

## Estilo de código

- C: ANSI C99, funciones ≤ 60 líneas, comentarios clave en español/inglés técnico
- Lua: Sin os.execute/io.popen; cumplimiento scripts/log_event.lua
- Batch: Estilo DOS/Unix documentado, privilegios mínimos

## Conducta

- Comunicación profesional, toda sugerencia técnica será registrada en issue del sprint activo

**Issues y PRs violando políticas de compliance/regulación serán rechazados hasta corregir!**
