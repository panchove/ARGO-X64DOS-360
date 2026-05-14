// tests/kernel/test_kernel_scheduler.c
// QA scheduler compliance multitarea ARM64
#include "../../src/kernel/kernel_multitask.h"
#include <assert.h>
#include <stdio.h>

void test_scheduler(void) {
    kernel_inicializar_multitarea();
    uint32_t pid[3];
    for(int i=0;i<3;++i)
        assert(kernel_crear_proceso("pri", (void*)0, NULL, &pid[i]) == 0);
    kernel_cambiar_contexto(pid[0]);
    int pid_next = kernel_scheduler_tick();
    assert(pid_next > 0 && pid_next != pid[0]);
    printf("[QA] Round robin PID: %d\n", pid_next);
}

int main(void) {
    puts("[QA] Test scheduler...");
    test_scheduler();
    puts("[QA] Scheduler OK\n");
    return 0;
}
