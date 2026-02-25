# Raspberry Pi IO Logger

## Testing

```bash
pinctrl set 26 ip
pinctrl set 27 ip
pinctrl set 19 op dh; pinctrl get 19,26
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

## Daemonize the logger

Install the service:
```bash
sudo cp Logger/Source/config/logger.service /etc/systemd/system/
cat /etc/systemd/system/logger.service # check the content
sudo systemctl daemon-reload
```

Start and enable the service (at boot):
```bash
sudo systemctl enable logger.service
sudo systemctl start logger.service
sudo systemctl status logger.service
```

Stop and disable the service (at boot):
```bash
sudo systemctl stop logger.service
sudo systemctl disable logger.service
```
