# Sprint-05 (Multitarea/Userspace)  
_Compliance ISO/IEC, industrial QA, backlog único_

## Objetivos industriales
- Integrar soporte multitarea preemptiva, userspace modular, y control de procesos bajo VFS ya validado.
- Garantizar compliance industrial: checklist QA ARM64 automatizado, evidencia en logs/, bitácora de cumplimiento efectiva.
- Documentación y políticas en español, diagramas solo Mermaid, drivers .SYS, paths case-insensitive.

## Backlog secuenciado
- [x] sprint-05-issue-01.md: API kernel y estructura básica multitarea
- [x] sprint-05-issue-02.md: Context switch y proceso mínimo
- [x] sprint-05-issue-03.md: Scheduler compliance industrial
- [x] sprint-05-issue-04.md: Userspace (segmentación, policies)
- [x] sprint-05-issue-05.md: QA ARM64/test industrial
- [x] sprint-05-issue-06.md: Auditoría, bitácora, handoff

## Referencias y cumplimiento
- Políticas QA, templates y compliance: ver docs/ref/, logs/, README.md
- Toda evidencia/log industrial en logs/, links auditables
- Markdownlint obligatorio; excepciones solo declaradas explícitamente

## Links
- [Docs/referencia industrial](../ref/)
- [Logs QA/handoff](../../logs/)
- [Historial sprints](HISTORIAL.md)
