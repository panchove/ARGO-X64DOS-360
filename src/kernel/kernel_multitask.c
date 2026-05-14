// kernel_multitask.c
// Implementación base multitarea X64DOS - Industrial compliance
#include "kernel_multitask.h"
#include <string.h>

static pcb_t pcb_tabla[MAX_PROCESOS];
static int num_procesos = 0;
static int proceso_actual = -1;

int kernel_inicializar_multitarea(void) {
    memset(pcb_tabla, 0, sizeof(pcb_tabla));
    num_procesos = 0;
    proceso_actual = -1;
    return 0;
}

int kernel_crear_proceso(const char *nombre, void* entry, void* segmento_usuario, uint32_t *pid_out) {
    if (num_procesos >= MAX_PROCESOS) return -1;
    pcb_t *pcb = &pcb_tabla[num_procesos];
    pcb->pid = num_procesos + 1;
    pcb->estado = PROC_ESTADO_NUEVO;
    pcb->stack_ptr = NULL; // A definir por contexto HW
    pcb->contexto_arch = entry;
    pcb->segmento_usuario = segmento_usuario;
    strncpy(pcb->nombre, nombre, sizeof(pcb->nombre) - 1);
    pcb->nombre[sizeof(pcb->nombre) - 1] = 0;
    if (pid_out) *pid_out = pcb->pid;
    num_procesos++;
    return 0;
}

int kernel_cambiar_contexto(uint32_t pid_destino) {
    // Simulación del cambio industrial de contexto
    for(int i=0;i<num_procesos;++i) {
        if (pcb_tabla[i].pid == pid_destino && pcb_tabla[i].estado != PROC_ESTADO_TERMINADO) {
            proceso_actual = i;
            pcb_tabla[i].estado = PROC_ESTADO_EJECUTANDO;
            // El resto de PC/context switch es dependiente de plataforma HW
            return 0;
        }
    }
    return -1;
}

int kernel_despachar(void) {
    // Scheduler round-robin simple, salta terminados
    if (num_procesos == 0) return -1;
    int partida = proceso_actual;
    for(int i=1;i<=num_procesos;++i) {
        int idx = (partida + i) % num_procesos;
        if (pcb_tabla[idx].estado != PROC_ESTADO_TERMINADO) {
            proceso_actual = idx;
            pcb_tabla[idx].estado = PROC_ESTADO_EJECUTANDO;
            return pcb_tabla[idx].pid;
        }
    }
    return -1;
}

int kernel_scheduler_tick(void) {
    // Tick: avanza 1 slot de round-robin (ejemplo base)
    return kernel_despachar();
}

int kernel_terminar_proceso(uint32_t pid) {
    for(int i=0;i<num_procesos;++i) {
        if (pcb_tabla[i].pid == pid) {
            pcb_tabla[i].estado = PROC_ESTADO_TERMINADO;
            return 0;
        }
    }
    return -1;
}

int kernel_listar_procesos(pcb_t *tabla, int max_count) {
    int n = num_procesos < max_count ? num_procesos : max_count;
    memcpy(tabla, pcb_tabla, n * sizeof(pcb_t));
    return n;
}
