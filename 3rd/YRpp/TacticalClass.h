#pragma once

#include <GeneralDefinitions.h>
#include <GeneralStructures.h>
#include <AbstractClass.h>
#include <ColorScheme.h>
#include <Helpers/CompileTime.h>

struct TacticalSelectableStruct
{
	TechnoClass* Techno;
	int X;
	int Y;
};

class DSurface;
class CellClass;

class NOVTABLE TacticalClass : public AbstractClass
{
public:
	static constexpr reference<TacticalClass*, 0x887324u> const Instance{};

	virtual bool sub_6DBB60(CoordStruct const& a2, CoordStruct const& a3, COLORREF a4, DWORD dwUnk) R0;

	void SetTacticalPosition(CoordStruct* pCoord)
		{ JMP_THIS(0x6D6070); }

	CellStruct* CoordsToCell(CellStruct* pDest, CoordStruct* pSource)
		{ JMP_THIS(0x6D6590); }

	// returns whether coords are visible at the moment
	bool CoordsToClient(CoordStruct const& coords, Point2D* pOutClient) const
		{ JMP_THIS(0x6D2140); }

	Point2D* CoordsToScreen(Point2D* pDest, CoordStruct* pSource)
		{ JMP_THIS(0x6D1F10); }

	CoordStruct* ClientToCoords(CoordStruct* pOutBuffer, Point2D const& client) const
		{ JMP_THIS(0x6D2280); }

	CoordStruct ClientToCoords(Point2D const& client) const {
		CoordStruct buffer;
		this->ClientToCoords(&buffer, client);
		return buffer;
	}

	char GetOcclusion(const CellStruct& cell, bool fog) const
		{ JMP_THIS(0x6D8700); }

	Point2D * AdjustForZShapeMove(Point2D* pDest, Point2D* pClient)
		{ JMP_THIS(0x6D1FE0); }

	// convert xyz height to xy height?
	static int __fastcall AdjustForZ(int Height)
		{ JMP_STD(0x6D20E0); }

	void FocusOn(CoordStruct* pDest, int Velocity)
		{ JMP_THIS(0x6D2420); }


	// called when area needs to be marked for redrawing due to external factors
	// - alpha lights, terrain changes like cliff destruction, etc
	void RegisterDirtyArea(RectangleStruct Area, bool bUnk)
		{ JMP_THIS(0x6D2790); }

	void RegisterCellAsVisible(CellClass* pCell)
		{ JMP_THIS(0x6DA7D0) };

	static int DrawTimer(int index, ColorScheme *Scheme, int Time, wchar_t *Text, Point2D *someXY1, Point2D *someXY2)
		{ JMP_STD(0x64DB50); }

	void AddSelectable(TechnoClass* pTechno, int x, int y)
		{ JMP_THIS(0x6D9EF0) };

	/*
	*   TacticalRenderMode_0_ALL = 0x0,
	*	TacticalRenderMode_TERRAIN = 0x1,
	*	TacticalRenderMode_MOVING_ANIMATING = 0x2,
	*	TacticalRenderMode_3_ALL = 0x3,
	*	TacticalRenderMode_STOPDRAWING = 0x4,
	*	TacticalRenderMode_5 = 0x5,
	*/
	void Render(DSurface* pSurface, bool flag, int eMode)
		{ JMP_THIS(0x6D3D10); }

public:

	wchar_t ScreenText[64];
	int EndGameGraphicsFrame;
	int LastAIFrame;
	bool field_AC;
	bool field_AD;
	PROTECTED_PROPERTY(char, gap_AE[2]);
	Point2D TacticalPos;
	Point2D LastTacticalPos;
	double ZoomInFactor;
	Point2D Point_C8;
	Point2D Point_D0;
	float field_D8;
	float field_DC;
	int VisibleCellCount;
	CellClass * VisibleCells [800];
	Point2D TacticalCoord1;
	DWORD field_D6C;
	DWORD field_D70;
	Point2D TacticalCoord2;
	bool field_D7C;
	bool Redrawing; // set while redrawing - cheap mutex // TacticalPosUpdated
	PROTECTED_PROPERTY(char, gap_D7E[2]);
	RectangleStruct ContainingMapCoords;
	LTRBStruct Band;
	DWORD MouseFrameIndex;
	CDTimerClass StartTime;
	int SelectableCount;
	Matrix3D Unused_Matrix3D;
	Matrix3D IsoTransformMatrix;
	DWORD field_E14;

};
