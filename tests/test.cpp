#define CATCH_CONFIG_MAIN
#include<catch2/catch.hpp>

#include "include/MoveableObject.h"
#include "include/Cell.h"
#include "include/Obstacle.h"
#include "include/GameObject.h"
#include "include/Background.h"
#include "include/ScreenButton.h"
#include "include/Button.h"
#include "include/functions.h"
#include "include/Lever.h"
#include "include/Door.h"
#include "include/GameObjectArray.h"
#include "include/GameTextures.h"
#include "include/GameEngine.h"
#include "include/Player.h"
#include "include/Exit.h"
#include "include/ImmoveableObject.h"
#include "include/Text.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/Player.cpp"  // Adjust the path

TEST_CASE("Player Movement", "[Player]") {
    GameTextures gameTextures;  // Mock this if needed
    Player player(0, 0, "red", gameTextures);

    SECTION("Move Left") {
        player.moveLeft();
        REQUIRE(player.getVelocityX() < 0);  // Replace with actual getter
    }

    SECTION("Move Right") {
        player.moveRight();
        REQUIRE(player.getVelocityX() > 0);  // Replace with actual getter
    }
}

TEST_CASE("Player Jump", "[Player]") {
    GameTextures gameTextures;  // Mock this if needed
    Player player(0, 0, "red", gameTextures);
    GameObjectArray objects;  // Mock this if needed

    player.jump(objects);
    REQUIRE(player.getVelocityY() < 0);  // Replace with actual getter
}