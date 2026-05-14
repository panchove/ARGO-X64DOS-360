#!/bin/bash
# setup_cross_arm64.sh
# Script automatizado para instalar toolchain y entorno de compilación/QA ARM64 para X64DOS industrial
set -e
echo "---- Instalando toolchain ARM64, utils de build y emulación ----"
sudo apt-get update
sudo apt-get install -y \
  gcc-aarch64-linux-gnu \
  g++-aarch64-linux-gnu \
  binutils-aarch64-linux-gnu \
  make \
  build-essential \
  qemu-user \
  qemu-system-arm \
  pkg-config
echo
echo "Toolchain, build tools y entorno QEMU instalados."
echo "Puedes compilar y testear ARM64 así: make drivers/exampledev_test && qemu-aarch64 drivers/exampledev_test"


