# NexCoin (NXC) - Pure CPU Mineable Blockchain

NexCoin is an open-source, decentralized, peer-to-peer cryptocurrency built upon the proven foundation of Bitcoin Core and Sugarchain, utilizing the specialized **Yespower** proof-of-work consensus algorithm. 

NexCoin is engineered from the ground up for **"One-CPU-One-Vote"** true decentralization: strictly ASIC-resistant and GPU-inefficient, allowing anyone with a standard desktop or laptop processor to participate equally in securing the network.

---

## ⚡ Specifications

| Parameter | Value |
| :--- | :--- |
| **Coin Name** | NexCoin |
| **Ticker / Symbol** | **NXC** |
| **Algorithm** | **Yespower** (CPU Only, ASIC/GPU Resistant) |
| **Block Time** | 5 seconds (DigiShieldZEC dynamic difficulty retargeting) |
| **Block Reward** | 2 NXC per block |
| **Max Supply** | **24,000,000 NXC** |
| **Halving Interval** | 6,000,000 blocks (~1 year) |
| **P2P Port** | `9333` |
| **RPC Port** | `9332` |
| **Address Prefix** | Legacy starts with `N` (e.g. `NdGG1y...`), SegWit starts with `nex1q...` |
| **Genesis Message** | *"The Times 20/Nov/2026 NexCoin Launch: Pure CPU One-Vote Fair Decentralization"* |
| **Pre-mine** | **0% (100% Fair Launch)** |

---

## 🚀 Building NexCoin Core from Source (Ubuntu / Debian)

### 1. Install Dependencies
```bash
sudo apt update
sudo apt install -y build-essential libtool autotools-dev automake pkg-config bsdmainutils python3 libssl-dev libevent-dev libboost-all-dev libdb5.3++-dev git
```

### 2. Clone and Compile
```bash
git clone https://github.com/nexcoin-project/nexcoin.git
cd nexcoin
./autogen.sh
./configure --with-incompatible-bdb --without-gui --disable-tests --disable-bench
make -j$(nproc)
sudo make install
```

### 3. Running the Daemon
Create your configuration file in `~/.nexcoin/nexcoin.conf`:
```ini
server=1
listen=1
daemon=1
rpcuser=your_rpc_username
rpcpassword=your_rpc_password
rpcport=9332
port=9333
addnode=43.131.9.171:9333
```

Start the daemon:
```bash
nexcoind -daemon
```

Check blockchain info:
```bash
nexcoin-cli getblockchaininfo
```

Generate a wallet address:
```bash
nexcoin-cli getnewaddress "" legacy
```

---

## ⛏ Mining NexCoin (CPU Mining)

NexCoin can be mined using any standard Yespower-compatible CPU miner (such as `sugarmaker` or `cpuminer-opt`).

### Example with Sugarmaker:
```bash
./sugarmaker -a yespowersugar -o stratum+tcp://43.131.9.171:9332 -u YOUR_NEXCOIN_ADDRESS -t 4
```

---

## 📜 License
NexCoin Core is released under the terms of the **MIT license**. See [COPYING](COPYING) for more information.
