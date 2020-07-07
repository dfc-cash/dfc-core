#pragma once
#include <xdr/DfcBlockChain-types.h>

namespace std
{
template <> struct hash<dfc::uint256>
{
    size_t operator()(dfc::uint256 const& x) const noexcept;
};
}
