//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include "fir.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"



TFMain *FMain;

extern unsigned char rdbuff[];
extern int rdindex;
extern int erori;

unsigned char rtbuff[1000];
int rtindex=0;

HANDLE m_hCommPort;

Fir *firReceptie= NULL;

//---------------------------------------------------------------------------
__fastcall TFMain::TFMain(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFMain::btnOpenCOMClick(TObject *Sender)
{  DCB dcbSerialParams ;
        m_hCommPort = CreateFile(cbSelectCOM->Text.c_str(),
            GENERIC_WRITE|GENERIC_READ,//access ( read and write)
            0,    //(share) 0:cannot share the COM port
            0,    //security  (None)
            OPEN_EXISTING,// creation : open_existing
            FILE_FLAG_OVERLAPPED,// we want overlapped operation
            0// no templates file for COM port...
            );

      if(m_hCommPort==NULL){
        ShowMessage("nu pot deschide port");
        return;
      }
      if(m_hCommPort==INVALID_HANDLE_VALUE) {
        ShowMessage("invalid handle value");
        return;
      }

      if (!GetCommState(m_hCommPort, &dcbSerialParams))
      {
           ShowMessage("error getting serial port state");
      }

      dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

      dcbSerialParams.BaudRate = CBR_19200;
      dcbSerialParams.ByteSize = 8;
      dcbSerialParams.StopBits = ONESTOPBIT;
      dcbSerialParams.Parity   = NOPARITY;

      dcbSerialParams.fBinary  = TRUE;

      if (!SetCommState(m_hCommPort, &dcbSerialParams))
      {
            ShowMessage(" error setting serial port state");
      }

      lHCom->Caption = (int)m_hCommPort;

      if(firReceptie==NULL)
        firReceptie = new Fir(false);
      else
        firReceptie->Resume();  
      btnOpenCOM->Enabled = false;
      btnCloseCOM->Enabled = true;
      eValueA->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TFMain::btnAfisErrClick(TObject *Sender)
{
        lErori->Caption = erori;
}
//---------------------------------------------------------------------------

void __fastcall TFMain::FormClose(TObject *Sender, TCloseAction &Action)
{
        CloseHandle(m_hCommPort);
}
//---------------------------------------------------------------------------

void __fastcall TFMain::btnSendTextClick(TObject *Sender)
{
        DWORD nr=0;
        OVERLAPPED ovlw;

          ovlw.hEvent=CreateEvent(NULL,TRUE,TRUE,NULL);
          if(!WriteFile(m_hCommPort, rtbuff, rtindex, &nr, &ovlw))
              if(GetLastError()!= ERROR_IO_PENDING)
                ShowMessage("WriteText: "+IntToStr(GetLastError()));
          eValueA->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TFMain::btnCloseCOMClick(TObject *Sender)
{
        CloseHandle(m_hCommPort);
        m_hCommPort = (void*)-1;
        firReceptie->Suspend();
        lHCom->Caption = "inchis";
        btnOpenCOM->Enabled = true;
        btnCloseCOM->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TFMain::btnStergereRClick(TObject *Sender)
{
        eReceptie->Text    = "";
        eHexReceptie->Text = "";
        rdindex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TFMain::btnStergereTClick(TObject *Sender)
{
        eSendA->Text = "";
        eSendH->Text = "";
        rtindex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TFMain::btnAdaugaAClick(TObject *Sender)
{
     for(int k=1;k <= eValueA->Text.Length();k++)
        {
        rtbuff[rtindex] = eValueA->Text[k];
        FMain->eSendA->Text = FMain->eSendA->Text +    (char)rtbuff[rtindex];
        FMain->eSendH->Text = FMain->eSendH->Text + IntToHex(rtbuff[rtindex],2)+" ";
        rtindex++;
        }
}
//---------------------------------------------------------------------------

void __fastcall TFMain::btnAdaugaHClick(TObject *Sender)
{
int x;
char v;
        eValueH->Text.LowerCase();
        if( (x = HexToBin(eValueH->Text.c_str(), &v, 1))!=1)
                                {ShowMessage("eroare conversie " + IntToStr(x)); return;}
        rtbuff[rtindex] = v;
        FMain->eSendA->Text = FMain->eSendA->Text +    (char)rtbuff[rtindex];
        FMain->eSendH->Text = FMain->eSendH->Text + IntToHex(rtbuff[rtindex],2)+" ";
        rtindex++;
}
//---------------------------------------------------------------------------
OVERLAPPED ovlw;
void TrimitePachet(unsigned char buff[], int n)
{
        DWORD nr=0;
 

        ovlw.hEvent=CreateEvent(NULL,TRUE,TRUE,NULL);
        if(!WriteFile(m_hCommPort, buff, n, &nr, &ovlw))
            if(GetLastError()!= ERROR_IO_PENDING)
              ShowMessage("WriteText: "+IntToStr(GetLastError()));
        //eValueA->SetFocus();
}

#define SPS 1
#define SOS 2
#define SPD 3
#define SOD 4
#define SPA 5
#define SOA 6

#define AIA 7
#define ACA 8
#define ASA 9

#define PIP 10
#define PPTA 13
#define POTA 14

unsigned char buffSPS[] = {SPS, 00, SPS};
unsigned char buffSOS[] = {SOS, 00, SOS};
unsigned char buffSPD[] = {SPD, 00, SPD};
unsigned char buffSOD[] = {SOD, 00, SOD};
unsigned char buffSPA[] = {SPA, 00, SPA};
unsigned char buffSOA[] = {SOA, 00, SOA};

unsigned char buffAIA[4];
unsigned char buffACA[] = {ACA, 00, ACA};
unsigned char buffASA[] = {ASA, 00, ASA};

unsigned char buffPIP[] = {PIP, 00, PIP};
unsigned char buffPPTA[] = {PPTA, 00, PPTA};
unsigned char buffPOTA[] = {POTA, 00, POTA};

void __fastcall TFMain::SPSbttnClick(TObject *Sender)
{
        TrimitePachet(buffSPS, 3);
}
//---------------------------------------------------------------------------

void __fastcall TFMain::SOSbttnClick(TObject *Sender)
{
        TrimitePachet(buffSOS, 3);
}
//---------------------------------------------------------------------------

void __fastcall TFMain::SPDbttnClick(TObject *Sender)
{
        TrimitePachet(buffSPD, 3);
}
//---------------------------------------------------------------------------

void __fastcall TFMain::SODbttnClick(TObject *Sender)
{
        TrimitePachet(buffSOD, 3);
}
//---------------------------------------------------------------------------

void __fastcall TFMain::SPAbttnClick(TObject *Sender)
{
        TrimitePachet(buffSPA, 3);
}
//---------------------------------------------------------------------------

void __fastcall TFMain::SOAbttnClick(TObject *Sender)
{
        TrimitePachet(buffSOA, 3);
}
//---------------------------------------------------------------------------

void __fastcall TFMain::AIAvaluebttnClick(TObject *Sender)
{
        unsigned char value = AIAtxtbox->Text.ToInt();
        buffAIA[0] = AIA;
        buffAIA[1] = 01;
        buffAIA[2] = value;
        unsigned char sum = buffAIA[0] + buffAIA[1] + buffAIA[2];
        buffAIA[3] = sum;
        TrimitePachet(buffAIA, 4);
}
//---------------------------------------------------------------------------

void __fastcall TFMain::AIAbttnClick(TObject *Sender)
{
        Randomize();
        unsigned char rand = RandSeed % 256; // interval 0-255
        buffAIA[0] = AIA;
        buffAIA[1] = 01;
        buffAIA[2] = rand;
        unsigned char sum = buffAIA[0] + buffAIA[1] + buffAIA[2];
        buffAIA[3] = sum;
        TrimitePachet(buffAIA, 4);
}
//---------------------------------------------------------------------------

void __fastcall TFMain::ACAbttnClick(TObject *Sender)
{
        TrimitePachet(buffACA, 3);        
}
//---------------------------------------------------------------------------

void __fastcall TFMain::ASAbttnClick(TObject *Sender)
{
        TrimitePachet(buffASA, 3);        
}
//---------------------------------------------------------------------------

void __fastcall TFMain::PIPbttnClick(TObject *Sender)
{
        TrimitePachet(buffPIP, 3);
}
//---------------------------------------------------------------------------

void __fastcall TFMain::PPTAbttnClick(TObject *Sender)
{
        TrimitePachet(buffPPTA, 3);
}
//---------------------------------------------------------------------------

void __fastcall TFMain::POTAbttnClick(TObject *Sender)
{
        TrimitePachet(buffPOTA, 3);
}
//---------------------------------------------------------------------------

