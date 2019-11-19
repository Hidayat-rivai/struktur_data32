//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
struct List
{
   List *Next;
   int isi;
};
List *Baru;
List *Awal=NULL;
List *Akhir=NULL;
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


void __fastcall TForm1::InputClick(TObject *Sender)
{
 int x;
 x=StrToInt(Edit1->Text);
 Edit1->Clear();
 Edit1->SetFocus();
 Baru= new List;
 Baru->Next=NULL;
 Baru->isi=x;

 if (Awal==NULL)
    {
       Awal=Baru;
       Akhir=Baru;
    }
 else
    {
       Akhir->Next=Baru;
       Akhir=Baru;
    }
 Hapus->Enabled=true;

 ListBox1->Clear();
 List *Tampil=Awal;
 while (Tampil!=NULL)
    {
       ListBox1->Items->Add(Tampil->isi);
       Tampil=Tampil->Next;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::HapusClick(TObject *Sender)
{
 int x;
 x=StrToInt(Edit1->Text);
 List *Cari=Awal;
 bool ketemu=false;
 for (Cari=Awal; Cari!=NULL; Cari=Cari->Next)
    {
       if (x==Cari->isi)
          {
             ketemu=true;
             if (Cari==Awal)
                {
                   if (Cari==Akhir)
                      {
                         Awal=NULL;
                         Akhir=NULL;
                         Hapus->Enabled=false;
                      }
                  else
                      {
                         Awal=Awal->Next;
                      }
                }
             else
                {
                   List *A=Awal;
                   while (A->Next!=Cari)
                      {
                         A=A->Next;
                      }
                   if (Cari==Akhir)
                      {
                         Akhir=A;
                         Akhir->Next=NULL;
                      }
                   else
                      {
                         A->Next=Cari->Next;
                         A=Cari;
                         Cari=Cari->Next;
                         A=NULL;
                      }
                }
          }
    }

 if (ketemu==false)
    {
       ShowMessage("data tidak ditemukan");
    }

 List *Tampil=Awal;
 ListBox1->Clear();
 while (Tampil!=NULL)
    {
       ListBox1->Items->Add(Tampil->isi);
       Tampil=Tampil->Next;
    }
}
//---------------------------------------------------------------------------

