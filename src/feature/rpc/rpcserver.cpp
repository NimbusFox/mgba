#include <mgba/feature/rpc.h>
#include "rpc/server.h"
#include <mgba/feature/rpcdata.h>
#include <mgba/internal/gba/memory.h>

rpc::server* server;
GBA* gba;
mMemory storage;
int byteIndex = 0;


mMemory readMemory(unsigned int address, unsigned int size) {
	storage.bytes.resize(size);
	storage.size = size;

	byteIndex = 0;

	for (auto i = address; i < address + size; i++) {
		storage.bytes[byteIndex++] = GBALoad8(reinterpret_cast<ARMCore*>(gba), i, nullptr);
	}

	return storage;
}

void startRPC(int port, struct GBA* eGba) {
	gba = eGba;
	server = new rpc::server(port);

	server->bind("readMemory", &readMemory);

	server->async_run();
}