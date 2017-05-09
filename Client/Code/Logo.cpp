#include "stdafx.h"
#include "Logo.h"

#include "Include.h"
#include "Export_Function.h"
#include "SceneSelector.h"
#include "Layer.h"
#include "GameObject.h"
#include "LogoBack.h"

CLogo::CLogo(LPDIRECT3DDEVICE9 pDevice)
	: Engine::CScene(pDevice)
{

}

CLogo::~CLogo(void)
{
	Release();
}

HRESULT CLogo::Initialize(void)
{
	HRESULT		hr = NULL;

	// 스레드에서 하면 좋을듯(디바이스 설정!)
	hr = Add_Buffer();
	hr = Add_Texture();

	hr = Add_Environment_Layer();	FAILED_CHECK(hr);
	hr = Add_GameLogic_Layer();		FAILED_CHECK(hr);
	hr = Add_UI_Layer();			FAILED_CHECK(hr);

	return S_OK;
}

void CLogo::Update(void)
{
	Engine::CScene::Update();
}

void CLogo::Render(void)
{
	if (GetAsyncKeyState(VK_RETURN)) // Render에 있는 이유 : Stage의 Update부터 시작하기 위해
	{
		Engine::Get_Management()->SceneChange(CSceneSelector(SCENE_STAGE), m_pDevice);
		return;
	}

	Engine::CScene::Render();
}

CLogo* CLogo::Create(LPDIRECT3DDEVICE9 pDevice)
{
	CLogo*	pScene = new CLogo(pDevice);
	if (FAILED(pScene->Initialize()))
		Safe_Delete(pScene);

	return pScene;
}

HRESULT CLogo::Add_Environment_Layer(void)
{
	return S_OK;
}

HRESULT CLogo::Add_GameLogic_Layer(void)
{
	Engine::CLayer*		pLayer = Engine::CLayer::Create();
	NULL_CHECK_RETURN(pLayer, E_FAIL);

	Engine::CGameObject*		pGameObject = NULL;

	pGameObject = CLogoBack::Create(m_pDevice);
	pLayer->AddObject(L"LogoBack", pGameObject);

	m_mapLayer.insert(MAPLAYER::value_type(LAYER_GAMELOGIC, pLayer));
	return S_OK;
}

HRESULT CLogo::Add_UI_Layer(void)
{
	return S_OK;
}

void CLogo::Release(void)
{
	Engine::Get_ResourceMgr()->ResetDynamic();
}

HRESULT CLogo::Add_Buffer(void)
{
	HRESULT		hr = NULL;

	hr = Engine::Get_ResourceMgr()->AddBuffer(m_pDevice, Engine::RESOURCE_STATIC, 
		Engine::BUFFER_TRICOLOR, L"Buffer_TriColor");
	FAILED_CHECK(hr);

	hr = Engine::Get_ResourceMgr()->AddBuffer(m_pDevice, Engine::RESOURCE_STATIC, 
		Engine::BUFFER_RCCOLOR, L"Buffer_RcColor");
	FAILED_CHECK(hr);

	hr = Engine::Get_ResourceMgr()->AddBuffer(m_pDevice, Engine::RESOURCE_STATIC,
		Engine::BUFFER_RCTEX, L"Buffer_RcTex");
	FAILED_CHECK(hr);

	hr = Engine::Get_ResourceMgr()->AddBuffer(m_pDevice, Engine::RESOURCE_STATIC,
		Engine::BUFFER_TERRAINTEX, L"Buffer_TerrainTex", 50, VTXCNTY, 700, VTXITV, D3DXVECTOR3(0.f, 1.f, 0.f));
	FAILED_CHECK(hr);

	hr = Engine::Get_ResourceMgr()->AddBuffer(m_pDevice, Engine::RESOURCE_STATIC,
		Engine::BUFFER_WALLTEX, L"Buffer_LeftWallTex", VTXCNTX, VTXCNTY, 700, VTXITV, D3DXVECTOR3(1.f, 0.f, 0.f));
	FAILED_CHECK(hr);

	hr = Engine::Get_ResourceMgr()->AddBuffer(m_pDevice, Engine::RESOURCE_STATIC,
		Engine::BUFFER_WALLTEX, L"Buffer_RightWallTex", VTXCNTX, VTXCNTY, 700, VTXITV, D3DXVECTOR3(-1.f, 0.f, 0.f));
	FAILED_CHECK(hr);

	hr = Engine::Get_ResourceMgr()->AddBuffer(m_pDevice, Engine::RESOURCE_STATIC,
		Engine::BUFFER_WALLXYTEX, L"Buffer_FrontWallTex", VTXCNTX, VTXCNTY, VTXCNTZ, VTXITV, D3DXVECTOR3(0.f, 0.f, -1.f));
	FAILED_CHECK(hr);

	hr = Engine::Get_ResourceMgr()->AddBuffer(m_pDevice, Engine::RESOURCE_STATIC,
		Engine::BUFFER_TERRAINTEX, L"Buffer_CeilingTex", 50, VTXCNTY, 700, VTXITV, D3DXVECTOR3(0.f, -1.f, 0.f));
	FAILED_CHECK(hr);
		
	return S_OK;
}

HRESULT CLogo::Add_Texture(void)
{
	HRESULT		hr = NULL;

	// --- Logo ---
	hr = Engine::Get_ResourceMgr()->AddTexture(m_pDevice, Engine::RESOURCE_DYNAMIC, Engine::TEXTURE_NORMAL, 
		L"Texture_LogoBack", L"../bin/Texture/LogoBack/LogoBack_%d.png", 38);
	FAILED_CHECK(hr);

	// --- Stage ---
	hr = Engine::Get_ResourceMgr()->AddTexture(m_pDevice, Engine::RESOURCE_STATIC, Engine::TEXTURE_NORMAL
		, L"Texture_Player", L"../bin/Texture/Player%d.png", 1);
	FAILED_CHECK(hr);

	hr = Engine::Get_ResourceMgr()->AddTexture(m_pDevice, Engine::RESOURCE_STATIC, Engine::TEXTURE_NORMAL
		, L"Texture_Terrain", L"../bin/Texture/Terrain/Terrain%d.png", 1);
	FAILED_CHECK(hr);

	hr = Engine::Get_ResourceMgr()->AddTexture(m_pDevice, Engine::RESOURCE_STATIC, Engine::TEXTURE_CUBE
		, L"Texture_Tile", L"../bin/Texture/Tile/Tile%d.dds", 23);
	FAILED_CHECK(hr);

	hr = Engine::Get_ResourceMgr()->AddTexture(m_pDevice, Engine::RESOURCE_STATIC, Engine::TEXTURE_NORMAL
		, L"Texture_Floor", L"../bin/Texture/Map/Floor%d.bmp", 1);
	FAILED_CHECK(hr);

	hr = Engine::Get_ResourceMgr()->AddTexture(m_pDevice, Engine::RESOURCE_STATIC, Engine::TEXTURE_NORMAL
		, L"Texture_Wall", L"../bin/Texture/Map/Wall%d.bmp", 1);
	FAILED_CHECK(hr);

	hr = Engine::Get_ResourceMgr()->AddTexture(m_pDevice, Engine::RESOURCE_STATIC, Engine::TEXTURE_NORMAL
		, L"Texture_Ceiling", L"../bin/Texture/Map/Ceiling%d.bmp", 1);
	FAILED_CHECK(hr);

	return S_OK;
}

