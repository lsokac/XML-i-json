//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "tasks.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::XmlLoadButtonClick(TObject *Sender)
{
  _di_IXMLtasksType tasks = Gettasks(XMLDocument);

  ListView1 -> Items -> Clear();
  for (int i= 0; i < tasks -> Count; i++) {
	ListView1 -> Items -> Add();
	ListView1 -> Items -> Item[i] -> Caption =  tasks -> task[i] -> name;
	ListView1 -> Items -> Item[i] -> SubItems ->Add( tasks -> task[i] -> duration);
	ListView1 -> Items -> Item[i] -> SubItems ->Add( tasks -> task[i] -> difficulty);

  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::AddTaskButtonClick(TObject *Sender)
{

	 if (NameEdit->Text.IsEmpty() || DurationEdit->Text.IsEmpty() || DifficultyEdit->Text.IsEmpty())
	{
		ShowMessage("All fields must have values.");
		return;
	}

 _di_IXMLtasksType tasks = Gettasks(XMLDocument);
 _di_IXMLtaskType task = tasks -> Add();
 task -> name = NameEdit -> Text;
 task -> duration = StrToFloat(DurationEdit->Text);
 task -> difficulty = DifficultyEdit -> Text;

 XMLDocument -> SaveToFile(XMLDocument->FileName);

 NameEdit -> Text = "";
 DurationEdit -> Text = "";
 DifficultyEdit -> Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DeleteTaskButtonClick(TObject *Sender)
{
  _di_IXMLtasksType tasks = Gettasks(XMLDocument);
  tasks -> Delete(ListView1->ItemIndex);
  XMLDocument -> SaveToFile(XMLDocument->FileName);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::EditTaskButtonClick(TObject *Sender)
{
	// Provjera jel je koje oznaceno
	if(ListView1->ItemIndex == -1)
	return; // ako nije kraj
	_di_IXMLtasksType tasks = Gettasks(XMLDocument);

	_di_IXMLtaskType task = tasks -> task[ListView1 -> ItemIndex];

    if (NameEdit->Text.IsEmpty() || DurationEdit->Text.IsEmpty() || DifficultyEdit->Text.IsEmpty())
	{
		ShowMessage("All fields must have values.");
		return;
	}

	 task -> name = NameEdit -> Text;
	 task -> duration = StrToFloat(DurationEdit->Text);
	 task -> difficulty = DifficultyEdit -> Text;

	 XMLDocument -> SaveToFile(XMLDocument->FileName);

	 NameEdit -> Text = "";
	 DurationEdit -> Text = "";
	 DifficultyEdit -> Text = "";
}
//---------------------------------------------------------------------------

