# Raspberry Pi IO Logger

## Testing

```bash
pinctrl set 17 op dh; pinctrl get 17,27
```

## Install PJ's GPIO library

```bash
cd PJ_RPI
mkdir build
cd build
cmake ..
make
sudo make install
```

