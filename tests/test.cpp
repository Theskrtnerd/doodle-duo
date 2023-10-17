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

TEST_CASE("Example Text Object") {
    // Arrange: Set up the initial conditions
    Text('Hello', 12, 12, )
}

TEST_CASE("Example Test Case 2") {
    // Another test case
    // Arrange
    int a = 0;
    int b = 42;

    // Act
    int result = divide(b, a); // Replace 'divide' with the actual function to test

    // Assert
    REQUIRE(result == 0);
}
