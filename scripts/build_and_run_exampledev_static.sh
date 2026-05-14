#!/bin/bash
# build_and_run_exampledev_static.sh
set -e
MAKEFILE="Makefile"
STATIC_BUILD_CMD='\t$(CC) $(CFLAGS) -static -DUNIT_TEST -o drivers/exampledev_test drivers/exampledev.c'
# 1. Modifica el Makefile (como antes)
if ! grep -q '\-static.*\-DUNIT_TEST' "$MAKEFILE"; then
    echo "Ajustando Makefile para build estático ARM64..."
    sed -i '/^drivers\/exampledev_test:/!b;n;c\'"$STATIC_BUILD_CMD" "$MAKEFILE"
fi
echo "Limpiando artefactos previos...\n"
make clean
echo "Eliminando ejecutable anterior si existe..."
rm -f drivers/exampledev_test
echo "Compilando test unitario ARM64 (estático)..."
make drivers/exampledev_test
mkdir -p logs
echo "Ejecutando bajo QEMU ARM64 y generando evidencia log..."
qemu-aarch64 drivers/exampledev_test | tee logs/test_exampledev_static.log
echo
echo "RESULTADO: Evidencia guardada en logs/test_exampledev_static.log"
echo "Salida resumida:"
tail -n 10 logs/test_exampledev_static.log

