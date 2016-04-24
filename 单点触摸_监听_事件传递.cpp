#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    //获取屏幕的大小
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();



    //显示文本arg(String,font,fontsize)
    auto label = LabelTTF::create("Click me", "Courier", 30);
    //显示位置
    label->setPosition(visibleSize.width/2,visibleSize.height/2);
    //添加到当前场景
    addChild(label);
    
    //文本的点击监听器
    //getBoundingBox() 获得边界盒子
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [](Touch *t,Event *e){
    
        //限定点击范围
        if(e->getCurrentTarget()->
           getBoundingBox().containsPoint(t->
                                          getLocation())){
            log("onTouchBegan !");
        }
        
        return true;
        
    };
    
    //事件传递,移动监听，点击事件需要返回true才能生效
    listener->onTouchMoved=[](Touch* t, Event* e){
        log("onTouchMoved");
    
    };
    
    //事件传递,抬起监听，点击事件需要返回true才能生效
    listener->onTouchEnded=[](Touch* t, Event* e){
        log("onTouchEnded");
        
    };
    
    
    
    //监听器添加到场景
    Director::getInstance()->getEventDispatcher()->
    addEventListenerWithSceneGraphPriority(listener, label);
    
    
    
    
    return true;
}





void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}





