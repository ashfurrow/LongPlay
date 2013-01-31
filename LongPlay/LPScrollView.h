#import <Cocoa/Cocoa.h>

// A NSScrollView subclass which uses an instance of RBLClipView
// as the clip view instead of NSClipView. Layer-backed by default.
@interface LPScrollView : NSScrollView

@end
