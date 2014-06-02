/*
 MIT License

 Copyright (c) 2010 Andreas Loew / www.code-and-web.de

 For more information about htis module visit
 http://www.PhysicsEditor.de

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 */
#ifndef __GB2SPRITE_H__
#define __GB2SPRITE_H__

#include "cocos2d.h"
#include "GB2Node.h"

NS_GB_BEGIN

class GB2Sprite : public GB2Node
{
public:

    GB2Sprite();
    ~GB2Sprite();
    /**
     * Create a GB2Sprite with the given shape and dispay frame name.
     * The body is created as dynamic body
     * @param shape shape name for the body
     * @param spriteName name of the sprite
     */
    //-(id) initWithDynamicBody:(NSString *)shape spriteFrameName:(NSString*)spriteName;

    /**
     * Create a GB2Sprite with the given shape and dispay frame name.
     * The body is created as static body
     * @param shape shape name for the body
     * @param spriteName name of the sprite
     */
    //-(id) initWithStaticBody:(NSString *)shape spriteFrameName:(NSString*)spriteName;
    static GB2Sprite* initWithStaticBody(std::string shapeName, std::string spriteName);

    /**
     * Create a GB2Sprite with the given shape and dispay frame name.
     * The body is created as kinematic body
     * @param shape shape name for the body
     * @param spriteName name of the sprite
     */
    //-(id) initWithKinematicBody:(NSString *)shape spriteFrameName:(NSString*)spriteName;

    /**
     * Create a GB2Sprite with the given shape and dispay frame name.
     * The body is created as dynamic body
     * @param shape shape name for the body
     * @param spriteName name of the sprite
     */
    //+(id) spriteWithDynamicBody:(NSString *)shape spriteFrameName:(NSString*)spriteName;

    /**
     * Create a GB2Sprite with the given shape and dispay frame name.
     * The body is created as static body
     * @param shape shape name for the body
     * @param spriteName name of the sprite
     */
    //+(id) spriteWithStaticBody:(NSString *)shape spriteFrameName:(NSString*)spriteName;

    /**
     * Create a GB2Sprite with the given shape and dispay frame name.
     * The body is created as kinematic body
     * @param shape shape name for the body
     * @param spriteName name of the sprite
     */
    //+(id) spriteWithKinematicBody:(NSString *)shape spriteFrameName:(NSString*)spriteName;

    /**
     * Sets the display frame on the inner CCSprite
     * @param newFrame frame to set
     */
    //-(void) setDisplayFrame:(CCSpriteFrame*)newFrame;

    /**
     * Sets a display frame by it's name
     * @param name name of the frame to set
     */
    //-(void) setDisplayFrameNamed:(NSString*)name;

};

NS_GB_END

#endif  // __GB2SPRITE_H__