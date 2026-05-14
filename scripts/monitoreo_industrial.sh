#!/bin/bash
# monitoreo_industrial.sh - Script industrial de monitoreo/QA para X64DOS
# Simula captura de métricas sistema, chequeo driver, bridge Lua y deja evidencia en logs según docs/04-Pruebas-STD.md
# Cumple políticas OS real: logging, resultado reproducible, QA batch
# Versión: 0.03.03

set -e
LOGDIR="logs"
LOGFILE="$LOGDIR/monitoreo_industrial_$(date +%Y%m%d%H%M).log"
mkdir -p "$LOGDIR"

{
  echo "# MONITOREO INDUSTRIAL X64DOS - $(date)"
  echo "Hostname: $(uname -n)"
  echo "Kernel:   $(uname -a)"
  echo
  echo "--- Chequeo driver exampledev (simulado) ---"
  if [ -x drivers/exampledev_test ]; then
    qemu-aarch64 drivers/exampledev_test
  else
    echo "[Error] Binario drivers/exampledev_test no encontrado. Ejecute make drivers/exampledev_test."
  fi
  echo
  echo "--- Chequeo bridge Lua ↔ C (simulado) ---"
  if command -v luajit 2>&1 >/dev/null && [ -f tools/bridge_int21_64.so ]; then
    qemu-aarch64 luajit scripts/bridge_int21_64.lua
  else
    echo "[Warning] LuaJIT/tests no disponibles o módulo bridge no localizado."
  fi
  echo
  echo "--- Métricas runtime: demos industrial ---"
  echo "CPU:   $(grep 'model name' /proc/cpuinfo | head -1)"
  echo "Uptime: $(uptime)"
  echo "Fecha: $(date +%Y-%m-%d)"
  echo "# FIN DE MONITOREO --- QA Industrial"
} | tee "$LOGFILE"

echo "EVIDENCIA de monitoreo guardada en $LOGFILE"
