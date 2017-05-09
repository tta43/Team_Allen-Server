#pragma once

#include "engine_include.h"

BEGIN(Engine)

class CObserver;

class ENGINE_DLL CSubject
{
protected:
	list<CObserver*>		m_listObserver;

public:
	//관찰자를 등록하자.
	virtual void SetWatch(CObserver* pObserver);

	//관찰자를 해제하자.
	virtual void UnWatch(CObserver* pObserver);

	//갱신한 데이터를 알려주는 함수.
	virtual void Notify(int iMessage, void* pData = NULL);

	void Release(void);

public:
	CSubject(void);
	virtual ~CSubject(void);
};

END