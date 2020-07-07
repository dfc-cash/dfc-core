#pragma once

// Copyright 2017 DfcBlockChain Development Foundation and contributors. Licensed
// under the Apache License, Version 2.0. See the COPYING file at the root
// of this distribution or at http://www.apache.org/licenses/LICENSE-2.0

#include "xdr/DfcBlockChain-types.h"
#include <vector>

namespace dfc
{

struct SCPEnvelope;
struct SCPStatement;
struct DfcBlockChainValue;

std::vector<Hash> getTxSetHashes(SCPEnvelope const& envelope);
std::vector<DfcBlockChainValue> getDfcBlockChainValues(SCPStatement const& envelope);
}
