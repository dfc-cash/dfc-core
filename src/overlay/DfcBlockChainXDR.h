#pragma once
#include "xdr/DfcBlockChain-ledger-entries.h"
#include "xdr/DfcBlockChain-ledger.h"
#include "xdr/DfcBlockChain-overlay.h"
#include "xdr/DfcBlockChain-transaction.h"
#include "xdr/DfcBlockChain-types.h"

namespace dfc
{

std::string xdr_printer(const PublicKey& pk);
}
