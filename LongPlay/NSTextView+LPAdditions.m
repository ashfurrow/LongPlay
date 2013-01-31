#import "NSTextView+LPAdditions.h"
#import <objc/runtime.h>

static void (*originalDrawRectIMP)(id, SEL, NSRect);

static void fixedDrawRect (NSTextView *self, SEL _cmd, NSRect rect) {
	CGContextRef context = NSGraphicsContext.currentContext.graphicsPort;
	CGContextSetAllowsAntialiasing(context, YES);
	CGContextSetAllowsFontSmoothing(context, YES);
	CGContextSetAllowsFontSubpixelPositioning(context, YES);
	CGContextSetAllowsFontSubpixelQuantization(context, YES);

	if(self.superview)
		self.frame = [self.superview backingAlignedRect:self.frame options:NSAlignAllEdgesNearest];
	originalDrawRectIMP(self, _cmd, rect);
}

@implementation NSTextView (LPAdditions)

+ (void)load {
	Method drawRect = class_getInstanceMethod(self, @selector(drawRect:));
	originalDrawRectIMP = (void (*)(id, SEL, NSRect))method_getImplementation(drawRect);
	method_setImplementation(drawRect, (IMP)&fixedDrawRect);
}

@end
