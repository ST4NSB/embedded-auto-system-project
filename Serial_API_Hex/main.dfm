object FMain: TFMain
  Left = 210
  Top = 192
  Width = 1053
  Height = 574
  Caption = 'FMain'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object lErori: TLabel
    Left = 616
    Top = 380
    Width = 34
    Height = 16
    Caption = 'Erori'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lReceptionate: TLabel
    Left = 8
    Top = 272
    Width = 99
    Height = 20
    Caption = 'lReceptionate'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNone
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object lHCom: TLabel
    Left = 552
    Top = 20
    Width = 40
    Height = 20
    Caption = 'inchis'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Shape1: TShape
    Left = 8
    Top = 56
    Width = 681
    Height = 1
    Brush.Color = clBtnText
  end
  object Shape2: TShape
    Left = 7
    Top = 248
    Width = 681
    Height = 1
  end
  object lText: TLabel
    Left = 456
    Top = 22
    Width = 83
    Height = 16
    Caption = 'COM Handle: '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label1: TLabel
    Left = 32
    Top = 80
    Width = 27
    Height = 13
    Caption = 'ASCII'
  end
  object Label2: TLabel
    Left = 32
    Top = 112
    Width = 25
    Height = 13
    Caption = 'Hexa'
  end
  object Semnalizare: TLabel
    Left = 800
    Top = 32
    Width = 88
    Height = 20
    Caption = 'Semnalizare'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Acceleratie: TLabel
    Left = 800
    Top = 184
    Width = 79
    Height = 20
    Caption = 'Acceleratie'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Parametrii: TLabel
    Left = 800
    Top = 408
    Width = 71
    Height = 20
    Caption = 'Parametrii'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Shape3: TShape
    Left = 744
    Top = 32
    Width = 1
    Height = 465
  end
  object accinfo: TLabel
    Left = 800
    Top = 216
    Width = 167
    Height = 13
    Caption = 'Introduceti o valoare pt. acceleratie'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object accinfo2: TLabel
    Left = 800
    Top = 232
    Width = 56
    Height = 13
    Caption = 'intre (0-255)'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object btnOpenCOM: TButton
    Left = 160
    Top = 8
    Width = 113
    Height = 33
    Caption = 'Deschide'
    TabOrder = 0
    OnClick = btnOpenCOMClick
  end
  object btnClose: TBitBtn
    Left = 8
    Top = 432
    Width = 681
    Height = 57
    Caption = '&Inchide'
    TabOrder = 1
    Kind = bkClose
  end
  object eReceptie: TEdit
    Left = 8
    Top = 296
    Width = 681
    Height = 28
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
  end
  object btnAfisErr: TBitBtn
    Left = 488
    Top = 376
    Width = 113
    Height = 25
    Caption = 'Afisare Numar Erori'
    TabOrder = 3
    OnClick = btnAfisErrClick
  end
  object eSendA: TEdit
    Left = 8
    Top = 144
    Width = 681
    Height = 28
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 4
  end
  object btnSendText: TBitBtn
    Left = 512
    Top = 72
    Width = 169
    Height = 57
    Caption = 'Trimite Text'
    TabOrder = 5
    OnClick = btnSendTextClick
  end
  object cbSelectCOM: TComboBox
    Left = 32
    Top = 16
    Width = 89
    Height = 21
    ItemHeight = 13
    TabOrder = 6
    Text = 'COM1'
    Items.Strings = (
      'COM1'
      'COM2'
      'COM3'
      'COM4'
      'COM5'
      'COM6'
      'COM7'
      'COM8'
      'COM9'
      'COM10'
      'COM11'
      'COM12')
  end
  object btnCloseCOM: TButton
    Left = 296
    Top = 8
    Width = 121
    Height = 33
    Caption = 'Inchide'
    Enabled = False
    TabOrder = 7
    OnClick = btnCloseCOMClick
  end
  object btnStergereR: TButton
    Left = 8
    Top = 376
    Width = 145
    Height = 25
    Caption = 'Stergere Buffer Receptie'
    TabOrder = 8
    OnClick = btnStergereRClick
  end
  object eHexReceptie: TEdit
    Left = 7
    Top = 328
    Width = 681
    Height = 28
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 9
  end
  object eValueA: TEdit
    Left = 72
    Top = 72
    Width = 121
    Height = 21
    TabOrder = 10
  end
  object eValueH: TEdit
    Left = 72
    Top = 104
    Width = 121
    Height = 21
    TabOrder = 11
  end
  object btnAdaugaA: TButton
    Left = 216
    Top = 72
    Width = 89
    Height = 25
    Caption = 'Adauga ASCII'
    TabOrder = 12
    OnClick = btnAdaugaAClick
  end
  object btnAdaugaH: TButton
    Left = 216
    Top = 104
    Width = 89
    Height = 25
    Caption = 'Adauga Hexa'
    TabOrder = 13
    OnClick = btnAdaugaHClick
  end
  object eSendH: TEdit
    Left = 7
    Top = 176
    Width = 681
    Height = 28
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 14
  end
  object btnStergereT: TButton
    Left = 8
    Top = 208
    Width = 129
    Height = 25
    Caption = 'Sterge buffer transmisie'
    TabOrder = 15
    OnClick = btnStergereTClick
  end
  object SPSbttn: TButton
    Left = 800
    Top = 64
    Width = 75
    Height = 25
    Caption = 'SPS'
    TabOrder = 16
    OnClick = SPSbttnClick
  end
  object SOSbttn: TButton
    Left = 888
    Top = 64
    Width = 75
    Height = 25
    Caption = 'SOS'
    TabOrder = 17
    OnClick = SOSbttnClick
  end
  object SPDbttn: TButton
    Left = 800
    Top = 104
    Width = 75
    Height = 25
    Caption = 'SPD'
    TabOrder = 18
    OnClick = SPDbttnClick
  end
  object SODbttn: TButton
    Left = 888
    Top = 104
    Width = 75
    Height = 25
    Caption = 'SOD'
    TabOrder = 19
    OnClick = SODbttnClick
  end
  object SPAbttn: TButton
    Left = 800
    Top = 144
    Width = 75
    Height = 25
    Caption = 'SPA'
    TabOrder = 20
    OnClick = SPAbttnClick
  end
  object SOAbttn: TButton
    Left = 888
    Top = 144
    Width = 75
    Height = 25
    Caption = 'SOA'
    TabOrder = 21
    OnClick = SOAbttnClick
  end
  object ACAbttn: TButton
    Left = 800
    Top = 368
    Width = 75
    Height = 25
    Caption = 'ACA'
    TabOrder = 22
    OnClick = ACAbttnClick
  end
  object ASAbttn: TButton
    Left = 888
    Top = 368
    Width = 75
    Height = 25
    Caption = 'ASA'
    TabOrder = 23
    OnClick = ASAbttnClick
  end
  object PIPbttn: TButton
    Left = 800
    Top = 440
    Width = 75
    Height = 25
    Caption = 'PIP'
    TabOrder = 24
    OnClick = PIPbttnClick
  end
  object AIAbttn: TBitBtn
    Left = 800
    Top = 328
    Width = 161
    Height = 25
    Caption = 'AIA (valoare random)'
    TabOrder = 25
    OnClick = AIAbttnClick
  end
  object AIAtxtbox: TEdit
    Left = 800
    Top = 256
    Width = 161
    Height = 21
    TabOrder = 26
    Text = '0'
  end
  object AIAvaluebttn: TButton
    Left = 800
    Top = 288
    Width = 75
    Height = 25
    Caption = 'AIA'
    TabOrder = 27
    OnClick = AIAvaluebttnClick
  end
  object PPTAbttn: TButton
    Left = 800
    Top = 480
    Width = 75
    Height = 25
    Caption = 'PPTA'
    TabOrder = 28
    OnClick = PPTAbttnClick
  end
  object POTAbttn: TButton
    Left = 888
    Top = 480
    Width = 75
    Height = 25
    Caption = 'POTA'
    TabOrder = 29
    OnClick = POTAbttnClick
  end
end
