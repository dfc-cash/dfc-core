#pragma once

// Copyright 2018 DfcBlockChain Development Foundation and contributors. Licensed
// under the Apache License, Version 2.0. See the COPYING file at the root
// of this distribution or at http://www.apache.org/licenses/LICENSE-2.0

#include "crypto/ByteSliceHasher.h"
#include "xdr/DfcBlockChain-ledger.h"
#include <functional>

// implements a default hasher for "LedgerKey"
namespace std
{
template <> class hash<dfc::LedgerKey>
{
  public:
    size_t
    operator()(dfc::LedgerKey const& lk) const
    {
        size_t res;
        switch (lk.type())
        {
        case dfc::ACCOUNT:
            res = dfc::shortHash::computeHash(
                dfc::ByteSlice(lk.account().accountID.ed25519().data(), 8));
            break;
        case dfc::TRUSTLINE:
        {
            auto& tl = lk.trustLine();
            res = dfc::shortHash::computeHash(
                dfc::ByteSlice(tl.accountID.ed25519().data(), 8));
            switch (lk.trustLine().asset.type())
            {
            case dfc::ASSET_TYPE_NATIVE:
                break;
            case dfc::ASSET_TYPE_CREDIT_ALPHANUM4:
            {
                auto& tl4 = tl.asset.alphaNum4();
                res ^= dfc::shortHash::computeHash(
                    dfc::ByteSlice(tl4.issuer.ed25519().data(), 8));
                res ^= tl4.assetCode[0];
                break;
            }
            case dfc::ASSET_TYPE_CREDIT_ALPHANUM12:
            {
                auto& tl12 = tl.asset.alphaNum12();
                res ^= dfc::shortHash::computeHash(
                    dfc::ByteSlice(tl12.issuer.ed25519().data(), 8));
                res ^= tl12.assetCode[0];
                break;
            }
            default:
                abort();
            }
            break;
        }
        case dfc::DATA:
            res = dfc::shortHash::computeHash(
                dfc::ByteSlice(lk.data().accountID.ed25519().data(), 8));
            res ^= dfc::shortHash::computeHash(dfc::ByteSlice(
                lk.data().dataName.data(), lk.data().dataName.size()));
            break;
        case dfc::OFFER:
            res = dfc::shortHash::computeHash(dfc::ByteSlice(
                &lk.offer().offerID, sizeof(lk.offer().offerID)));
            break;
        default:
            abort();
        }
        return res;
    }
};
}
