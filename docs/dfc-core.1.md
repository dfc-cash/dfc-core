% dfc-core(1)
% DfcBlockChain Development Foundation
%

# NAME

dfc-core - Core daemon for DfcBlockChain payment network

# SYNOPSYS

dfc-core [OPTIONS]

# DESCRIPTION

DfcBlockChain is a decentralized, federated peer-to-peer network that allows
people to send payments in any asset anywhere in the world
instantaneously, and with minimal fee. `DfcBlockChain-core` is the core
component of this network. `DfcBlockChain-core` is a C++ implementation of
the DfcBlockChain Consensus Protocol configured to construct a chain of
ledgers that are guaranteed to be in agreement across all the
participating nodes at all times.

## Configuration file

In most modes of operation, dfc-core requires a configuration
file.  By default, it looks for a file called `dfc-core.cfg` in
the current working directory, but this default can be changed by the
`--conf` command-line option.  The configuration file is in TOML
syntax.  The full set of supported directives can be found in
`%prefix%/share/doc/dfc-core_example.cfg`.

%commands%

# EXAMPLES

See `%prefix%/share/doc/*.cfg` for some example dfc-core
configuration files

# FILES

dfc-core.cfg
:   Configuration file (in current working directory by default)

# SEE ALSO

<https://www.dfc.org/developers/dfc-core/software/admin.html>
:   dfc-core administration guide

<https://www.dfc.org>
:   Home page of DfcBlockChain development foundation

# BUGS

Please report bugs using the github issue tracker:\
<https://github.com/dfc/dfc-core/issues>
