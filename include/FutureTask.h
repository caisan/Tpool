// -*- mode: c++ -*-
#ifndef _TPOOL_FUTURE_TASK_H_
#define _TPOOL_FUTURE_TASK_H_

#include "TaskBase.h"

namespace tpool {
  template <typename T>
  class FutureTask : public TaskBase {
  public:
    FutureTask();
    virtual ~FutureTask();

    T GetResult();
    
  private:
    virtual void DoRun();
    virtual T Call() = 0;

    T m_result;
  };

  // Partial specialization for void, which forbids
  // users from defining a method returning void.
  template <>
  class FutureTask<void>;

  // Implementation
  
}

#endif