object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 590
  ClientWidth = 612
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Label1: TLabel
    Left = 62
    Top = 411
    Width = 32
    Height = 15
    Caption = 'Name'
  end
  object Label2: TLabel
    Left = 62
    Top = 467
    Width = 46
    Height = 15
    Caption = 'Duration'
  end
  object Label3: TLabel
    Left = 62
    Top = 523
    Width = 48
    Height = 15
    Caption = 'Difficulty'
  end
  object ListView1: TListView
    Left = 24
    Top = 40
    Width = 545
    Height = 257
    Columns = <
      item
        AutoSize = True
        Caption = 'Name'
      end
      item
        AutoSize = True
        Caption = 'Duration'
      end
      item
        AutoSize = True
        Caption = 'Difficulty'
      end>
    TabOrder = 0
    ViewStyle = vsReport
  end
  object XmlLoadButton: TButton
    Left = 24
    Top = 328
    Width = 113
    Height = 41
    Caption = 'Load tasks'
    TabOrder = 1
    OnClick = XmlLoadButtonClick
  end
  object AddTaskButton: TButton
    Left = 176
    Top = 328
    Width = 105
    Height = 41
    Caption = 'Add task'
    TabOrder = 2
    OnClick = AddTaskButtonClick
  end
  object DeleteTaskButton: TButton
    Left = 320
    Top = 328
    Width = 105
    Height = 41
    Caption = 'Delete task'
    TabOrder = 3
    OnClick = DeleteTaskButtonClick
  end
  object EditTaskButton: TButton
    Left = 464
    Top = 328
    Width = 105
    Height = 41
    Caption = 'Edit task'
    TabOrder = 4
    OnClick = EditTaskButtonClick
  end
  object NameEdit: TEdit
    Left = 136
    Top = 408
    Width = 153
    Height = 23
    TabOrder = 5
  end
  object DurationEdit: TEdit
    Left = 136
    Top = 464
    Width = 153
    Height = 23
    NumbersOnly = True
    TabOrder = 6
  end
  object DifficultyEdit: TEdit
    Left = 136
    Top = 520
    Width = 153
    Height = 23
    TabOrder = 7
  end
  object XMLDocument: TXMLDocument
    FileName = '.\tasks.xml'
    Left = 208
    Top = 152
  end
end
