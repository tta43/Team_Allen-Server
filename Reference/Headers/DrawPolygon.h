#ifndef DrawPolygon_h__
#define DrawPolygon_h__

#include "Engine_Include.h"

BEGIN(Engine)

class ENGINE_DLL CDrawPolygon
{
public:
	DECLARE_SINGLETON(CDrawPolygon)

private:
	CDrawPolygon(void);
public:
	~CDrawPolygon(void);

public:
	void DrawPolygon(LPDIRECT3DDEVICE9 pDevice, D3DXVECTOR3 vec3);

	LPDIRECT3DVERTEXBUFFER9 GetVB(void) { return m_pVB; }
	LPDIRECT3DINDEXBUFFER9 GetIB(void) { return m_pIB; }

private:
	LPDIRECT3DDEVICE9			m_pDevice;

	LPDIRECT3DVERTEXBUFFER9		m_pVB;
	LPDIRECT3DINDEXBUFFER9		m_pIB;
};

END

#endif
