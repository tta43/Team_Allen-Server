#include "stdafx.h"
#include "Player.h"

#include "Include.h"
#include "Export_Function.h"
#include "VIBuffer.h"
#include "Texture.h"
#include "Transform.h"
#include "Camera.h"

CPlayer::CPlayer(LPDIRECT3DDEVICE9 pDevice)
	: Engine::CGameObject(pDevice)
	, m_pBuffer(NULL)
	, m_pTexture(NULL)
{

}

CPlayer::~CPlayer(void)
{
	Release();
}

HRESULT CPlayer::Initialize(void)
{
	HRESULT		hr = NULL;

	hr = AddComponent();
	FAILED_CHECK(hr);

	m_pInfo->m_vPos = D3DXVECTOR3(10.f, 10.f, 0.f);

	return S_OK;
}

void CPlayer::Update(void)
{
	D3DXVec3TransformNormal(&m_pInfo->m_vDir, &g_Look, &m_pInfo->m_matWorld);

	KeyCheck();

	Engine::CGameObject::Update();
}

void CPlayer::Render(void)
{
	/*m_pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	m_pDevice->SetTransform(D3DTS_WORLD, &m_pInfo->m_matWorld);

	m_pTexture->Render(0, 0);
	m_pBuffer->Render();
	m_pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);*/
}

CPlayer* CPlayer::Create(LPDIRECT3DDEVICE9 pDevice)
{
	CPlayer*		pLogo = new CPlayer(pDevice);
	if (FAILED(pLogo->Initialize()))
	{
		Engine::Safe_Delete(pLogo);
	}

	return pLogo;
}

HRESULT CPlayer::AddComponent(void)
{
	Engine::CComponent*		pCompontent = NULL;

	pCompontent = m_pInfo = Engine::CTransform::Create(g_Look);
	NULL_CHECK_RETURN(m_pInfo, E_FAIL);
	m_mapComponent.insert(MAPCOMPONENT::value_type(L"Transform", pCompontent));

	// Ä«¸Þ¶ó
	pCompontent = Engine::CCamera::Create(this);
	NULL_CHECK_RETURN(pCompontent, E_FAIL);
	m_mapComponent.insert(MAPCOMPONENT::value_type(L"Camera", pCompontent));

	pCompontent = Engine::Get_ResourceMgr()->CloneResource(Engine::RESOURCE_STATIC, L"Buffer_RcTex");
	m_pBuffer = dynamic_cast<Engine::CVIBuffer*>(pCompontent);
	NULL_CHECK_RETURN(pCompontent, E_FAIL);
	m_mapComponent.insert(MAPCOMPONENT::value_type(L"Buffer", pCompontent));

	pCompontent = Engine::Get_ResourceMgr()->CloneResource(Engine::RESOURCE_STATIC, L"Texture_Player");
	m_pTexture = dynamic_cast<Engine::CTexture*>(pCompontent);
	NULL_CHECK_RETURN(pCompontent, E_FAIL);
	m_mapComponent.insert(MAPCOMPONENT::value_type(L"Texture", pCompontent));

	return S_OK;
}

void CPlayer::Release(void)
{

}

void CPlayer::KeyCheck(void)
{
	
}
