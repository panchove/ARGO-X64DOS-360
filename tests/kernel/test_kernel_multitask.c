// tests/kernel/test_kernel_multitask.c
// QA ARM64 multitarea, compliance industrial ISO/IEC
#include "../../src/kernel/kernel_multitask.h"
#include <assert.h>
#include <stdio.h>

void test_inicializacion(void) {
    assert(kernel_inicializar_multitarea() == 0);
}

void test_crear_proceso(void) {
    uint32_t pid;
    int r = kernel_crear_proceso("init", (void*)0xdeadbeef, NULL, &pid);
    assert(r == 0);
    assert(pid == 1);
}

void test_listar_procesos(void) {
    pcb_t tabla[8];
    int num = kernel_listar_procesos(tabla, 8);
    assert(num > 0);
    printf("[QA] Proceso listado PID=%u\n", tabla[0].pid);
}

int main(void) {
    puts("[QA] Kernel multitarea: inicializando...");
    test_inicializacion();
    test_crear_proceso();
    test_listar_procesos();
    puts("[QA] Kernel multitarea: OK\n");
    return 0;
}
