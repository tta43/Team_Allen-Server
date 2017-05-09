#pragma once

#include "Engine_Include.h"

BEGIN(Engine)

class ENGINE_DLL CComponent
{
protected :
	CComponent(void);

public:
	~CComponent(void);

public:
	virtual void Update(void);

};

END