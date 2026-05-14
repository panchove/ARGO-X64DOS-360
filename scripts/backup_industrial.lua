-- Script Lua industrial seguro y multiusuario para X64DOS
local sec = require('security')
local bridge = require('bridge')

if not sec.is_authenticated() then error('Sesión no válida') end
if not sec.in_user_workspace() then error('Debe ejecutarse desde el workspace del usuario') end

local user = sec.current_user()
local src = 'C:/Users/' .. user .. '/proyectos/'
local dst = 'D:/Backups/' .. user .. '/'

local ok, err = pcall(function()
    bridge.secure_copy(src, dst)
end)

if not ok then
    bridge.log_event('backup', user, err)
    error('Fallo el backup: ' .. tostring(err))
else
    print('Backup industrial realizado exitosamente en: '..dst)
    bridge.log_event('backup', user, 'OK')
end
