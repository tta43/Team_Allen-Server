#include "Mouse.h"

IMPLEMENT_SINGLETON(Engine::CMouse)

Engine::CMouse::CMouse(void)
{
}

Engine::CMouse::~CMouse(void)
{
}

D3DXVECTOR3 Engine::CMouse::GetMousePos(void)
{
	static POINT ptMouse;
	// ���� ���콺 Ŀ���� ��ǥ�� ������ �Լ�.
	GetCursorPos(&ptMouse);

	// ���� ��ü â�� ���� ���콺�� ��ǥ�� �ش� ������ â ���� ���� ��ǥ�� ��ȯ���ִ� �Լ�.
	ScreenToClient(m_hWnd, &ptMouse);

	return D3DXVECTOR3((float)ptMouse.x, (float)ptMouse.y, 0.f);
}

void Engine::CMouse::Initialize(HWND hWnd)
{
	m_hWnd = hWnd;
}
