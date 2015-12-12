#pragma once

template <class entity_type>
class StateMachine
{
  entity_type*          owner;
  State<entity_type>*   currentState;
  State<entity_type>*   previousState;
  State<entity_type>*   globalState;
public:
  StateMachine(entity_type* owner):owner(owner),
                                   currentState(NULL),
                                   previousState(NULL),
                                   globalState(NULL)
  {}
  virtual ~StateMachine(){}
  void SetCurrentState(State<entity_type>* s){currentState = s;}
  void SetGlobalState(State<entity_type>* s) {globalState = s;}
  void SetPreviousState(State<entity_type>* s){previousState = s;}

  State<entity_type>* CurrentState()  const{return currentState;}
  State<entity_type>* GlobalState()   const{return globalState;}
  State<entity_type>* PreviousState() const{return previousState;}
  
  void Update(long long time)const
  {
    if(globalState)   globalState->Execute(owner, time);
    if (currentState) currentState->Execute(owner, time);
  }

  void ChangeState(State<entity_type>* newState)
  {
    //assert(pNewState && "<StateMachine::ChangeState>:trying to assign null state to current");
    previousState = currentState;
    currentState->Exit(owner);
    currentState = newState;
    currentState->Enter(owner);
  }

  void RevertToPreviousState()
  {
    ChangeState(previousState);
  }

  bool isInState(const State<entity_type>& st)const
  {
    if (typeid(*currentState) == typeid(st)) return true;
    return false;
  }

  std::string GetNameOfCurrentState()const
  {
    std::string s(typeid(*currentState).name());
    if (s.size() > 5)
    {
      s.erase(0, 6);
    }
    return s;
  }
};