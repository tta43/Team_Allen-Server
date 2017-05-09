#pragma once

#include "../../Reference/Headers/GraphicDev.h"
#include "../../Reference/Headers/TimeMgr.h"
#include "../../Reference/Headers/Mouse.h"

BEGIN(Engine)

inline CGraphicDev* Get_GraphicDev(void);
inline CTimeMgr* Get_TimeMgr(void);
inline CMouse* Get_Mouse(void);

#include "Export_System.inl"

END