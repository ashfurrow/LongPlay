#import <Cocoa/Cocoa.h>

@interface NSImage (LPAdditions)

// Returns a CGImageRef corresponding to the receiver.
+ (NSImage *)lp_imageWithCGImage:(CGImageRef)cgImage;

// Returns an NSImage whose contents are those drawn by the block provided. Thread safe.
+ (NSImage *)lp_imageWithSize:(CGSize)size drawing:(void (^)(CGContextRef))draw;

// Returns a CGImageRef corresponding to the receiver. This should only
// be used with bitmaps. For vector images, use -CGImageForProposedRect:context:hints instead.
@property (nonatomic, readonly) CGImageRef lp_CGImage;

//  Similar to -CGImageForProposedRect:context:hints:, but accepts a CGContextRef instead.
- (CGImageRef)lp_CGImageForProposedRect:(CGRect *)rectPtr CGContext:(CGContextRef)context;

// Draws the whole image originating at the given point.
- (void)lp_drawAtPoint:(CGPoint)point;

// Draws the whole image into the given rectangle.
- (void)lp_drawInRect:(CGRect)rect;

@end
