inThe `chip-tool` application uses the Matter protocol to communicate with Matter servers. It includes instructions for building the application and using it to commission and send commands to devices.

## Run 
- Mode 1: CLI command by command 
```bash
./chip-tool <command> <Args>
```
- Mode 2: interactive mode 
```
./chip-tool interactive start 
```

## testing on RPI-4 with the lighthing-app-linux

```bash 
discover commissionables
pairing onnetwork 123 20202021
pairing onnetwork-instance-name 213 20202021 4CBDE0B59627139
pairing ble-wifi 123 "SOFIA_R1" "SOFIA-R1-WIFI@2024***" 20202021 3840
onoff toggle 123 1

```

## CHIP-Tool capabilities: 
- Device  commissioning 
- Network managing ( adding a device to a group ) 
- Device control ( send commands to different clusters) 
- Cluster Interaction (Read sensor value's from cluster's and request information about the device)
- Testing and debugging
## CHIP-Tool basic commands 
The `matter-chip` tool provides several CLI (Command Line Interface) commands to interact with Matter devices. Here are some of the basic CLI commands you can use with the `chip-tool`:

### Commissioning Commands

- **pairing**: Handles commissioning of devices.
  - `chip-tool pairing onnetwork <node-id> <setup-pin-code> <discriminator>`: Commissions a device that is already on the network.
  - `chip-tool pairing ble-wifi <node-id> <ssid> <password> <setup-pin-code> <discriminator>`: Commissions a WiFi device using BLE.
  - `chip-tool pairing ble-thread <node-id> <operational-dataset> <setup-pin-code> <discriminator>`: Commissions a Thread device using BLE.
  - `chip-tool pairing eth <node-id> <ip-address> <setup-pin-code>`: Commissions an Ethernet device.
**Parameters:**
- `<node-id>`: The node ID to assign to the device being paired. This can be a decimal number or a hexadecimal number prefixed with `0x`.
- `<ssid>`: The SSID of the Wi-Fi network to which the device should connect.
- `<password>`: The password for the Wi-Fi network.
- `<setup-pin-code>`: The setup code for the device. This is usually provided by the device manufacturer.
- `<discriminator>`: The discriminator for the device. This is used to differentiate between devices during the pairing process.

**Example:**
```bash
chip-tool pairing ble-wifi 1234 mySSID myPassword 20202021 3840
```

### Device Control Commands

- **onoff**: Controls devices with on/off functionality.
  - `chip-tool onoff on <node-id> <endpoint>`: Turns the device on.
  - `chip-tool onoff off <node-id> <endpoint>`: Turns the device off.
  - `chip-tool onoff toggle <node-id> <endpoint>`: Toggles the device state.
  **Example** 
	To turn on the device with the node id `123456789`:
	```bash
	chip-tool onoff on 123456789 1
	```
  - `123456789` represents the device ID.
  - `1` is the endpoint ID.

- **levelcontrol**: Controls devices with level control (e.g., dimmable lights).
  - `chip-tool levelcontrol move-to-level <level> <transition-time> <node-id> <endpoint>`: Moves to a specified level over a period.
  - `chip-tool levelcontrol step <step-mode> <step-size> <transition-time> <node-id> <endpoint>`: Steps up or down by a specified size.
  **example**:
```bash
  chip-tool levelcontrol move-to-level 50 1000 123 1
```
  - `50` : `<level> specifies the level to move to.   
  - `1000`: `<transition-time>` specifies the duration over which the transition to the target level should occur, in milliseconds.
  - `123`: `<node-id>` represents the unique identifier of the device you want to control. 
  - `1`: `<endpoint>` specifies the endpoint within the device. 

- **colorcontrol**: Controls color settings for devices.
  - `chip-tool colorcontrol move-to-hue <hue> <transition-time> <node-id> <endpoint>`: Moves to a specified hue.
  - `chip-tool colorcontrol move-to-saturation <saturation> <transition-time> <node-id> <endpoint>`: Moves to a specified saturation.
  - `chip-tool colorcontrol move-to-hue-and-saturation <hue> <saturation> <transition-time> <node-id> <endpoint>`: Moves to specified hue and saturation.

### Network Management Commands

- **discover**: Discovers devices on the network.
  - `chip-tool discover commissioners`: Discovers Matter commissioners on the network.
  - `chip-tool discover devices`: Discovers Matter devices on the network.
- **Group adding**: Allows for  multiple devices to be controlled simultaneously using a single command. 
This is useful for scenarios where you want to manage several devices as a unit, such as turning on all lights in a room at once.
  ```bash
chip-tool groups add-group <groupId> <groupName> <endpointId>
```
**Parameters:**


**Example:**
```bash
chip-tool groups add-group 0x1234 "Living Room" 1
```
- `0x1234`: `<groupId>`The identifier for the group. This can be a decimal number or a hexadecimal.
- `"Living Room"`:`<groupName>` represents the name of the group.
- `1` : `<endpointId>` The endpoint ID of the device where the group is being added.
### Attribute Interaction Commands

- **read**: Reads attribute values.
  - `chip-tool read <cluster-name> <attribute-name> <node-id> <endpoint>`: Reads an attribute from a specified cluster.

- **write**: Writes attribute values.
  - `chip-tool write <cluster-name> <attribute-name> <value> <node-id> <endpoint>`: Writes a value to a specified attribute in a cluster.
**example** :
```bash
chip-tool write OnOff OnOff true 123456789 1
```
- `OnOff`: `<cluster-name>`Specifies the cluster name .
- `OnOff`: `<attribute-name>`Specifies the attribute name .
- `true`: Specifies the value you want to write. 
- `123456789`: Specifies the node ID of the device.
- `1`: Specifies the endpoint where the OnOff cluster is located on the device.
### Cluster Interaction Commands

- **identify**: Identifies devices.
  - `chip-tool identify identify <duration> <node-id> <endpoint>`: Identifies the device for a specified duration.

- **scenes**: Manages scenes on devices.
`scenes` refer to predefined states or configurations that you can set for multiple devices simultaneously. Scenes allow users to activate a specific combination of settings across different devices with a single command
  - `chip-tool scenes add-scene <group-id> <scene-id> <node-id> <endpoint>`: Adds a new scene.
  - `chip-tool scenes recall-scene <group-id> <scene-id> <node-id> <endpoint>`: Recalls a specified scene.

- **doorlock**: Controls door lock devices.
  - `chip-tool doorlock lock-door <node-id> <endpoint>`: Locks the door.
  - `chip-tool doorlock unlock-door <node-id> <endpoint>`: Unlocks the door.

## References
[CHIP-TOOL](https://github.com/project-chip/connectedhomeip/blob/master/docs/guides/chip_tool_guide.md)


