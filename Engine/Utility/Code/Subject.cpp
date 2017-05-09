#include "Subject.h"
#include "observer.h"

void Engine::CSubject::SetWatch(CObserver* pObserver)
{
	m_listObserver.push_back(pObserver);
}

void Engine::CSubject::UnWatch(CObserver* pObserver)
{
	list<CObserver*>::iterator iter = m_listObserver.begin();

	for (iter; iter != m_listObserver.end(); )
	{
		if ((*iter) == pObserver)
		{
			Safe_Delete(*iter);
			iter = m_listObserver.erase(iter);
		}
		else
			++iter;
	}
}

void Engine::CSubject::Notify(int iMessage, void* pData /*= NULL */)
{
	list<CObserver*>::iterator iter = m_listObserver.begin();

	for (iter; iter != m_listObserver.end(); ++iter)
	{
		(*iter)->Update(iMessage, pData);
	}
}

void Engine::CSubject::Release(void)
{
	list<CObserver*>::iterator iter = m_listObserver.begin();

	for (iter; iter != m_listObserver.end(); ++iter)
	{
		Safe_Delete(*iter);
	}

	m_listObserver.clear();
}

Engine::CSubject::CSubject(void)
{
}

Engine::CSubject::~CSubject(void)
{
	Release();
}
