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

#include "GB2Sprite.h"
#include "GB2Engine.h"
#include "GB2ShapeCache.h"

USING_NS_GB;

GB2Sprite::GB2Sprite(void)
{
}

GB2Sprite::~GB2Sprite()
{
}

GB2Sprite* gbox2d::GB2Sprite::initWithStaticBody(std::string shapeName, std::string spriteName)
{
    return (GB2Sprite*) GB2Node::initWithStaticBody(__String::create(shapeName), Sprite::createWithSpriteFrameName(spriteName));
}


//-(id) initWithDynamicBody:(NSString *)shape spriteFrameName:(NSString*)spriteName
//{
//    return [super initWithDynamicBody:shape node:[CCSprite spriteWithSpriteFrameName:spriteName]];   
//}
//
//-(id) initWithStaticBody:(NSString *)shape spriteFrameName:(NSString*)spriteName
//{
//    return [super initWithStaticBody:shape node:[CCSprite spriteWithSpriteFrameName:spriteName]];
//}


//
//-(id) initWithKinematicBody:(NSString *)shape spriteFrameName:(NSString*)spriteName
//{
//    return [super initWithKinematicBody:shape node:[CCSprite spriteWithSpriteFrameName:spriteName]];
//}
//
//+(id) spriteWithDynamicBody:(NSString *)shape spriteFrameName:(NSString*)spriteName
//{
//    return [[[GB2Sprite alloc] initWithDynamicBody:shape spriteFrameName:spriteName] autorelease];    
//}
//
//+(id) spriteWithStaticBody:(NSString *)shape spriteFrameName:(NSString*)spriteName
//{
//    return [[[GB2Sprite alloc] initWithStaticBody:shape spriteFrameName:spriteName] autorelease];        
//}
//
//+(id) spriteWithKinematicBody:(NSString *)shape spriteFrameName:(NSString*)spriteName
//{
//    return [[[GB2Sprite alloc] initWithKinematicBody:shape spriteFrameName:spriteName] autorelease];        
//}
//
//- (NSString*) description
//{
//    b2Vec2 pos = [self physicsPosition];
//    b2Vec2 vel = [self linearVelocity];
//	return [NSString stringWithFormat:@"<%@ = %8@ | pos:(%f,%f) active=%d awake=%d vel=(%f,%f)>", 
//            [self class], 
//            self, 
//            pos.x, pos.y, 
//            [self active], 
//            [self awake],
//            vel.x, vel.y
//            ];
//}
//
//-(void)setDisplayFrame:(CCSpriteFrame *)newFrame
//{
//    [(CCSprite*)self.ccNode setDisplayFrame:newFrame];
//}
//
//-(void) setDisplayFrameNamed:(NSString*)name
//{
//    [(CCSprite*)self.ccNode setDisplayFrame:[[CCSpriteFrameCache sharedSpriteFrameCache] spriteFrameByName:name]];
//}
