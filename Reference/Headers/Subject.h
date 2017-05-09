#pragma once

#include "engine_include.h"

BEGIN(Engine)

class CObserver;

class ENGINE_DLL CSubject
{
protected:
	list<CObserver*>		m_listObserver;

public:
	//�����ڸ� �������.
	virtual void SetWatch(CObserver* pObserver);

	//�����ڸ� ��������.
	virtual void UnWatch(CObserver* pObserver);

	//������ �����͸� �˷��ִ� �Լ�.
	virtual void Notify(int iMessage, void* pData = NULL);

	void Release(void);

public:
	CSubject(void);
	virtual ~CSubject(void);
};

END