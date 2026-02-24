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

## Build and run the Read example

```bash
cd Read/Source
mkdir build
cd build
cmake ..
make
sudo ./Read
```

## Database access

```sql
CREATE USER '[USER]'@'localhost' IDENTIFIED BY '[PASSWORD]';
GRANT ALL PRIVILEGES ON rpi_io_logger.* TO '[USER]'@'localhost';
FLUSH PRIVILEGES;
```

