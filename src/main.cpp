
#include <Geode/Geode.hpp>


using namespace geode::prelude;


#include <Geode/modify/MenuLayer.hpp>
class $modify(MyMenuLayer, MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}
		if (Mod::get()->getSettingValue<bool>("toggle") = true) {
			log::debug("Hello from my MenuLayer::init hook! This layer has {} children.", this->getChildrenCount());

			auto myButton = CCMenuItemSpriteExtra::create(
				CCSprite::createWithSpriteFrameName("GJ_likeBtn_001.png"),
				this,
				menu_selector(MyMenuLayer::onMyButton)
			);

			if (!Mod::get()->getSettingValue<bool>("Second-Button") = true) {
				auto button2 = CCMenuItemSpriteExtra::create(
					CCSprite::createWithSpriteFrameName("chest_02_03_001.png"),
					this,
					menu_selector(MyMenuLayer::onMyButton)
				);
			}

			auto menu = this->getChildByID("bottom-menu");
			menu->addChild(myButton);
			if (!Mod::get()->getSettingValue<bool>("Second-Button") = true) {
				menu->addChild(mybutton2);
			}

			myButton->setID("my-button"_spr);
			if (!Mod::get()->getSettingValue<bool>("Second-Button") = true) {
				myButton2->setID("my-button"_spr);
			}

			menu->updateLayout();

			return true;
		}
		void onMyButton(CCObject*) {
			FLAlertLayer::create(
				"Geode", // Title of popup
				"Hello from my custom mod!", // Body of popup
				"OK" // button of popup
			)->show(); // show the popup
		}
	}
};