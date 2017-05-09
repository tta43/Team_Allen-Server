#include "Scene.h"
#include "Layer.h"

Engine::CScene::CScene(LPDIRECT3DDEVICE9 pDevice)
	: m_pDevice(pDevice)
{

}

Engine::CScene::~CScene(void)
{
	Release();
}

HRESULT Engine::CScene::InitScene(void)
{
	return S_OK;
}

void Engine::CScene::Update(void)
{
	MAPLAYER::iterator	iter = m_mapLayer.begin();
	MAPLAYER::iterator	iter_end = m_mapLayer.end();

	for (; iter != iter_end; ++iter)
	{
		iter->second->Update();
	}
}

void Engine::CScene::Render(void)
{
	MAPLAYER::iterator	iter = m_mapLayer.begin();
	MAPLAYER::iterator	iter_end = m_mapLayer.end();

	for (; iter != iter_end; ++iter)
	{
		iter->second->Render();
	}
}

void Engine::CScene::Release(void)
{
	for_each(m_mapLayer.begin(), m_mapLayer.end(), CDeleteMap());
	m_mapLayer.clear();
}

