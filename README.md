# Abstract-Machine

本项目是一个简易的RISC-V硬件抽象层。

使用前需要安装`riscv-gnu-toolchain`，默认使用`riscv64-unknown-elf`进行编译。

本项目使用`newlib`作为C标准库，已经作为子模块集成到仓库中。

参考下方的指示可以编译安装`newlib`：

```sh
# Clone the repo with submodule
git clone ----recursive git@github.com:nanjo712/abstract-machine.git
cd abstract-machine

# create a dir for built object
mkdir build
cd build
mkdir riscv32-newlib
cd riscv32-newlib

# configure the project and make it
# target will be treated as the compiler's prefix
../newlib/configure --target=riscv64-unknown-elf
make -j8

# install newlib to your system
make install # may need sudo

# default install localtion : /usr/local/riscv64-unknown-elf
```



