#import <Foundation/Foundation.h>

void sendNotification(double batteryPercentage) {
    NSString *title = @"Low Battery Notification";
    NSString *message = [NSString stringWithFormat:@"Battery Percentage is %.2f%%. Connect the charger!", batteryPercentage];
    
    NSString *scriptSource = [NSString stringWithFormat:@"display notification \"%@\" with title \"%@\" sound name \"default\"  subtitle \"%@\"", message, title, message];
    
    NSString *command = [NSString stringWithFormat:@"osascript -e '%@'", scriptSource];
    system([command UTF8String]);
}
