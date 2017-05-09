#include "GameObject.h"
#include "Component.h"

Engine::CGameObject::CGameObject(LPDIRECT3DDEVICE9 pDevice)
	: m_pDevice(pDevice)
	,m_pObserver(nullptr)
	,m_matPipeline(D3DXVECTOR3(0.f, 0.f, 0.f))
	,m_pInfo(nullptr)
{

}

Engine::CGameObject::~CGameObject(void)
{
	Release();
}

void Engine::CGameObject::Update(void)
{
	MAPCOMPONENT::iterator iter = m_mapComponent.begin();
	MAPCOMPONENT::iterator iter_end = m_mapComponent.end();

	for (; iter != iter_end; ++iter)
	{
		iter->second->Update();
	}
}

void Engine::CGameObject::Render(void)
{

}

void Engine::CGameObject::Release(void)
{
	for_each(m_mapComponent.begin(), m_mapComponent.end(), CDeleteMap());
	m_mapComponent.clear();
}
