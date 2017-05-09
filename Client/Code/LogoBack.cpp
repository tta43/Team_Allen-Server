#include "stdafx.h"
#include "LogoBack.h"

#include "Export_Function.h"
#include "VIBuffer.h"
#include "Texture.h"
#include "Frame.h"

CLogoBack::CLogoBack(LPDIRECT3DDEVICE9 pDevice)
	: Engine::CGameObject(pDevice)
	, m_pBuffer(NULL)
	, m_pTexture(NULL)
	, m_pFrame(nullptr)
{

}

CLogoBack::~CLogoBack(void)
{
	Release();
}

HRESULT CLogoBack::Initialize(void)
{
	HRESULT		hr = NULL;

	hr = AddComponent();
	FAILED_CHECK(hr);

	return S_OK;
}

void CLogoBack::Update(void)
{
	Engine::CGameObject::Update();
}

void CLogoBack::Render(void)
{
	m_pTexture->Render(0, (DWORD)m_pFrame->m_tFrame.fFrame);
	m_pBuffer->Render();
}

CLogoBack* CLogoBack::Create(LPDIRECT3DDEVICE9 pDevice)
{
	CLogoBack*		pLogo = new CLogoBack(pDevice);
	if (FAILED(pLogo->Initialize()))
	{
		Engine::Safe_Delete(pLogo);
	}

	return pLogo;
}

HRESULT CLogoBack::AddComponent(void)
{
	Engine::CComponent*		pCompontent = NULL;

	pCompontent = m_pFrame = Engine::CFrame::Create(Engine::FRAME(0.f, 38.f, 38.f));
	NULL_CHECK_RETURN(m_pFrame, E_FAIL);
	m_mapComponent.insert(MAPCOMPONENT::value_type(L"Frame", pCompontent));

	pCompontent = Engine::Get_ResourceMgr()->CloneResource(Engine::RESOURCE_STATIC, L"Buffer_RcTex");
	m_pBuffer = dynamic_cast<Engine::CVIBuffer*>(pCompontent);
	NULL_CHECK_RETURN(pCompontent, E_FAIL);
	m_mapComponent.insert(MAPCOMPONENT::value_type(L"Buffer", pCompontent));

	pCompontent = Engine::Get_ResourceMgr()->CloneResource(Engine::RESOURCE_DYNAMIC, L"Texture_LogoBack");
	m_pTexture = dynamic_cast<Engine::CTexture*>(pCompontent);
	NULL_CHECK_RETURN(pCompontent, E_FAIL);
	m_mapComponent.insert(MAPCOMPONENT::value_type(L"Texture", pCompontent));

	return S_OK;
}

void CLogoBack::Release(void)
{

}
