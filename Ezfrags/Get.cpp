#include "MemManager.h"
#include "Signatures.h"
#include "Get.h"

namespace Get {
	INT32 LocalPlayer() {
		return Mem::RPM<INT32>(Mem::client + Signatures::dwLocalPlayer);
	}
}
