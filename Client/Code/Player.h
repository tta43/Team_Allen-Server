/*!
* \file Player.h
* \date 2017/05/01 15:35
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

#ifndef Player_h__
#define Player_h__

#include "GameObject.h"

namespace Engine
{
	class CVIBuffer;
	class CTexture;
	class CTransform;
}

class CPlayer
	: public Engine::CGameObject
{
private:
	explicit CPlayer(LPDIRECT3DDEVICE9 pDevice);

public:
	virtual ~CPlayer(void);

public:
	virtual void Update(void);
	virtual void Render(void);

public:
	static CPlayer* Create(LPDIRECT3DDEVICE9 pDevice);

private:
	HRESULT Initialize(void);
	HRESULT AddComponent(void);
	void Release(void);
	void KeyCheck(void);


private:
	Engine::CVIBuffer*		m_pBuffer;
	Engine::CTexture*		m_pTexture;
	
};

#endif // Player_h__