#include <CoreFoundation/CoreFoundation.h>
#include <IOKit/ps/IOPSKeys.h>
#include <IOKit/ps/IOPowerSources.h>
#include <iostream>
#include <unistd.h>

double getBatData() {
    CFTypeRef sourceInfo = IOPSCopyPowerSourcesInfo();
    CFArrayRef sourceList = IOPSCopyPowerSourcesList(sourceInfo);

    double percent = 0;

    // Check if power sources were found
    if (sourceList != nullptr && CFArrayGetCount(sourceList) > 0) {
        CFDictionaryRef source = nullptr;

        // Loop through sources, find the first battery
        for (CFIndex i = 0; i < CFArrayGetCount(sourceList); ++i) {
            source = IOPSGetPowerSourceDescription(sourceInfo, CFArrayGetValueAtIndex(sourceList, i));

            // Is this a battery?
            CFStringRef type = (CFStringRef)CFDictionaryGetValue(source, CFSTR(kIOPSTransportTypeKey));
            if (kCFCompareEqualTo == CFStringCompare(type, CFSTR(kIOPSInternalType), 0)) {
                break;
            }
        }

        // Check if battery information was found
        if (source != nullptr) {
            int curCapacity;
            CFNumberRef curCapacityNum = (CFNumberRef)CFDictionaryGetValue(source, CFSTR(kIOPSCurrentCapacityKey));
            CFNumberGetValue(curCapacityNum, kCFNumberIntType, &curCapacity);

            int maxCapacity;
            CFNumberRef maxCapacityNum = (CFNumberRef)CFDictionaryGetValue(source, CFSTR(kIOPSMaxCapacityKey));
            CFNumberGetValue(maxCapacityNum, kCFNumberIntType, &maxCapacity);

            // Check if maxCapacity is greater than 0 to avoid division by zero
            if (maxCapacity > 0) {
                percent = static_cast<double>(curCapacity) / maxCapacity * 100.0;
            }
        }
    }

    CFRelease(sourceInfo);
    CFRelease(sourceList);
    return percent;
}

extern "C" {
    void sendNotification(double batteryPercentage);
}

int main() {
    
    while (true) {
        double batteryPercentage = getBatData();

        if (batteryPercentage < 3) {
            sendNotification(batteryPercentage);
        }

        sleep(60);
    }

    return 0;
}
