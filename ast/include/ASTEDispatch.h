#ifndef ASTEDISPATCH_H_
#define ASTEDISPATCH_H_

#include "ASTNode.h"
#include <memory>

namespace cool {
class ASTEDispatch : public ASTNode {

public:
  virtual ~ASTEDispatch() {}
};

typedef std::unique_ptr<ASTEDispatch> ASTEDispatchPtr;
}
#endif /* ASTEDISPATCH_H_ */
