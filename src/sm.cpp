#include <iostream>


enum class State {
    NONE,
    SETUP,
    PRELAUNCH,
    READY,
    LAUNCH
};

enum class ActionType {
    TURN_ON_CAMERA,
    PYRO_CHARGES
};

class Permissions {
private:
    std::unordered_map<ActionType, std::vector<State>> allowedActions;

public:
    Permissions() {
        allowedActions[ActionType::TURN_ON_CAMERA] = {State::READY, State::LAUNCH};
        allowedActions[ActionType::PYRO_CHARGES] = {State::LAUNCH};
    }

bool isActionAllowed(ActionType action, State currentState) const {
        auto it = allowedActions.find(action);
        if (it != allowedActions.end()) {
            const std::vector<State>& allowedStates = it->second;
            return std::find(allowedStates.begin(), allowedStates.end(),
                currentState) != allowedStates.end();
        }
        return false;



class StateMachine {
private:
    State currentState;
    Permissions permissions;

public:
    StateMachine() : currentState(State::NONE) {}

    void transition() {
        switch (currentState) {
            case State::NONE:
                currentState = State::SETUP;
                //std::cout << "Transition: SETUP -> " << stateToString(currentState) << "\n";  pour debug s'il le faut  
                break;
            case State::SETUP:
                // Conditions pour savoir si on passe à prelaunch ou none, si none réinitialiser les métadonnées
                // Si resetPressedOn ou erreur détectée alors none
                std::cout << "Transition: SETUP -> " << stateToString(currentState) << "\n";
                break;
            case State::PRELAUNCH:
                // Conditions pour savoir si on passe à ready ou none, si none réinitialiser les métadonnées
                // Si resetPressedOn ou erreur détectée alors none
                std::cout << "Transition: PRELAUNCH->"<<stateToString(currentState) << "\n";
                break;
            case State::READY:
                // Conditions pour savoir si on passe à launch ou none, si none réinitialiser les métadonnées
                // Si resetPressedOn ou erreur détectée alors none
                std::cout << "Transition: READY -> " << stateToString(currentState) << "\n";
                break;
            case State::LAUNCH:
                // ne rien faire
                break;
            default:
                // n'est pas censé avoir lieu
                std::cout << "Impossible Error";
                break;
        }
        // TODO : modification des métadonnées + appel de fonctions dans certaines transitions 
    }


    std::string stateToString(State state) const {
        switch (state) {
            case State::NONE: return "NONE";
            case State::SETUP: return "SETUP";
            case State::PRELAUNCH: return "PRELAUNCH";
            case State::READY: return "READY";
            case State::LAUNCH: return "LAUNCH";
            default: return "UNKNOWN";
        }
    }
};
