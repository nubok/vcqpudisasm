# vcqpudisasm

Disassemble machine codes of VideoCore IV and VideoCore VI QPUs. Inspired by [Terminus-IMRC/vc6qpudisas](https://github.com/Terminus-IMRC/vc6qpudisas).


## Setting up

First, you need to build the disassembler in [Mesa 3d](https://www.mesa3d.org/):

```shell
$ git clone https://gitlab.freedesktop.org/mesa/mesa.git --depth=1
$ cd mesa/
$ mkdir build/
$ cd build/
$ meson .. -Dgallium-drivers=vc4,v3d -Dvulkan-drivers=broadcom -Dplatforms=x11
$ ninja src/broadcom/qpu/libbroadcom_qpu.a src/util/libmesa_util.a src/gallium/drivers/vc4/libvc4.a
$ cd ../../
```

After that, vcqpudisasm can be built as:

```shell
$ git clone https://github.com/nubok/vcqpudisasm.git
$ cd vcqpudisasm/
$ mkdir build/
$ cd build/
$ cmake .. -DCMAKE_PREFIX_PATH="$(realpath ../../mesa);$(realpath ../../mesa/build)"
$ make
```


## Usage

### VideoCore IV

```shell
$ ./vc6qpudisasm 42 <<< '0x54001f4038f91fbf'
add  r0, r1, r2      ; fmul  rf61, rf62, rf63
```

See
[mesa/src/broadcom/qpu/tests/qpu_disasm.c](https://gitlab.freedesktop.org/mesa/mesa/blob/master/src/broadcom/qpu/tests/qpu_disasm.c)
for other examples.

### VideoCore VI

```shell
$ ./vc4qpudisasm <<< '0x10025020cc9e7081'
add rb0, r0, r2 ; v8adds r0, r0, r1
```

See
[userland/host_applications/linux/apps/hello_pi/hello_fft/hex · raspberrypi/userland](https://github.com/raspberrypi/userland/tree/master/host_applications/linux/apps/hello_pi/hello_fft/hex) (also available at
[firmware/opt/vc/src/hello_pi/hello_fft/hex · raspberrypi/firmware]](https://github.com/raspberrypi/firmware/tree/master/opt/vc/src/hello_pi/hello_fft/hex))
for other examples.
