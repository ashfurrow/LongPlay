#import "LPAlbumViewController.h"

@implementation LPAlbumViewController

- (void)loadView {
	[super loadView];
	
	self.collectionView.enclosingScrollView.backgroundColor = [NSColor colorWithPatternImage:LPBackgroundPirelli];
	self.collectionView.backgroundColors = @[[NSColor clearColor]];
	self.collectionView.minItemSize = NSMakeSize(256, 256);
	self.collectionView.maxItemSize = NSMakeSize(256, 256);
	self.collectionView.content = @[@"A", @"B", @"A", @"B", @"A", @"B", @"A", @"B", @"A", @"B", @"A", @"B", @"A", @"B"];
}

@end
