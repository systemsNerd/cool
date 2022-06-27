#ifndef ASTIDISPATCH_H_
#define ASTIDISPATCH_H_

#include "ASTNode.h"
#include <memory>

namespace cool {
class ASTIDispatch : public ASTNode {

public:
  virtual ~ASTIDispatch() {}
};

typedef std::unique_ptr<ASTIDispatch> ASTIDispatchPtr;
}
#endif /* ASTIDISPATCH_H_ */
