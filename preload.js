const { contextBridge, ipcRenderer } = require('electron')

// Expor APIs seguras para a camada web (renderer)
contextBridge.exposeInMainWorld('electronAPI', {
  runGameFunction: (args) => ipcRenderer.invoke('run-game-function', args)
})
