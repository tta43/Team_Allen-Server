#ifndef Mouse_h__
#define Mouse_h__

#include "Engine_Include.h"

BEGIN(Engine)

class ENGINE_DLL CMouse
{
public:
	DECLARE_SINGLETON(CMouse)

private:
	CMouse(void);
public:
	~CMouse(void);

public:
	D3DXVECTOR3 GetMousePos(void);

public:
	void Initialize(HWND hWnd);

private:
	HWND		m_hWnd;

};

END

#endif // Mouse_h__