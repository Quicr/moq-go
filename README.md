# qgo - Go Bindings for libquicr

`qgo` provides idiomatic Go bindings for [libquicr](https://github.com/Quicr/libquicr), a C++ implementation of the Media over QUIC Transport (MoQT) protocol.


## Requirements

- Go 1.21 or later
- C++17 compatible compiler (clang++ or g++)
- CMake 3.15 or later
- Git (for submodules)

### Platform Dependencies

**macOS:**
```bash
# Install via Homebrew
brew install cmake openssl
```

**Linux (Ubuntu/Debian):**
```bash
sudo apt-get install cmake build-essential libssl-dev
```

## Installation

### 1. Clone with Submodules

```bash
git clone --recursive https://github.com/quicr/qgo.git
cd qgo
```

If you already cloned without `--recursive`:
```bash
git submodule update --init --recursive
```

### 2. Build the C Shim and libquicr

```bash
make shim
```

This builds:
- libquicr (the C++ library)
- quicr_shim (the CGO-compatible C wrapper)

### 3. Build the Go Package

```bash
make build
```

### 4. Run Tests

```bash
make test
```

### 5. Build Examples

```bash
make examples
```

## License

This project is licensed under the same terms as libquicr. See [LICENSE](LICENSE) for details.
