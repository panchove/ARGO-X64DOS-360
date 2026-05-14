# Guía de Despliegue - X64DOS Industrial
>
> **Cumplimiento:** ISO/IEC 12207, 25010, 15504, 27001, 9001.  
> **Documento versionado y auditado.**  
> **Revisión:** 2026-05-14, **Responsable:** Equipo X64DOS

## Pasos generales

1. Verifique dependencias:
   - gcc (ARM64)
   - Lua 5.4 o superior
   - make
2. Configure variables en `.env` y `config.ini` según corresponda.
3. Compile el kernel y el bridge:

   ```sh
   make all
   ```

4. Cree usuarios mediante script o manualmente en `/userland/Users/`.
5. Asigne permisos y valide segregación de workspaces.
6. Añada drivers en `/drivers` (solo archivos `.SYS`, insensible a mayúsculas/minúsculas).
7. Monte volumen (FAT32): consulte `fs/fat32_layout.txt`.
8. Ejecute scripts solo desde el home de usuarios autenticados.

## Buenas prácticas

- Siga checklist de compliance (ver CHECKLIST-COMPLIANCE.md)
- Realice pruebas batch, shell y scripting como usuario estándar y root
- Conserve los logs de `/fs/example_audit.log` para auditoría.
- Documente cada cambio relevante.
