/*!
* \file GameObject.h
* \date 2017/04/27 15:46
*
* \author Administrator
* Contact: user@company.com
*
* \brief
*
* TODO: long description
*
* \note
*/

#ifndef GameObject_h__
#define GameObject_h__

#include "Engine_Include.h"

BEGIN(Engine)

class CComponent;
class CObserver;
class CTransform;

class ENGINE_DLL CGameObject
{
protected:
	explicit CGameObject(LPDIRECT3DDEVICE9 pDevice);

public:
	virtual ~CGameObject(void);

public:
	virtual void Update(void);
	virtual void Render(void);

private:
	void Release(void);

protected:
	LPDIRECT3DDEVICE9		m_pDevice;

public:
	Engine::CTransform* GetTransform(void) { return m_pInfo; }

protected:
	typedef map<wstring, CComponent*>		MAPCOMPONENT;
	MAPCOMPONENT		m_mapComponent;

	CObserver*			m_pObserver;
	D3DXMATRIX	m_matPipeline;

	Engine::CTransform*		m_pInfo;
};

END

#endif // GameObject_h__