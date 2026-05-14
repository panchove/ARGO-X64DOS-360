# Gestión de Sprints - X64DOS
> **Cumplimiento:** ISO/IEC 12207, 25010, 15504, 27001, 9001.  
> **Documento versionado y auditado.**  
> **Revisión:** 2026-05-14, **Responsable:** Equipo X64DOS


Este directorio contiene la documentación de los sprints del proyecto.

- Cada sprint cuenta con backlog, objetivos, entregables, responsables y criterios de cumplimiento.
- Las incidencias/bugs se documentan bajo `docs/sprints/issues/` siguiendo el formato industrial.
- Checklist de cumplimiento y cierre obligatorio por compliance ISO/IEC.

## Estructura recomendada

- sprint-XX.md (documento del sprint)
- issues/ (incidencias, bugs, mejoras específicas)

---

## Cómo usar estas plantillas

- Al iniciar nuevo sprint, copie `sprint-template.md`, ajuste nombre/campo fechas, backlog y objetivos.
- Enumere todas las tareas y relacione issues abiertos.
- Al finalizar, complete la checklist de cierre en [CHECKLIST-CIERRE.md](CHECKLIST-CIERRE.md) y adjúntela como evidencia.
- Solo puede cerrarse un sprint si pasa QA y compliance, con documentación y logs referenciados.

Para añadir un sprint:
1. Copie la plantilla de `sprint-template.md` (para iniciar) o `sprint-01.md` (como ejemplo) y ajuste fechas y responsables.
2. Incremente correlativo XX.
3. Relacione issues usando el formato de referencias cruzadas.

