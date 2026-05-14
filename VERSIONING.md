# VERSIONING - Reglas de versionado X64DOS
> **Cumplimiento:** ISO/IEC 12207, 25010, 15504, 27001, 9001.  
> **Documento versionado y auditado.**  
> **Revisión:** 2026-05-14, **Responsable:** Equipo X64DOS


Este proyecto sigue el estándar [SemVer 2.0.0](https://semver.org/lang/es/): MAJOR.MINOR.PATCH

## Convención específica X64DOS: MAJOR.SPRINT.ISSUE
- **xx**: Versión mayor del sistema (major version, cambios disruptivos)
- **yy**: Número de sprint (avance organizacional/ciclo)
- **zz**: Issue asociado (cada entrega relevante se traza a su issue)

**Ejemplo:**
- `01.03.12` significa versión mayor 1, sprint 3, cambio o entrega por el issue 12.

Política:
- Todo aumento de `yy` refleja el avance a un nuevo sprint (no se cierra actual hasta todo DONE)
- Cada fix/actualización relevante va como `zz=issue` correspondiente, indicada en el changelog y la documentación del commit.
- Los releases y el changelog deben anotar claramente a qué sprint pertenece cada cambio y a qué issue corresponde.

## Normas para incremento de versión

- **Cambio MAJOR (X.y.z):**
  - Cambios incompatibles en APIs/scripts (
breaking changes) o en arquitectura principal
  - Nueva política, regla de compliance o cambio en estructura de datos o rutas
- **Cambio MINOR (x.Y.z):**
  - Nuevas funciones/backlogs que no rompen compatibilidad
  - Mejoras importantes en batch, logs, drivers .SYS, integración o capacidades de scripting
- **Cambio PATCH (x.y.Z):**
  - Corrección de errores menores, mejoras de documentación, QA, ajustes de ruta, fix en logs

## Tagging y releases

- Todo release requiere tag `vX.Y.Z` en git (ej: v1.2.0)
- Todo commit a rama principal con cambio en versión debe reflejarse en CHANGELOG.md
- Prerelease/tag especial usar `-alpha`, `-beta` o `-rc` (ej: v2.0.0-beta.1)

## Relación con la documentación y compliance

- El CHANGELOG.md centraliza detalles de todos los cambios de versión.
- Cuando se modifica una plantilla clave, política de compliance, guía de QA, o procedimiento de auditoría, debe incrementarse al menos la versión PATCH (x.y.Z).
- Toda release debe validarse según checklist de cierre (sprints, QA, compliance).
- Versiona explícitamente documentos como sprints, policies, templates, y README cuando afecten a equipos, responsables o auditores.
- Indicar en el header (ejemplo: "Versión actual: v1.2.0 (2026-06-01)") cuando el documento sea recurrente/revisado manualmente.
- Si un cambio de documentación causa que workflows, auditoría o despliegue cambien para todos los equipos, incrementa MINOR (x.Y.z).

## Versionado de plantillas y compliance artifacts

- Plantillas y checklists deberán referenciar la versión en su primer sección o pie de página.
- Si cambia la estructura/criterio de una plantilla que impacte QA/auditoría, agregar una nota de versión y update en CHANGELOG.md.

## Referencias

- Este archivo debe enlazarse desde CONTRIBUTING.md y CHANGELOG.md para visibilidad total.
