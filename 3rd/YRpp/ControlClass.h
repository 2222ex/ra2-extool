#pragma once

#include <GadgetClass.h>

class NOVTABLE ControlClass : public GadgetClass
{
public:
	virtual unsigned int const GetID() override { return ID; }
	virtual bool Draw(bool bForced) override { JMP_THIS(0x48E620); }
	virtual bool Action(GadgetFlag Flags, DWORD* pKey, KeyModifier Modifier) override { JMP_THIS(0x48E5A0); }
	virtual void MakePeer(GadgetClass& gadget) { SendTo = &gadget; }

	//Non virtual

	//Statics

	//Constructors
	ControlClass(unsigned int nID, int nX, int nY, int nWidth, int nHeight, GadgetFlag eFlag, bool bSticky) noexcept
		: ControlClass(noinit_t()) {
		JMP_THIS(0x48E520);
	}

	ControlClass(ControlClass& another) noexcept
		: ControlClass(noinit_t()) {
		JMP_THIS(0x48E570);
	}

protected:
	explicit __forceinline ControlClass(noinit_t)  noexcept
		: GadgetClass(noinit_t())
	{
	}

	//Properties
public:

	int ID;
	GadgetClass* SendTo; // Peer
};
