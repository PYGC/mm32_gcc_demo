# MM32 GCC Demo

- Target: [MM32F3270](https://www.mindmotion.com.cn/en/products/mm32mcu/mm32f/mm32f_mainstream/mm32f3270/)
- Board: [MB-039](https://www.mindmotion.com.cn/en/support/development_tools/evaluation_boards/evboard/mm32f3277g9p/)
- Toolchain: [GNU Arm Embedded Toolchain](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads)

Windows need:

- [Windows Build Tools](https://github.com/gnu-mcu-eclipse/windows-build-tools/releases)

## Build

Clone the repository:

```bash
git clone https://github.com/PYGC/mm32_gcc_demo.git --recursive
```

Change directory:

```bash
cd mm32_gcc_demo
```

Build the project:

```bash
make
```

The project will generate the `build` directory.

Clean the project:

```bash
make clean
```

## Git Submodule

- [ARM-software/CMSIS_5](https://github.com/ARM-software/CMSIS_5)
- [PYGC/mm32_startup](https://github.com/PYGC/mm32_startup)
- [PYGC/mm32_ld](https://github.com/PYGC/mm32_ld)