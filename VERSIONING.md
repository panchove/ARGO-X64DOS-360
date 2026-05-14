
# VERSIONING - X64DOS

> **Cumplimiento:** ISO/IEC 12207, 25010, 15504, 27001, 9001.  
> **Documento versionado y auditado.**  
> **Revisión:** 2026-05-15, **Responsable:** Equipo X64DOS

## Doble esquema de versionado

A partir del release v1.0.0, X64DOS adopta dos esquemas de versionado complementarios:

- **SemVer externo**: v1.0.0, v1.0.1, etc.  
  Usado para releases públicos, entrega a cliente y etiquetas en el repositorio.

- **Esquema correlativo interno**: MAJOR.SPRINT.ISSUE (ejemplo: 01.04.00)  
  Donde:
  - MAJOR: Versión mayor del producto (solo si TODOS los sprints/issues del ciclo están en DONE y validados)
  - SPRINT: Sprint donde se realizan cambios agregados
  - ISSUE: Número principal de issue asociado al cambio

### Tabla de conversión de versiones

| SemVer   | Correlativo interno | Descripción breve                           | Estado de sprints/issues |
|----------|---------------------|---------------------------------------------|--------------------------|
| v1.0.0   | 01.04.00            | Release estable base, Sprints 01-04 cerrados| 100% DONE               |
| v1.0.1   | 01.05.00            | Fix documental, ajuste compliance           | 100% DONE               |
| v1.x.x   | --                  | (No permitido, hay sprints/issues abiertos) | Pendientes              |

---

## REGLA BLOQUEANTE

**No se puede publicar un release mayor mientras existan sprints o issues abiertos/pendientes de QA o Compliance.**  
Esto es obligatorio para mantener compliance normativo y trazabilidad.

Toda documentación debe referenciar ambos esquemas para maximizar trazabilidad y cumplimiento normativo.  
Para más detalles, ver [CHANGELOG.md](./CHANGELOG.md).

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

## Compacting y versionado/documentación raíz
- Cuando se realice compacting (reorganización, archivado, deduplicación, etc.) que afecte artefactos/documentos clave, todos los documentos raíz y HANDOFF.md deben actualizarse y versionarse acorde.
- Cualquier cambio debe quedar trazado en CHANGELOG.md y en el historial del repo con incremento al menos PATCH o MINOR.

## Referencias

- Este archivo debe enlazarse desde CONTRIBUTING.md y CHANGELOG.md para visibilidad total.
