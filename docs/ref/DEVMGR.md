# API Device Manager/Dispositivos X64DOS (Compliance ISO/IEC)

---
_Documenta ciclo sprint-06, referencia técnica y evidencia._

## Arquitectura
- Device Manager gestiona tabla de dispositivos industriales: nombre, estado, puntero driver, user_data.
- Soporta hasta MAX_DISPOSITIVOS (definido), avances mediante API pública bajo compliance.

### Prototipos clave
```c
int devmgr_init(void);
int devmgr_registrar(const char* nombre, void* driver_ptr, uint32_t* devid_out);
int devmgr_set_estado(uint32_t devid, dev_estado_t estado);
int devmgr_listar(devmgr_ent_t *lista, int max_count);
```

### Estructura
```c
typedef struct {
    uint32_t devid;
    char nombre[32];
    dev_estado_t estado;
    void* driver_ptr;
    void* user_data;
} devmgr_ent_t;
```

## Trazabilidad
- Definido en src/devmgr/devmgr.h|c
- Checklist QA y evidencia en docs/sprints/issues/sprint-06-issue-01.md y logs/

---
_Verificar compliance y checklist QA antes de avanzar a drivers y plug/hotplug._
