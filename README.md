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
  ``` bash
git clone https://github.com/Abhigyan126/Custom_Low_Battery_Warning.git
```
3. Compile the program using the following command:

 ```bash
clang++ -o battery_info warning_battery.cpp notification_sender.m -framework IOKit -framework CoreFoundation -framework Foundation -x objective-c++
```
or
```bash
./battery_info 
 ````
To automate startup at Login follow these step 
1. Open terminal and paste the following code
```bash
echo '<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple Computer//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
    <key>Label</key>
    <string>com.example.battery_info</string>
    <key>ProgramArguments</key>
    <array>
        <string>/path/to/your/compiled/program</string>
    </array>
    <key>RunAtLoad</key>
    <true/>
</dict>
</plist>' > ~/Library/LaunchAgents/com.example.battery_info.plist

```
2. Replace /path/to/your/compiled/program with binary location
3. run the following command in terminal
```bash
launchctl load /path/to/your/plist/file

```
