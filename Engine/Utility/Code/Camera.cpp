#include "Camera.h"
#include "Pipeline.h"
#include "Export_Function.h"
#include "GameObject.h"
#include "Transform.h"
#include "MathMgr.h"

Engine::CCamera::CCamera(CGameObject* pGameObject)
	:m_pGameObject(pGameObject)
	,m_vecEye(D3DXVECTOR3(25.f, 25.f, -20.f))
	, m_fDistance(1000.f)
	,m_vecAt(D3DXVECTOR3(1025.f, 25.f, -20.f))
	,m_fAngle(90.f)
{
}

Engine::CCamera::~CCamera(void)
{
}

void Engine::CCamera::Update(void)
{
	KeyInput();

	D3DXMATRIX	matRotY,matView;

	D3DXVECTOR3 vecMouse, vecAt;
	vecMouse = Engine::Get_Mouse()->GetMousePos();

	m_fAngle = (1600.f - vecMouse.x) / 1600.f * 180.f;

	D3DXMatrixRotationY(&matRotY, D3DXToRadian(-m_fAngle));

	// m_vecAt을 Y축 회전
	vecAt = m_vecAt + m_vecEye;

	vecAt -= m_vecEye;
	D3DXVec3TransformCoord(&vecAt, &vecAt, &matRotY);
	vecAt += m_vecEye;

	m_vecDir = vecAt - m_vecEye;

	Engine::CPipeline::MakeViewSpaceMatrix(&m_matView, &m_vecEye, &vecAt, &D3DXVECTOR3(0.f, 1.f, 0.f));

	Get_GraphicDev()->GetDevice()->SetTransform(D3DTS_VIEW, &m_matView);
}

void Engine::CCamera::KeyInput(void)
{
	float	fTime = Engine::Get_TimeMgr()->GetTime();

	D3DXVec3Normalize(&m_vecDir, &m_vecDir);

	if (GetAsyncKeyState('W'))
	{
		m_vecEye += m_vecDir * 100.f * fTime;
	}

	if (GetAsyncKeyState('S'))
	{
		m_vecEye += -m_vecDir * 100.f * fTime;
	}

	if (GetAsyncKeyState('A'))
	{
		
	}

	if (GetAsyncKeyState('D'))
	{

	}
}

Engine::CCamera* Engine::CCamera::Create(CGameObject* pGameObject)
{
	return new CCamera(pGameObject);
}

