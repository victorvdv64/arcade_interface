/*
** EPITECH PROJECT, 2021
** IGameModule.hpp
** File description:
** header file for the IGameModule class
*/

#ifndef _IGAMEMODULE_H_
#define _IGAMEMODULE_H_

#include <string>
#include <map>

#include "IDisplayModule.hpp"

namespace Arcade {
    enum SwitchStatus
    {
        PREV = -1,
        NONE = 0,
        NEXT = 1
    };
    /*!
    ** \interface IGameModule
    ** This is an interface containing only pure virtual functions.
    ** The purpose of this class is to manage all data related to its game.
    ** It the passes it to the Arcade class, which the passes the data
    ** to the IDisplayModule class
    **/
    class IGameModule
    {
    public:
        virtual ~IGameModule(void) = default; ///< default destructor
        virtual void init(void) = 0; ///< Class initialization
        virtual void setEventManager(Arcade::EventManager *eventManager) = 0;
        virtual void start(void) = 0; ///< starts/stops the game
        virtual const char *getMap(void) const = 0;
        virtual const std::vector<TextData> *getTexts(void) const = 0;
        virtual bool isGameOver(void) const = 0;
        virtual int getScore(void) const = 0;
        virtual const std::map<char, struct Data> *getConfig(void) const = 0;
        virtual const VectorXY &getWindowSize(void) const = 0;
        virtual void restart(void) = 0; ///< restarts the game
        virtual void pause(void) = 0; ///< pauses the game
        virtual bool isQuit(void) const = 0; ///< Check if a quite signal has been sent
        virtual bool isRestartPressed(void) const = 0;
        virtual bool backToMenuPressed(void) const = 0;
        virtual SwitchStatus getGameSwitch(void) = 0; ///< get game switch status
        virtual SwitchStatus getDisplaySwitch(void) = 0; ///< get display switch status
        ///< @return true if the KEYEXIT has been pressed
        ///< @see Keyboard for more information about the keys
        virtual void update(float deltaTime) = 0; ///< this function updates the game data if needed
        virtual const std::string &getName(void) const = 0;
        virtual const Sprite *getBackGround(void) const = 0;
    };

}

#endif
