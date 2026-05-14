// userspace.c - User segment & policy interface X64DOS
#include "kernel_multitask.h"
#include <stdio.h>

int crear_segmento_userspace(uint32_t pid, void *addr, size_t size) {
    // Simulación segmentación por proceso
    for(int i=0;i<MAX_PROCESOS;++i) {
        if (pcb_tabla[i].pid == pid) {
            pcb_tabla[i].segmento_usuario = addr;
            // NOTE: Para compliance industrial real, registrar tamaño y protección
            printf("[USERS] PID %u segmento @%p tamaño %zu bytes\n", pid, addr, size);
            return 0;
        }
    }
    return -1;
}

int userspace_policy_apply(uint32_t pid, int policy_id) {
    // Placeholder: aplicar política dummy
    printf("[USERS] Policy %d aplicada a PID %u\n", policy_id, pid);
    return 0;
}
