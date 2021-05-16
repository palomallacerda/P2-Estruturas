#coding: utf-8
from sys import flags
import wx
from wx.core import CLOSE, CloseEvent, DC, DefaultPosition, DefaultSize, EVT_MENU, FileDialog, LIGHT_GREY, LIGHT_GREY_BRUSH, Position, RED, SaveFileSelector

class EquacaoFrame(wx.Frame):
    def __init__(self, *args, **kw):
        super(EquacaoFrame, self).__init__(*args, **kw)
        tela = wx.Panel(self)
        vbox = wx.BoxSizer(wx.VERTICAL) 

        st = wx.StaticText(tela, label="Crie sua equação abaixo")
        font = st.GetFont()
        font.PointSize+=4
        font = font.Italic() 
        st.SetFont(font)
        tela.SetBackgroundColour(LIGHT_GREY)
        
        sizer = wx.BoxSizer(wx.HORIZONTAL)
        sizer.Add(st, wx.SizerFlags().Border(wx.TOP|wx.LEFT, 15))
        tela.SetSizer(sizer)
        

        #criando botões
        #bottom_1= wx.BoxSizer(wx.HORIZONTAL)
        #bottom_1.Add(wx.Button(self, -1,"Botao" ), 0, wx.ALIGN_CENTER, 0)
        #self.SetSizer(bottom_1)#



        #criando caixa de texto#
        hbox = wx.BoxSizer(wx.HORIZONTAL)
        l1 = wx.StaticText(tela,-1, label ="Escreva sua equação aqui:")
        hbox.Add(l1,0, wx.EXPAND| wx.ALIGN_LEFT| wx.ALL, 30)
        
        
        
        self.t1 = wx.TextCtrl(tela,-1, size=(200,100), style = wx.TE_MULTILINE)
        hbox.Add(self.t1, 1, wx.EXPAND|wx.ALIGN_LEFT|wx.Left,10)
        vbox.Add(hbox) 
        tela.SetSizer(vbox) 

        
        #criando uma barra de menu#
        self.makeMenuBar()

        #criando uma barra de status#
        self.CreateStatusBar()
        self.SetStatusText("Trabalho realizado pelos alunos do IC UFAL")
    

    def makeMenuBar(self):
        fileMenu = wx.Menu()
        saveItem = fileMenu.Append(-1, "&Salvar\tCtrl+S",
                "Help string shown in status bar for this menu item")
        fileMenu.AppendSeparator()
        saveitemas = fileMenu.Append(-1, "&Salvar como\tCtrl+Shift+S",
                "Salvar como")        
        
        fileMenu.AppendSeparator()
        openitem = fileMenu.Append(wx.ID_OPEN)
        
        fileMenu.AppendSeparator()
        exitItem = fileMenu.Append(wx.ID_EXIT, "&Exit\tCtrl+X")
        


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

