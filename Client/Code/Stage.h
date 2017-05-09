/*!
* \file Stage.h
* \date 2017/04/27 16:48
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

#ifndef Stage_h__
#define Stage_h__

#include "Scene.h"

class CStage
	: public Engine::CScene
{
public:
	enum LAYERID { LAYER_ENVIROMENT, LAYER_GAMELOGIC, LAYER_UI };

private:
	explicit CStage(LPDIRECT3DDEVICE9 pDevice);

public:
	virtual ~CStage(void);

public:
	virtual void Update(void);
	virtual void Render(void);

public:
	static CStage* Create(LPDIRECT3DDEVICE9 pDevice);

private:
	HRESULT	Initialize(void);
	HRESULT Add_Environment_Layer(void);
	HRESULT Add_GameLogic_Layer(void);
	HRESULT Add_UI_Layer(void);

	void Add_Light(D3DXVECTOR3 vecPos);
	void Release(void);

private:
	D3DXMATRIX m_matProject;
	int		   m_iLightCount;
};


#endif // Stage_h__