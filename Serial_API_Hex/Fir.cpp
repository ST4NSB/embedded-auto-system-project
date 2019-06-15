//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Fir.h"
#include "main.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall Unit2::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

extern HANDLE m_hCommPort;
unsigned char rdbuff[10000];
int rdindex=0;
int erori=0;

__fastcall Fir::Fir(bool CreateSuspended)
        : TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void __fastcall Fir::Execute()
{
unsigned long nrbytesread=0;
unsigned char nextcar;
OVERLAPPED ovlr;

        //---- Place thread code here ----

        rdindex=0;
        ovlr.hEvent=CreateEvent(NULL,TRUE,TRUE,NULL);
        while(1)
        {
                nrbytesread=0;

                if(ReadFile(m_hCommPort, &nextcar, 1, &nrbytesread, &ovlr) == 0) // fails
                     { // fails
                     if( GetLastError() == ERROR_IO_PENDING)
                         GetOverlappedResult(m_hCommPort, &ovlr, &nrbytesread, TRUE);
                     else {erori++;continue;} //errors
                     }

                rdbuff[rdindex] = nextcar;
                rdindex += nrbytesread;
                Synchronize(UpdateCaption);
        }// while
}
//---------------------------------------------------------------------------

void __fastcall Fir::UpdateCaption()
{
   FMain->lReceptionate->Caption = rdindex;

   FMain->eHexReceptie->Text = "";
   FMain->eReceptie->Text    = "";
   for(int k=0;k<rdindex ;k++)
      {
      FMain->eReceptie->Text    = FMain->eReceptie->Text    +    (char)rdbuff[k];
      FMain->eHexReceptie->Text = FMain->eHexReceptie->Text + IntToHex(rdbuff[k],2)+" ";
      }
}

