## Ubuntu Matter Installation
```bash
# clone repo 
git clone --recurse-submodules https://github.com/project-chip/connectedhomeip.git
cd connectedhomeip
git pull 
git submodule update --init
# install prerequists
sudo apt-get install -y git gcc g++ pkg-config libssl-dev libdbus-1-dev \
     libglib2.0-dev libavahi-client-dev ninja-build python3-venv python3-dev \
     python3-pip unzip libgirepository1.0-dev libcairo2-dev libreadline-dev
```

## Matter on RaspberryPI
- Follow the `ubuntu` installation 
```bash
sudo apt-get -y install pi-bluetooth avahi-utils
```
#### Enable experimental Bluetooth support and disable battery plugin in BlueZ

[](https://github.com/project-chip/connectedhomeip/blob/master/docs/guides/BUILDING.md#enable-experimental-bluetooth-support-and-disable-battery-plugin-in-bluez)

The Matter application on Linux uses BlueZ to communicate with the Bluetooth controller. The BlueZ version that comes with Ubuntu 22.04 does not support all the features required by the Matter application by default. To enable these features, you need to enable experimental Bluetooth support in BlueZ.

Also disable the battery plugin from BlueZ, because iOS devices advertises a battery service via BLE, which requires pairing if accessed. BlueZ includes a battery plugin by default which tries to connect to the battery service. The authentication fails, because in this case no BLE pairing has been done. If the BlueZ battery plugin is not disabled, the BLE connection will be terminated during the Matter commissioning process.

1. Edit the `bluetooth.service` unit by running the following command:
    
    ```bash
    sudo systemctl edit bluetooth.service
    ```
    

2. Add the following content to the override file:

```bash
[Service]
ExecStart=
ExecStart=/usr/lib/bluetooth/bluetoothd -E -P battery
```

3. Restart the Bluetooth service by running the following command:

```shell
sudo systemctl restart bluetooth.service
```

#### Configuring wpa_supplicant for storing permanent changes

[configuring-wpa_supplicant-for-storing-permanent-changes](https://github.com/project-chip/connectedhomeip/blob/master/docs/guides/BUILDING.md#configuring-wpa_supplicant-for-storing-permanent-changes)

By default, wpa_supplicant is not allowed to update (overwrite) configuration. If you want the Matter application to be able to store the configuration changes permanently, you need to make the following changes:

1. Edit the `dbus-fi.w1.wpa_supplicant1.service` file to use configuration file instead by running the following command:
    
    ```bash
    sudo nano /etc/systemd/system/dbus-fi.w1.wpa_supplicant1.service
    ```

 2. Run the following command to change the wpa_supplicant start parameters to the provided values:

```bash
ExecStart=/sbin/wpa_supplicant -u -s -i wlan0 -c /etc/wpa_supplicant/wpa_supplicant.conf
```

3. Add the `wpa-supplicant` configuration file by running the following command:

```bash
sudo nano /etc/wpa_supplicant/wpa_supplicant.conf
```

4. Add the following content to the `wpa-supplicant` file:

```bash
ctrl_interface=DIR=/run/wpa_supplicant
update_config=1
```

- Reboot your Raspberry Pi.
## Running 
- setup environment 
```bash
source scripts/activate.sh
source scripts/bootstrap.sh
```
## Resources:
[matter-git-repo](https://github.com/project-chip/connectedhomeip/blob/master/docs/guides/BUILDING.md)
