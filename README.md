# icaOS

open source x86_64 operating system

# how to build

install everything using:
```bash
./buildLibs.sh
```

build OS using:
```bash
make build-x86_64
```

## how to run

after build, use:
```bash
qemu-system-x86_64 -cdrom dist/x86_64/kernel.iso
```