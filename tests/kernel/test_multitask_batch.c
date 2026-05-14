// tests/kernel/test_multitask_batch.c
// QA batch multitarea/userspace industrial ARM64
#include "../../src/kernel/kernel_multitask.h"
#include "../../src/kernel/userspace.h"
#include <assert.h>
#include <stdio.h>

int main(void) {
    puts("[QA BATCH] Multitask/Userspace...");
    // Inicializar kernel multitarea y procesos
    kernel_inicializar_multitarea();
    uint32_t pid1, pid2;
    assert(kernel_crear_proceso("procA", (void*)0x1000, NULL, &pid1) == 0);
    assert(kernel_crear_proceso("procB", (void*)0x2000, NULL, &pid2) == 0);
    assert(crear_segmento_userspace(pid1, (void*)0xA000, 8192) == 0);
    assert(crear_segmento_userspace(pid2, (void*)0xB000, 8192) == 0);
    for(int n=0;n<2;++n) {
        assert(kernel_scheduler_tick() > 0);
    }
    assert(userspace_policy_apply(pid1, 1) == 0);
    assert(userspace_policy_apply(pid2, 2) == 0);
    printf("[QA BATCH] Todo PASSED. PID %u y %u activos.\n", pid1, pid2);
    return 0;
}
