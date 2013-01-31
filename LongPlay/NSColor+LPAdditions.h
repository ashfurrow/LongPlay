#import <Cocoa/Cocoa.h>

// Extensions to NSColor that add interoperability with CGColor.
@interface NSColor (LPAdditions)

// The CGColor corresponding to the receiver.
@property (nonatomic, readonly) CGColorRef lp_CGColor;

// Returns an NSColor corresponding to the given CGColor.
+ (NSColor *)lp_colorWithCGColor:(CGColorRef)color;

@end
