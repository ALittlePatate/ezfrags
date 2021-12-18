#pragma once
#include <stdio.h>

namespace get_sigs {
	void start();
}

namespace Signatures {
	static DWORD dwForceJump;
	static DWORD dwLocalPlayer;
}

namespace Netvars {
	static int m_fFlags;
	static int m_flFlashMaxAlpha;
}