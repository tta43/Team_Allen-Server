#ifndef Camera_h__
#define Camera_h__

#include "Component.h"

BEGIN(Engine)

class CGameObject;

class ENGINE_DLL CCamera
	: public CComponent
{
private:
	explicit CCamera(CGameObject* pGameObject);

public:
	virtual ~CCamera(void);

public:
	virtual void Update(void);
	void KeyInput(void);

public:
	static CCamera* Create(CGameObject* pGameObject);

private:
	CGameObject* m_pGameObject;

	D3DXVECTOR3 m_vecEye;
	D3DXVECTOR3 m_vecAt;
	D3DXVECTOR3 m_vecDir;

	float m_fDistance;
	float m_fAngle;

private:
	D3DXMATRIX m_matView;

};

END

#endif // Camera_h__