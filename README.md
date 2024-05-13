# Custom_Low_Battery_Warning
# Battery Percentage Notifier

Battery Percentage Notifier is a simple C++ program for macOS that notifies you when your battery percentage falls below a certain threshold. It uses the macOS IOKit framework to get battery information and displays a notification using AppleScript.

## Features

- Notifies you when the battery percentage falls below a certain threshold.
- Customizable threshold percentage.
- Customizable notification message.
- Low resource consumption

## Requirements

- macOS
- Xcode Command Line Tools

## Installation

1. Clone this repository.
2. Compile the program using the following command:

 ```bash
   g++ -std=c++11 battery_info.cpp -o battery_info -framework CoreFoundation -framework IOKit
```
or
```bash
./battery_info <custom limit>
 ````
