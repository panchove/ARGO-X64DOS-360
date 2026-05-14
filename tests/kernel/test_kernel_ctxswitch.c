// tests/kernel/test_kernel_ctxswitch.c
// QA context switch ARM64, compliance industrial
#include "../../src/kernel/kernel_multitask.h"
#include <assert.h>
#include <stdio.h>

void test_ctxswitch(void) {
    kernel_inicializar_multitarea();
    uint32_t pid1, pid2;
    assert(kernel_crear_proceso("p1", (void*)0x1, NULL, &pid1) == 0);
    assert(kernel_crear_proceso("p2", (void*)0x2, NULL, &pid2) == 0);
    assert(kernel_cambiar_contexto(pid2) == 0);
    printf("[QA] Contexto activo PID: %u\n", pid2);
}

int main(void) {
    puts("[QA] Test context switch...");
    test_ctxswitch();
    puts("[QA] Context switch OK\n");
    return 0;
}
