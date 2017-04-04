# stm8s-touch-switch-4ch

stm8s 4-channel capacitive touch switch module for driving ssr relays

## Pin assignments

|               |               |               |          |            |             |          |           |              |              |
|---------------|---------------|---------------|----------|------------|-------------|----------|-----------|--------------|--------------|
|   OUT1 (D3)   |   OUT2 (D2)   |   SWIM (D1)   | IN4 (C7) |  IN3 (C6)  |   IN2 (C5)  | IN1 (C4) | OUT3 (C3) | I2C_SCL (B4) | I2C_SDA (B5) |
| Reserved (D4) | Reserved (D5) | Reserved (D6) |    RST   | OSCIN (A1) | OSCOUT (A2) |    GND   |     5V    |      3V3     |   OUT4 (A3)  |
|               |               |               |          |            |             |          |           |              |              |

## How to build

Requires [STM8S Standard Peripherals Library V2.2.0](http://www.st.com/en/embedded-software/stsw-stm8069.html)

- Using [STVD](http://www.st.com/en/development-tools/stvd-stm8.html) with [CXSTM8](http://cosmicsoftware.com/download_stm8_free.php)

- Using [SDCC](http://sdcc.sourceforge.net/) and [STM8_SPL_v2.2.0_SDCC.patch](https://github.com/gicking/SPL_2.2.0_SDCC_patch/) or run prepared docker container:
```bash
docker run --rm -v "$PWD":/usr/src/myapp -w /usr/src/myapp zcsevcik/toolchain-stm8s make
```
