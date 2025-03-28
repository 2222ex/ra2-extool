#pragma once

#include <GeneralDefinitions.h>
#include <YRPPCore.h>

class LinkClass
{
public:
	//Destructor
	virtual ~LinkClass() JMP_THIS(0x5565A0);

	//LinkClass
	virtual LinkClass* GetNext() { return Next; };
	virtual LinkClass* GetPrev() { return Previous; };
	virtual LinkClass* Add(LinkClass& another) JMP_THIS(0x5566A0);
	virtual LinkClass* AddTail(LinkClass& another) JMP_THIS(0x556700);
	virtual LinkClass* AddHead(LinkClass& another) JMP_THIS(0x5566D0);
	virtual LinkClass* HeadOfList() JMP_THIS(0x556640);
	virtual LinkClass* TailOfList() JMP_THIS(0x556670);
	virtual void Zap() JMP_THIS(0x5565F0);
	virtual LinkClass* Remove() JMP_THIS(0x556730);

	//Non virtual
	LinkClass& operator=(LinkClass& another) { JMP_THIS(0x556600); }

	//Constructors
	LinkClass(LinkClass& another) { JMP_THIS(0x556550); }

protected:
	explicit __forceinline LinkClass(noinit_t)  noexcept
	{
	}

	//Properties
public:

	LinkClass* Next;
	LinkClass* Previous;
};
