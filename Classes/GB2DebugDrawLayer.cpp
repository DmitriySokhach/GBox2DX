#include "GB2DebugDrawLayer.h"
#include "GB2Engine.h"
#include "Box2D/Box2D.h"
#include "GB2Helper.h"
#include "2d/CCLayer.h"

USING_NS_CC;
USING_NS_GB;

GB2DebugDrawLayer* GB2DebugDrawLayer::create()
{
    b2World *bworld = GB2Engine::sharedInstance()->getworld();
    return create(bworld, PTM_RATIO);
}

GB2DebugDrawLayer* GB2DebugDrawLayer::create(b2World* pB2World, float pPtmRatio)
{
    GB2DebugDrawLayer *pRet = new GB2DebugDrawLayer(pB2World, pPtmRatio);
    if (pRet && pRet->init())
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}

GB2DebugDrawLayer::GB2DebugDrawLayer(b2World* pB2World, float pPtmRatio)
: _world(pB2World), _ptmRatio(pPtmRatio)
{
}

bool GB2DebugDrawLayer::init()
{
    //////////////////////////////
    // 1. super init first

    if (!Layer::init())
    {
        return false;
    }

    mB2DebugDraw = new GLESDebugDraw(_ptmRatio);
    _world->SetDebugDraw(mB2DebugDraw);

    uint32 flags = 0;
    flags += b2Draw::e_shapeBit;
    flags += b2Draw::e_jointBit;
    flags += b2Draw::e_aabbBit;
    flags += b2Draw::e_pairBit;
    flags += b2Draw::e_centerOfMassBit;
    mB2DebugDraw->SetFlags(flags);

    return true;
}

//GB2DebugDrawLayer *GB2DebugDrawLayer::init()
//{
//    GB2DebugDrawLayer *ddlayer = new GB2DebugDrawLayer();
//
//    if (!cocos2d::Layer::init())
//    {
//        return false;
//    }
//
//    if (ddlayer)
//    {
//        // take world from the singleton
//        //world = [GB2Engine sharedInstance].world;
//        b2World *bworld = GB2Engine::sharedInstance()->getworld();
//
//        // Enable debug draw
//        GLESDebugDraw *debugDraw = new GLESDebugDraw(PTM_RATIO);
//
//        // Set the flags
//        uint32 flags = 0;
//
//        flags += b2Draw::e_shapeBit;
//        /*
//        flags += b2Draw::e_jointBit;
//        flags += b2Draw::e_centerOfMassBit;
//        flags += b2Draw::e_aabbBit;
//        flags += b2Draw::e_pairBit;
//        */
//        flags += b2Draw::e_centerOfMassBit;
//
//        debugDraw->SetFlags(flags);
//
//        bworld->SetDebugDraw(debugDraw);
//
//        ddlayer->setWorld(bworld);
//    }
//    return ddlayer;
//}

GB2DebugDrawLayer::~GB2DebugDrawLayer()
{
    // remove debug draw from the world
    _world->SetDebugDraw(0);
}

void GB2DebugDrawLayer::draw(Renderer *renderer, const Mat4 &transform, bool transformUpdated)
{
    //
    // IMPORTANT:
    // This is only for debug purposes
    // It is recommend to disable it
    //
    Layer::draw(renderer, transform, transformUpdated);

//#if CC_ENABLE_BOX2D_INTEGRATION
    GL::enableVertexAttribs(cocos2d::GL::VERTEX_ATTRIB_FLAG_POSITION);
    Director* director = Director::getInstance();
    CCASSERT(nullptr != director, "Director is null when seting matrix stack");
    director->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);

    _modelViewMV = director->getMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);

    _customCommand.init(_globalZOrder);
    _customCommand.func = CC_CALLBACK_0(GB2DebugDrawLayer::onDraw, this);
    renderer->addCommand(&_customCommand);

    director->popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
//#endif
}

//#if CC_ENABLE_BOX2D_INTEGRATION
void GB2DebugDrawLayer::onDraw()
{
    Director* director = Director::getInstance();
    CCASSERT(nullptr != director, "Director is null when seting matrix stack");

    Mat4 oldMV;
    oldMV = director->getMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
    director->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, _modelViewMV);
    _world->DrawDebugData();
    director->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, oldMV);
}
//#endif