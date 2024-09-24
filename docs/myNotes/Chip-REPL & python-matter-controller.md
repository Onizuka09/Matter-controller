### Introduction 
Connected-home-ip ( Read-Eval-Print loop), a command line tool that set's up the python CHIP controller library. 
This library provides API's to communicate with matter devices. 
for installation follow this [python_chip_controller_building](https://github.com/project-chip/connectedhomeip/blob/master/docs/guides/python_chip_controller_building.md)
```bash 
cd connectedhomeip
./scripts/build_python.sh -m platform -i separate
```
 the program may not run so you need to change the at line 22
``` bash
 
_normpath() {
    python3 -c "import os.path; print(os.path.normpath('$@'))"
}
```
If the command ran successfully a new directory called `separate` will be create 
```bash 
cd separate
# activate the python environment 
source bin/activate
chip-repl
```
#### how to use the chip-repl
It 's a command line tool used to get info about the API's provided by the `Matter python controller`
Its usage resembles the `python3` CLI. 
an Example on how to get info about 
```bash
import import chip.DeviceCtrl as DeviceCtrl
```
To list all the functions and attributes available in `DeviceCtrl`, use Python’s built-in `dir()` function:
```python
dir(DeviceCtrl)
```
To get more detailed information about a specific function or class within the `ChipStack` module, you can use the `help()` function:
```python
help(DeviceCtrl.SomeFunction)
```
### The main utilities that this library provides is :
- `BLE Commissioning` : ability to Commission a new matter device 
- `Control application clusters` send commands to the device 
- `Read basic information`: get information about the device 
### Basic python script (doesn't work)

```python 
import chip import ChipDeviceCtrl

# Initialize controller
fabricId = 1  # Fabric ID, usually provided by your Matter configuration
nodeId = 12345  # Node ID, unique identifier for the node
adminVendorId = 0xFFF1  # Vendor ID, assigned by the Matter protocol for testing
opCredsContext=None

devCtrl = ChipDeviceCtrl.ChipDeviceController(opCredsContext, fabricId, nodeId, adminVendorId)

# Discover commissionable devices
devCtrl.DiscoverCommissionableNodes()

# Set network credentials (example for Wi-Fi)
ssid = 'YOUR_SSID'
password = 'YOUR_PASSWORD'
devCtrl.SetWiFiCredentials(ssid, password)

# Commission a device (example with specific discriminator and setup pin code)
discriminator = 3840
setup_pin_code = 20202021
node_id = 1234
devCtrl.ConnectBLE(discriminator, setup_pin_code, node_id)

# Send a command to a commissioned device (example to toggle a light)
command = ChipDeviceCtrl.LevelControl.Commands.MoveToLevel(level=50, transitionTime=0, optionsMask=0, optionsOverride=0)
await devCtrl.SendCommand(node_id, 1, command)

# Read an attribute from the device (example to get vendor name)
attributes = [(0, ChipDeviceCtrl.Clusters.BasicInformation.Attributes.VendorName)]
await devCtrl.ReadAttribute(node_id, attributes)

```
- **discriminator = 3840**: A specific value used to identify the device you want to commission.
- **setup_pin_code = 20202021**: A specific value used to authenticate the device.
- **node_id = 1234**: A temporary identifier assigned to the device.
```python
Traceback (most recent call last):
  File "/home/moktar/connectedhomeip/separate/example/test.py", line 15, in <module>
    devCtrl = ChipDeviceCtrl.ChipDeviceController(opCredsContext, fabricId, nodeId, adminVendorId)
  File "/home/moktar/connectedhomeip/separate/lib/python3.10/site-packages/chip/ChipDeviceCtrl.py", line 1860, in __init__
    f"caIndex({fabricAdmin.caIndex:x})/fabricId(0x{fabricId:016X})/nodeId(0x{nodeId:016X})"
AttributeError: 'NoneType' object has no attribute 'caIndex'
Exception ignored in: <function ChipDeviceControllerBase.__del__ at 0x7b96a4a0c280>
Traceback (most recent call last):
  File "/home/moktar/connectedhomeip/separate/lib/python3.10/site-packages/chip/ChipDeviceCtrl.py", line 584, in __del__
    self.Shutdown()
  File "/home/moktar/connectedhomeip/separate/lib/python3.10/site-packages/chip/ChipDeviceCtrl.py", line 545, in Shutdown
    if not self._isActive:
AttributeError: 'ChipDeviceController' object has no attribute '_isActive
```

### Some useful API's 
1. **Discover Commissionable Nodes**:
   ```python
   devCtrl.DiscoverCommissionableNodes()
   ```

2. **Set Network Credentials**:
   - For Wi-Fi:
     ```python
     devCtrl.SetWiFiCredentials("SSID", "PASSWORD")
     ```
   - For Thread:
     ```python
     thread_dataset = bytes.fromhex("...hex dataset...")
     devCtrl.SetThreadOperationalDataset(thread_dataset)
     ```

3. **Commission the Device**:
   - Using Bluetooth LE:
     ```python
     devCtrl.ConnectBLE(discriminator, setup_pin_code, node_id)
     ```
 


4. **Control the Device**:
```python
await devCtrl.SendCommand(1234, 1, Clusters.OnOff.Commands.Toggle())
```
## Resources 
https://project-chip.github.io/connectedhomeip-doc/testing/python.html
[Controller-Readme](https://github.com/project-chip/connectedhomeip/blob/master/src/controller/README.md)
