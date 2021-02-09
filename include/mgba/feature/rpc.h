#ifndef RPC_H
#define RPC_H

#include <mgba/internal/gba/gba.h>
#if __cplusplus
extern "C" {
#endif
void startRPC(int port, struct GBA* eGba);
#if __cplusplus
};
#endif

#endif // RPC_H
