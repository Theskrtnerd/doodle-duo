#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "../include/MoveableObject.h"
#include "../include/Cell.h"
#include "../include/Obstacle.h"
#include "../include/GameObject.h"
#include "../include/Background.h"
#include "../include/ScreenButton.h"
#include "../include/Button.h"
#include "../include/functions.h"
#include "../include/Lever.h"
#include "../include/Door.h"
#include "../include/GameObjectArray.h"
#include "../include/GameTextures.h"
#include "../include/GameEngine.h"
#include "../include/Player.h"
#include "../include/Exit.h"
#include "../include/ImmoveableObject.h"
#include "../include/Text.h"




#include "../src/Player.cpp"  // Adjust the path
#include "../src/GameEngine.cpp"  // Adjust the path
#include "../src/GameTextures.cpp"  // Adjust the path
#include "../src/functions.cpp"  // Adjust the path
#include "../src/GameObjectArray.cpp"  // Adjust the path
#include "../src/MoveableObject.cpp"  // Adjust the path
#include "../src/GameObject.cpp"  // Adjust the path
#include "../src/Obstacle.cpp"  // Adjust the path
#include "../src/Background.cpp"  // Adjust the path
#include "../src/Cell.cpp"
#include "../src/ScreenButton.cpp"
#include "../src/Button.cpp"
#include "../src/Door.cpp"
#include "../src/Lever.cpp"
#include "../src/Exit.cpp"
#include "../src/Text.cpp"
#include "../src/ImmoveableObject.cpp"


TEST_CASE("Player Movement", "[Player]") {
    GameTextures* gameTextures = new GameTextures();  // Mock this if needed
    Player player(0, 0, "red", *gameTextures);

    SECTION("Move Left") {
        player.moveLeft();
        REQUIRE(player.getVelocityX() < 0.0);  // Replace with actual getter
    }

    SECTION("Move Right") {
        player.moveRight();
        REQUIRE(player.getVelocityX() > 0.0);  // Replace with actual getter
    }
}

TEST_CASE("Button Collision Type", "[Button]") {
    GameTextures* gameTextures = new GameTextures();  // Mock this if needed
    Button button(0, 0, *gameTextures, "red");

    SECTION("Collision Type") {
        REQUIRE(button.collisionType() == "button");
    }

    delete gameTextures;
}

TEST_CASE("Door Collision Type based on open and close", "[Door]") {
    GameTextures* gameTextures = new GameTextures();  // Mock this if needed
    Door door(0, 0, *gameTextures, "red");

    SECTION("DOOR OPEN")
    {
        door.listen("red", "on");
        REQUIRE(door.collisionType() != "immoveable");
    }

    SECTION("DOOR CLOSE")
    {
        door.listen("red", "off");
        REQUIRE(door.collisionType() == "immoveable");
    }
}

TEST_CASE("String to color", "[functions]")
{
    SECTION("RED")
    {
        REQUIRE(stringToColor("red") == sf::Color::Red);
    }
    SECTION("GREEN")
    {
        REQUIRE(stringToColor("green") == sf::Color::Green);
    }
    SECTION("BLUE")
    {
        REQUIRE(stringToColor("blue") == sf::Color::Blue);
    }
}

TEST_CASE("GameObject passable", "[GameObject]")
{
    GameTextures* gameTextures = new GameTextures();  // Mock this if needed
    GameObject gameObject(0, 0, *gameTextures);

    REQUIRE(gameObject.collisionType() == "passable");
}

TEST_CASE("ImmoveableObject Collision Type", "[ImmoveableObject]")
{
    GameTextures* gameTextures = new GameTextures();  // Mock this if needed
    ImmoveableObject immoveableObject(0, 0, *gameTextures);

    REQUIRE(immoveableObject.collisionType() == "immoveable");
}

TEST_CASE("MoveableObject stop movement", "[MoveableObject]")
{
    GameTextures* gameTextures = new GameTextures();  // Mock this if needed
    MoveableObject moveableObject(0, 0, *gameTextures);

    REQUIRE(moveableObject.getVelocityX() == 0.0);
    REQUIRE(moveableObject.getVelocityY() == 0.0);

    moveableObject.stopMovement();

    REQUIRE(moveableObject.getVelocityX() == 0.0);
    REQUIRE(moveableObject.getVelocityY() == 0.0);

    moveableObject.stopHorizontalMovement();

    REQUIRE(moveableObject.getVelocityX() == 0.0);
    REQUIRE(moveableObject.getVelocityY() == 0.0);

    moveableObject.stopVerticalMovement();

    REQUIRE(moveableObject.getVelocityX() == 0.0);
    REQUIRE(moveableObject.getVelocityY() == 0.0);
}

TEST_CASE("Obstacle Collision Type", "[Obstacle]")
{
    GameTextures* gameTextures = new GameTextures();  // Mock this if needed
    Obstacle obstacle(0, 0, *gameTextures, "red");

    REQUIRE(obstacle.collisionType() == "obstacle red");

    Obstacle obstacle2(0, 0, *gameTextures, "blue");

    REQUIRE(obstacle2.collisionType() == "obstacle blue");
}