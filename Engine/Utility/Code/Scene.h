#pragma once

#include "Engine_Include.h"

BEGIN(Engine)

class CLayer;

class ENGINE_DLL CScene
{
protected:
	explicit CScene(LPDIRECT3DDEVICE9 pDevice);
public:
	virtual ~CScene(void);

public:
	virtual HRESULT	InitScene(void);
	virtual void	Update(void);
	virtual void	Render(void);

private:
	virtual void	Release(void);

protected:
	LPDIRECT3DDEVICE9		m_pDevice;

protected:
	typedef map<WORD, CLayer*>		MAPLAYER;
	MAPLAYER		m_mapLayer;

};

END