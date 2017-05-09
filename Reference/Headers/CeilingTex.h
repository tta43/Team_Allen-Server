/*!
* \file CeilingTex.h
* \date 2017/05/02 15:20
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

#ifndef CeilingTex_h__
#define CeilingTex_h__

#include "VIBuffer.h"

BEGIN(Engine)

class ENGINE_DLL CCeilingTex
	: public CVIBuffer
{
private:
	explicit CCeilingTex(LPDIRECT3DDEVICE9 pDevice);

public:
	virtual ~CCeilingTex(void);

public:
	virtual CResources* CloneResource(void);

public:
	virtual HRESULT CreateBuffer(const WORD& wCntX, const WORD& wCntY, const WORD& wCntZ, const WORD& wItv);

public:
	static CCeilingTex* Create(LPDIRECT3DDEVICE9 pDevice
		, const WORD& wCntX, const WORD& wCntY, const WORD& wCntZ, const WORD& wItv);
};

END

#endif // CeilingTex_h__