#pragma once

#include <GeneralDefinitions.h>

class BeaconClass
{
public:
    static constexpr reference<BeaconClass, 0x89C3B0u> const Instance{};

	~BeaconClass()
		{ JMP_THIS(0x430980); }

	void Place(char house_id, int coor_x, int coor_y, int coor_z, char a6)
    {
        JMP_THIS(0x430BA0)
    }
    void DeleteAll(int house_id)
    {
        JMP_THIS(0x431410)
    }
    void Delete(char playerid, char index)
    {
        JMP_THIS(0x4311C0)
    }
    void SendText(wchar_t *Source, int a3, int a4, char a5)
    {
        JMP_THIS(0x431450)
    }
    struct BeaconEach
    {
        CoordStruct coord;
        bool maybe_select_state;
        wchar_t message[128];
        int house_id;
    };

public:

	BeaconEach *beacon[24];
    int BeaconNum;
    int PBEACON_Width;
    int PBEACON_Height;
    int PBEACON_Frame;
    int RDRBEACN_Width;
    int RDRBEACN_Height;
    int RDRBEACN_Frame;
    int RDRBEACN_4Frame;
    CoordStruct coord;
    char unknownData[132];
    __int16 house_id;

};
