#import "LPClipView.h"
#import "NSColor+LPAdditions.h"

@implementation LPClipView

#pragma mark Properties

@dynamic layer;

- (NSColor *)backgroundColor {
	return [NSColor lp_colorWithCGColor:self.layer.backgroundColor];
}

- (void)setBackgroundColor:(NSColor *)color {
	self.layer.backgroundColor = color.lp_CGColor;
}

- (BOOL)isOpaque {
	return self.layer.opaque;
}

- (void)setOpaque:(BOOL)opaque {
	self.layer.opaque = opaque;
}

#pragma mark Lifecycle

- (id)initWithFrame:(NSRect)frame {
	self = [super initWithFrame:frame];
	if (self == nil) return nil;

	self.layer = [CAScrollLayer layer];
	self.wantsLayer = YES;

	self.layerContentsRedrawPolicy = NSViewLayerContentsRedrawNever;

	// Matches default NSClipView settings.
	self.backgroundColor = NSColor.clearColor;
	self.opaque = NO;

	return self;
}

@end
