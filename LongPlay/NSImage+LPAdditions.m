#import "NSImage+LPAdditions.h"

@implementation NSImage (LPAdditions)

+ (NSImage *)lp_imageWithCGImage:(CGImageRef)cgImage {
	CGSize size = CGSizeMake(CGImageGetWidth(cgImage), CGImageGetHeight(cgImage));
	return [[self alloc] initWithCGImage:cgImage size:size];
}

+ (NSImage *)lp_imageWithSize:(CGSize)size drawing:(void(^)(CGContextRef))draw {
	if(size.width < 1 || size.height < 1)
		return nil;
	
	CGFloat scale = [[NSScreen mainScreen] respondsToSelector:@selector(backingScaleFactor)] ? [[NSScreen mainScreen] backingScaleFactor] : 1.0f;
	size = CGSizeMake(size.width * scale, size.height * scale);
	
	CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
	CGBitmapInfo bitmapInfo = kCGBitmapByteOrder32Host | kCGImageAlphaPremultipliedFirst;
	CGContextRef ctx = CGBitmapContextCreate(NULL, size.width, size.height, 8, 4 * size.width, colorSpace, bitmapInfo);
	CGColorSpaceRelease(colorSpace);

	CGContextScaleCTM(ctx, scale, scale);
	draw(ctx);
	
	CGImageRef CGImage = CGBitmapContextCreateImage(ctx);
	CGSize newSize = CGSizeMake(CGImageGetWidth(CGImage), CGImageGetHeight(CGImage));
	NSImage *image = [[NSImage alloc] initWithCGImage:CGImage size:newSize];
	CGImageRelease(CGImage);
	CGContextRelease(ctx);
	return image;
}

- (CGImageRef)lp_CGImage {
	return [self CGImageForProposedRect:NULL context:nil hints:nil];
}

- (CGImageRef)lp_CGImageForProposedRect:(CGRect *)rectPtr CGContext:(CGContextRef)context {
	NSGraphicsContext *graphicsContext = [NSGraphicsContext graphicsContextWithGraphicsPort:context flipped:NO];
	return [self CGImageForProposedRect:rectPtr context:graphicsContext hints:nil];
}

- (void)lp_drawAtPoint:(CGPoint)point {
	[self drawAtPoint:point fromRect:NSZeroRect operation:NSCompositeSourceOver fraction:1.0];
}

- (void)lp_drawInRect:(CGRect)rect {
	[self drawInRect:rect fromRect:NSZeroRect operation:NSCompositeSourceOver fraction:1.0];
}

@end
