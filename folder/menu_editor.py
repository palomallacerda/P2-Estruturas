import wx
from wx.core import CLOSE, CloseEvent, EVT_MENU, FileDialog, SaveFileSelector

class EquacaoFrame(wx.Frame):
    def __init__(self, *args, **kw):
        super(EquacaoFrame, self).__init__(*args, **kw)
        tela = wx.Panel(self)
        st = wx.StaticText(tela, label="This is an equation editor")
        font = st.GetFont()
        font.PointSize+=10
        font = font.Bold() 
        st.SetFont(font)

        
        sizer = wx.BoxSizer(wx.HORIZONTAL)
        sizer.Add(st, wx.SizerFlags().Border(wx.TOP|wx.LEFT, 45))
        tela.SetSizer(sizer)

        #criando uma barra de menu#
        self.makeMenuBar()

        
        #criando uma barra de status#
        self.CreateStatusBar()
        self.SetStatusText("Trabalho realizado pelos alunos do IC UFAL")


    def makeMenuBar(self):
        fileMenu = wx.Menu()
        saveItem = fileMenu.Append(-1, "&Salvar\tCtrl-S",
                "Help string shown in status bar for this menu item")
        fileMenu.AppendSeparator()
        saveitemas = fileMenu.Append(-1, "&Salvar como\tCtrl-T",
                "Salvar como")        
        
        fileMenu.AppendSeparator()
        openitem = fileMenu.Append(wx.ID_OPEN)
        
        fileMenu.AppendSeparator()
        exitItem = fileMenu.Append(wx.ID_EXIT)
        


        helpmenu = wx.Menu()
        aboutItem = helpmenu.Append(wx.ID_ABOUT)


        menuBar = wx.MenuBar()
        menuBar.Append(fileMenu,"&Arquivo")
        menuBar.Append(helpmenu, "&Ajuda")

        self.SetMenuBar(menuBar)

        
        self.Bind(wx.EVT_MENU, self.Onsave, saveItem)
        self.Bind(wx.EVT_MENU, self.Onsaveas, saveitemas)
        self.Bind(wx.EVT_MENU, self.Onexit,  exitItem)
        self.Bind(wx.EVT_MENU, self.Onsobre, aboutItem)
        self.Bind(wx.EVT_MENU, self.Onopen, openitem)
    
    def Onsave(self, event):
       wx.MessageBox("salvar aquivo")
    def Onsaveas(self, event):
     with wx.FileDialog(self,"Save as XYZ file", wildcard="xyz files (*.xyz)|*.xyz",
                        style=wx.FD_SAVE|wx.FD_OVERWRITE_PROMPT) as fileDialog:
        if fileDialog.ShowModal() == wx.ID_CANCEL:
            return   
        pathname = fileDialog.GetPath()
        try:
            with open(pathname, 'w') as file:
                self.doSaveData(file)
        except IOError:
            wx.LogError("Cannot save current data in file '%s'." % pathname)
    def Onexit(self, event):
        self.Close(True)
    def Onsobre(self, event):       
        wx.MessageBox("Trabalho feito por alunos do IC UFAL")
    def Onopen(self, event):
        wx.FileSelector("Escolha um arquivo")

if __name__ == '__main__':
    app = wx.App()
    frm = EquacaoFrame(None, title='Equation Editor')
    frm.Show()
    app.MainLoop()

