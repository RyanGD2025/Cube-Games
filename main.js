const { app, BrowserWindow, ipcMain } = require('electron')
const path = require('path')

function createWindow() {
  
  const mainWindow = new BrowserWindow({
    width: 800,
    height: 600,
    webPreferences: {
      preload: path.join(__dirname, 'preload.js'), // opcional, para expor APIs ao renderer
      nodeIntegration: false,
      contextIsolation: true
    }
  })

  
  mainWindow.loadFile('home.html')

  
  if (process.env.NODE_ENV === 'development') {
    mainWindow.webContents.openDevTools()
  }
}


app.whenReady().then(() => {
  createWindow()

  app.on('activate', () => {
    
    if (BrowserWindow.getAllWindows().length === 0) createWindow()
  })
})


app.on('window-all-closed', () => {
  if (process.platform !== 'darwin') {
    app.quit()
  }
})


ipcMain.handle('run-game-function', async (event, args) => {

  return `Executando jogo com args: ${args}`
})
