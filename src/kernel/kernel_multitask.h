// kernel_multitask.h
// API multitarea X64DOS - Compliance industrial ISO/IEC

#ifndef KERNEL_MULTITASK_H
#define KERNEL_MULTITASK_H

#include <stdint.h>
#include <stdbool.h>

#define MAX_PROCESOS 64

typedef enum {
    PROC_ESTADO_NUEVO = 0,
    PROC_ESTADO_LISTO,
    PROC_ESTADO_EJECUTANDO,
    PROC_ESTADO_BLOQUEADO,
    PROC_ESTADO_TERMINADO
} proc_estado_t;

// PCB estructurado, compliance industrial
typedef struct {
    uint32_t pid;
    proc_estado_t estado;
    void *stack_ptr;
    void *contexto_arch;
    void *segmento_usuario; // Base userspace para segmentación
    char nombre[32];
} pcb_t;

// API industrial multitarea
int kernel_inicializar_multitarea(void);
int kernel_crear_proceso(const char *nombre, void* entry, void* segmento_usuario, uint32_t *pid_out);
int kernel_cambiar_contexto(uint32_t pid_destino);
int kernel_despachar(void); // Despacha proceso según política industrial (round-robin)

// Scheduler interfaz modular, permite swap
int kernel_scheduler_tick(void);
int kernel_terminar_proceso(uint32_t pid);
int kernel_listar_procesos(pcb_t *tabla, int max_count);

#endif // KERNEL_MULTITASK_H
