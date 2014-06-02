/*
 MIT License

 Copyright (c) 2010 Andreas Loew / www.code-and-web.de
 Copyright (c) 2012 Chris Hannon / channon.us

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
#ifndef __GB2DEBUGDRAWLAYER_H__
#define __GB2DEBUGDRAWLAYER_H__

#include "GB2Config.h"
#include "cocos2d.h"

USING_NS_CC;

class b2World;
class GLESDebugDraw;

/**
 * Debug draw layer
 * Wraps the GLESDebugDraw in an CCLayer
 * Detects retina display
 */

#include "GLES-Render.h"

NS_GB_BEGIN

class GB2DebugDrawLayer : public cocos2d::Layer
{
protected:
    CC_SYNTHESIZE(b2World*, _world, World);  //!< weak reference to the world
    CC_SYNTHESIZE(GLESDebugDraw*, _debugDraw, DebugDraw); //!< weak reference to a GLESDebugDraw
    const float _ptmRatio;
    GLESDebugDraw* mB2DebugDraw;

    GB2DebugDrawLayer(b2World* pB2World, float pPtmRatio);
    ~GB2DebugDrawLayer();
    
    static GB2DebugDrawLayer* create(b2World* pB2World, float pPtmRatio);
    static GB2DebugDrawLayer* create();
    bool GB2DebugDrawLayer::init() override; 

    Mat4 _modelViewMV;
    void onDraw();
    CustomCommand _customCommand;

public:
    virtual void draw(Renderer *renderer, const Mat4 &transform, bool transformUpdated) override;
};

NS_GB_END

#endif