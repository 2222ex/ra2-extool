#pragma once

#include <Memory.h>

enum class FieldDataType : unsigned short
{
	CHAR = 1,
	UNSINGED_CHAR = 2,
	SHORT = 3,
	UNSIGNED_SHORT = 4,
	INT = 5,
	UNSINGED_INT = 6,
	STRING = 7,
	CHUNK = 20,
};

#pragma pack(push, 1)
class FieldClass
{
public:
	FieldClass() = default;

	FieldClass(char* id, char data)
	{
		JMP_THIS(0x4CB580);
	}

	FieldClass(char* id, unsigned char data)
	{
		JMP_THIS(0x4CB5E0);
	}

	FieldClass(char* id, short data)
	{
		JMP_THIS(0x4CB640);
	}

	FieldClass(char* id, unsigned short data)
	{
		JMP_THIS(0x4CB6A0);
	}

	FieldClass(char* id, int data)
	{
		JMP_THIS(0x4CB700);
	}

	FieldClass(char* id, unsigned int data)
	{
		JMP_THIS(0x4CB760);
	}

	FieldClass(char* id, char* data)
	{
		JMP_THIS(0x4CB7C0);
	}

	FieldClass(char* id, void* data, int length)
	{
		JMP_THIS(0x4CB830);
	}

	~FieldClass()
	{
		JMP_THIS(0x4CB890);
	}

	void HostToNet()
	{
		JMP_THIS(0x4CB8B0);
	}

	void NetToHost()
	{
		JMP_THIS(0x4CB920);
	}

	// Properties
	char ID[4];
	FieldDataType DataType;
	unsigned short Size;
	void* Data;
	FieldClass* Next;
};
static_assert(sizeof(FieldClass) == 0x10);

class PacketClass
{
public:
	void AddField(FieldClass* pField)
	{
		pField->Next = this->Head;
		this->Head = pField;
	}

	template<typename T, typename... Args>
	void AddField(char* id, T data, Args... args)
	{
		auto pField = GameCreate<FieldClass>(id, data, args...);
		this->AddField(pField);
	}

	// Properties
	short Size;
	short ID;
	FieldClass* Head;
	FieldClass* Current;
};
static_assert(sizeof(PacketClass) == 0x0C);

#pragma pack(pop)