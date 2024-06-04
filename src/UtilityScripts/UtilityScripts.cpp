//
// Created by KDen404 on 29.05.24.
//

namespace UtilityScripts {
    template<class ConditionClass, class ActionClass, class ReturnClass>
    inline ReturnClass await(ConditionClass condition, ActionClass action) {

        //This is a simple await function that takes a condition and an action and waits until the condition is false.
        //initial design was made to be used to observe a variable until it was initialized,
        //then starts executing code after the Variable is no longer a nullptr.
        while (condition()) {
        }
        return ReturnClass(action());
    }
}