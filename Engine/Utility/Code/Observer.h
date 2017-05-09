#pragma once

#include "Engine_Include.h"

BEGIN(Engine)

class ENGINE_DLL CObserver abstract
{
public:
	virtual void Update(int _iMessage, void* _pData)PURE;

public:
	CObserver(void);
	virtual ~CObserver(void);
};

END
