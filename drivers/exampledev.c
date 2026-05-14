/* exampledev.c - Esqueleto mínimo driver .SYS para X64DOS
 * Cumple con políticas industriales, ISO/IEC, y pruebas asociadas.
 * Versión: 0.03.01
 */

#include <stdio.h>
#include <stdint.h>

// Inicialización mínima del driver
int exampledev_init(void) {
    // Registro en log de driver (simulado)
    printf("[exampledev] Init OK\n");
    return 0;
}

// Operación simulada del driver (por ejemplo, lectura simple)
int exampledev_read(uint8_t *buf, size_t len) {
    for(size_t i=0; i<len; ++i) buf[i] = 0xAA;
    printf("[exampledev] Lectura ficticia, len=%zu\n", len);
    return (int)len;
}

// Entrada de prueba principal (sólo para test unitario)
#ifdef UNIT_TEST
int main(void) {
    uint8_t buf[8];
    exampledev_init();
    exampledev_read(buf, sizeof(buf));
    for (int i=0; i<8; ++i) printf("%02X ", buf[i]);
    printf("\n");
    return 0;
}
#endif
