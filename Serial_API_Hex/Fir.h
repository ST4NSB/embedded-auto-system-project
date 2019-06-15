//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
class Fir : public TThread
{
private:
protected:
        void __fastcall Execute();
public:
        __fastcall Fir(bool CreateSuspended);
        void __fastcall UpdateCaption();
};
//---------------------------------------------------------------------------
#endif
