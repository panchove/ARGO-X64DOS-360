-- bridge_int21_64.lua - Esqueleto de integración Lua ↔ INT21-64 X64DOS
-- Cumple estándar scripting industrial/QA automático
-- Versión: 0.03.02

local ffi_OK, ffi = pcall(require, 'ffi')
local bridge
if ffi_OK then
    ffi.cdef[[ int bridge_receive_cmd(const char*); ]]
    bridge = ffi.load('./tools/bridge_int21_64.so')
else
    bridge = { bridge_receive_cmd = function(cmd) print('(stub) '..cmd) end }
end

-- Enviar comando simulado INT21 (ejemplo)
local cmd = 'SYS_PRINT'
print('Lua: Enviando comando', cmd)
bridge.bridge_receive_cmd(cmd)

cmd = 'NOP'
print('Lua: Enviando comando', cmd)
bridge.bridge_receive_cmd(cmd)

-- Evidencia de prueba y log
