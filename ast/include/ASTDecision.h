#ifndef ASTDECISION_H_
#define ASTDECISION_H_

#include "ASTNode.h"
#include <memory>

namespace cool {
class ASTDecision : public ASTNode {

public:
  virtual ~ASTDecision() {}
};

typedef std::unique_ptr<ASTDecision> ASTDecisionPtr;
}
#endif /* ASTDECISION_H_ */
