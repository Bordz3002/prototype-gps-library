----------------------------------
Pinouts: 
Vin, GND
TX: RX_18
RX: TX_19
This is a customized gps library that takes the official "Adafruit Gps Library" for an ease of use;
Instructions: 
Create an instance of "GPS" to access the class methods;
GPS instance(hardware_Serial);
Pass the Serial Adress to the instance's argument, Since it is only tested on the Arduino Boards that supports hardware Serial. 
Please refer to the AUTHOR for software_serial uses an instructions.
Note: not tested on Arduino uno (tested on Arduino Mega);
*
Documentation:
Method: .begin()
Type: void
Argument: none
Definiton: "Initiates the gps hardware and preloading all of its assets, the "UPDATE_RATE" can be customized to your needs.
Default is 10HZ. Range (1HZ-10HZ)";
*
Method: .gps_access()
Type: bool
Argument: none
Definition: "Returns true if the gps has a valid connection and there is transmission of gps data";
*
Method: .fix()
Type: int
Argument: none
Definition: "Returns '0' if there is no valid fix(gps reception), 1 if there are few satellites scanned and 2 if there are more satellites found";
*
Method: .fix_quality()
Type: int 
Argument: none
Definition: same definiton as .fix() method
*
Method: .satellites()
Type: int
Argument: none
Definition: "Returns the quantity of the sattelites available in you locale area";
*
Method: .hour()
Type: int 
Argument: none
Definition: "returns the current hour";
* 
Method: .minutes()
Type: int
Argument: none
Definition: "returns the current minutes";
*
Method: .day()
Type: int
Argument: none
Definition: "returns the current day";
*
Method: .month()
Type: int
Argument: none
Definition: "returns the current month";
*
Method: .year()
Type: int
Argument: none
Definition: "returns the current year";
*
Method: .lat()
Type: char
Argument: none
Definition: "returns the 'Y' postion eg; N,S";
*
Method: .lon()
Type: char
Argument: none
Definition: "returns the 'X' position eg; W,E";
*
Method: .latitude()
Type: float
Argument: none
Definiton: "returns the current 'Y' coordinates";
* 
Method: .longitude()
Type: float
Argument: none
Definition: "returns the current 'X' coordinates";
