-- Plantilla registro de eventos de auditoría para X64DOS
local bridge = require('bridge')

return function(tipo, usuario, msg)
  bridge.log_event(tipo, usuario, msg)
end
