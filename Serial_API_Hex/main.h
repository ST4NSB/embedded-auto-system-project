//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
//#include <DisComp.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFMain : public TForm
{
__published:	// IDE-managed Components
        TButton *btnOpenCOM;
        TBitBtn *btnClose;
        TEdit *eReceptie;
        TLabel *lErori;
        TBitBtn *btnAfisErr;
        TLabel *lReceptionate;
        TLabel *lHCom;
        TEdit *eSendA;
        TBitBtn *btnSendText;
        TComboBox *cbSelectCOM;
        TButton *btnCloseCOM;
        TShape *Shape1;
        TShape *Shape2;
        TButton *btnStergereR;
        TLabel *lText;
        TEdit *eHexReceptie;
        TEdit *eValueA;
        TLabel *Label1;
        TEdit *eValueH;
        TLabel *Label2;
        TButton *btnAdaugaA;
        TButton *btnAdaugaH;
        TEdit *eSendH;
        TButton *btnStergereT;
        TButton *SPSbttn;
        TButton *SOSbttn;
        TButton *SPDbttn;
        TButton *SODbttn;
        TButton *SPAbttn;
        TButton *SOAbttn;
        TButton *ACAbttn;
        TButton *ASAbttn;
        TButton *PIPbttn;
        TLabel *Semnalizare;
        TLabel *Acceleratie;
        TLabel *Parametrii;
        TShape *Shape3;
        TBitBtn *AIAbttn;
        TLabel *accinfo;
        TEdit *AIAtxtbox;
        TButton *AIAvaluebttn;
        TLabel *accinfo2;
        void __fastcall btnOpenCOMClick(TObject *Sender);
        void __fastcall btnAfisErrClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall btnSendTextClick(TObject *Sender);
        void __fastcall btnCloseCOMClick(TObject *Sender);
        void __fastcall btnStergereRClick(TObject *Sender);
        void __fastcall btnAdaugaAClick(TObject *Sender);
        void __fastcall btnStergereTClick(TObject *Sender);
        void __fastcall btnAdaugaHClick(TObject *Sender);
        void __fastcall SPSbttnClick(TObject *Sender);
        void __fastcall SOSbttnClick(TObject *Sender);
        void __fastcall SPDbttnClick(TObject *Sender);
        void __fastcall SODbttnClick(TObject *Sender);
        void __fastcall SPAbttnClick(TObject *Sender);
        void __fastcall SOAbttnClick(TObject *Sender);
        void __fastcall ACAbttnClick(TObject *Sender);
        void __fastcall ASAbttnClick(TObject *Sender);
        void __fastcall PIPbttnClick(TObject *Sender);
        void __fastcall AIAbttnClick(TObject *Sender);
        void __fastcall AIAvaluebttnClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFMain *FMain;
//---------------------------------------------------------------------------
#endif
