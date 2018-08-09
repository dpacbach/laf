// LAF OS Library
// Copyright (C) 2012-2017  David Capello
//
// This file is released under the terms of the MIT license.
// Read LICENSE.txt for more information.

#ifndef OS_OSX_WINDOW_H_INCLUDED
#define OS_OSX_WINDOW_H_INCLUDED
#pragma once

#include <Cocoa/Cocoa.h>

#include "gfx/point.h"
#include "gfx/rect.h"
#include "gfx/size.h"
#include "os/keys.h"
#include "os/native_cursor.h"

namespace os {
  class Surface;
}

class OSXWindowImpl {
public:
  virtual ~OSXWindowImpl() { }
  virtual void onClose() = 0;
  virtual void onResize(const gfx::Size& size) = 0;
  virtual void onDrawRect(const gfx::Rect& rect) = 0;
  virtual void onWindowChanged() = 0;
};

@class OSXWindowDelegate;

@interface OSXWindow : NSWindow {
@private
  OSXWindowImpl* m_impl;
  OSXWindowDelegate* m_delegate;
  int m_scale;
}
- (OSXWindow*)initWithImpl:(OSXWindowImpl*)impl
                     width:(int)width
                    height:(int)height
                     scale:(int)scale;
- (OSXWindowImpl*)impl;
- (int)scale;
- (void)setScale:(int)scale;
- (gfx::Size)clientSize;
- (gfx::Size)restoredSize;
- (void)setMousePosition:(const gfx::Point&)position;
- (BOOL)setNativeMouseCursor:(os::NativeCursor)cursor;
- (BOOL)setNativeMouseCursor:(const os::Surface*)surface
                       focus:(const gfx::Point&)focus
                       scale:(const int)scale;
@end

#endif
