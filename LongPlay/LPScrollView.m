#import "LPScrollView.h"
#import "LPClipView.h"

@implementation LPScrollView

#pragma mark Lifecycle

- (id)initWithFrame:(NSRect)frameRect {
	self = [super initWithFrame:frameRect];
	if (self == nil) return nil;
	
	[self swapClipView];
	
	return self;
}

- (void)awakeFromNib {
	[super awakeFromNib];
	
	if (![self.contentView isKindOfClass:LPClipView.class] ) {
		[self swapClipView];
	}
}

#pragma mark Clip view swapping

- (void)swapClipView {
	self.wantsLayer = YES;
	id documentView = self.documentView;
	LPClipView *clipView = [[LPClipView alloc] initWithFrame:self.contentView.frame];
	self.contentView = clipView;
	self.documentView = documentView;
}

@end
