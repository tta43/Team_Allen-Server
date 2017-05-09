#ifndef TCPServer_h__
#define TCPServer_h__

#include "Engine_Include.h"

BEGIN(Engine)

class ENGINE_DLL CTCPServer
{
public:
	DECLARE_SINGLETON(CTCPServer)

private:
	CTCPServer(void);
	~CTCPServer(void);

public:
	HRESULT Initialize();

private:
	char m_Port[5];

};

END

#endif // TCPServer_h__