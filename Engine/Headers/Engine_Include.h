#ifndef Engine_Include_h__
#define Engine_Include_h__

#include <map>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <d3dx9.h>
#include <d3d9.h>

#include "Engine_Enum.h"
#include "Engine_Macro.h"
#include "Engine_Struct.h"
#include "Engine_Function.h"
#include "Engine_Functor.h"


#pragma warning(disable : 4251)

using namespace std;

#include <crtdbg.h>

#ifdef _DEBUG
#define new new(_CLIENT_BLOCK, __FILE__, __LINE__)
#endif

#endif // Engine_Include_h__