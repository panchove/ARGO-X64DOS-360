#!/bin/bash
# qa_batch.sh - QA industrial automatizado para X64DOS. Ejecuta todos los tests registrados vía Makefile, archiva logs y evidencia para compliance.
# Versión: 0.03.04

set -e
LOGDIR="logs"
TS=$(date +%Y%m%d%H%M)
mkdir -p "$LOGDIR"
LOGFILE_BASE="$LOGDIR/qa_batch_$TS"

# 1. Build/test binarios
make test | tee "$LOGFILE_BASE.log"

# 2. Evidencia (resumida)
echo
cat "$LOGFILE_BASE.log" | grep -E '==>|\[exampledev\]|\[bridge\]' || true

echo
EVIDENCIA QA ARCHIVADA en $LOGFILE_BASE.log
