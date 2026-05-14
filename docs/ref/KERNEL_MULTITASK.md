# API Kernel Multitarea X64DOS (Compliance ISO/IEC)

---
_Estándar para ciclo sprint-05, documento técnico, funcional y de evidencia._

## Estructura y Función
- Proporciona estructura PCB (Process Control Block) por proceso.
- API pública router industrial para gestión: crear, terminar, cambiar contexto, despachar, etc.
- Limite de proceso y estado explícito.

### Prototipos clave
```c
int kernel_inicializar_multitarea(void);
int kernel_crear_proceso(const char *nombre, void* entry, void* segmento_usuario, uint32_t *pid_out);
int kernel_cambiar_contexto(void);
int kernel_despachar(void);
int kernel_terminar_proceso(uint32_t pid);
int kernel_listar_procesos(pcb_t *tabla, int max_count);
```

### Estructura PCB
```c
typedef struct {
    uint32_t pid;
    proc_estado_t estado;
    void *stack_ptr;
    void *contexto_arch;
    void *segmento_usuario;
    char nombre[32];
} pcb_t;
```

## Trazabilidad
- Definido en src/kernel/kernel_multitask.h|c
- Checklist QA y evidencia en docs/sprints/issues/sprint-05-issue-01.md y logs/

---
_Verifica compliance y checklist QA antes de avanzar a context switch y scheduling._
