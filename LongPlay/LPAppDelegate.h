#import <Cocoa/Cocoa.h>
#import "LPCommon.h"

@class INAppStoreWindow;

@interface LPAppDelegate : NSObject <NSApplicationDelegate>

@property (nonatomic, weak) IBOutlet INAppStoreWindow *window;
@property (nonatomic, weak) IBOutlet NSView *titlebarView;

@property (nonatomic, strong, readonly) NSPersistentStoreCoordinator *persistentStoreCoordinator;
@property (nonatomic, strong, readonly) NSManagedObjectModel *managedObjectModel;
@property (nonatomic, strong, readonly) NSManagedObjectContext *managedObjectContext;

- (IBAction)saveAction:(id)sender;

@end
