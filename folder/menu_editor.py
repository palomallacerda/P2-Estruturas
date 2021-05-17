import wx
from wx.core import LIGHT_GREY, Size

class equacaoFrame(wx.Frame):
######## INICIANDO PAGINA #########
    def __init__(self, parent, title):
        super(equacaoFrame, self).__init__(parent, title=title, size= (410,400))
    
        self.locale = wx.Locale(wx.LANGUAGE_PORTUGUESE_BRAZILIAN)
        #criando uma barra de menu#
        self.makeMenuBar()

        #criando uma barra de status#
        self.CreateStatusBar()
        self.SetStatusText("Trabalho realizado pelos alunos do IC UFAL")

        #criando entrada
        self.InitEntrada()
        #Mudando o Icone
        self.InitIcone()


    #Mudando o icone da tela  
    def InitIcone(self):    
        self.icon =wx.Icon(wx.Bitmap("C:/Users/Paloma lacerda/Documents/estruturas/Ab2/Icones/alpha.png"))#path to icon
        self.SetIcon(self.icon)
        self.Show()

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

    ##### ações do Menu ##########

   ##### FALTA FAZER PRA SALVAR O ARQUIVO #####    
    def Onsave(self, event):
       wx.MessageBox("salvar aquivo")

    #### SALVAR COMO ####
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

   #### FECHAR A TELA ####
    def Onexit(self, event):
        self.Close(True)

    ##### SOBRE #######
    def Onsobre(self, event):       
        wx.MessageBox("Trabalho feito por alunos do IC UFAL")

    ###### ABRIR AQUIVO NOVO #######
    def Onopen(self, event):
        wx.FileSelector("Escolha um arquivo")

    ##### ENTRADA DA EQUAÇÃO ##########
    def InitEntrada(self):

        Tela = wx.Panel(self)
        sizer = wx.GridBagSizer(4, 4)

        text = wx.StaticText(Tela, label="Digite sua equação abaixo:")
        font_text1 = wx.Font(12, wx.ROMAN, wx.ITALIC, wx.NORMAL)
        text.SetFont(font_text1)
        sizer.Add(text, pos=(0, 0), flag=wx.TOP|wx.LEFT|wx.BOTTOM, border=5)

        tc = wx.TextCtrl(Tela)
        sizer.Add(tc, pos=(1, 0), span=(1, 4),
            flag=wx.EXPAND|wx.LEFT|wx.RIGHT, border=5)
        Tela.SetSizer(sizer)

        #inserindo botao de enviar e limpar 
        buttonsend = wx.Button(Tela, label="Enviar", size=(90, 28))
        buttonClear = wx.Button(Tela, label="Limpar", size=(90, 28))
        sizer.Add(buttonsend, pos=(2, 2))
        sizer.Add(buttonClear, pos=(2, 3), flag=wx.RIGHT|wx.Right, border=10)

        #Inserindo botões de imagem
        beta = wx.Image("C:/Users/Paloma lacerda/Documents/estruturas/Ab2/Icones/beta.png", wx.BITMAP_TYPE_ANY).ConvertToBitmap()
        self.betabutton = wx.BitmapButton(Tela, -1, beta, pos=(5,100), size =(beta.GetWidth()+5, beta.GetHeight()+5))

        alpha = wx.Image("C:/Users/Paloma lacerda/Documents/estruturas/Ab2/Icones/alpha.png", wx.BITMAP_TYPE_ANY).ConvertToBitmap()
        self.alphabutton = wx.BitmapButton(Tela, -1, alpha, pos=(60,100), size =(alpha.GetWidth()+5, alpha.GetHeight()+5))

        theta = wx.Image("C:/Users/Paloma lacerda/Documents/estruturas/Ab2/Icones/theta.jpg", wx.BITMAP_TYPE_ANY).ConvertToBitmap()
        self.thetabutton = wx.BitmapButton(Tela, -1, theta, pos=(115,100), size =(theta.GetWidth()+5, theta.GetHeight()+5))

        delta = wx.Image("C:/Users/Paloma lacerda/Documents/estruturas/Ab2/Icones/delta.jpg", wx.BITMAP_TYPE_ANY).ConvertToBitmap()
        self.deltabutton = wx.BitmapButton(Tela, -1, delta, pos=(170,100), size =(delta.GetWidth()+5, delta.GetHeight()+5))

        omega = wx.Image("C:/Users/Paloma lacerda/Documents/estruturas/Ab2/Icones/omega.png", wx.BITMAP_TYPE_ANY).ConvertToBitmap()
        self.omegabutton = wx.BitmapButton(Tela, -1, omega, pos=(225,100), size =(omega.GetWidth()+5, omega.GetHeight()+5))

        sigma = wx.Image("C:/Users/Paloma lacerda/Documents/estruturas/Ab2/Icones/sigma.png", wx.BITMAP_TYPE_ANY).ConvertToBitmap()
        self.sigmabutton = wx.BitmapButton(Tela, -1, sigma, pos=(280,100), size =(sigma.GetWidth()+5, sigma.GetHeight()+5))
  
        menorq = wx.Image("C:/Users/Paloma lacerda/Documents/estruturas/Ab2/Icones/lessthan.png", wx.BITMAP_TYPE_ANY).ConvertToBitmap()
        self.menorqbutton = wx.BitmapButton(Tela, -1, menorq, pos=(335,100), size =(menorq.GetWidth()+5, menorq.GetHeight()+5))

        exist = wx.Image("C:/Users/Paloma lacerda/Documents/estruturas/Ab2/Icones/exist.png", wx.BITMAP_TYPE_ANY).ConvertToBitmap()
        self.existbutton = wx.BitmapButton(Tela, -1, exist, pos=(5,155), size =(exist.GetWidth()+5, exist.GetHeight()+5))

        npertence = wx.Image("C:/Users/Paloma lacerda/Documents/estruturas/Ab2/Icones/npertence.png", wx.BITMAP_TYPE_ANY).ConvertToBitmap()
        self.npertencebutton = wx.BitmapButton(Tela, -1, npertence, pos=(60,155), size =(npertence.GetWidth()+5, npertence.GetHeight()+5))

        pertence = wx.Image("C:/Users/Paloma lacerda/Documents/estruturas/Ab2/Icones/pertence.png", wx.BITMAP_TYPE_ANY).ConvertToBitmap()
        self.pertencebutton = wx.BitmapButton(Tela, -1, pertence, pos=(115,155), size =(pertence.GetWidth()+5, pertence.GetHeight()+5))

        pi = wx.Image("C:/Users/Paloma lacerda/Documents/estruturas/Ab2/Icones/pi.png", wx.BITMAP_TYPE_ANY).ConvertToBitmap()
        self.pibutton = wx.BitmapButton(Tela, -1, pi, pos=(170,155), size =(pi.GetWidth()+5, pi.GetHeight()+5))

        raiz = wx.Image("C:/Users/Paloma lacerda/Documents/estruturas/Ab2/Icones/squareroot.png", wx.BITMAP_TYPE_ANY).ConvertToBitmap()
        self.raizbutton = wx.BitmapButton(Tela, -1, raiz, pos=(225,155), size =(raiz.GetWidth()+5, raiz.GetHeight()+5))

        raizN = wx.Image("C:/Users/Paloma lacerda/Documents/estruturas/Ab2/Icones/squarerootX.png", wx.BITMAP_TYPE_ANY).ConvertToBitmap()
        self.raizNbutton = wx.BitmapButton(Tela, -1, raizN, pos=(280,155), size =(raizN.GetWidth()+5, raizN.GetHeight()+5))

        maiorq = wx.Image("C:/Users/Paloma lacerda/Documents/estruturas/Ab2/Icones/biggerthan.png", wx.BITMAP_TYPE_ANY).ConvertToBitmap()
        self.maiorqbutton = wx.BitmapButton(Tela, -1, maiorq, pos=(335,155), size =(maiorq.GetWidth()+5, maiorq.GetHeight()+5))
        
        sobre = wx.Image("C:/Users/Paloma lacerda/Documents/estruturas/Ab2/Icones/sobre.png", wx.BITMAP_TYPE_ANY).ConvertToBitmap()
        self.sobrebutton = wx.BitmapButton(Tela, -1, sobre, pos=(115,210), size =(sobre.GetWidth()+5, sobre.GetHeight()+5))

        abaixo = wx.Image("C:/Users/Paloma lacerda/Documents/estruturas/Ab2/Icones/abaixo.png", wx.BITMAP_TYPE_ANY).ConvertToBitmap()
        self.abaixobutton = wx.BitmapButton(Tela, -1, abaixo, pos=(170,210), size =(abaixo.GetWidth()+5, abaixo.GetHeight()+5))

        fraction = wx.Image("C:/Users/Paloma lacerda/Documents/estruturas/Ab2/Icones/fraction.png", wx.BITMAP_TYPE_ANY).ConvertToBitmap()
        self.abaixobutton = wx.BitmapButton(Tela, -1, fraction, pos=(225,210), size =(fraction.GetWidth()+5, fraction.GetHeight()+5))

        notsubset = wx.Image("C:/Users/Paloma lacerda/Documents/estruturas/Ab2/Icones/notsubset2.png", wx.BITMAP_TYPE_ANY).ConvertToBitmap()
        self.notsubsetbutton = wx.BitmapButton(Tela, -1, notsubset, pos=(60,210), size =(notsubset.GetWidth()+5, notsubset.GetHeight()+5))

        subset = wx.Image("C:/Users/Paloma lacerda/Documents/estruturas/Ab2/Icones/subset.png", wx.BITMAP_TYPE_ANY).ConvertToBitmap()
        self.subsetbutton = wx.BitmapButton(Tela, -1, subset, pos=(280,210), size =(subset.GetWidth()+5, subset.GetHeight()+5))


        #saida da equação
        saida = wx.StaticText(Tela, label="Sua resposta abaixo:", pos=(5,265))
        font = wx.Font(12, wx.ROMAN, wx.ITALIC, wx.NORMAL)
        saida.SetFont(font)

        #caixa de texto da saida
        resposta_final = wx.TextCtrl(Tela)
        sizer.Add(resposta_final, pos=(4,0), span=(1,5), flag=wx.EXPAND|wx.LEFT|wx.RIGHT,
            border=8)


        #definindo cor de background
        Tela.SetBackgroundColour(LIGHT_GREY)

        #criando linha de separação
        line = wx.StaticLine(Tela)
        sizer.Add(line, pos=(3,0), span=(1,5), 
                flag = wx.EXPAND|wx.RIGHT, border = 10)

        #pra a entrada se encaixar na tela
        sizer.AddGrowableCol(1)
        sizer.AddGrowableRow(2)

def main():

    app = wx.App()
    ex = equacaoFrame(None, title='Editor de equação')
    ex.Show()
    app.MainLoop()


if __name__ == '__main__':
    main()
