#ifndef LongPlay_Header_h
#define LongPlay_Header_h

#define LPBackgroundPirelli ([NSImage imageNamed:@"pirelli"])
#define LPBackgroundMiniPirelli ([NSImage imageNamed:@"mini_pirelli"])

static NSString *const LPErrorDomain = @"LPErrorDomain";
typedef enum LPErrorCode : NSUInteger {
	LPErrorCodeUnknownError = -9999
} LPErrorCode;

#endif
