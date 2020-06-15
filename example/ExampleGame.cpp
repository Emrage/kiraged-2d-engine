//
// Created by Emre on 6/15/2020.
//

#include <iostream>
#include "ExampleGame.h"


ExampleGame::ExampleGame(int width, int height) : GameWindow(width, height) {
    auto rectangle = std::make_shared<Rectangle>(Point(50, 50), Dimension(50, 50));
    this->shapes.push_back(rectangle);
}

void ExampleGame::draw() {
    for (auto &shape : this->shapes) {
        shape->draw(static_cast<float>(getWidth()), static_cast<float>(getHeight()));
    }
}

void ExampleGame::onMouseButton(GLFWwindow *window, MouseEvents::MouseButtonEvent button, MouseEvents::MouseActionEvent action, int mods) {
    if (action == MouseEvents::pressed) {
        auto rectangle = std::dynamic_pointer_cast<Rectangle>(this->shapes[0]);
        rectangle->getDimension().incrementWidth(button == MouseEvents::leftClick ? 50 : -50);
        rectangle->getDimension().incrementHeight(button == MouseEvents::leftClick ? 50 : -50);
    }
}

void ExampleGame::onMouseMove(GLFWwindow *window, double xPos, double yPos) {
    GameWindow::onMouseMove(window, xPos, yPos);

    this->shapes[0]->getPoints()[0]->setX(static_cast<float>(xPos));
    this->shapes[0]->getPoints()[0]->setY(static_cast<float>(getHeight() - yPos));
}

