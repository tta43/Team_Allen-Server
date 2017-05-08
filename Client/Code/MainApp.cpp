#include "stdafx.h"
#include "MainApp.h"

#include "Export_Function.h"
#include "VIBuffer.h"
#include "SceneSelector.h"

CMainApp::CMainApp(void)
: m_pGraphicDev(Engine::CGraphicDev::GetInstance())
, m_pDevice(NULL)
{
	// Å×½ºÆ®
}

CMainApp::~CMainApp(void)
{
	Release();
}

HRESULT CMainApp::InitApp(void)
{
	HRESULT hr = m_pGraphicDev->InitGraphicDev(Engine::CGraphicDev::MODE_WIN
		, g_hWnd, WINCX, WINCY);

	m_pDevice = m_pGraphicDev->GetDevice();

	m_pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
	
	Engine::Get_TimeMgr()->InitTime();

	hr = Engine::Get_Management()->InitManagement(m_pDevice);
	FAILED_CHECK(hr);
	hr = Engine::Get_Management()->SceneChange(CSceneSelector(SCENE_LOGO), m_pDevice);
	FAILED_CHECK(hr);
	Engine::Get_Mouse()->Initialize(g_hWnd);

	return S_OK;
}

void CMainApp::Update(void)
{
	Engine::Get_TimeMgr()->SetTime();
	Engine::Get_Management()->Update();
}

void CMainApp::Render(void)
{
	Engine::Get_Management()->Render(Engine::Get_TimeMgr()->GetTime());
}

CMainApp* CMainApp::Create(void)
{
	CMainApp*	pMainApp = new CMainApp;
	if (FAILED(pMainApp->InitApp()))
	{
		delete pMainApp;
		pMainApp = nullptr;
	}
	return pMainApp;
}

void CMainApp::Release(void)
{
	Engine::Get_Management()->DestroyInstance();
	Engine::Get_GraphicDev()->DestroyInstance();
	Engine::Get_TimeMgr()->DestroyInstance();
	Engine::Get_ResourceMgr()->DestroyInstance();
}