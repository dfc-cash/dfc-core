#include "HashOfHash.h"
#include "crypto/ByteSliceHasher.h"

namespace std
{

size_t
hash<dfc::uint256>::operator()(dfc::uint256 const& x) const noexcept
{
    size_t res =
        dfc::shortHash::computeHash(dfc::ByteSlice(x.data(), 8));

    return res;
}
}
