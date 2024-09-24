
### Components of a matter data model 


![[matter_datamodel_endpoints.png]]

![[matter_datalmodel_2.png]]

#### Device: 
The device is the hardware that establishes communication in the matter network it could be: 
- lamp 
- Smartphone 
- Thermostat
#### Node : 
A node is an abstract representation of the device in the network that is assigned to it an ID. 
Based on the device complexity and Features, a device could have more than a node, each node represents a certain application of the device. 
A node could have one or more Endpoints
##### Example-1 : Smart thermostat: 
- Node 1: Thermostat
- Node 2: Fan control 
- Node 3: Display and interface 
##### Example-1 : Smart Lamp: 
- Node 1:  Lighting (set color, color animation, dimming, On/Off ...) 
- Node 2: Environmental sensing
#### Endpoint:
It is a logical entity within a node, it specifies a certain functionality within the node. 
In a node there could be more than one endpoints, each endpoint describes a certain function of the device . 

Each endpoint can hold multiple clusters.  
##### Example-1 : Smart Lamp => Node 1:  Lighting   
Lighting (set color, color animation, dimming, On/Off ...)
- Endpoint 1 :  On-Off 
- Endpoint 2: Light control
- Endpoint 3: Current measurement

#### Cluster : 
A cluster is a collection of attributes and commands that defines a specific piece of functionality within an endpoint. 

Clusters can be thought of as modules that encapsulate certain capabilities and characteristics of the device.

There are standard clusters (like On/Off, Temperature Measurement, etc.) defined by the Matter specification, which ensure interoperability between devices from different manufacturers.

Clusters can be server-side (providing functionality) or client-side (consuming functionality).

##### Example-1 : Smart Lamp => Endpoint 2: Light control   
- Cluster 1 :  On-Off 
	- Attributes : On-Off
	- Commands: On/Off/Toggle
- Cluster 2: Light Color:
	- Attributes: color
	- Commands: Set-RGB-val
- Cluster 3: Color animation 
	- Attributes: animation_type  
	- Command: set-animation
- Cluster 4: Dimming 
	- Attributes: brightness level
	- Commands: set-brightness 
### Example Device: Smart Thermostat

#### Node 1: Thermostat

- **Endpoint 1: Temperature Control**
    
    - **Cluster 1: Thermostat Cluster**
        - Attributes: Current Temperature, Desired Temperature, Mode (heat/cool/auto)
        - Commands: Set Temperature, Switch Mode
    - **Cluster 2: Temperature Measurement Cluster**
        - Attributes: Measured Temperature
        - Commands: Read Temperature
- **Endpoint 2: Humidity Control**
    
    - **Cluster 1: Humidity Measurement Cluster**
        - Attributes: Current Humidity
        - Commands: Read Humidity

#### Node 2: Fan Control (if the thermostat also has a fan)

- **Endpoint 1: Fan Speed Control**
    - **Cluster 1: Fan Control Cluster**
        - Attributes: Fan Speed, Fan Mode
        - Commands: Set Fan Speed, Switch Fan Mode

#### Node 3: Display and Interface (if the thermostat has a display interface)

- **Endpoint 1: Display Control**
    
    - **Cluster 1: Display Configuration Cluster**
        - Attributes: Brightness, Contrast, Screen Mode
        - Commands: Adjust Brightness, Switch Screen Mode
- **Endpoint 2: Button Interface**
    
    - **Cluster 1: Button Cluster**
        - Attributes: Button State
        - Commands: Button Press, Button Release

In this example, the smart thermostat device is represented by multiple nodes. Each node groups related functionalities together. For instance:

- The first node deals with temperature and humidity control.
- The second node deals with fan control.
- The third node handles the display and user interface functionalities.
![[matter_data_model_3.png]]